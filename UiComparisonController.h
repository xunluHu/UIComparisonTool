#ifndef UICOMPARISONCONTROLLER_H
#define UICOMPARISONCONTROLLER_H

#include <string>
#include <iostream>
#include <QObject>
#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class UiComparisonController : public QObject
{
    Q_OBJECT
public:
    explicit UiComparisonController(QObject *parent = nullptr);

signals:
    void originFileNameChanged();
    void targetFileNameChanged();

public slots:
    void setTargetFileName(QString);
    void setOriginFileName(QString);
    bool comparePic();

public:
    QString m_originFileName;
    QString m_targetFileName;
};

#endif // UICOMPARISONCONTROLLER_H
