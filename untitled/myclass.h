#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QString>
#include <QThread>

class MyClass:public QObject
{
    Q_OBJECT
public:
    MyClass(QString name);
public slots:
    void doWork();
    void receiveGlobalVar (int i);
signals:
    void send(int i);
private:
    QString name;
    int globalVar;
};

#endif // MYCLASS_H
