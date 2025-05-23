#include <QCoreApplication>
#include <QString>
#include "iostream"
#include "file_conteiner.h"
#include <QDebug>
#include "file_watcher.h"
#include "consoleLog.h"
#include <QObject>
#include <thread>
#include <QDir>


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QString orig = app.applicationDirPath()+"/origin.txt";
    consoleLog logger;
    file_watcher manager(orig,&logger);
    int i=0;
    while(true)
    {
        manager.filesCheck();
        std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
        i++;
        if(i>100)
        {
            (manager.getLogger())->clear();
            i=0;
            std::this_thread::sleep_for( std::chrono::milliseconds( 3000) );
        }
    }
}
