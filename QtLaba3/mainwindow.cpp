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

    QStringList nameOperation = {"Вывод множеств", "Сумма", "Разность", "Умножение", "Деление", "Остаток", "Сравнение", "Палиндром"};

    ui->examp1->setPixmap(pix1.scaled(225, 60, Qt::KeepAspectRatio));
    ui->examp2->setPixmap(pix2.scaled(225, 60, Qt::KeepAspectRatio));
    for (int i = 0; i < nameOperation.size() ; i++) {
        ui->comboBox->addItem(nameOperation.at(i));
    }



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

void ShowWindow(QString StringA, QString StringB)
{

    Polynomial A = getData(StringA);



    Polynomial B = getData(StringB);

    QMessageBox::information( nullptr, "result", A.show() + '\n' + B.show());

}



void Sum(QString StringA, QString StringB)
{

    Polynomial A = getData(StringA);



    Polynomial B = getData(StringB);

    QMessageBox::information(nullptr, "result", (A+B).show());
}

void Subtraction(QString StringA, QString StringB)
{

    Polynomial A = getData(StringA);



    Polynomial B = getData(StringB);

     QMessageBox::information(nullptr, "result", (A-B).show());
}

void Mult(QString StringA, QString StringB)
{
    Polynomial A = getData(StringA);



    Polynomial B = getData(StringB);

     QMessageBox::information(nullptr, "result", (A*B).show());
}

void Division(QString StringA, QString StringB)
{
    Polynomial A = getData(StringA);



    Polynomial B = getData(StringB);

     QMessageBox::information(nullptr, "result", (A/B).show());
}

void Remains(QString StringA, QString StringB)
{
    Polynomial A = getData(StringA);



    Polynomial B = getData(StringB);

     QMessageBox::information(nullptr, "result", (A%B).show());
}

void Comparison(QString StringA, QString StringB)
{
    Polynomial A = getData(StringA);



    Polynomial B = getData(StringB);

     QMessageBox::information(nullptr, "result", (A<B));
}



void Palindrome(QString StringA, QString StringB)
{
    Polynomial A = getData(StringA);



    Polynomial B = getData(StringB);

     QMessageBox::information(nullptr, "result", A.palindrome()+'\n'+B.palindrome());

}

void MainWindow::on_Input_clicked()
{
    int choice = ui->comboBox->currentIndex();
    QString StringA = ui->StringA->text();
    QString StringB = ui->StringB->text();
    switch (choice) {
    case 0: ShowWindow(StringA, StringB);
        break;
    case 1: Sum(StringA, StringB);
        break;
    case 2: Subtraction(StringA, StringB);
        break;
    case 3: Mult(StringA, StringB);
        break;
    case 4: Division(StringA, StringB);
        break;
    case 5: Remains(StringA, StringB);
        break;
    case 6: Comparison(StringA, StringB);
        break;
    case 7: Palindrome(StringA, StringB);
        break;

    }
}
