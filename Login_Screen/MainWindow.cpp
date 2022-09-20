#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "QMessageBox"
#include "QIntValidator"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> LineEdit_2 -> setValidator(new QIntValidator(0, 9999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_clicked()
{
    if(ui -> LineEdit_1 -> text() == Name && ui -> LineEdit_2 -> text() == Password)
    {
        QMessageBox::information(this, "Bilgilendirme Mesajı", "Kullanıcı Adı ve Şifre Doğrulandı.\nGiriş Yapılıyor...");
    }
    else
    {
        QMessageBox::information(this, "Bilgilendirme Mesajı", "Kullanıcı Adı veya Şifre Hatalı.\nLütfen Tekrar Deneyin.");
    }
}

void MainWindow::on_CheckBox_clicked()
{
    if(ui -> CheckBox -> checkState())
    {
        ui -> LineEdit_2 -> setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui -> LineEdit_2 -> setEchoMode(QLineEdit::Password);
    }
}
