#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LineEdit_Celcius_editingFinished()
{
    QString Celcius = ui -> LineEdit_Celcius -> text();
    int Celcius_Number = Celcius.toInt();

    ui -> LineEdit_Kelvin -> setText(QString::number(Celcius_Number + 273));
    ui -> LineEdit_Reomur -> setText(QString::number((Celcius_Number * 4) / 5));
    ui -> LineEdit_Fahrenayt -> setText(QString::number(((Celcius_Number * 9) + 160) / 5));
}

void MainWindow::on_LineEdit_Kelvin_editingFinished()
{
    QString Kelvin = ui -> LineEdit_Kelvin -> text();
    int Kelvin_Number = Kelvin.toInt();

    ui -> LineEdit_Celcius -> setText(QString::number(Kelvin_Number - 273));
    ui -> LineEdit_Reomur -> setText(QString::number(((Kelvin_Number * 4) - 1092) / 5));
    ui -> LineEdit_Fahrenayt -> setText(QString::number(((Kelvin_Number * 9) - 2297) / 5));
}

void MainWindow::on_LineEdit_Fahrenayt_editingFinished()
{
    QString Fahrenayt = ui -> LineEdit_Fahrenayt -> text();
    int Fahrenayt_Number = Fahrenayt.toInt();

    ui -> LineEdit_Reomur -> setText(QString::number(((Fahrenayt_Number * 4) - 128) / 9));
    ui -> LineEdit_Celcius -> setText(QString::number(((Fahrenayt_Number * 5) - 160) / 9));
    ui -> LineEdit_Kelvin -> setText(QString::number(((Fahrenayt_Number * 5) + 2297) / 9));
}

void MainWindow::on_LineEdit_Reomur_editingFinished()
{
    QString Reomur = ui -> LineEdit_Reomur -> text();
    int Reomur_Number = Reomur.toInt();

    ui -> LineEdit_Celcius -> setText(QString::number((Reomur_Number * 5) / 4));
    ui -> LineEdit_Kelvin -> setText(QString::number(((Reomur_Number * 5) + 1092) / 4));
    ui -> LineEdit_Fahrenayt -> setText(QString::number(((Reomur_Number * 9) + 128) / 4));
}
