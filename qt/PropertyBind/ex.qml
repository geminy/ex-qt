import QtQuick 2.4

NQView {
    id: view
    width: 800
    height: 480
    NQRectangle {
        id: rect
        width: view.width / 2
        height: view.height
    }
    NQMouseArea {
        anchors.fill: parent
        onClicked: {
            rect.width = 100
            rect.height = view.height
        }
    }
}
