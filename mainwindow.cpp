#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_widgetpainter.h"
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

void Boot()
{

}
void MainWindow::on_pushButton_clicked()
{
    QString str;

    str=ui->LineEditArgs_E->text();
    ui->widget->SetE(str.toFloat());
    str=ui->LineEditArgs_I->text();
    ui->widget->SetI(str.toFloat());
    str=ui->LineEditArgs_m->text();
    ui->widget->Setm(str.toFloat());
    str=ui->lineEdit_num->text();
    ui->widget->SetNum(str.toFloat());
    str=ui->lineEdit_step->text();
    ui->widget->SetStep(str.toFloat());
    str=ui->lineEdit_xRatio->text();
    ui->widget->SetXRatio(str.toFloat());
    str=ui->lineEdit_lenth->text();
    ui->widget->SetTan(str.toFloat());


    ui->widget->repaint();
}
