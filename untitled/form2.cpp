#include "form2.h"
#include "ui_form2.h"

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
}

Form2::~Form2()
{
    delete ui;
}

void Form2::working(int )
{
    QThread *thread= new QThread;
   MyClass *my = new MyClass("B");

   my->moveToThread(thread);
   connect(my, SIGNAL(send(int)), this, SLOT(update(int)));
   connect(thread, SIGNAL(started()), my, SLOT(doWork(int)), Qt::DirectConnection);

   thread->start();
}

void Form2::update(int i)
{
    ui->plainTextEdit->insertPlainText(QString::number(i));
}

void Form2::on_pushButton_clicked()
{
    this->close();

}
