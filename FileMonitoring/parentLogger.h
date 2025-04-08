#ifndef PARENTLOGGER_H
#define PARENTLOGGER_H
#include <QString>
#include <QObject>
class parentLogger: public QObject
{
    Q_OBJECT
public:
    explicit parentLogger(QObject *parent = nullptr) : QObject(parent) {}
    ~parentLogger()=default;
    public slots:
    virtual void iteretionOutput(QString filePath)=0;
    virtual void existenceCheckOutput(QString filePath)=0;
    virtual void existenceCheckErrorOutput(QString filePath)=0;
    virtual void weightsCheckOutput(QString filePath)=0;
    virtual void modifiedDatesCheckOutput(QString filePath)=0;
    virtual void changeInFileListOutput(QString filePath)=0;
    virtual void clear()=0;
};

#endif // ConsoleLog_H
