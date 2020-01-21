#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "stream.h"
#include "queue.h"

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
    void update(int, bool, int, bool);
    void on_start_clicked();
    void on_stop_clicked();

signals:

private:
    Ui::MainWindow *ui;
    QThread thread;
    stream _stream;
    QStringList OutputInfoAdd;
    QString OutputInfoDel;
};
#endif // MAINWINDOW_H
