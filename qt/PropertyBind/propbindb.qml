import QtQuick 2.4

Item {
    id: item
    width: 360
    height: 360

    property int wid: 100
    property int hei: 100
    property bool isbinded: false

    function getHeight() {
        return item.hei
    }

    Rectangle {
        id: rect
        width: 100
        height: isbinded ? getHeight() : 100
        color: "yellow"
    }

    focus: true
    Keys.onSpacePressed: {
        console.log("onSpacePressed")
        if (isbinded) {
            console.log("unbind")
        }
        else {
            console.log("bind")
        }
        isbinded = !isbinded
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
        text: "using Binding"
    }

    Binding {
        id: binding
        target: rect
        property: "width"
        value: item.wid
        when: isbinded
    }
}
