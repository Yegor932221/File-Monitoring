#include "logger.h"
#include <QString>
 #include <QObject>
#include <QDebug>

logger::logger()
{

}

void logger::existenceCheckOutput(QString filePath)
{
    qInfo() <<filePath<<" existance error";
}

void logger::weightsCheckOutput(QString filePath)
{
    qInfo() <<filePath<<" weight was changed";
}

void logger::modifiedDatesCheckOutput(QString filePath)
{
    qInfo() <<filePath<<" was modified without weights chages";
}
