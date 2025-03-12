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
    QString line;
    QTextStream in(&file);
    while (!file.atEnd())
    {
        line = file.readLine().trimmed();
        m_files.append(line);
        QFileInfo fileInfo(line);
        bool exists = fileInfo.exists();
        m_existenceFlags.append(exists);
        if(exists)
        {
            m_weights.append(fileInfo.size());
            m_lastModifiedDates.append(fileInfo.lastModified());
        }
        else
        {
            m_weights.append(0);
            m_lastModifiedDates.append(QDateTime());
        }
    }
    file.close();
}


file_conteiner::file_conteiner( )
{
    m_sourceFile.append(NULL);

}

const QVector<QString>& file_conteiner::getFiles() const {
        return m_files;
}


const QVector<int>& file_conteiner::getWeights() const {
        return m_weights;
}


const QVector<bool>& file_conteiner::getExistenceFlags() const {
        return m_existenceFlags;
}


const QVector<QDateTime>& file_conteiner::getLastModifiedDates() const {
        return m_lastModifiedDates;
}


file_conteiner::~file_conteiner() {
    m_sourceFile.clear();
    m_files.clear();
    m_weights.clear();
    m_existenceFlags.clear();
    m_lastModifiedDates.clear();
}

bool file_conteiner::operator ==(file_conteiner sec)
{
    if(m_sourceFile!= sec.m_sourceFile)
        return false;
    if(m_files.size()!= sec.m_files.size())
        return false;
    for(int i=0;i<m_files.size();i++)
    {
        if(m_files[i]!= sec.m_files[i])
            return false;
    }
    for(int i=0;i<m_existenceFlags.size();i++)
    {
        if(m_existenceFlags[i]!= sec.m_existenceFlags[i])
            return false;
    }
    for(int i=0;i<m_weights.size();i++)
    {
        if(m_weights[i]!= sec.m_weights[i])
            return false;
    }
    for(int i=0;i<m_lastModifiedDates.size();i++)
    {
        if(m_lastModifiedDates[i]!= sec.m_lastModifiedDates[i])
            return false;
    }
}

file_conteiner& file_conteiner::setFile(QString& filePath)
{
    m_sourceFile.clear();
    m_files.clear();
    m_weights.clear();
    m_existenceFlags.clear();
    m_lastModifiedDates.clear();
    m_sourceFile.append(filePath);
    QFile file(m_sourceFile);
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        return *this;
    }
    QString line;
    QTextStream in(&file);
    while (!file.atEnd())
    {
        line = file.readLine().trimmed();
        m_files.append(line);
        QFileInfo fileInfo(line);
        bool exists = fileInfo.exists();
        m_existenceFlags.append(exists);
        if(exists)
        {
            m_weights.append(fileInfo.size());
            m_lastModifiedDates.append(fileInfo.lastModified());
        }
        else
        {
            m_weights.append(0);
            m_lastModifiedDates.append(QDateTime());
        }
    }
    file.close();
    return *this;
}
