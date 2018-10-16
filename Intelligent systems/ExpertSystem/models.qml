import QtQuick 2.10

Item {
    id: root
    property int state: 0

    Component {
        id: answersModelComponent
        ListModel { }
    }

    function getAnswers(state) {
        var newModel = answersModelComponent.createObject(root)
        for(var i = 0; i < root.edges.count; i++){
            var item = root.edges.get(i)
            if(item.begin === state)
                newModel.append(item)
        }
        return newModel
    }

    property ListModel edges: ListModel {
        ListElement { begin: 0; end: 1; answer: "Стебель - зеленый" }
        ListElement { begin: 0; end: 2; answer: "Стебель - древесный" }
        ListElement { begin: 2; end: 3; answer: "Положение - стелящееся" }
        ListElement { begin: 2; end: 4; answer: "Положение - прямое" }
        ListElement { begin: 4; end: 5; answer: "Один ствол - да" }
        ListElement { begin: 4; end: 6; answer: "Один ствол - нет" }
        ListElement { begin: 5; end: 7; answer: "Форма листа широкая и плоская - да" }
        ListElement { begin: 5; end: 8; answer: "Форма листа широкая и плоская - нет" }
        ListElement { begin: 8; end: 9; answer: "Форма листа - чешуеобразная" }
        ListElement { begin: 8; end: 10; answer: "Форма листа - иглообразная" }
        ListElement { begin: 10; end: 11; answer: "Конфигурация - хаотическая" }
        ListElement { begin: 10; end: 12; answer: "Конфигурация - 2 ряда" }
        ListElement { begin: 12; end: 11; answer: "Серебряная полоса - да" }
        ListElement { begin: 12; end: 13; answer: "Серебряная полоса - нет" }
    }

    property ListModel names: ListModel {
        ListElement { state: 0; answer: "Ничего"}
        ListElement { state: 5; answer: "Тип - деревья"}
        ListElement { state: 8; answer: "Класс - голосемянные"}
    }

    property ListModel questions: ListModel {
        ListElement { state: 0; question: "Какой стебель у растения: древесный или зеленый?"}
        ListElement { state: 2; question: "Каково положение стебля: стелящееся или прямостоящее?"}
        ListElement { state: 4; question: "Имеет ли растение один основное ствол?"}
        ListElement { state: 5; question: "Имеют ли листья широкую и плоскую форму?"}
        ListElement { state: 8; question: "Какая форма листа: чешуеобразная или иглоподобная?"}
        ListElement { state: 10; question: "Какую конфигурацию имеет расположение игл: хаотическую или в 2 ряда?"}
        ListElement { state: 12; question: "Имеется ли серебристая полоса снизу иглы?"}
    }

    property ListModel results: ListModel {
        ListElement { state: 0; question: "Какой стебель у растения: древесный или зеленый?";                       explanation: "Если стебель зеленый, то тип - травянистые. Если стебель древесный и положение стелящееся, то тип лианы." }
        ListElement { state: 1; question: "Ответ: тип - травянистые. Вопросов больше нет.";                        explanation: "Установлено, что тип - травянистые." }
        ListElement { state: 2; question: "Каково положение стебля: стелящееся или прямостоящее?";                  explanation: "Если стебель древесный и положение стелящееся, то тип - лианы. Если стебель древесный и положение - прямостоящее и один основной ствол - да, то тип - деревья. Если стебель двересный и положение прямостоящее и один основной ствол - нет, то тип - кустарниковые." }
        ListElement { state: 3; question: "Ответ: тип - лианы. Вопросов больше нет.";                             explanation: "Установлено, что тип - лианы." }
        ListElement { state: 4; question: "Имеет ли растение один основное ствол?";                                 explanation: "Если стбель древесный и положение прямостоящее и один основной ствол - да, то тип - деревья. Если стебель древесный и положение прямостоящее и один основной ствол - нет, то тип - кустарниковые" }
        ListElement { state: 5; question: "Имеют ли листья широкую и плоскую форму?";                               explanation: "Если тип - деревья и широкая и плоская листва - да, то класс - покрытосемянные. Если тип - деревья и  широкая и плоская листва - нет, то класс - голосемянные." }
        ListElement { state: 6; question: "Ответ: тип - кустарниковые. Вопросов больше нет.";                     explanation: "Установленно, что тип - кустарниковые." }
        ListElement { state: 7; question: "Ответ: класс - покрытосемянные. Вопросов больше нет.";                 explanation: "Установленно, что класс - покрытосемянные." }
        ListElement { state: 8; question: "Какая форма листа: чешуеобразная или иглоподобная?";                     explanation: "Если класс - голосемянные и форма листа иглообразная и конфигурация хаотическая, то семейство - сосновые. Если класс голосемянные и форма листа чешуеобразная, то семейство - кипарисовые." }
        ListElement { state: 9; question: "Ответ: семейство - кипарисовые. Вопросов больше нет.";                 explanation: "установлено, что семейство - кипарисовые." }
        ListElement { state: 10; question: "Какую конфигурацию имеет расположение игл: хаотическую или в 2 ряда?";  explanation: "Если класс голосемянные и форма листа иглоподобная и конфигурация - 2 ровных ряда и сереблистая полоса, то семейство сосновые. Если класс голосемянные и форма листа иглоподобная и конфигурация - хаотическая то семейство сосновые." }
        ListElement { state: 11; question: "Ответ: семейство - сосновые. Вопросов больше нет.";                   explanation: "Установлено, что семейство - сосновые." }
        ListElement { state: 12; question: "Имеется ли серебристая полоса снизу иглы?";                             explanation: "Если класс голосемянные и форма листа иглоподобная и конфигурация - 2 ровных ряда и нет серебристой полосы, то семейство - болотный кипарис. Если класс голосемянные и форма листа иглоподобная и конфигурация - 2 ровных ряда и есть серебристая полоса, то семейство - сосновые. "}
        ListElement { state: 13; question: "Ответ: семейство - болотный кипарис. Вопросов больше нет.";           explanation: "Установлено, что семейство - болотный кипарис." }
    }
}
