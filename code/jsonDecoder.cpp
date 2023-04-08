#include <jsonDecoder.h>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QMessageBox>

void json::jsonDecode(const QString& jsonLocation, QVector<QString>& appNames, QVector<QString>& appLocations){
    QFile file(jsonLocation);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }

        // 读取JSON数据
        QByteArray jsonData = file.readAll();
        file.close();

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(jsonData, &jsonError); //转化为JSON文档

    QJsonArray appsArray = document.object().value("apps").toArray();

    for (int i = 0; i < appsArray.size(); i++) {
        QJsonObject appObject = appsArray[i].toObject();

        // 获取每个应用程序的名称和位置
        appNames.push_back(appObject.value("appName").toString());
        appLocations.push_back(appObject.value("appLocation").toString());
    }
}

//template <class T>
void json::jsonDecode(const QString& jsonLocation, int &value, const QString& param){
    QFile file(jsonLocation);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }
        // 读取JSON数据
        QByteArray jsonData = file.readAll();
        file.close();

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(jsonData, &jsonError); //转化为JSON文档
    value = document.object().value(param).toInt();
}

