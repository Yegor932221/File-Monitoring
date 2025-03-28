#ifndef FILE_WATCHER_H
#define FILE_WATCHER_H
#include "file_conteiner.h"
#include "ConsoleLog.h"
#include <QVector>
#include <QString>
#include <QObject>



class file_watcher: public QObject
{
    Q_OBJECT
private:
    file_conteiner m_files[2];
    QString m_filePath;
public:
    consoleLog m_log;
public:
    file_watcher(QString& filePath);
    ~file_watcher();
    file_conteiner getCoteiner(int index);
    void update(bool number);
    void filesCheck(bool integer);
    QString getFilePath();
signals:
    void iteretion(QString filePath);
    void allFind(QString filePath);
    void existenceCheckError(QString filePath);
    void existenceCheckAppeard(QString filePath);
    void weightsCheckError(QString filePath);
    void modifiedDatesCheckError(QString filePath);
};

#endif // FILE_WATCHER_H
