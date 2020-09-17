import QtQuick 2.4
import aidear.com 1.0

Item {
    id: item
    width: 360
    height: 360

    Rectangle {
        id: rect
        width: {
            if (demo.ageover) {
                demo.age
            }
            else {
                100
            }
        }
        height: 100
        color: "green"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("onClicked")
            if (demo.age >= 360) {
                demo.age = 100
            }
            else {
                demo.age += 10
            }
            console.log("Demo::age age is " + demo.age)
        }
    }

    Text {
        id: text
        anchors.centerIn: parent
        text: "from C++ Object"
    }

    Demo {
        id: demo
    }
}
