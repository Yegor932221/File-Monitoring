#ifndef FILE_WATCHER_H
#define FILE_WATCHER_H
#include "file_conteiner.h"
#include <QVector>
#include <QString>

class file_watcher
{
private:
    file_conteiner m_files[2];
    QString m_filePath;
public:
    file_watcher(QString& filePath);
    file_conteiner getCoteiner(int index);
    void update(bool number);
    bool existenceCheck();
    bool weightsCheck();
    bool modifiedDatesCheck();
};

#endif // FILE_WATCHER_H
