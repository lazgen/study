import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Item {
    id: root

    property alias question: questionText.text
    property alias answers: answerVariantsView.model
    property alias explanation: explanationText.text

    signal selected(var item)
    signal back


    Pane {
        id: questionTextPane
        Material.elevation: 3
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            topMargin: 10
        }

        width: parent.width * 0.95
        height: 50

        Text {
            id: questionText
            anchors.fill: parent
            anchors.rightMargin: button.visible ? 40 : 0

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            fontSizeMode: Text.HorizontalFit

            font {
                pixelSize: 18

            }

            text: qsTr("Вопрос")
        }

        Button {
            id: button
            visible: root.explanation != "" && answerVariantsView.count !== 0
            Material.accent: Material.Yellow
            anchors {
                right: parent.right
                verticalCenter: parent.verticalCenter
            }

            height: 50
            width: height
            text: "?"

            onClicked: {
                popup.open()
            }
        }

        Popup {
            id: popup
            x: parent.width * 0.2
            y: parent.y + parent.height
            width: parent.width * 0.8
            height: 150
            modal: true
            focus: true
            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

            Text {
                anchors.fill: parent
                text: root.explanation

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                fontSizeMode: Text.Fit
                wrapMode: Text.WordWrap

                font {
                    pixelSize: 18
                }
            }
        }
    }

    Pane {
        Material.elevation: 3
        anchors {
            top: questionTextPane.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            margins: parent.width * 0.025
        }

        ListView {
            id: answerVariantsView
            anchors.fill: parent
            interactive: false

            model: 4
            spacing: 15

            delegate: Pane {
                Material.elevation: 3
                width: answerVariantsView.width
                height: answerVariantsView.height / answerVariantsView.count - answerVariantsView.spacing

                Text {
                    id: answerText
                    anchors.fill: parent

                    text: model.answer

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    fontSizeMode: Text.HorizontalFit

                    font {
                        pixelSize: 18
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        root.selected(model)
                    }
                }
            }

            Text {
                id: explanationText
                visible: answerVariantsView.count == 0
                anchors.fill: parent

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                fontSizeMode: Text.HorizontalFit

                font {
                    pixelSize: 18
                }
            }

            Button {
                visible: answerVariantsView.count == 0
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    bottom: parent.bottom
                    bottomMargin: 12
                }

                text: "Начать заново"
                onClicked: {
                    root.back();
                }
            }
        }
    }
}
