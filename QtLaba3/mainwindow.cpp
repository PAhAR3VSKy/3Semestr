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

Polynomial getData(QString String)
{
    QStringList ListString = String.split(" ", QString::SkipEmptyParts);
    Polynomial temp(ListString.size());
    for (int i = 0; i < ListString.size(); i++) {
        temp.setCoefficientf(i, ListString.at(i).toDouble());
    }
    return temp;
}

void MainWindow::on_Show_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A = getData(StringA);


    QString StringB = ui->StringB->text();
    Polynomial B = getData(StringB);

    QMessageBox::information(this, "result", A.show() + '\n' + B.show());

}



void MainWindow::on_Sum_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A = getData(StringA);


    QString StringB = ui->StringB->text();
    Polynomial B = getData(StringB);

    QMessageBox::information(this, "result", (A+B).show());
}

void MainWindow::on_subtraction_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A = getData(StringA);


    QString StringB = ui->StringB->text();
    Polynomial B = getData(StringB);

     QMessageBox::information(this, "result", (A-B).show());
}

void MainWindow::on_mult_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A = getData(StringA);


    QString StringB = ui->StringB->text();
    Polynomial B = getData(StringB);

    QMessageBox::information(this, "result", (A*B).show());
}

void MainWindow::on_division_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A = getData(StringA);


    QString StringB = ui->StringB->text();
    Polynomial B = getData(StringB);

    QMessageBox::information(this, "result", (A/B).show());
}

void MainWindow::on_remains_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A = getData(StringA);


    QString StringB = ui->StringB->text();
    Polynomial B = getData(StringB);

    QMessageBox::information(this, "result", (A%B).show());
}

void MainWindow::on_comparison_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A = getData(StringA);


    QString StringB = ui->StringB->text();
    Polynomial B = getData(StringB);

    QMessageBox::information(this, "result", (A<B));
}



void MainWindow::on_palindrome_clicked()
{
    QString StringA = ui->StringA->text();
    Polynomial A = getData(StringA);


    QString StringB = ui->StringB->text();
    Polynomial B = getData(StringB);

    QMessageBox::information(this, "result", A.palindrome()+'\n'+B.palindrome());

}
