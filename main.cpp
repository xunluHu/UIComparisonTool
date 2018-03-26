#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QQmlFile>
#include <QQmlContext>
#include "UiComparisonController.h"

int main(int argc, char** argv) {

    QGuiApplication app(argc, argv);

    UiComparisonController UCC;

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("UCC",&UCC);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
