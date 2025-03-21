#include <QCoreApplication>
#include <QString>
#include "iostream"
#include "file_conteiner.h"
#include <QDebug>
#include "file_watcher.h"
#include "consoleLog.h"
#include <QObject>

int main()
{
    QString orig("C:/Users/Yegor/File-Monitoring/Files/origin.txt");
    QString &file =  orig;
    file_conteiner cont(file);
    file_watcher manager(orig);
    consoleLog log;

    qInfo() <<"m_files:"<<manager.getCoteiner(1).getFiles().size();

    manager.update(true);

}
