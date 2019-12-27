#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(int i)
{

    ui->plainTextEdit->setPlainText(QString::number(i));
}



void MainWindow::on_pushButton_clicked()
{
    QThread *thread = new QThread;
    MyClass *my = new MyClass("a");

    my->moveToThread(thread);


    connect(my, SIGNAL(send(int)), this, SLOT(update(int)));
    connect(thread, SIGNAL(started()), my, SLOT(doWork()));
    //connect(this, SIGNAL(sendGlobalVar(int)), my, SLOT(receiveGlobalVar(int)), Qt::DirectConnection);
    //emit sendGlobalVar(7);
    thread->start();

}


