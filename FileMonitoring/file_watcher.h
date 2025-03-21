#ifndef FILE_WATCHER_H
#define FILE_WATCHER_H
#include "file_conteiner.h"
#include <QVector>
#include <QString>
#include <QObject>
#include "logger.h"

class file_watcher
{
private:
    file_conteiner m_files[2];
    QString m_filePath;
public:
    file_watcher(QString& filePath);
    ~file_watcher();
    file_conteiner getCoteiner(int index);
    void update(bool number);
    void existenceCheck();
    void weightsCheck();
    void modifiedDatesCheck();
signals:
    void existenceCheckerror(QString filePath);
    void weightsCheckerror(QString filePath);
    void  modifiedDatesCheckerror(QString filePath);
};

#endif // FILE_WATCHER_H
