#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QThread>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> ProgressBar -> setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PushButton_clicked()
{
    for(int i = ui -> ProgressBar -> value(); i <= 100; i++)
    {
        srand(time(0));

        switch(rand() % 6)
        {
            case 0 :
            {
                QThread::sleep(1);
            }
            default :
            {
                switch(rand() % 2)
                {
                    case 0 :
                    {
                        QThread::msleep(1);
                    }
                    case 1 :
                    {
                        QThread::msleep(10);
                    }
                    case 2 :
                    {
                        QThread::msleep(100);
                    }
                }
            }
        }

        ui -> ProgressBar -> setValue(i);
    }

    QMessageBox::information(this, "Bilgilendirme Mesajı", "İlerleme Tamamlandı.");
}
