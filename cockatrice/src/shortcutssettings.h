#ifndef SHORTCUTSSETTINGS_H
#define SHORTCUTSSETTINGS_H

#include <QKeySequence>
#include <QMap>
#include <QObject>
#include <QSettings>

class ShortcutsSettings : public QObject
{
    Q_OBJECT
public:
    ShortcutsSettings(QString settingsFilePath, QObject *parent = nullptr);

    QList<QKeySequence> getShortcut(QString name);
    QKeySequence getSingleShortcut(QString name);

    QString getDefaultShortcutString(QString name);
    QString getShortcutString(QString name);

    void setShortcuts(QString name, QList<QKeySequence> Sequence);
    void setShortcuts(QString name, QKeySequence Sequence);
    void setShortcuts(QString name, QString Sequences);

    bool isValid(QString name, QString Sequences);

    void resetAllShortcuts();
    void clearAllShortcuts();

signals:
    void shortCutchanged();
    void allShortCutsReset();
    void allShortCutsClear();

private:
    QString settingsFilePath;
    QMap<QString, QList<QKeySequence>> shortCuts;
    QMap<QString, QList<QKeySequence>> defaultShortCuts;
    void fillDefaultShorcuts();

    QString stringifySequence(QList<QKeySequence> Sequence) const;
    QList<QKeySequence> parseSequenceString(QString stringSequence);
};

#endif // SHORTCUTSSETTINGS_H
