import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1280
    height: 480

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
//            Qt.quit();
        }
    }

    Image {
        id: image
        objectName: "image"
    }
}
