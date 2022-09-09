#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QThread>
#include <QMessageBox>
#include <QValidator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> LineEdit_Turkce_D -> setValidator(new QIntValidator(0, 40, this));
    ui -> LineEdit_Turkce_Y -> setValidator(new QIntValidator(0, 40, this));

    ui -> LineEdit_Sosyal_Bilimler_D -> setValidator(new QIntValidator(0, 20, this));
    ui -> LineEdit_Sosyal_Bilimler_Y -> setValidator(new QIntValidator(0, 20, this));

    ui -> LineEdit_Matematik_D -> setValidator(new QIntValidator(0, 40, this));
    ui -> LineEdit_Matematik_Y -> setValidator(new QIntValidator(0, 40, this));

    ui -> LineEdit_Fen_Bilimleri_D -> setValidator(new QIntValidator(0, 20, this));
    ui -> LineEdit_Fen_Bilimleri_Y -> setValidator(new QIntValidator(0, 20, this));

    ui -> LineEdit_Turkce_NET -> setReadOnly(true);
    ui -> LineEdit_Sosyal_Bilimler_NET -> setReadOnly(true);
    ui -> LineEdit_Matematik_NET -> setReadOnly(true);
    ui -> LineEdit_Fen_Bilimleri_NET -> setReadOnly(true);

    ui -> ProgressBar -> setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_Calculation_clicked()
{
    QString Turkce_D_String = ui -> LineEdit_Turkce_D -> text();
    Turkce_D = Turkce_D_String.toInt();
    QString Turkce_Y_String = ui -> LineEdit_Turkce_Y -> text();
    Turkce_Y = Turkce_Y_String.toInt();

    QString Sosyal_Bilimler_D_String = ui -> LineEdit_Sosyal_Bilimler_D -> text();
    Sosyal_Bilimler_D = Sosyal_Bilimler_D_String.toInt();
    QString Sosyal_Bilimler_Y_String = ui -> LineEdit_Sosyal_Bilimler_Y -> text();
    Sosyal_Bilimler_Y = Sosyal_Bilimler_Y_String.toInt();

    QString Matematik_D_String = ui -> LineEdit_Matematik_D -> text();
    Matematik_D = Matematik_D_String.toInt();
    QString Matematik_Y_String = ui -> LineEdit_Matematik_Y -> text();
    Matematik_Y = Matematik_Y_String.toInt();

    QString Fen_Bilimleri_D_String = ui -> LineEdit_Fen_Bilimleri_D -> text();
    Fen_Bilimleri_D = Fen_Bilimleri_D_String.toInt();
    QString Fen_Bilimleri_Y_String = ui -> LineEdit_Fen_Bilimleri_Y -> text();
    Fen_Bilimleri_Y = Fen_Bilimleri_Y_String.toInt();

    ui -> ProgressBar -> setValue(0);
    ui -> ProgressBar -> setVisible(true);

    for(int i = ui -> ProgressBar -> value(); i <= 100; i++)
    {
        switch(i)
        {
            case 25 :
            {
                ui -> LineEdit_Turkce_NET -> setText(QString::number(Turkce_D - (Turkce_Y / 4)));
                break;
            }
            case 50 :
            {
                ui -> LineEdit_Sosyal_Bilimler_NET -> setText(QString::number(Sosyal_Bilimler_D - (Sosyal_Bilimler_Y / 4)));
                break;
            }
            case 75 :
            {
                ui -> LineEdit_Matematik_NET -> setText(QString::number(Matematik_D - (Matematik_Y / 4)));
                break;
            }
            case 100 :
            {
                ui -> LineEdit_Fen_Bilimleri_NET -> setText(QString::number(Fen_Bilimleri_D - (Fen_Bilimleri_Y / 4)));
                break;
            }
        }

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

    QMessageBox::information(this, "Bilgilendirme Mesajı", "Hesaplama Tamamlandı.");
    ui -> ProgressBar -> setVisible(false);
}
