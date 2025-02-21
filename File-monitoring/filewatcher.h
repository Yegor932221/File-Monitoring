#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QMainWindow>

class FileWatcher : public QMainWindow
{
    Q_OBJECT

public:
    FileWatcher(QWidget *parent = nullptr);
    ~FileWatcher();
};
#endif // FILEWATCHER_H
