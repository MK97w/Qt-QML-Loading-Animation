#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl("qrc:/loadingAnimation.qml"));
    ui->quickWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //ui->quickWidget->show();
    //QString program = "C:/WINDOWS/system32/cmd.exe";
    QProcess *childProcess = new QProcess;
    QString program = "cmd.exe";
    childProcess->startDetached(program);
    //childProcess->waitForFinished();
    //qDebug()<<"output: "<<qb_data;
    childProcess->write("python\r\n");
   // QByteArray qb_data = childProcess->readAll();
    childProcess->write("2+2\r\n");
    long long i = 100'000'000;
    while( i>0)
    {
        i--;
    }
    QByteArray qb_data = childProcess->readAll();
    qDebug()<<"output: "<<qb_data;
}

