#ifndef FILE_WATCHER_H
#define FILE_WATCHER_H
#include "file_conteiner.h"
#include "parentLogger.h"
#include <QVector>
#include <QString>
#include <QObject>



class file_watcher: public QObject
{
    Q_OBJECT
private:
    file_conteiner m_files[2];
    QString m_filePath;
    parentLogger* m_log;
public:
    file_watcher(QString& filePath,parentLogger* logger);
    ~file_watcher();
    file_conteiner getCoteiner(int index);
    void update();
    void filesCheck();
    parentLogger* getLogger();
    void setLogger(parentLogger* logger);
    bool removeFile(QString& filePath);
    void addFile(QString& filePath);
signals:
    void existenceCheckError(QString filePath);
    void existenceCheckAppeard(QString filePath);
    void weightsCheckError(QString filePath);
    void modifiedDatesCheckError(QString filePath);
};

#endif // FILE_WATCHER_H
