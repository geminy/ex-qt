import QtQuick 2.4

Item {
    id: item
    width: 360
    height: 360

    property int wid: 100
    property int hei: 100
    property bool isbinded: true

    function getHeight() {
        return item.hei
    }

    Rectangle {
        id: rect
        width: item.wid
        height: item.hei
        color: "red"
    }

    focus: true
    Keys.onSpacePressed: {
        console.log("onSpacePressed")
        if (isbinded) {
            rect.width = win.wid
            rect.height = win.hei
        }
        else {
            rect.width = Qt.binding(function() { return win.wid } )
            rect.height = Qt.binding(getHeight)
        }
        isbinded != isbinded
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("onClicked")
            if (item.wid >= item.width) {
                item.wid = 100
            }
            else {
                item.wid += 10
            }
            if (item.hei >= item.height) {
                item.hei = 100
            }
            else {
                item.hei += 10
            }
        }
    }

    Text {
        id: text
        anchors.centerIn: parent
        text: "auto property binding"
    }
}
