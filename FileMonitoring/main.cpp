#include <QCoreApplication>
#include <QString>
#include "iostream"
#include "file_conteiner.h"
#include <QDebug>

int main()
{
    QString file="C:/Users/Yegor/File-Monitoring/Files/origin.txt";
    QString &files=file;
    file_conteiner mon(files);
    qDebug()<<mon.getFiles()[0];
}
