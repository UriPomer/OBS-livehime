#ifndef JSONDECODER_H
#define JSONDECODER_H
#include <QWidget>
#include <QProcess>

namespace json {
    void jsonDecode(const QString& jsonLocation, QVector<QString>& appNames, QVector<QString>& appLocations);
//    template <class T>
    void jsonDecode(const QString& jsonLocation, int &value, const QString& param);
};
#endif // JSONDECODER_H
