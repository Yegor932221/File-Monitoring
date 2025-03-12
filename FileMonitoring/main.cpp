#include <QCoreApplication>
#include <QString>
#include "iostream"
#include "file_conteiner.h"
#include <QDebug>
#include "file_watcher.h"

int main()
{
    QString orig("C:/Users/Yegor/File-Monitoring/Files/origin.txt");
    QString &file =  orig;
    file_watcher manager(orig);

    if(manager.existenceCheck())
    qDebug() <<"Exist const";
    if(manager.weightsCheck())
    qDebug() <<"Weights const";
    if(manager.modifiedDatesCheck())
    qDebug() <<"Modifi date const";
    manager.update(true);

}
