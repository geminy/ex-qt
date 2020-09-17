import QtQuick 2.4

import test 1.0

ItemTest {
    id: itemtest
    width: 360
    height: 360

    Rectangle {
        width: parent.width
        height: parent.height / 2
        color: "lightblue"

        Text {
            anchors.centerIn: parent
            text: qsTr("Create")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                itemtest.doCreate()
            }
        }
    }

    Rectangle {
        y: height
        width: parent.width
        height: parent.height / 2
        color: "lightyellow"

        Text {
            anchors.centerIn: parent
            text: qsTr("Destroy")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                itemtest.doDestroy()
            }
        }
    }
}
