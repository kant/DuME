#ifndef QUEUEWIDGET_H
#define QUEUEWIDGET_H

#include "ui_queuewidget.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "uiinputwidget.h"
#include "uioutputwidget.h"

class UIQueueWidget : public QWidget, private Ui::QueueWidget
{
    Q_OBJECT

public:
    explicit UIQueueWidget(FFmpeg *ff, QWidget *parent = nullptr);
    MediaInfo *getInputMedia();
    QList<MediaInfo *> getOutputMedia();
    void addInputFile(QString file);
    void addInputFile(QUrl file);

signals:
    /**
     * @brief console general messages to be displayed in the UI by MainWindow
     */
    void consoleEmit( QString );

public slots:
    void presetsPathChanged(QString path);

private slots:
    void on_outputTab_tabCloseRequested(int index);
    void on_outputTab_tabBarClicked(int index);
    void consoleReceive(QString log);

private:
    FFmpeg *ffmpeg;
    QSettings _settings;

    QList<UIOutputWidget*> outputWidgets;
    QList<UIInputWidget*> inputWidgets;

    void addOutput();

};

#endif // QUEUEWIDGET_H