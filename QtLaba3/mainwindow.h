#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include "Polynomial.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Show_clicked();


    void on_Sum_clicked();

    void on_subtraction_clicked();

    void on_mult_clicked();

    void on_division_clicked();

    void on_comparison_clicked();

    void on_remains_clicked();

    void on_palindrome_clicked();

private:
    Ui::MainWindow *ui;
    double *mainCoef;
};
#endif // MAINWINDOW_H
