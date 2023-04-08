#include <QApplication>
#include <QProcess>
#include <QTimer>
#include <windows.h>
#include <broadcaster.h>
#include <otherThingToDo.h>

QApplication *a;

int main(int argc, char *argv[])
{
    a = new QApplication(argc, argv);
    broadcaster BC;
    BC.show();
    return a->exec();
}

