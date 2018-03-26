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
    int diffCount = 0;
    int totalPicNum = img.channels() * img.rows * img.cols;
    //cout << "R(numpy)" << endl << format(img, Formatter::FMT_CSV) << endl;
    qWarning() << "channels" << img.channels();
    for(int i = 0; i < 400; ++i) {
        if(*(img.ptr<uchar>(i)) != *(img2.ptr<uchar>(i))) {
            ++diffCount;
        }
        qWarning() << "each bit of pic" << *(img.ptr<uchar>(i));
    }
    cout << "the img rows" << img.rows << "    " << img.cols << endl;;
    cout << "the different count is " << diffCount << "the procent is " << (float)diffCount / totalPicNum << endl;

    return true;
}
