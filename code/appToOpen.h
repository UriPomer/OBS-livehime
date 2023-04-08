#ifndef APPTOOPEN_H
#define APPTOOPEN_H

#include<QString>
#include<QVector>

class appToOpen{
public:
    QVector<QString> appNames;
    QVector<QString> appLocations;
    const QString jsonLocation;
    appToOpen();
};

#endif // APPTOOPEN_H
