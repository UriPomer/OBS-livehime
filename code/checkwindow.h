#ifndef CHECKWINDOW_H
#define CHECKWINDOW_H

#include <QWidget>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class checkwindow; }
QT_END_NAMESPACE

class checkwindow : public QWidget
{
    Q_OBJECT

public:
    checkwindow(QWidget *parent = nullptr);
    ~checkwindow() = default;
    void CheckAndOpen(const QString& _appName, const QString& _appLocation);

private slots:
    void OpenApp(const QString&name);


private:
    Ui::checkwindow *ui;
};

#endif // CHECKWINDOW_H
