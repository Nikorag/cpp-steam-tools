#include "../include/steamshortcutentry.h"

SteamShortcutEntry::SteamShortcutEntry() {
}

void SteamShortcutEntry::setProperty(QString key, QString real_key, steam_shortcut_property property) {
    properties.insert(key, property);
    keys.insert(key, real_key);
}

QMap<QString, steam_shortcut_property> SteamShortcutEntry::getProperties(){
    return properties;
}

QMap<QString, QString> SteamShortcutEntry::getKeys(){
    return keys;
}

QString SteamShortcutEntry::getAppid() {
    return properties.value("appid").value;
}
QString SteamShortcutEntry::getAppName() {
    return properties.value("appname").value;
}
QString SteamShortcutEntry::getExe() {
    return properties.value("exe").value;
}
QString SteamShortcutEntry::getStartDir() {
    return properties.value("startdir").value;
}
QString SteamShortcutEntry::geticon() {
    return properties.value("icon").value;
}
QString SteamShortcutEntry::getShortcutPath() {
    return properties.value("shortcutpath").value;
}
QString SteamShortcutEntry::getLaunchOptions() {
    return properties.value("launchoptions").value;
}
QString SteamShortcutEntry::getIsHidden() {
    return properties.value("ishidden").value;
}
QString SteamShortcutEntry::getAllowDesktopConfig() {
    return properties.value("allowdesktopconfig").value;
}
QString SteamShortcutEntry::getAllowOverlay() {
    return properties.value("allowoverlay").value;
}
QString SteamShortcutEntry::getOpenVR() {
    return properties.value("openvr").value;
}
QString SteamShortcutEntry::getDevkit() {
    return properties.value("devkit").value;
}
QString SteamShortcutEntry::getDevkitGameID() {
    return properties.value("devkitgameid").value;
}
QString SteamShortcutEntry::getDevkitOverrideAppID() {
    return properties.value("devkitoverrideappid").value;
}
QString SteamShortcutEntry::getLastPlayTime() {
    return properties.value("lastplaytime").value;
}
QString SteamShortcutEntry::getFlatpakAppID() {
    return properties.value("flatpakappid").value;
}
QString SteamShortcutEntry::getTags() {
    return properties.value("tags").value;
}
