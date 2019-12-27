#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include "myclass.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:

    void update(int);
    void on_pushButton_clicked();

signals:
    void sendData(int str);
    void sendGlobalVar(int);


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H