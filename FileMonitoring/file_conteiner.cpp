#include "file_conteiner.h"
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QVector>
#include <QString>
#include <QTextStream>


file_conteiner::file_conteiner( QString& filePath)
{
    m_sourceFile=filePath;
    QFile file(m_sourceFile);
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        return;
    }

    while (!file.atEnd())
    {
        QFileInfo infofile(file.readLine().trimmed());
        fileInfo entry(infofile, infofile.exists(), infofile.baseName());
        if(m_files.contains(entry))
        {
            continue;
        }
        m_files.append(entry);
    }
    file.close();
}


file_conteiner::file_conteiner( )
{
    m_sourceFile.append(NULL);
}

fileInfo& file_conteiner::getFile(int i)  {
        return m_files[i];
}


file_conteiner::~file_conteiner() {
    m_sourceFile.clear();
    m_files.clear();
}

void file_conteiner::update()
{
    for(auto& entry : m_files)
    {
        entry.m_info.refresh();
        entry.m_flag = entry.m_info.exists();
    }
}

void file_conteiner::addFile(QString& filePath)
{
    QFileInfo file(filePath);
    bool exist=file.exists();
    fileInfo fileinfo(file, exist, filePath);
    m_files.push_back(fileinfo);
}

bool file_conteiner::removeFile(QString& filePath)
{
    QFileInfo file(filePath);
    bool exist=file.exists();
    fileInfo fileinfo(file, exist, filePath);
    return m_files.removeAll(fileinfo);
}

QVector<fileInfo>& file_conteiner::getFiles()  {
    return m_files;
}

file_conteiner& file_conteiner::operator=(const file_conteiner& other)
{
    if (this != &other)
    {
        m_sourceFile = other.m_sourceFile;
        m_files = other.m_files;
    }
    return *this;
}

bool file_conteiner::operator==(const file_conteiner& other)
{
    return (m_sourceFile == other.m_sourceFile) &&
           (m_files == other.m_files);
}

bool file_conteiner::operator!=(const file_conteiner& other)
{
    return !(*this == other);
}
