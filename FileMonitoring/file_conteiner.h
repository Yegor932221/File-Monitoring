#ifndef FILE_CONTEINER_H
#define FILE_CONTEINER_H
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QFileInfo>

class file_conteiner
{
private:
    QString m_sourceFile;
    QVector<QFileInfo> m_files;
public:
    file_conteiner( );
    file_conteiner( QString& filePath);
    ~file_conteiner();
    void update();
    void setSourceFile(QString& filePath);
    QString getSourceFile();
    QVector<QFileInfo>& getFiles();
    void addFile(QString& filePath);
    bool removeFile(QString& filePath);
};

#endif // FILE_CONTEINER_H


