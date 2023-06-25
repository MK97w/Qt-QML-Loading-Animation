#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include "Windows.h"

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
    ui->quickWidget->show();
   // QProcess *childProcess1 = new QProcess(this);
   // QString program = "python.exe";
   // QString program = "cmd.exe";

   // QStringList arguments = QStringList()<<"-c"<<"print('Hello World!')"; //test 1

  //  QStringList  arguments = QStringList()<<"mert.py"; //test 2
//    childProcess1->setCreateProcessArgumentsModifier(
//              [](QProcess::CreateProcessArguments *args) {
//      args->flags |= CREATE_NEW_CONSOLE;
//      args->startupInfo->dwFlags &=~ STARTF_USESTDHANDLES;
//    });
    //childProcess1->setInputChannelMode( QProcess::ForwardedInputChannel );
   // childProcess1->setProcessChannelMode( QProcess::ForwardedChannels );
    //childProcess1->start( program, arguments , QIODevice::ReadWrite | QIODevice::Text );
    //childProcess1->waitForStarted();
    //childProcess1->write("2+2\n");
    //childProcess1->waitForBytesWritten();
    //childProcess1->waitForReadyRead(400000);
    //qDebug()<<"output:"<<childProcess1->readAll();
}

