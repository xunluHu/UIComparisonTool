import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("UiComparisonTool")
    Item {
        id: root
        width: parent.width
        height: parent.height
        property string whichName: "origin"
        FileDialog {
            property string originFileName: ""
            property string targetFileName: ""
            id: loadProjectFileDialog
            modality: Qt.ApplicationModal
            folder: shortcuts.home
            selectMultiple: false
            title: qsTr("选择文件所在路径")
            onAccepted: {
                //获取文件地址
                if(root.whichName === "origin") {
                    originImage.source = originFileName = loadProjectFileDialog.fileUrl;
                    UCC.setOriginFileName(originFileName);
                } else if(root.whichName === "target") {
                    targetImage.source = targetFileName = loadProjectFileDialog.fileUrl;
                    UCC.setTargetFileName(targetFileName);
                } else {
                    console.log("there must be something wrong")
                }
            }
        }
        MessageDialog {
            id: hintBox
            title: qsTr("提示")
            text:  qsTr("请选中要比对的图片")
            standardButtons: StandardButton.Yes
            onYes: hintBox.close()
        }
        Column {
            spacing: 20
            Row {
                spacing: 110
                Button {
                    id: chooseOriginSource
                    width: 200
                    height: 50
                    text: qsTr("选择从UI获取的图片")
                    onClicked: {
                        root.whichName = "origin";
                        loadProjectFileDialog.open();
                    }
                }

                Button {
                    id: chooseTargetSource
                    width: 200
                    height: 50
                    text: qsTr("选中从仪表获取的图片")
                    onClicked: {
                        root.whichName = "target";
                        loadProjectFileDialog.open();
                    }
                }
            }
            Row {
                spacing: 10
                Image {
                    id: originImage
                    width: 300
                    height: 180
                    onStatusChanged: {
                        if(status === Image.Error) {
                            hintBox.text = qsTr("源图片显示异常,请选择合适的格式")
                            hintBox.open();
                        }
                    }
                }
                Image {
                    id: targetImage
                    width: 300
                    height: 180
                    onStatusChanged: {
                        if(status === Image.Error) {
                            hintBox.text = qsTr("目标图片显示异常,请选择合适的格式")
                            hintBox.open();
                        }
                    }
                }
            }
            Button {
                id: comparisonButton
                width: 200
                height: 50
                text: qsTr("进行对比")
                onClicked: {
                    if(originImage.source.toString() === ""
                            || targetImage.source.toString() === "") {
                        hintBox.text = qsTr("请选中要比对的图片")
                        hintBox.open();
                    } else {
                        if(UCC.comparePic()) {
                            hintBox.text = qsTr("对比完成结果保存在....");
                        } else {
                            hintBox.text = qsTr("对比错误");
                        }
                    }
                }
            }
        }
    }
}
