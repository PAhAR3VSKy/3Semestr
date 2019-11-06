#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include "Polynomial.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix1(":/image/Снимок.PNG");
    QPixmap pix2(":/image/Сницмок.PNG");

    ui->examp1->setPixmap(pix1.scaled(225, 60, Qt::KeepAspectRatio));
    ui->examp2->setPixmap(pix2.scaled(225, 60, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete [] mainCoef;
}








void MainWindow::on_Show_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A(StringA.size()/2);
    for (int i = 0, j = 0;i < StringA.size();i+=2, j++) {
        QString temp = StringA.at(i);
        A.setCoefficientf(j, temp.toDouble());
    }
    QMessageBox::information(this, "m", "");
    // ui->StringB->setText("123");
    // QString StringB = ui->StringB->text();
    // Polynomial A, B;
    // QMessageBox::warning(this, "m", "3");
    //QMessageBox::information(0, "m", "3");
}


