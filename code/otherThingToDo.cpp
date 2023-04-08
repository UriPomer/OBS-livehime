#include "otherThingToDo.h"
#include <QString>
#include <QProcess>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>


void OtherToDos::winActivate(){
    QString exePath = "../ahk/ActivateLivehime.exe";
    QProcess *process = new QProcess();
    process->start(exePath);
}

void OtherToDos::winClickButtonAutomatically(){
    QString exePath = "../ahk/livehime.exe";
    QProcess *process = new QProcess();
    process->start(exePath);
}

void OtherToDos::MyThread::run(){
    QFile file("../setting.json");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }
        QByteArray jsonData = file.readAll();
        file.close();

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(jsonData, &jsonError); //转化为JSON文档
    startDelayTime = document.object().value("startDelayTime").toInt();
    QThread::sleep(startDelayTime);
    winActivate();
    winClickButtonAutomatically();
    QThread::sleep(30);
    a->quit();
}





