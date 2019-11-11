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
    QStringList ListStringA = StringA.split(" ", QString::SkipEmptyParts);
    Polynomial A(ListStringA.size());
    for (int i = 0; i < ListStringA.size(); i++) {
        A.setCoefficientf(i, ListStringA.at(i).toDouble());
    }

    QString StringB = ui->StringB->text();
    QStringList ListStringB = StringB.split(" ", QString::SkipEmptyParts);
    Polynomial B(ListStringB.size());
    for (int i = 0; i < ListStringB.size(); i++) {
        B.setCoefficientf(i, ListStringB.at(i).toDouble());
    }
    QMessageBox::information(this, "result", A.show() + '\n' + B.show());

}



void MainWindow::on_Sum_clicked()
{
    QString StringA = ui->StringA->text();
    QStringList ListStringA = StringA.split(" ", QString::SkipEmptyParts);
    Polynomial A(ListStringA.size());
    for (int i = 0; i < ListStringA.size(); i++) {
        A.setCoefficientf(i, ListStringA.at(i).toDouble());
    }

    QString StringB = ui->StringB->text();
    QStringList ListStringB = StringB.split(" ", QString::SkipEmptyParts);
    Polynomial B(ListStringB.size());
    for (int i = 0; i < ListStringB.size(); i++) {
        B.setCoefficientf(i, ListStringB.at(i).toDouble());
    }

    QMessageBox::information(this, "result", (A+B).show());
}

void MainWindow::on_subtraction_clicked()
{
    QString StringA = ui->StringA->text();
    QStringList ListStringA = StringA.split(" ", QString::SkipEmptyParts);
    Polynomial A(ListStringA.size());
    for (int i = 0; i < ListStringA.size(); i++) {
        A.setCoefficientf(i, ListStringA.at(i).toDouble());
    }

    QString StringB = ui->StringB->text();
    QStringList ListStringB = StringB.split(" ", QString::SkipEmptyParts);
    Polynomial B(ListStringB.size());
    for (int i = 0; i < ListStringB.size(); i++) {
        B.setCoefficientf(i, ListStringB.at(i).toDouble());
    }

     QMessageBox::information(this, "result", (A-B).show());
}

void MainWindow::on_mult_clicked()
{
    QString StringA = ui->StringA->text();
    QStringList ListStringA = StringA.split(" ", QString::SkipEmptyParts);
    Polynomial A(ListStringA.size());
    for (int i = 0; i < ListStringA.size(); i++) {
        A.setCoefficientf(i, ListStringA.at(i).toDouble());
    }

    QString StringB = ui->StringB->text();
    QStringList ListStringB = StringB.split(" ", QString::SkipEmptyParts);
    Polynomial B(ListStringB.size());
    for (int i = 0; i < ListStringB.size(); i++) {
        B.setCoefficientf(i, ListStringB.at(i).toDouble());
    }
    (A*B).show();
    QMessageBox::information(this, "result", (A*B).show());
}

void MainWindow::on_division_clicked()
{
    QString StringA = ui->StringA->text();
    QStringList ListStringA = StringA.split(" ", QString::SkipEmptyParts);
    Polynomial A(ListStringA.size());
    for (int i = 0; i < ListStringA.size(); i++) {
        A.setCoefficientf(i, ListStringA.at(i).toDouble());
    }

    QString StringB = ui->StringB->text();
    QStringList ListStringB = StringB.split(" ", QString::SkipEmptyParts);
    Polynomial B(ListStringB.size());
    for (int i = 0; i < ListStringB.size(); i++) {
        B.setCoefficientf(i, ListStringB.at(i).toDouble());
    }
    QMessageBox::information(this, "result", (A/B).show());
}

void MainWindow::on_remains_clicked()
{
    QString StringA = ui->StringA->text();
    QStringList ListStringA = StringA.split(" ", QString::SkipEmptyParts);
    Polynomial A(ListStringA.size());
    for (int i = 0; i < ListStringA.size(); i++) {
        A.setCoefficientf(i, ListStringA.at(i).toDouble());
    }

    QString StringB = ui->StringB->text();
    QStringList ListStringB = StringB.split(" ", QString::SkipEmptyParts);
    Polynomial B(ListStringB.size());
    for (int i = 0; i < ListStringB.size(); i++) {
        B.setCoefficientf(i, ListStringB.at(i).toDouble());
    }
    (A%B).show();
    QMessageBox::information(this, "result", (A%B).show());
}

void MainWindow::on_comparison_clicked()
{
    QString StringA = ui->StringA->text();
    QStringList ListStringA = StringA.split(" ", QString::SkipEmptyParts);
    Polynomial A(ListStringA.size());
    for (int i = 0; i < ListStringA.size(); i++) {
        A.setCoefficientf(i, ListStringA.at(i).toDouble());
    }

    QString StringB = ui->StringB->text();
    QStringList ListStringB = StringB.split(" ", QString::SkipEmptyParts);
    Polynomial B(ListStringB.size());
    for (int i = 0; i < ListStringB.size(); i++) {
        B.setCoefficientf(i, ListStringB.at(i).toDouble());
    }
    QMessageBox::information(this, "result", (A<B));
}



void MainWindow::on_palindrome_clicked()
{
    QString StringA = ui->StringA->text();
    QStringList ListStringA = StringA.split(" ", QString::SkipEmptyParts);
    Polynomial A(ListStringA.size());
    for (int i = 0; i < ListStringA.size(); i++) {
        A.setCoefficientf(i, ListStringA.at(i).toDouble());
    }

    QString StringB = ui->StringB->text();
    QStringList ListStringB = StringB.split(" ", QString::SkipEmptyParts);
    Polynomial B(ListStringB.size());
    for (int i = 0; i < ListStringB.size(); i++) {
        B.setCoefficientf(i, ListStringB.at(i).toDouble());
    }

    QMessageBox::information(this, "result", A.palindrome()+'\n'+B.palindrome());

}
