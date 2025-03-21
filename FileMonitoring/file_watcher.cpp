#include "file_watcher.h"
#include <QString>
#include "file_conteiner.h"

 file_watcher::file_watcher(QString& filePath)
{
    m_filePath=filePath;
    m_files[0].setFile(m_filePath);
    m_files[1].setFile(m_filePath);
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

void file_watcher::existenceCheck()
{
    for(int i=0;i<getCoteiner(0).getExistenceFlags().size();i++)
    {
        if(getCoteiner(0).getExistenceFlags()[i]!=getCoteiner(1).getExistenceFlags()[i])
        {
           emit existenceCheckerror(getCoteiner(0).getFiles()[i]);
        }
    }
}

void file_watcher::weightsCheck()
{
    for(int i=0;i<getCoteiner(0).getWeights().size();i++)
    {
        if(getCoteiner(0).getWeights()[i]!=getCoteiner(1).getWeights()[i])
        {
            emit weightsCheckerror(getCoteiner(0).getFiles()[i]);
        }
    }
}

void file_watcher::modifiedDatesCheck()
{
    for(int i=0;i<getCoteiner(0).getLastModifiedDates().size();i++)
    {
        if(getCoteiner(0).getLastModifiedDates()[i]!=m_files[1].getLastModifiedDates()[i])
        {
            emit modifiedDatesCheckerror(getCoteiner(0).getFiles()[i]);
        }
    }
}

file_watcher::~file_watcher()
{
    m_filePath.clear();
    delete[] m_files;
}
