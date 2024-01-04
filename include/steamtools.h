#ifndef STEAMTOOLS_H
#define STEAMTOOLS_H

#include "cpp-steam-tools_global.h"
#include "steamshortcutentry.h"

#include <QObject>
#include <QPixmap>

class CPPSTEAMTOOLS_EXPORT SteamTools : public QObject
{
    Q_OBJECT

public:
    SteamTools(const std::function<void(const QString&)>& infoFunction, const std::function<void(const QString&)>& errorFunction);

    bool steamExists();
    QVector<SteamShortcutEntry> parseShortcuts();
    SteamShortcutEntry buildShortcutEntry(QString appName, QString filepath, QMap<QString, const QPixmap*> artwork);
    void updateShortcuts(QVector<SteamShortcutEntry> shortcuts);
    void updateControllerConfig(QString appname, QString controllerConfigID);

private:
    QString steamBaseDir;
    QString mostRecentUser;
    QString shortcutFile;

    std::function<void(const QString&)> infoFunction;
    std::function<void(const QString&)> errorFunction;
    QString getSteamBaseDir();
    QString getMostRecentUser();
    QString getShortcutFile();
    QString generateShortAppId(QString exe, QString appname);
    uint32_t generateShortcutId(QString exe, QString appname);
    void saveArtwork(QString shortAppId, QMap<QString, const QPixmap*> artwork, QMap<QString, QString> artworkLocations);
};

#endif // STEAMTOOLS_H
