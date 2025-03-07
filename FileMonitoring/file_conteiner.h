#ifndef FILE_CONTEINER_H
#define FILE_CONTEINER_H
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QVector>
#include <QString>
#include <QTextStream>

class file_conteiner
{
private:
    QString m_sourceFile;
    QVector<QString> m_files;
    QVector<int> m_weights;
    QVector<bool> m_existenceFlags;
    QVector<QDateTime> m_lastModifiedDates;
public:
    file_conteiner( QString& filePath);
    ~file_conteiner();
    void loadFiles();

    const QVector<QString>& getFiles() const;
    const QVector<int>& getWeights() const;
    const QVector<bool>& getExistenceFlags() const;
    const QVector<QDateTime>& getLastModifiedDates() const;



};

#endif // FILE_CONTEINER_H
