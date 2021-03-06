#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include "ui_inputwidget.h"

#include "Renderer/mediainfo.h"

#include <QFileDialog>
#include <QSettings>
#include <QThread>
#include <QTime>

class UIInputWidget : public QWidget, private Ui::InputWidget
{
    Q_OBJECT

public:
    explicit UIInputWidget(FFmpeg *ff, QWidget *parent = nullptr);
    MediaInfo *getMediaInfo();
    void openFile(QString file);
    void openFile(QUrl file);

signals:
    void newMediaLoaded(MediaInfo *);

private slots:
    void on_inputBrowseButton_clicked();
    void on_addParamButton_clicked();
    void on_frameRateButton_toggled(bool checked);
    void on_frameRateBox_activated(const QString &arg1);
    void on_frameRateEdit_valueChanged(double arg1);
    void on_trcButton_toggled(bool checked);
    void on_trcBox_currentIndexChanged(int index);
    void on_inputEdit_editingFinished();
    void on_compButton_clicked();
    void on_threadsButton_toggled(bool checked);
    void on_rqindexButton_clicked();
    void on_compEdit_textEdited(const QString &arg1);
    void on_rqindexBox_valueChanged(int arg1);
    void on_aeRenderQueueButton_clicked();
    void on_threadsBox_valueChanged(int arg1);
    void on_aeRenderQueueButton_toggled(bool checked);

private:
    MediaInfo *_mediaInfo;
    QList<QLineEdit *> _customParamEdits;
    QList<QLineEdit *> _customValueEdits;
    void updateOptions();

};

#endif // INPUTWIDGET_H
