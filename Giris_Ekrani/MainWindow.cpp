#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "QMessageBox"
#include "QIntValidator"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> LineEdit_Password -> setValidator(new QIntValidator(0, 9999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PushButton_Login_clicked()
{
    if(ui -> LineEdit_Name -> text() == Name && ui -> LineEdit_Password -> text() == Password)
    {
        QMessageBox::information(this, "Bilgilendirme Mesajı", "Kullanıcı Adı ve Şifre Doğrulandı.\nGiriş Yapılıyor.");
    }
    else
    {
        QMessageBox::information(this, "Bilgilendirme Mesajı", "Kullanıcı Adı veya Şifre Hatalı.\nLütfen Tekrar Deneyin.");
    }
}

void MainWindow::on_CheckBox_Password_Visible_clicked()
{
    if(ui -> CheckBox_Password_Visible -> checkState())
    {
        ui -> LineEdit_Password -> setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui -> LineEdit_Password -> setEchoMode(QLineEdit::Password);
    }
}
