#ifndef WORKCLASS_H
#define WORKCLASS_H


#include <windows.h>
#include <QObject>

#include "queue.h"

class WorkClass:public QObject
{
public:
    WorkClass();
public slots:
    void doWork(int, int);
signals:
    void send(int);
};

#endif // WORKCLASS_H
