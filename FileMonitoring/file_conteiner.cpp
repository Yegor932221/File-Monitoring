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
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QString line;
    QTextStream in(&file);
    while (!file.atEnd())
    {
        line = file.readLine();
        line.trimmed();
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
        m_files.clear();
        m_weights.clear();
        m_existenceFlags.clear();
        m_lastModifiedDates.clear();
}
