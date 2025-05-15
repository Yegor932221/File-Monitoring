#include "file_watcher.h"
#include <QString>
#include "file_conteiner.h"
#include <QObject>
#include "parentLogger.h"

#include <QDebug>

file_watcher::file_watcher(QString& filePath,parentLogger* logger)
{
    m_filePath=filePath;
    m_files[0]=file_conteiner(m_filePath);
    m_files[1]=file_conteiner(m_filePath);
    m_log = logger;
    QObject::connect(this,&file_watcher::existenceCheckError, m_log,&parentLogger::existenceCheckErrorOutput);
    QObject::connect(this,&file_watcher::existenceCheckAppeard,m_log,&parentLogger::existenceCheckOutput);
    QObject::connect(this,&file_watcher::weightsCheckError,m_log,&parentLogger::weightsCheckOutput);
    QObject::connect(this,&file_watcher::modifiedDatesCheckError,m_log,&parentLogger::modifiedDatesCheckOutput);
}

void file_watcher::update()
{
    m_files[0]=m_files[1];
    m_files[1].update();
}

file_conteiner file_watcher::getCoteiner(int index)
{
    if (index>1)
    {
        index= index%2;
    }
    return m_files[index];
}

parentLogger* file_watcher::getLogger()
{
    return m_log;
}

void file_watcher::filesCheck()
{
    static bool first=true;
    for(int i=0;i<getCoteiner(0).getFiles().size();i++)
    {
        if(first)
            {
            if(!getCoteiner(0).getFile(i).m_flag)
            {
            emit existenceCheckError(getCoteiner(0).getFile(i).m_info.absoluteFilePath());
            continue;
            }
        }
        if(getCoteiner(0).getFile(i).m_flag != getCoteiner(1).getFile(i).m_flag)
        {
            if(!getCoteiner(1).getFile(i).m_flag)
            {
                emit existenceCheckError(getCoteiner(1).getFile(i).m_info.absoluteFilePath());
                continue;
            }
            else
            {
                emit existenceCheckAppeard(getCoteiner(1).getFile(i).m_info.absoluteFilePath());
                continue;
            }
        }
        if(getCoteiner(0).getFile(i).m_info.size()!=getCoteiner(1).getFile(i).m_info.size())
        {
            emit weightsCheckError(getCoteiner(0).getFile(i).m_info.absoluteFilePath());
            continue;
        }
        if(getCoteiner(0).getFile(i).m_info.lastModified()!=getCoteiner(1).getFile(i).m_info.lastModified())
        {
            emit modifiedDatesCheckError(getCoteiner(0).getFile(i).m_info.absoluteFilePath());
            continue;
        }
    }
    first=false;
    update();
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

bool file_watcher::removeFile(QString& filePath)
{
    return(m_files[0].removeFile(filePath)&& m_files[1].removeFile(filePath));
}

void file_watcher::addFile(QString& filePath)
{
    m_files[0].addFile(filePath);
    m_files[1].addFile(filePath);
}

