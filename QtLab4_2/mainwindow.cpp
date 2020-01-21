#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&thread, &QThread::started, &_stream, &stream::run);
    connect(&_stream, &stream::finished, &thread, &QThread::terminate);
    _stream.moveToThread(&thread);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(int interval, bool status, int numberPlane, bool UpOrDown)
{
    switch (status)
    {
    case 0:
        OutputInfoAdd += "Номер самолета: " + QString::number(numberPlane) + "Время прибытия: " +  QString::number(interval) + '\n';
        ui->turn->setPlainText(OutputInfoAdd);
        break;
    case 1:
        if(UpOrDown)
        {
            OutputInfoDel = "Самолет №" + QString::number(numberPlane) + "Успешно прибыл в: " +  QString::number(interval);
            ui->output->setPlainText(OutputInfoDel);
        }
        else
        {
            OutputInfoDel = "Самолет №" + QString::number(numberPlane) + "Успешно покинул в: " +  QString::number(interval);
            ui->output->setPlainText(OutputInfoDel);
        }
        break;

    }
}





void MainWindow::on_start_clicked()
{
    connect(&_stream, &stream::send, this, &MainWindow::update);
    _stream.setCount(ui->countPlane->value());
    _stream.setInterval(ui->interval->value());
    _stream.setRunning(true);
    thread.start();
}


void MainWindow::on_stop_clicked()
{
    _stream.setRunning(false);
}
