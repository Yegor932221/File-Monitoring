#include "consoleLog.h"
#include <QProcess>
#include <QString>
 #include <QObject>
#include <QDebug>
#include "file_watcher.h"
#include <cstdlib>
#include<QTime>
consoleLog::consoleLog()
{

}

void consoleLog::existenceCheckErrorOutput(QString filePath)
{
    qInfo() <<filePath<<" existance error\n";
}

 void consoleLog::iteretionOutput(QString filePath)
{
    qInfo() <<" Results of observation: "<<filePath<<" in "<<QTime::currentTime()<<"\n";
}

void consoleLog::findOutput(QString filePath)
{
    qInfo() <<filePath<<" don't changed\n";
}

void consoleLog::existenceCheckOutput(QString filePath)
{
    qInfo() <<filePath<<" appeared\n";
}

void consoleLog::weightsCheckOutput(QString filePath)
{
    qInfo() <<filePath<<" weight was changed\n";
}

void consoleLog::modifiedDatesCheckOutput(QString filePath)
{
    qInfo() <<filePath<<" was modified without weights chages\n";
}

void consoleLog::clear()
{
    system("cls");
}
