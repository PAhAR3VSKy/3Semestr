#include "secondwindow.h"
#include "ui_secondwindow.h"


SecondWindow::SecondWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer()));
    timer->start(500);

}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::timer()
{
    ui->label->setText(QTime::currentTime().toString());
}

void SecondWindow::doWorking(int count, int interval)
{
    QueueP<int> P(count);
    int i = 0;
    while(!P.IsFull())
    {
        P.Push(i+1, 1);
    }

    for (int j = 0;P.IsEmpty();j++) {
        emit send(P.Pop());
        Sleep(1000);
    }
}

void SecondWindow::recieveData(int countPlane, int interval)
{
    doWorking(countPlane, interval);
}
