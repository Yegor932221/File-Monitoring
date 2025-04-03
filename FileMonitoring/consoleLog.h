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
    void iteretionOutput(QString filePath);
    void findOutput(QString filePath);
    void existenceCheckOutput(QString filePath);
    void existenceCheckErrorOutput(QString filePath);
    void weightsCheckOutput(QString filePath);
    void modifiedDatesCheckOutput(QString filePath);
    void changeInFileListOutput(QString filePath);
    void clear();
};

#endif // ConsoleLog_H
