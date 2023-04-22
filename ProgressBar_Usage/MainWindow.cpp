#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QThread>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> ProgressBar -> setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_clicked()
{
    for(int i = 0; i < 101; i++)
    {
        ui -> ProgressBar -> setValue(i);

        switch(qrand() % 5)
        {
            case 0 :
            {
                QThread::msleep(100);
            }
            case 1 ... 4 :
            {
                switch(qrand() % 2)
                {
                    case 0 :
                    {
                        QThread::msleep(10);
                    }
                    case 1 :
                    {
                        QThread::usleep(100);
                    }
                }
            }
        }
    }

    QMessageBox::information(this, "Bilgilendirme Mesajı", "İndirme Tamamlandı");
}
