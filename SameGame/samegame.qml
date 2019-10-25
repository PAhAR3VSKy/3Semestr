import QtQuick 2.9
import "samegame.js" as SameGame

Rectangle { // "холст" главного окна приложения в виде приямоугольника
    id: screen // его уникальное имя
    width: 490; height: 720 // размеры прямоугольника
    SystemPalette { id: activePalette }
    Item { // контейнер для группировки элементов
        width: parent.width // ширина - такая же как и у родительского объёкта
        // (в данном случае - прямоугольника "screen"
        anchors { top: parent.top; bottom: toolBar.top } // верх должен совпасть
        // с верхом родителя, низ - с верход панели инструментов toolBar
        Image { // Изображение
            id: background
            anchors.fill: parent // Должно целиком заполнить родительский
            //элемент
            source: "shared/pics/background.jpg"
            fillMode: Image.PreserveAspectCrop // изображение растягивается,
            // если нужно - обрезается
        }
    }

    Item {
        id: gameCanvas
        property int score: 0
        property int blockSize: 40
        width: parent.width - (parent.width % blockSize)
        height: parent.height - (parent.height% blockSize + 10)
        anchors.centerIn: parent
        MouseArea {
            anchors.fill: parent
            onClicked: SameGame.handleClick(mouse.x, mouse.y)
        }
    }

    Dialog {
        id: dialog
        anchors.centerIn: parent
        z: 100
    }

    Rectangle {
        id: toolBar // панель инструментов
        width: parent.width; height: 30
        color: activePalette.window
        anchors.bottom: screen.bottom
        Button {
            anchors { left: parent.left; verticalCenter: parent.verticalCenter }
            text: "New Game"
            onClicked: SameGame.startNewGame()
        }

        Text {
            id: score
            anchors { right: parent.right; verticalCenter: parent.verticalCenter
            }
            text: "Score:" + gameCanvas.score
        }
    }
}
