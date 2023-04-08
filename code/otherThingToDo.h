#ifndef OTHERTHINGTODO_H
#define OTHERTHINGTODO_H
#include <QThread>
#include <QApplication>
extern QApplication *a;

namespace OtherToDos {
class MyThread : public QThread
{
public:
    void run() override;
private:
    int startDelayTime = 10;
};

void winActivate();
void winClickButtonAutomatically();
}

#endif // OTHERTHINGTODO_H
