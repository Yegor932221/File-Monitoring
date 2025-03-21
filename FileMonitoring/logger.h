#ifndef LOGGER_H
#define LOGGER_H
#include <QString>
#include <QObject>

class logger
{
public:
    logger();
    public slots:
    void existenceCheckOutput(QString filePath);
    void weightsCheckOutput(QString filePath);
    void modifiedDatesCheckOutput(QString filePath);
};

#endif // LOGGER_H
