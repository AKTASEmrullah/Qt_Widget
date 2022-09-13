#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <math.h>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int Width = ui -> Label -> width();
    int Height = ui -> Label -> height();

    QPixmap Pixmap(Width, Height);
    QPainter Painter(&Pixmap);

    Pixmap.fill(QColor(227, 10, 23));
    Painter.setBrush(QColor(255, 255, 255));
    Painter.setPen(QPen(QColor(255, 255, 255)));

    QPainterPath Path_Moon;
    Path_Moon.addEllipse(150, 125, 125, 125);
    Painter.drawPath(Path_Moon);

    Painter.setBrush(QColor(227, 10, 23));
    Painter.setPen(QPen(QColor(227, 10, 23)));

    QPainterPath Path_Moon_2;
    Path_Moon_2.addEllipse(165, 129.5, 115, 115);
    Painter.drawPath(Path_Moon_2);

    Painter.setBrush(QColor(255, 255, 255));
    Painter.setPen(QPen(QColor(255, 255, 255)));

    QPainterPath Path_Star;
    Path_Star.setFillRule(Qt::WindingFill);

    Path_Star.moveTo(280, 180);

    for(int i = 1; i < 5; i++)
    {
        Path_Star.lineTo(325 - 40 * cos(0.8 * i * M_PI), 180 - 40 * sin(0.8 * i * M_PI));
    }

    Path_Star.closeSubpath();
    Painter.drawPath(Path_Star);

    ui -> Label -> setPixmap(Pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}
