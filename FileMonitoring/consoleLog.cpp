#include "consoleLog.h"
#include <QString>
 #include <QObject>
#include <QDebug>
#include "file_watcher.h"
consoleLog::consoleLog()
{

}

void consoleLog::existenceCheckOutput(QString filePath)
{
    qInfo() <<filePath<<" existance error";
}

void consoleLog::weightsCheckOutput(QString filePath)
{
    qInfo() <<filePath<<" weight was changed";
}

void consoleLog::modifiedDatesCheckOutput(QString filePath)
{
    qInfo() <<filePath<<" was modified without weights chages";
}
