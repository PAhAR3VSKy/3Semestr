import QtQuick 2.9
Rectangle {
    id: container
    property string text: "Button"
    signal clicked // имеет сигнал "нажата"
    width: buttonLabel.width + 20; height: buttonLabel.height + 5 // размеры
   // кнопки рассчитываются автоматически в зависимости от размеров текста в ней
    border { width: 1; color: Qt.darker(activePalette.button) } // задаётся
    //граница размером 1 пиксель
    antialiasing: true // сглаживание "лесенок"
    radius: 8 // радиус закругления углов прямоугольника
    // цвет кнопки зададим с помощью градиента
    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: { // цвет зависит от нажатия на кнопку
                if (mouseArea.pressed)
                    return activePalette.dark
                else
                    return activePalette.light
            }
        }
        GradientStop { position: 1.0; color: activePalette.button }
    }
    MouseArea { // Зона, в которой отслеживается курсор
        id: mouseArea
        anchors.fill: parent
        onClicked: container.clicked(); // при нажатии на зону элемент container
        //посылает сигнал о нажатии
    }
        Text {
            id: buttonLabel
            anchors.centerIn: container
            color: activePalette.buttonText
            text: container.text
        }
    }
