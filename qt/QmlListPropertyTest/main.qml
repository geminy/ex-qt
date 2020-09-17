import QtQuick 2.4
import QtQuick.Window 2.2
import  test 1.0

Window {
    visible: true
    width: 360
    height: 360

    MyItem {
        id: myitem
    }

    Rectangle {
        width: parent.width
        height: parent.height / 3
        color: "red"

        Text {
            anchors.centerIn: parent
            text: qsTr("Create")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                myitem.createBtnTexts()
            }
        }
    }

    Rectangle {
        y: height
        width: parent.width
        height: parent.height / 3
        color: "yellow"

        Text {
            anchors.centerIn: parent
            text: qsTr("Delete")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                myitem.deleteBtnTexts()
            }
        }
    }

    Rectangle {
        y: height * 2
        width: parent.width
        height: parent.height / 3
        color: "green"

        Text {
            anchors.centerIn: parent
            text: qsTr("Check")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                myitem.checkBtnTexts()
                console.log("----------")
                var texts = myitem.getButton().btnTextList
                console.log(texts.length)
                for (var i = 0; i < texts.length; ++i) {
                    console.log(texts[i])
                    if (texts[i]) {
                        console.log(texts[i].buttonText())
                    }
                }
            }
        }
    }

//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            Qt.quit();
//        }
//    }
}
