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
    QFile m_conteiner;
    QVector <QFile> m_files;
    QVector<int> m_weight;
    QVector<QDateTime> m_date_of_modification;
public:
    file_conteiner();
    file_conteiner(QString &files);
};

#endif // FILE_CONTEINER_H
