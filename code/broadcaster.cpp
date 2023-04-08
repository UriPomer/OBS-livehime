#include "broadcaster.h"
#include "ui_broadcaster.h"
#include "appToOpen.h"
#include "otherThingToDo.h"
#include <QThread>
#include <jsonDecoder.h>

broadcaster::broadcaster(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::broadcaster)
{
    ui->setupUi(this);
    check = new checkwindow();
    apps = new appToOpen();
    connect(ui->openButton, &QPushButton::clicked, [=](){
        QThread* thread1 = new QThread();
        QObject::connect(thread1, &QThread::started, [=](){
            check->CheckAndOpen(apps->appNames[0], apps->appLocations[0]);
        });
        thread1->start();
    });
    connect(ui->openButton, &QPushButton::clicked, [=](){

        QThread* thread2 = new QThread();
        int obsDelayTime = 10;
        QString jsonLocation = "../setting.json";
        QString jsonParam = "obsDelayTime";
        json::jsonDecode(jsonLocation, obsDelayTime, jsonParam);
        QObject::connect(thread2, &QThread::started, [=](){
            QThread::sleep(obsDelayTime);
            check->CheckAndOpen(apps->appNames[1], apps->appLocations[1]);
        });
        thread2->start();
    });
    connect(ui->openButton, &QPushButton::clicked, [=](){
        this->hide();
        OtherToDos::MyThread Thread;
        Thread.run();
        Thread.wait();
    });
}


broadcaster::~broadcaster()
{
    delete ui;
}

