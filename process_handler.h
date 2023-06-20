#ifndef PROCESS_HANDLER_H
#define PROCESS_HANDLER_H

#include <QObject>
#include <QProcess>
/*
 * This work is based on voidrealms' Qprocess Ping example qt5dp-16-1
 */

class process_handler : public QObject
{
    Q_OBJECT
public:
    explicit process_handler(QObject *parent = nullptr);

signals:
    void output(QString data);

public slots:
    void start();
    void stop();

private slots:
    void errorOccurred(QProcess::ProcessError error);
    void finished(int exitCode, QProcess::ExitStatus exitStatus);
    void readyReadStandardError();
    void readyReadStandardOutput();
    void started();
    void stateChanged(QProcess::ProcessState newState);
    void readyRead();


private:
    QProcess m_process;
    QString m_address;
    bool m_listening;
    QString getProcess();
    void startPing();

signals:

};

#endif // PROCESS_HANDLER_H
