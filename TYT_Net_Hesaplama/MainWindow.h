#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    double Turkce_D, Turkce_Y;
    double Sosyal_Bilimler_D, Sosyal_Bilimler_Y;
    double Matematik_D, Matematik_Y;
    double Fen_Bilimleri_D, Fen_Bilimleri_Y;

private slots:
    void on_PushButton_Calculation_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
