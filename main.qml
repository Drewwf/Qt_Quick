import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

import QLoadFile 1.0

ApplicationWindow {
    title: qsTr("Program to read and display file /proc/cpuinfo")
    width: 640
    height: 480
    visible: true
    onVisibilityChanged: fillTextBox();

    QLoadFile {
        id: fileLoader
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")

            MenuItem {
                text: qsTr("&Open")
                onTriggered: fillTextBox();
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
        id: mainForm
        anchors.fill: parent
    }

    function fillTextBox() {
        mainForm.cpuInfo.remove(0, mainForm.cpuInfo.length);
        mainForm.cpuInfo.append(fileLoader.loadThatFile());
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("Information")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
