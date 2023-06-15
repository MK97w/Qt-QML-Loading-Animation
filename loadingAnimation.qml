import QtQuick 2.15

Rectangle {
    id: rootRect
    color: "black"

    Text{
        id: subText
        color: "#22ff00"
        text: qsTr("Child Process Started!")
        anchors.centerIn: parent
        font.pixelSize: 60
        font.bold: true
    }

}
