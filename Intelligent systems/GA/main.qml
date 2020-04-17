import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    visible: true
    width: 800
    height: 480
    title: qsTr("GA")


    Material.accent: Material.Yellow
    Material.background: Material.Cyan

    Connections {
        target: GProxima
        onPointsChanged: {
            console.debug("onPointsChanged")
            pointsModel.clear();
            for(var i in GProxima.points) {
                console.debug(i, GProxima.points[i])
                pointsModel.append({
                                       xPoint: GProxima.points[i].x,
                                       yPoint: GProxima.points[i].y
                                   })
            }
        }
    }

    header: Pane {
        height: 70
        Material.elevation: 2

        Row {
            anchors.fill: parent
            layoutDirection: Qt.RightToLeft
            spacing: 10

            Button {
                text: "Rand"
                onClicked: {
                    GProxima.fillRandPoints();
                }
            }

            Button {
                text: "Очитить"
                onClicked: {
                    GProxima.clear()
                }
            }

            Button {
                text: "Аппроксимировать"
                onClicked: {
                    GProxima.solve()
                }
            }
        }

    }

    Pane {
        Material.elevation: 2
        anchors {
            margins: 4
            left: parent.left
            top: parent.top
            right: parent.horizontalCenter
            bottom: parent.bottom
        }

        ListView {
            anchors.fill: parent
            anchors.bottomMargin: 60

            model: ListModel {
                id: pointsModel
            }

            header: Row {
                width: parent.width
                height: 30
                spacing: 5

                Text{
                    width: parent.width * 0.5 - 5
                    text: "X"
                }
                Text{
                    width: parent.width * 0.5 - 5
                    text: "Y"
                }
            }

            delegate: Row {
                width: parent.width
                height: 30
                spacing: 5

                Text{
                    width: parent.width * 0.5 - 5
                    text: model.xPoint
                }
                Text{
                    width: parent.width * 0.5 - 5
                    text: model.yPoint
                }
            }
        }

        Rectangle {
            anchors {
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }
            height: 60
            border.width: 1
            color: "transparent"

            Row {
                anchors.fill: parent
                anchors.margins: 4
                spacing: 4

                TextField {
                    id: xPoint
                    width: parent.width / 3 - 4
                    placeholderText: "X"
                    validator: DoubleValidator {
                        bottom: -9999.0
                        top: 9999.0
                        decimals: 2
                    }
                }
                TextField {
                    id: yPoint
                    width: parent.width / 3 - 4
                    placeholderText: "Y"
                    validator: DoubleValidator {
                        bottom: -9999.0
                        top: 9999.0
                        decimals: 2
                    }
                }
                Button {
                    //width: parent.width / 3 - 4
                    text: "Добавить"
                    anchors.verticalCenter: parent.verticalCenter
                    onClicked: {
                        GProxima.addPoint(parseFloat(xPoint.text),
                                          parseFloat(yPoint.text))
                    }
                }
            }
        }
    }

    Pane {
        Material.elevation: 2
        anchors {
            margins: 4
            top: parent.top
            right: parent.right
            left: parent.horizontalCenter
        }
        height: parent.height * 0.15


        Text {
            anchors.fill: parent
            font.pointSize: 18
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: qsTr("y = %1 * x + %2").arg(GProxima.answer.x).arg(GProxima.answer.y)
        }
    }


    Pane {
        Material.elevation: 2
        anchors {
            margins: 4
            bottom: parent.bottom
            right: parent.right
            left: parent.horizontalCenter
        }
        height: parent.height * 0.8

        Column {
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                bottom: parent.bottom
            }

            spacing: 4
            Text {
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
                text: "Аппроксимация набора точек функцией:\ny(x) = a*x + b;"
                font.pointSize: 12
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5
                Text {
                    font.pointSize: 10
                    text: qsTr("Min (a,b):")
                }
                TextField {
                    text: GProxima.bottomBorder
                    width: parent.width / 4
                    validator: DoubleValidator {
                        bottom: -100.0
                        top: 100.0
                        decimals: 2
                    }
                    onTextChanged: GProxima.bottomBorder = parseFloat(text)
                }

                Text {
                    font.pointSize: 10
                    text: qsTr("Max (a,b):")
                }
                TextField {
                    width: parent.width / 4
                    text: GProxima.topBorder
                    validator: DoubleValidator {
                        bottom: -100.0
                        top: 100.0
                        decimals: 2
                    }
                    onTextChanged: GProxima.topBorder = parseFloat(text)
                }
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5
                Text {
                    font.pointSize: 10
                    text: qsTr("Популяция:")
                }
                TextField {
                    width: parent.width / 4
                    text: GProxima.population
                    validator: IntValidator {
                        bottom: 2
                        top: 9999999
                    }
                    onTextChanged: GProxima.population = parseInt(text)
                }

                Text {
                    font.pointSize: 10
                    text: qsTr("Число\nпоколений:")
                }
                TextField {
                    width: parent.width / 4
                    text: GProxima.generation
                    validator: IntValidator {
                        bottom: 2
                        top: 9999999
                    }
                    onTextChanged: GProxima.generation = parseInt(text)
                }
            }


            Text {
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
                text: "Вероятноти:"
                font.pointSize: 12
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5
                Text {
                    font.pointSize: 10
                    text: qsTr("Кроссинговера:")
                }
                TextField {
                    width: parent.width / 4
                    text: GProxima.krossengoverLikelihood
                    validator: DoubleValidator {
                        bottom: 0.0
                        top: 1.0
                        decimals: 2
                    }
                    onTextChanged: GProxima.krossengoverLikelihood = parseInt(text)
                }

                Text {
                    font.pointSize: 10
                    text: qsTr("Мутации:")
                }
                TextField {
                    width: parent.width / 4
                    text: GProxima.mutationLilelihood
                    validator: DoubleValidator {
                        bottom: 0.0
                        top: 1.0
                        decimals: 2
                    }
                    onTextChanged: GProxima.mutationLilelihood = parseInt(text)
                }
            }
        }
    }
}
