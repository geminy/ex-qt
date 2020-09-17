import QtQuick 2.4

import test 1.0

MyItem {
    id: myitem
    width: 360
    height: 360

    Rectangle {
        width: parent.width
        height: parent.height / 2
        color: "lightblue"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                myitem.onMouseClicked()
            }
        }
    }

    Rectangle {
        y: height
        width: parent.width
        height: parent.height / 2
        color: "lightyellow"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                myitem.onMouseClicked2()
            }
        }
    }
}
