#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QThread>
#include "myclass.h"

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();
private slots:
    void working(int);
    void update(int);
    void on_pushButton_clicked();

private:
    Ui::Form2 *ui;
    QTimer *tmr;
};

#endif // FORM2_H
