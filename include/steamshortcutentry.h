#ifndef STEAMSHORTCUTENTRY_H
#define STEAMSHORTCUTENTRY_H
#include <QMap>
#include <QObject>

enum class FieldType {
    STRING,
    BOOLEAN,
    LIST,
    DATE,
    APPID
};
typedef struct steam_shortcut_property_t {
    QString value;
    FieldType type;
} steam_shortcut_property;
class SteamShortcutEntry {

    private:
        QMap<QString, steam_shortcut_property> properties;
        QMap<QString, QString> keys;

    public:
        explicit SteamShortcutEntry();
        void setProperty(QString key, QString real_key, steam_shortcut_property property);
        QMap<QString, steam_shortcut_property> getProperties();
        QMap<QString, QString> getKeys();
        QString getAppid();
        QString getAppName();
        QString getExe();
        QString getStartDir();
        QString geticon();
        QString getShortcutPath();
        QString getLaunchOptions();
        QString getIsHidden();
        QString getAllowDesktopConfig();
        QString getAllowOverlay();
        QString getOpenVR();
        QString getDevkit();
        QString getDevkitGameID();
        QString getDevkitOverrideAppID();
        QString getLastPlayTime();
        QString getFlatpakAppID();
        QString getTags();

};

#endif //STEAMSHORTCUTENTRY_H
