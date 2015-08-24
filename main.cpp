#include <QApplication>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QDebug>
#include <QObject>

#include "qloadfile.h"

QString loadFile()
{
    QString strRetVal = "Test File Contents";

    return strRetVal;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<QLoadFile>("QLoadFile", 1, 0, "QLoadFile");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

#if 0
    QQmlComponent component(&engine, "MainForm.ui.qml");
    QObject *object = component.create();

    qDebug() << "component created:";

    QVariant returnedValue;
    QVariant msg = "Hello from C++";
    QMetaObject::invokeMethod(object, "fillTextBox",
          Q_RETURN_ARG(QVariant, returnedValue),
          Q_ARG(QVariant, msg));

    qDebug() << "QML function returned:" << returnedValue.toString();
    delete object;
#endif

    QLoadFile fileLoader;

    return app.exec();
}
