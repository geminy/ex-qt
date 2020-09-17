import QtQuick 2.4
import aidear.com 1.0

Item {
    id: item
    width: 360
    height: 360

//    property bool chooseperson: true

    Rectangle {
        id: rect
        anchors.fill: parent
        color: "lightyellow"

        ListView {
            id: listview
            width: rect.width
            height: rect.height / 2
//            model: chooseperson ? listmodel : listmodelfruit
            model: demo.show ? listmodel : listmodelfruit
            delegate: listdelegate
        }

        ListModel {
            id: listmodel
            ListElement {
                name: "Bill Smith"
                number: "555 3264"
            }
            ListElement {
                name: "John Brown"
                number: "555 8426"
            }
            ListElement {
                name: "Sam Wise"
                number: "555 0473"
            }
        }

        ListModel {
            id: listmodelfruit
            ListElement {
                name: "apple"
                number: 100
            }
            ListElement {
                name: "pear"
                number: 200
            }
            ListElement {
                name: "banana"
                number: 300
            }
        }

        Component {
            id: listdelegate
            Rectangle {
                id: delegatebg
                width: 360
                height: 60
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)

                Text {
                    id: delegatecontent
                    anchors.centerIn: parent
                    text: "<b>name:</b> " + name + "  <b>number:</b> " + number
                }
            }
        }

        Demo {
            id: demo
        }

        Text {
            id: text
            width: rect.width
            height: rect.height / 2
            y: height
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "listview & listmodel"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("onClicked")
//                    if (chooseperson) {
//                        chooseperson = false
//                    }
                    demo.btnClicked()
                }
            }
        }
    }
}
