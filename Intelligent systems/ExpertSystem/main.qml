import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Ботаническая экспертная система")

    Models {
        id: models
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: startComponent
    }

    Component {
        id: startComponent
        QuestionForm {
            question: "Что вы уже знаете о растении?"
            answers: models.names

            onSelected: {
                models.state = item.state
                stackView.push(questionsComponent)
            }
        }
    }

    Component {
        id: questionsComponent
        SwipeView {
            id: view
            currentIndex: models.state
            interactive: false

            Repeater {
                model: models.results
                QuestionForm {
                    question: model.question

                    answers: models.getAnswers(model.state)
                    explanation: model.explanation

                    onSelected: {
                        models.state = item.end
                    }

                    onBack: {
                        stackView.pop()
                    }
                }
            }

        }
    }
}
