#ifndef CONSOLELOG_H
#define CONSOLELOG_H
#include <QString>
#include <QObject>
class consoleLog: public QObject
{
    Q_OBJECT
public:
    consoleLog();
    public slots:
    void existenceCheckOutput(QString filePath);
    void weightsCheckOutput(QString filePath);
    void modifiedDatesCheckOutput(QString filePath);
};

#endif // ConsoleLog_H
