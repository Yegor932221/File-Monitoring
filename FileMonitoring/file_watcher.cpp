#include "file_watcher.h"
#include <QString>
#include "file_conteiner.h"
#include <QObject>
#include "parentLogger.h"

file_watcher::file_watcher(QString& filePath,parentLogger* logger)
{
    m_filePath=filePath;
    m_files[0].setFile(m_filePath);
    m_files[1].setFile(m_filePath);
    m_log = logger;
    QObject::connect(this,&file_watcher::existenceCheckError, m_log,&parentLogger::existenceCheckErrorOutput);
    QObject::connect(this,&file_watcher::existenceCheckAppeard,m_log,&parentLogger::existenceCheckOutput);
    QObject::connect(this,&file_watcher::weightsCheckError,m_log,&parentLogger::weightsCheckOutput);
    QObject::connect(this,&file_watcher::modifiedDatesCheckError,m_log,&parentLogger::modifiedDatesCheckOutput);
    QObject::connect(this,&file_watcher::changeInFileList,m_log,&parentLogger::changeInFileListOutput);
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

parentLogger* file_watcher::getLogger()
{
    return m_log;
}

void file_watcher::filesCheck(bool integer)
{
    QFile file(getFilePath());
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        emit existenceCheckError(getFilePath());
        return;
    }
    static bool first=true;
    int h=0;
    int j=0;
    if (integer) j++;
    if(getCoteiner(0).getExistenceFlags().size()!=getCoteiner(1).getExistenceFlags().size())
    {
        if(getCoteiner(0).getExistenceFlags().size()>getCoteiner(1).getExistenceFlags().size())
        {
            h+=1;
            emit changeInFileList(getFilePath());
        }
    }
    for(int i=0;i<getCoteiner(h).getExistenceFlags().size();i++)
    {
        if(first)
            {
            if(!getCoteiner(0).getExistenceFlags()[i])
                emit existenceCheckError(getCoteiner(0).getFiles()[i]);
            continue;
        }
        if(getCoteiner(0).getExistenceFlags()[i] != getCoteiner(1).getExistenceFlags()[i])
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
    }
    first=false;
}

void file_watcher::setLogger(parentLogger* logger)
{
    m_log=logger;
}

file_watcher::~file_watcher()
{
    m_filePath.clear();
    delete[] m_files;
}


