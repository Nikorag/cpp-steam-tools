#include "../include/steamshortcutentry.h"

SteamShortcutEntry::SteamShortcutEntry() {
}

void SteamShortcutEntry::setProperty(QString key, QString value) {
    properties.insert(key, value);
}

QString SteamShortcutEntry::getAppid() {
    return properties.value("appid");
}
QString SteamShortcutEntry::getAppName() {
    if(properties.contains("AppName"))
        return properties.value("AppName");
    else
        return properties.value("appname");
}
QString SteamShortcutEntry::getExe() {
    if(properties.contains("Exe"))
        return properties.value("Exe");
    else
        return properties.value("exe");
}
QString SteamShortcutEntry::getStartDir() {
    return properties.value("StartDir");
}
QString SteamShortcutEntry::geticon() {
    return properties.value("icon");
}
QString SteamShortcutEntry::getShortcutPath() {
    return properties.value("ShortcutPath");
}
QString SteamShortcutEntry::getLaunchOptions() {
    return properties.value("LaunchOptions");
}
QString SteamShortcutEntry::getIsHidden() {
    return properties.value("IsHidden");
}
QString SteamShortcutEntry::getAllowDesktopConfig() {
    return properties.value("AllowDesktopConfig");
}
QString SteamShortcutEntry::getAllowOverlay() {
    return properties.value("AllowOverlay");
}
QString SteamShortcutEntry::getOpenVR() {
    return properties.value("OpenVR");
}
QString SteamShortcutEntry::getDevkit() {
    return properties.value("Devkit");
}
QString SteamShortcutEntry::getDevkitGameID() {
    return properties.value("DevkitGameID");
}
QString SteamShortcutEntry::getDevkitOverrideAppID() {
    return properties.value("DevkitOverrideAppID");
}
QString SteamShortcutEntry::getLastPlayTime() {
    return properties.value("LastPlayTime");
}
QString SteamShortcutEntry::getFlatpakAppID() {
    return properties.value("FlatpakAppID");
}
QString SteamShortcutEntry::getTags() {
    return properties.value("tags");
}
