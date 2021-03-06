#ifndef ABSTRACTRENDERERINFO_H
#define ABSTRACTRENDERERINFO_H

#include <QObject>
#include <QProcess>
#include <QRegularExpression>

#include "utils.cpp"

class AbstractRendererInfo : public QObject
{
    Q_OBJECT
public:
    explicit AbstractRendererInfo(QObject *parent = nullptr);

    QString binary() const;

    QString lastErrorMessage() const;

signals:
    void newLog( QString, LogUtils::LogType lt = LogUtils::Information );
    void console( QString );
    void binaryChanged( QString binary );

public slots:
    bool setBinary( QString binary );
    /**
     * @brief runCommand Runs FFmpeg with the commands
     * @param commands The arguments, space separated. Use double quotes for any argument containing spaces
     */
    bool runCommand(QString commands, int timeout = 0, QIODevice::OpenModeFlag of = QIODevice::ReadOnly);
    /**
     * @brief runCommand Runs FFmpeg with the commands
     * @param commands The arguments
     */
    bool runCommand(QStringList commands, int timeout = 0, QIODevice::OpenModeFlag of = QIODevice::ReadOnly);

protected slots:
    void log( QString l, LogUtils::LogType lt = LogUtils::Information );
    //Binary signals
    void stdError();
    void stdOutput();
    void errorOccurred(QProcess::ProcessError e);

protected:
    // The process output
    QString _output;
    // The Status
    MediaUtils::Status _status;

private:
    QString _binary;
    // The process
    QProcess *_process;
    // The last error if any (used if the error happens before signals could be connected)
    QString _lastErrorMessage;

    void readyRead(QString output);
};

#endif // ABSTRACTRENDERERINFO_H
