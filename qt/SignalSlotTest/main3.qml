import QtQuick 2.4

import test 1.0

ItemTest3 {
    id: itemtest3
    width: 360
    height: 360

    Rectangle {
        width: parent.width
        height: parent.height / 3
        color: "lightblue"

        Text {
            anchors.centerIn: parent
            text: qsTr("Create")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                itemtest3.doCreate()
            }
        }
    }

    Rectangle {
        y: height
        width: parent.width
        height: parent.height / 3
        color: "lightyellow"

        Text {
            anchors.centerIn: parent
            text: qsTr("Destroy")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                itemtest3.doDestroy()
            }
        }
    }

    Rectangle {
        y: height * 2
        width: parent.width
        height: parent.height / 3
        color: "red"

        Text {
            anchors.centerIn: parent
            text: qsTr("Check")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                itemtest3.doCheck()
            }
        }
    }
}
