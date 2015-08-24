#include <QDebug>
#include <QFile>
#include "qloadfile.h"

QLoadFile::QLoadFile(QObject *parent) : QObject(parent)
{

}

QString QLoadFile::loadThatFile(void)
{
    QString strRetVal = "";

    QFile file("/proc/cpuinfo");
    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly))
        {
            while (!file.atEnd())
            {
                QString strOneLine(file.readLine());
                //ui->listWidget->addItem(strOneLine.trimmed());
                strRetVal += strOneLine;
            }

            file.close();
        }
        else
        {
            strRetVal = "Could not open file /proc/cpuinfo.";
        }
    }
    else
    {
        strRetVal = "File /proc/cpuinfo does not exist.";
    }

    qDebug() << "QLoadFile::loadThatFile() returning " << strRetVal;

    return strRetVal;
}

