#include "filewatcher.h"
#include <QFile>
#include <QMainWindow>
#include <QDateTime>

FileWatcher::FileWatcher(QWidget *parent)
    : QMainWindow(parent)
{
}

FileWatcher::~FileWatcher()
{
}

void FileWatcher::setFileName(std::string filename)
{
    FileWatcher.m_fileName=filename;
}

FileWatcher::FileWatcher(std::string filename)
{
    setFileName(filename);
    FileWatcher.m_weight=
}
