#ifndef CONSOLELOG_H
#define CONSOLELOG_H
#include <QString>
#include <QObject>
#include "parentLogger.h"
class consoleLog: public parentLogger
{
Q_OBJECT
public:
    explicit consoleLog(QObject *parent = nullptr) : parentLogger(parent) {}
    ~consoleLog()=default;
public slots:
    void existenceCheckOutput(QString filePath) override ;
    void existenceCheckErrorOutput(QString filePath) override ;
    void weightsCheckOutput(QString filePath) override ;
    void modifiedDatesCheckOutput(QString filePath) override ;
    void clear();
};

#endif // ConsoleLog_H
