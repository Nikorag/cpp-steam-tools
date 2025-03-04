#ifndef VDFSTATEMACHINE_H
#define VDFSTATEMACHINE_H

#include <vector>
#include <string>
#include <cstdint>

#include "steamshortcutentry.h"

namespace VDFStateMachine {

    enum class ParseState {
        ENTRYID,
        WAITING,
        KEY,
        VALUE,
        ENDING
    };

    enum class ListParseState {
        WAITING,
        INDEX,
        VALUE,
        ENDING
    };

    namespace ENTRYID {
        void handleState(uint8_t& value, ParseState& state, FieldType& type);
    };

    namespace WAITING {
        void handleState(uint8_t& value, ParseState& state, FieldType& type, QStringList& listValue);
    };

    namespace KEY {
        void handleState(uint8_t& value, ParseState& state, FieldType& type, std::ostringstream& utf8String, QString& key);
    };

    namespace VALUE {
        std::string delimit(const std::vector<std::string>& vec, char delimiter);

        void handleState(uint8_t& value, ParseState& state, FieldType& type, std::ostringstream& utf8String,
            QString& key, SteamShortcutEntry& entry, ListParseState& listState, QStringList& listValue,
            QByteArray& bytes, std::vector<char>& endingBuffer, QVector<SteamShortcutEntry>& shortcuts);
    };

    namespace ENDING {
        void handleState(uint8_t& value, ParseState& state, FieldType& type, std::vector<char>& endingBuffer);
    };
};

#endif // VDFSTATEMACHINE_H
