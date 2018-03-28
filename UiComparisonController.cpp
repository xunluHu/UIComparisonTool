#include "UiComparisonController.h"

UiComparisonController::UiComparisonController(QObject *parent) : QObject(parent) {

}

void UiComparisonController::setOriginFileName(QString tmpString) {
    m_originFileName = tmpString.remove(0, 7);
}

void UiComparisonController::setTargetFileName(QString tmpString) {
    m_targetFileName = tmpString.remove(0, 7);
}

bool UiComparisonController::comparePic() {
    qDebug() << "m_originFileName" << m_originFileName;
    qDebug() << "m_targetFileName" << m_targetFileName;

    //图片信息的获取,新建,对比,标记,保存
    Mat img, img2;
    img = imread("./speedPlate.png", IMREAD_COLOR);
    img2 = imread("./speedPlate.png", IMREAD_COLOR);
    int nr = img.rows;
    int nc = img.cols * img.channels();
    int div = 64;
    int totalCount = 0;
    int differentCount = 0;
    for(int j = 0; j < nr; ++j) {
        uchar* data = img.ptr<uchar>(j);
        uchar* data1 = img2.ptr<uchar>(j);
        for(int i=0; i < nc; ++i) {
            *data++ = *data / div * div + div / 2;
            *data1++ = *data1 / div * div + div / 2;
            if(data1 != data) {
                qDebug() << "data !== data1";
                ++differentCount;
            }
            ++totalCount;
        }
        qDebug() << "the ratio of different count" << (double)differentCount / (double)totalCount;
    }
    return true;
}
