#ifndef BROADCASTER_H
#define BROADCASTER_H

#include <QWidget>
#include <checkwindow.h>
#include <appToOpen.h>

QT_BEGIN_NAMESPACE
namespace Ui { class broadcaster; }
QT_END_NAMESPACE

class broadcaster : public QWidget
{
    Q_OBJECT

public:
    broadcaster(QWidget *parent = nullptr);
    ~broadcaster();

private:
    Ui::broadcaster *ui;
    checkwindow *check;
    appToOpen *apps;
};
#endif // BROADCASTER_H
