#ifndef FILE_CONTEINER_H
#define FILE_CONTEINER_H
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QFileInfo>

struct fileInfo
{
    QFileInfo m_info;
    bool m_flag;
    QString m_path;

    fileInfo(QFileInfo& info, bool exist, QString path):m_info(info),m_flag(exist),m_path(path){}

    bool operator==(const fileInfo& other) const
    {
        return m_info == other.m_info && m_flag == other.m_flag && m_path==other.m_path;
    }

    fileInfo& operator=(const fileInfo& other)
    {
        m_info = other.m_info;
        m_flag = other.m_flag;
        m_path = other.m_path;
        return *this;
    }
};

class file_conteiner
{
private:
    QString m_sourceFile;
    QVector<fileInfo> m_files;
public:
    file_conteiner( );
    file_conteiner( QString& filePath);
    ~file_conteiner();
    void update();
    QString getSourceFile();
    fileInfo& getFile(int i);
    void addFile(QString& filePath);
    bool removeFile(QString& filePath);
    QVector<fileInfo>& getFiles();
    file_conteiner& operator=(const file_conteiner& other);
    bool operator==(const file_conteiner& other);
    bool operator!=(const file_conteiner& other);
};

#endif // FILE_CONTEINER_H


