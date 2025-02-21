#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QFile>
#include <QMainWindow>
#include <QDateTime>


class FileWatcher : public QMainWindow
{
    Q_OBJECT

private:
    std::string m_fileName = nullptr;
    int m_weight=0;
    bool m_isOpend=false;
    QDateTime m_date_of_modification=nullptr;
public:
    FileWatcher(QWidget *parent = nullptr);
    ~FileWatcher();
    FileWatcher(std::string filename);
    void setFileName(std::string filename);
};
#endif // FILEWATCHER_H
