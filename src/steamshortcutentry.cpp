#include "../include/steamshortcutentry.h"

SteamShortcutEntry::SteamShortcutEntry() {
}

void SteamShortcutEntry::setProperty(QString key, QString value) {
    properties.insert(key, value);
}

QString SteamShortcutEntry::getEntryid() {
    return properties.value("entryid");
}

QString SteamShortcutEntry::getAppid() {
    return properties.value("appid");
}
QString SteamShortcutEntry::getAppName() {
    return properties.value("appname");
}
QString SteamShortcutEntry::getExe() {
    return properties.value("exe");
}
QString SteamShortcutEntry::getStartDir() {
    return properties.value("startdir");
}
QString SteamShortcutEntry::geticon() {
    return properties.value("icon");
}
QString SteamShortcutEntry::getShortcutPath() {
    return properties.value("shortcutpath");
}
QString SteamShortcutEntry::getLaunchOptions() {
    return properties.value("launchoptions");
}
QString SteamShortcutEntry::getIsHidden() {
    return properties.value("ishidden");
}
QString SteamShortcutEntry::getAllowDesktopConfig() {
    return properties.value("allowdesktopconfig");
}
QString SteamShortcutEntry::getAllowOverlay() {
    return properties.value("allowoverlay");
}
QString SteamShortcutEntry::getOpenVR() {
    return properties.value("openvr");
}
QString SteamShortcutEntry::getDevkit() {
    return properties.value("devkit");
}
QString SteamShortcutEntry::getDevkitGameID() {
    return properties.value("devkitgameid");
}
QString SteamShortcutEntry::getDevkitOverrideAppID() {
    return properties.value("devkitoverrideappid");
}
QString SteamShortcutEntry::getLastPlayTime() {
    return properties.value("lastplaytime");
}
QString SteamShortcutEntry::getFlatpakAppID() {
    return properties.value("flatpakappid");
}
QString SteamShortcutEntry::getTags() {
    return properties.value("tags");
}
