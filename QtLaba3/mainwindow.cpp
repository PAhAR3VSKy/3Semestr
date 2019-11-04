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
}




void MainWindow::on_Show_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A(StringA.size()/2);
    QStringList parts = StringA.split(' ');
    for (int i = 0;i< StringA.size();i++) {
        A.setCoefficientf(i, parts[i].toDouble());
    }
    std::cout << A;
}
