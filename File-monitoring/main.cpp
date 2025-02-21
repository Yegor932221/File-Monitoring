#include "filewatcher.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileWatcher w;
    w.show();
    return a.exec();
}
