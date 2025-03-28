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
    while (!file.atEnd())
    {
        line = file.readLine().trimmed();
        if(!m_files.contains(line))
        {
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
    }
    file.close();
}


file_conteiner::file_conteiner( )
{
    m_sourceFile.append(NULL);

}

const QVector<QString>& file_conteiner::getFiles()  {
        return m_files;
}


const QString file_conteiner::getSourceFile()  {
        return m_sourceFile;
}

const QVector<int>& file_conteiner::getWeights()  {
        return m_weights;
}


const QVector<bool>& file_conteiner::getExistenceFlags()  {
        return m_existenceFlags;
}


const QVector<QDateTime>& file_conteiner::getLastModifiedDates()  {
        return m_lastModifiedDates;
}


file_conteiner::~file_conteiner() {
    m_sourceFile.clear();
    m_files.clear();
    m_weights.clear();
    m_existenceFlags.clear();
    m_lastModifiedDates.clear();
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
        if(!m_files.contains(line))
        {
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
    }
    file.close();
    return *this;
}

