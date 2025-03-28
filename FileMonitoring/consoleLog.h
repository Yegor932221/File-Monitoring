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
    void iteretionOutput(QString filePath);
    void findOutput(QString filePath);
    void existenceCheckOutput(QString filePath);
    void existenceCheckErrorOutput(QString filePath);
    void weightsCheckOutput(QString filePath);
    void modifiedDatesCheckOutput(QString filePath);
    void clear();
};

#endif // ConsoleLog_H
