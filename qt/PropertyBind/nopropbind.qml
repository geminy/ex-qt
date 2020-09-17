import QtQuick 2.4

Item {
    id: item
    width: 360
    height: 360

    Rectangle {
        id: rect
        width: 100
        height: 100
        color: "lightblue"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("onClicked")
        }
    }

    Text {
        id: text
        anchors.centerIn: parent
        text: "no property binding"
    }
}
