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
    m_sourceFile.append(filePath);
    QFile file(m_sourceFile);
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        return;
    }
    QFileInfo infofile;
    while (!file.atEnd())
    {
        infofile.setFile(file.readLine().trimmed());
        if(!m_files.contains(infofile))
        {
            m_files.append(infofile);
        }
    }
    file.close();
}


file_conteiner::file_conteiner( )
{
    m_sourceFile.append(NULL);
}

 QVector<QFileInfo>& file_conteiner::getFiles()  {
        return m_files;
}


file_conteiner::~file_conteiner() {
    m_sourceFile.clear();
    m_files.clear();
}

void file_conteiner::setSourceFile(QString& filePath)
{
    m_sourceFile=filePath;
    m_files.clear();
    QFile file(m_sourceFile);
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        return;
    }
    QFileInfo infofile;
    while (!file.atEnd())
    {
        infofile.setFile(file.readLine().trimmed());
        if(!m_files.contains(infofile))
        {
            m_files.append(infofile);
        }
    }
    file.close();
}

void file_conteiner::update()
{
    for(int i=0;i<getFiles().size();i++)
    {
        getFiles()[i].refresh();
    }
}

void file_conteiner::addFile(QString& filePath)
{
    QFileInfo file;
    file.setFile(filePath);
    m_files.push_back(file);
}

bool file_conteiner::removeFile(QString& filePath)
{
    QFileInfo file;
    file.setFile(filePath);
    return m_files.removeAll(file);
}
