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
    //ui->quickWidget->show();
    //QString program = "C:/WINDOWS/system32/cmd.exe";
    QProcess *childProcess1 = new QProcess(this);
    //QProcess *childProcess2 = new QProcess(this);
    QString program = "C:/WINDOWS/system32/cmd.exe";
    //QString program = "python";
    //childProcess->start(program);
    //QString program = "cmd.exe";
    QStringList arguments = QStringList() << "/K" << "python.exe";
    //childProcess1->setCreateProcessArgumentsModifier(
    //          [](QProcess::CreateProcessArguments *args) {
    //  args->flags |= CREATE_NEW_CONSOLE;
    //  args->startupInfo->dwFlags &=~ STARTF_USESTDHANDLES;
    //});
   // childProcess2->setStandardOutputProcess(childProcess1);
    childProcess1->start(program, arguments);
    //childProcess2->start();
    //childProcess1->waitForBytesWritten();
    //qDebug()<<"output:"<<childProcess1->readAll()<<"\n";
    //childProcess->waitForStarted();

    QProcess P2;
    P2.start("2+2");
    P2.waitForFinished(-1);
    P2.setReadChannel(QProcess::StandardOutput);
    QTextStream reade2(&P2);
    QString line2,line,Out;
    while (reade2.readLineInto(&line2))
        Out.append(line2 +'\n');
    P2.setReadChannel(QProcess::StandardError);
    QTextStream reader(&P2);
    while (reader.readLineInto(&line))
        Out.append(line +'\n');
    P2.close();
    qDebug()<<Out.trimmed();












}

