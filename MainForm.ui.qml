import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias cpuInfo: cpuInfo

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.fill: parent

        TextArea {
            id: cpuInfo
            text: ""
            font.pointSize: 12
            font.bold: false
            Layout.fillHeight: true
            Layout.fillWidth: true
            textColor: "#1b0000"
        }
    }
}
