#include "../include/vdfstatemachine.h"

#include <QVariant>
#include <sstream>

namespace VDFStateMachine {

    namespace ENTRYID {
        void handleState(uint8_t& value, ParseState& state, FieldType& type) {
            if (value == 0x02) {
                state = ParseState::KEY;
                type = FieldType::BOOLEAN;
            }
            else if(value == 0x01)
            {
                state = ParseState::KEY;
                type = FieldType::STRING;
            }
        }
    };

    namespace WAITING {
        void handleState(uint8_t& value, ParseState& state, FieldType& type, QStringList& listValue) {
            if (value != 0x08) {
                //Update the state
                state = ParseState::KEY;
                if (value == 0x01) type = FieldType::STRING;
                else if (value == 0x02) type = FieldType::BOOLEAN;
                else if (value == 0x00) {
                    listValue.clear();
                    type = FieldType::LIST;
                }
            }
        }
    };

    namespace KEY {
        void handleState(uint8_t& value, ParseState& state, FieldType& type, std::ostringstream& utf8String, QString& key) {
            if (value != 0x00) {
                utf8String << static_cast<char>(value);
                if(QString::fromStdString(utf8String.str()).contains("\u0001"))
                    utf8String.str("");
            } else {
                key = QString::fromStdString(utf8String.str());
                utf8String.str("");

                //Update the state
                state = ParseState::VALUE;
                if (key == "lastplaytime")
                    type = FieldType::DATE;
                if(key == "appid")
                    type = FieldType::APPID;
            }
        }
    };

    namespace VALUE {
        void handleState(uint8_t& value, ParseState& state, FieldType& type, std::ostringstream& utf8String,
            QString& key, SteamShortcutEntry& entry, ListParseState& listState, QStringList& listValue,
            QByteArray& bytes, std::vector<char>& endingBuffer, QVector<SteamShortcutEntry>& shortcuts) {
                steam_shortcut_property new_property;
                switch(type) {
                case FieldType::STRING:
                    if (value != 0x00) {
                        utf8String << static_cast<char>(value);
                    } else {
                        new_property.value = QString::fromStdString(utf8String.str());
                        new_property.type = type;
                        entry.setProperty(key.toLower(), key, new_property);
                        utf8String.str("");

                        //Update the state
                        state = ParseState::WAITING;
                    }
                    break;
                case FieldType::BOOLEAN:
                    if (value == 0x01) {
                        new_property.value = "true";
                        new_property.type = type;
                        entry.setProperty(key.toLower(), key, new_property);
                    }
                    if (value == 0x00)
                    {
                        new_property.value = "false";
                        new_property.type = type;
                        entry.setProperty(key.toLower(), key, new_property);
                    }

                    //Update the state
                    state = ParseState::ENDING;
                    break;
                case FieldType::DATE:
                    new_property.value = "";
                    new_property.type = type;
                    entry.setProperty(key.toLower(), key, new_property);
                    //Update the state
                    state = ParseState::ENDING;
                    break;
                case FieldType::APPID:
                    if(bytes.size() < 4)
                        bytes.append(value);
                    if(bytes.size() >= 4)
                    {
                        new_property.value = QString::number(*reinterpret_cast<const uint32_t *>(bytes.constData()));
                        new_property.type = type;
                        entry.setProperty(key.toLower(), key, new_property);
                        bytes.clear();
                            //Update the state
                        state = ParseState::WAITING;
                    }
                    break;
                case FieldType::LIST:
                    if (listState == ListParseState::WAITING && value == 0x08 && endingBuffer.size() < 1) {
                        endingBuffer.emplace_back(value);
                    } else if (listState == ListParseState::WAITING && value == 0x08 && endingBuffer.size() >= 1) {
                        new_property.value = listValue.join(',');
                        new_property.type = type;
                        entry.setProperty(key.toLower(), key, new_property);
                        endingBuffer.clear();
                        //Update states
                        // Bit of a hack here but we know that tags is the only list and it's last off the block so we handle that here
                        listState = ListParseState::WAITING;
                        state = ParseState::ENTRYID;
                        //Add this entry and make a new one
                        shortcuts.append(entry);
                        entry = SteamShortcutEntry();
                    } else if (listState == ListParseState::WAITING && value != 0x08) {
                        listState = ListParseState::INDEX;
                    } else if (listState == ListParseState::INDEX && value == 0x00) {
                        listState = ListParseState::VALUE;
                        utf8String.str("");
                    } else if (listState == ListParseState::VALUE && value != 0x00) {
                        utf8String << static_cast<char>(value);
                    } else if (listState == ListParseState::VALUE) {
                        listValue.append(QString::fromStdString(utf8String.str()));
                        listState = ListParseState::WAITING;
                        utf8String.str("");
                    }
                    break;
            }
        }

    };

    namespace ENDING {
        void handleState(uint8_t& value, ParseState& state, FieldType& type, std::vector<char>& endingBuffer) {
            if ((type == FieldType::BOOLEAN || type == FieldType::DATE) && endingBuffer.size() < 2) {
                endingBuffer.emplace_back(value);
            } else if ((type == FieldType::BOOLEAN || type == FieldType::DATE) && endingBuffer.size() == 2) {
                endingBuffer.clear();
                //Update the state
                state = ParseState::WAITING;
            }
        }
    };
};
