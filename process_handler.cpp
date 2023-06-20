#include "process_handler.h"
#include "qdebug.h"
/*
 * This work is based on voidrealms' Qprocess Ping example qt5dp-16-1
 */

process_handler::process_handler(QObject *parent) : QObject(parent)
{
    connect(&m_process,&QProcess::errorOccurred,this,&process_handler::errorOccurred);
    connect(&m_process,&QProcess::readyReadStandardError,this,&process_handler::readyReadStandardError);
    connect(&m_process,&QProcess::readyReadStandardOutput,this,&process_handler::readyReadStandardOutput);
    connect(&m_process,&QProcess::started,this,&process_handler::started);
    connect(&m_process,&QProcess::stateChanged,this,&process_handler::stateChanged);
    connect(&m_process,&QProcess::readyRead,this,&process_handler::readyRead);

    //finished is overloaded...
    connect(&m_process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),this,&process_handler::finished);

    m_listening = false;
    m_address = "";
}

void process_handler::start()
{
    qInfo() << Q_FUNC_INFO;
    m_listening = true;
    m_process.start(getProcess());
}

void process_handler::stop()
{
    qInfo() << Q_FUNC_INFO;
    m_listening = false;
    m_process.close();
}

void process_handler::errorOccurred(QProcess::ProcessError error)
{
    if(!m_listening) return;
    qInfo() << Q_FUNC_INFO << error;
    emit output("Error");
}

void process_handler::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if(!m_listening) return;
    qInfo() << Q_FUNC_INFO;
    Q_UNUSED(exitCode);
    Q_UNUSED(exitStatus);
    emit output("Complete");
}

void process_handler::readyReadStandardError()
{
   if(!m_listening) return;
   qInfo() << Q_FUNC_INFO;
   QByteArray data =  m_process.readAllStandardError();
   QString message = "Standard Error: ";
   message.append(m_process.readAllStandardError());
   emit output(message);
}

void process_handler::readyReadStandardOutput()
{
    if(!m_listening) return;
    qInfo() << Q_FUNC_INFO;
    QByteArray data =  m_process.readAllStandardOutput();
    emit output(QString(data.trimmed()));
}

void process_handler::started()
{
    //Do nothing
     qInfo() << Q_FUNC_INFO;
}

void process_handler::stateChanged(QProcess::ProcessState newState)
{
    qInfo() << Q_FUNC_INFO;
    switch (newState) {
    case QProcess::NotRunning:
        emit output("Not running");
        break;
    case QProcess::Starting:
        emit output("Starting...");
        break;
    case QProcess::Running:
        emit output("Running");
        //Start the ping
        startPing();
        break;
    }
}

void process_handler::readyRead()
{
    if(!m_listening) return;
    qInfo() << Q_FUNC_INFO;
    QByteArray data = m_process.readAll().trimmed();
    qInfo() << data;
    emit output(data);
}

QString process_handler::getProcess()
{
    qInfo() << Q_FUNC_INFO;
    if(QSysInfo::productType() == "windows") return "cmd";
    if(QSysInfo::productType() == "osx") return "/bin/zsh";

    return "bash";
}

void process_handler::startPing()
{
    QByteArray command;
    command.append("ping " + m_address);
    if(QSysInfo::productType() == "windows") command.append("\r");
    command.append("\n");
    m_process.write(command);
}
