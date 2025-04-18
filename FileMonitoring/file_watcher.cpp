#include "file_watcher.h"
#include <QString>
#include "file_conteiner.h"
#include <QObject>
#include "parentLogger.h"

file_watcher::file_watcher(QString& filePath,parentLogger* logger)
{
    m_filePath=filePath;
    m_files[0].setSourceFile(m_filePath);
    m_files[1].setSourceFile(m_filePath);
    m_log = logger;
    QObject::connect(this,&file_watcher::existenceCheckError, m_log,&parentLogger::existenceCheckErrorOutput);
    QObject::connect(this,&file_watcher::existenceCheckAppeard,m_log,&parentLogger::existenceCheckOutput);
    QObject::connect(this,&file_watcher::weightsCheckError,m_log,&parentLogger::weightsCheckOutput);
    QObject::connect(this,&file_watcher::modifiedDatesCheckError,m_log,&parentLogger::modifiedDatesCheckOutput);
}

void file_watcher::update(bool number)
{
    int i=0;
    if(number) i++;
    m_files[i].update();
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
    static bool originExist=true;
    QFile file(getFilePath());
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text) &&originExist)
    {
        emit existenceCheckError(getFilePath());
        originExist=false;
        return;
    }
    static bool first=true;
    int h=0;
    int j=0;
    if (integer) j++;
    for(int i=0;i<getCoteiner(h).getFiles().size();i++)
    {
        if(first)
            {
            if(!getCoteiner(0).getFiles()[i].exists())
                emit existenceCheckError(getCoteiner(0).getFiles()[i].absoluteFilePath());
            continue;
        }
        if(getCoteiner(0).getFiles()[i].exists() != getCoteiner(1).getFiles()[i].exists())
        {
            if(getCoteiner(j).getFiles()[i].exists())
            {
                emit existenceCheckAppeard(getCoteiner(j).getFiles()[i].absoluteFilePath());
                continue;
            }
            else
            {
                emit existenceCheckError(getCoteiner(j).getFiles()[i].absoluteFilePath());
                continue;
            }
        }
        if(getCoteiner(0).getFiles()[i].size()!=getCoteiner(1).getFiles()[i].size())
        {
            emit weightsCheckError(getCoteiner(0).getFiles()[i].absoluteFilePath());
            continue;
        }
        if(getCoteiner(0).getFiles()[i].lastModified()!=getCoteiner(1).getFiles()[i].lastModified())
        {
            emit modifiedDatesCheckError(getCoteiner(0).getFiles()[i].absoluteFilePath());
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


