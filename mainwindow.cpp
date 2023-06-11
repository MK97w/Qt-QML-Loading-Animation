#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl("qrc:/loadingAnimation.qml"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    static bool show{true};
    if(show)
    {
        ui->quickWidget->show();
        show = false;
    }
    else
    {
        ui->quickWidget->hide();
        show = true;
    }

}

