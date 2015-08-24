#ifndef QLOADFILE_H
#define QLOADFILE_H

#include <QObject>

class QLoadFile : public QObject
{
    Q_OBJECT
public:
    explicit QLoadFile(QObject *parent = 0);
    Q_INVOKABLE QString loadThatFile(void);


signals:

public slots:
};

#endif // QLOADFILE_H
