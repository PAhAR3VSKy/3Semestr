#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include "queue.h"
#include <windows.h>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

public slots:
    void timer();
    void doWorking(int, int);
    void recieveData(int, int);
signals:
    void send(int);
private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
