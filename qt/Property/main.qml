import QtQuick 2.4
import QtQuick.Window 2.2
import MagicProperty 1.0

Window {
    visible: true
    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            magicproperty.age += 1
            magicproperty.name += " test"
        }
        mouseArea.onDoubleClicked: {
            Qt.quit()
        }
    }
    MagicProperty {
        id: magicproperty
        age: 10
        name: "test"
    }
}
