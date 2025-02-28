#include "file_conteiner.h"
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QVector>
#include <QString>
#include <QTextStream>

file_conteiner::file_conteiner()
{

}

file_conteiner::file_conteiner(QString &files)
{
    QFile conteiner(files);
    if (!conteiner.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    m_conteiner=conteiner;
    int k=0;
    QTextStream in(&conteiner);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QFile insert_file(line);
        m_files.insert(k,insert_file);
        m_weight.insert(k,m_files[k].size());
        k++;
    }
}
