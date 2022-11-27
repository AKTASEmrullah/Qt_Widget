#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QListWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> LineEdit_Number_1 -> setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui -> LineEdit_Number_2 -> setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_clicked()
{
    ui -> ListWidget -> clear();

    QString Number;
    Number = ui -> LineEdit_Number_1 -> text();
    int Number_1 = Number.toInt();
    Number = ui -> LineEdit_Number_2 -> text();
    int Number_2 = Number.toInt();

    if(Number_1 > Number_2)
    {
        QMessageBox::warning(this, "UYARI", "1. Sayı 2. Sayıdan Büyük Olamaz!");
    }

    int Increase = 0;

    for(int i = Number_1; i < Number_2; i++)
    {
        if(i == 1)
        {
            continue;
        }

        Increase = 0;

        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                Increase++;
            }
        }

        if(Increase == 0)
        {
            QListWidgetItem *ListWidgetItem = new QListWidgetItem(QString::number(i));
            ui -> ListWidget -> addItem(ListWidgetItem);
        }
    }
}
