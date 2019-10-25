import QtQuick 2.9

Item {
    id: block
    property int type: 0
    Image {
        id: img
        anchors.fill: parent
        source: {
            return "shared/pics/Stones/"+(type+1)+".png"


        }
    }

}
