#include "checkwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QProcess>

checkwindow::checkwindow(QWidget *parent)
    : QWidget(parent)
{

}

void checkwindow::OpenApp(const QString& appLocation)
{
    #ifdef Q_OS_WIN

    QProcess *process = new QProcess;
    process->startDetached(appLocation);
    process->close();
    delete process;
    #endif
}

void checkwindow::CheckAndOpen(const QString& _appName, const QString& _appLocation){
    if(_appName == "obs64.exe"){
        QString exePath = "../ahk/runobs.exe";
        QString arg1 = _appLocation;
        QProcess *process = new QProcess();
        process->start(exePath, QStringList() << arg1);
    }else{
        QProcess *process = new QProcess();
        process->start("tasklist" ,QStringList()<<"/FI"<<"imagename eq " + _appName);   //执行tasklist程序
        process->waitForFinished();
        QString outputStr = QString::fromLocal8Bit(process->readAllStandardOutput()); //把tasklist程序读取到的进程信息输出到字符串中
        if(outputStr.contains(_appName))
        {
            QMessageBox::warning(nullptr, "警告", "程序已经启动!");
        }
        else
        {
            OpenApp(_appLocation+ "/" +_appName);
        }
        process->close();
        delete process;
    }
}


