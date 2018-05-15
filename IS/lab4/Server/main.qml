import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.2

ApplicationWindow {
    visible: true
    width: 480
    height: 480
    title: qsTr("Lab 4")

    QtObject {
        id: internal
        property var keys: server.keys
    }

    header: Rectangle {
        id: head
        height: 80
        color: "#ff415a"

        Text {
            id: title
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 5
            }
            text: qsTr("Server")
            color: "#ffffff"
            font.pixelSize: 20
        }

        Text {
            anchors {
                bottom: col1.top
                left: parent.left
                leftMargin: 5
                bottomMargin: 5
            }

            text: qsTr("Secret key (S) = %1").arg(internal.keys.key)
            color: "#ffffff"
            font.pixelSize: 16
        }

        Column {
            id: col1
            anchors {
                left: parent.left
                top: title.bottom
                bottom: parent.bottom
                leftMargin: 5
            }
            spacing: 2
            Text {
                text: qsTr("G = %1").arg(internal.keys.G)
                color: "#ffffff"
                font.pixelSize: 16
            }

            Text {
                text: qsTr("P = %1").arg(internal.keys.P)
                color: "#ffffff"
                font.pixelSize: 16
            }
        }

        Column {
            id: col2
            anchors {
                left: col1.right
                top: title.bottom
                bottom: parent.bottom
                leftMargin: 10
            }
            width: contentItem.width
            spacing: 2
            Text {
                text: qsTr("Public key (A) = %1").arg(internal.keys.publicKey)
                color: "#ffffff"
                font.pixelSize: 16
            }

            Text {
                text: qsTr("Secret key (a) = %1").arg(internal.keys.secretKey)
                color: "#ffffff"
                font.pixelSize: 16
            }
        }

        Button {
            id: generateButton
            anchors {
                right: saveButton.left
                rightMargin: 10
                bottom: parent.bottom
                bottomMargin: 10
            }
            text: qsTr("Generate keys")
            onClicked: {
                server.generateKeys();
            }
        }
        Button {
            id: saveButton
            anchors {
                right: parent.right
                rightMargin: 10
                bottom: parent.bottom
                bottomMargin: 10
            }
            text: qsTr("Save keys")
            onClicked: {
                server.saveKeys();
            }
        }
    }

    Flickable {
        id: flick

        anchors.fill: parent
        contentWidth: edit.paintedWidth
        contentHeight: edit.paintedHeight
        clip: true
        flickableDirection: Flickable.VerticalFlick

        function ensureVisible(r)
        {
            if (contentX >= r.x)
                contentX = r.x;
            else if (contentX+width <= r.x+r.width)
                contentX = r.x+r.width-width;
            if (contentY >= r.y)
                contentY = r.y;
            else if (contentY+height <= r.y+r.height)
                contentY = r.y+r.height-height;
        }

        TextEdit {
            id: edit
            //anchors.fill: parent
            width: flick.width
            height: parent.height
            wrapMode: TextEdit.Wrap
            font.pixelSize: 15

            onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)

            Connections {
                target: server
                onLog: {
                    edit.insert(edit.length, "> " + entry + "\n");
                }
            }
        }
    }

//    Timer {
//        running: true
//        repeat: true
//        triggeredOnStart: false
//        interval: 1000
//        onTriggered: {
//            server.sendMessage("Hello")
//        }
//    }

    Component.onCompleted: server.start();

}
