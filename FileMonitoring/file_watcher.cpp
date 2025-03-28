#include "file_watcher.h"
#include <QString>
#include "file_conteiner.h"
#include <QObject>
#include "consoleLog.h"

file_watcher::file_watcher(QString& filePath)
{
    m_filePath=filePath;
    m_files[0].setFile(m_filePath);
    m_files[1].setFile(m_filePath);

    QObject::connect(this,&file_watcher::allFind,&m_log,&consoleLog::findOutput);
    QObject::connect(this,&file_watcher::existenceCheckError,&m_log,&consoleLog::existenceCheckErrorOutput);
    QObject::connect(this,&file_watcher::existenceCheckAppeard,&m_log,&consoleLog::existenceCheckOutput);
    QObject::connect(this,&file_watcher::weightsCheckError,&m_log,&consoleLog::weightsCheckOutput);
    QObject::connect(this,&file_watcher::modifiedDatesCheckError,&m_log,&consoleLog::modifiedDatesCheckOutput);
   QObject::connect(this,&file_watcher::iteretion,&m_log,&consoleLog::iteretionOutput);

}

void file_watcher::update(bool number)
{
    int i=0;
    if(number) i++;
    m_files[i].setFile(m_filePath);
}

file_conteiner file_watcher::getCoteiner(int index)
{
    if (index>1)
    {
        index= index%2;
    }
    return m_files[index];
}

QString file_watcher::getFilePath()
{
    return m_filePath;
}

void file_watcher::filesCheck(bool integer)
{
    emit iteretion(getFilePath());
    int j=0;
    if (integer) j++;
    for(int i=0;i<getCoteiner(0).getExistenceFlags().size();i++)
    {
        if(getCoteiner(0).getExistenceFlags()[i]!=getCoteiner(1).getExistenceFlags()[i])
        {
            if(getCoteiner(j).getExistenceFlags()[i])
            {
                emit existenceCheckAppeard(getCoteiner(0).getFiles()[i]);
                continue;
            }
            else
            {
                emit existenceCheckError(getCoteiner(0).getFiles()[i]);
                continue;
            }
        }
        if(getCoteiner(0).getWeights()[i]!=getCoteiner(1).getWeights()[i])
        {
            emit weightsCheckError(getCoteiner(0).getFiles()[i]);
            continue;
        }
        if(getCoteiner(0).getLastModifiedDates()[i]!=m_files[1].getLastModifiedDates()[i])
        {
            emit modifiedDatesCheckError(getCoteiner(0).getFiles()[i]);
            continue;
        }
        emit allFind(getCoteiner(0).getFiles()[i]);
    }
}

file_watcher::~file_watcher()
{
    m_filePath.clear();
    delete[] m_files;
}


