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
    consoleLog m_log;
public:
    file_watcher(QString& filePath);
    ~file_watcher();
    file_conteiner getCoteiner(int index);
    void update(bool number);
    void filesCheck();
signals:
    void existenceCheckerror(QString filePath);
    void weightsCheckerror(QString filePath);
    void  modifiedDatesCheckerror(QString filePath);
};

#endif // FILE_WATCHER_H
