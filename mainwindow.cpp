#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    painter.translate(260.0, 260.0);

    painter.drawLine(0, -260, 0, 260);
    painter.drawLine(260, 0, -260, 0);

    if(choize == 1)
    {
    int a = ui->spinBox->text().toInt();
    int b = ui->spinBox_2->text().toInt();
    int c = ui->spinBox_3->text().toInt();
    int d = ui->spinBox_4->text().toInt();
    for(int i = -240; i < 241; i++)
        {
            painter.drawLine(i, ((i * i * i * a) + (i * i * b) + (i * c) + d) * (-1), i + 1, (((i + 1) * (i + 1) * (i + 1) * a) + ((i + 1) * (i + 1) * b) + ((i + 1) * c) + d) * (-1));
        }
    }

    if(choize == 2)
    {
    int e = ui->spinBox_5->text().toInt();
    int f = ui->spinBox_6->text().toInt();
    int g = ui->spinBox_7->text().toInt();
    for(int i = -240; i < 241; i++)
        {
            painter.drawLine(i, ((i * i * e + i * f + g) * (-1)), i + 1, ((i + 1) * (i + 1) * e + (i + 1) * f + g) * (-1));
        }
    }

    if(choize == 3)
    {
    int h = ui->spinBox_8->text().toInt();
    int j = ui->spinBox_9->text().toInt();
    for(int i = -240; i < 241; i++)
        {
                painter.drawLine(-240, ((-240 * h + j) * (-1)), 240, ((240 * h + j) * (-1)));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::push()
{
    update();
}

void MainWindow::on_pushButton_clicked()
{
    choize = 1;
    push();
}

void MainWindow::on_pushButton_2_clicked()
{
    choize = 2;
    push();
}

void MainWindow::on_pushButton_3_clicked()
{
    choize = 3;
    push();
}

void MainWindow::on_pushButton_4_clicked()
{
    choize = 0;
    push();
}
