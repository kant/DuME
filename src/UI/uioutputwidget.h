#ifndef OUTPUTWIDGET_H
#define OUTPUTWIDGET_H

#include "ui_outputwidget.h"

#include "Renderer/mediainfo.h"

// BLOCKS
#include "UI/Blocks/uiblockwidget.h"
#include "UI/Blocks/blockresize.h"

#include <QFileDialog>
#include <QSettings>
#include <QStringList>
#include <QMenu>

class UIOutputWidget : public QWidget, private Ui::OutputWidget
{
    Q_OBJECT

public:
    explicit UIOutputWidget(FFmpeg *ff, int id, QWidget *parent = nullptr);
    MediaInfo *getMediaInfo();
    void setMediaInfo(MediaInfo *mediaInfo);
    void updateMediaInfo();
    QString getOutputPath();

signals:
    void checkSaveOutputPath(QString, UIOutputWidget*);
    /**
     * @brief console general messages to be displayed in the UI by MainWindow
     */
    void newLog( QString, LogUtils::LogType lt = LogUtils::Information );

public slots:
    void ffmpeg_init();
    void ffmpeg_loadCodecs();
    void ffmpeg_loadMuxers();
    void ffmpeg_loadPixFmts(bool init = false);
    void newInputMedia(MediaInfo *input);
    void loadPresets();

private slots:
    void on_videoTranscodeButton_toggled(bool checked);
    void on_audioTranscodeButton_toggled(bool checked);
    void on_frameRateButton_toggled(bool checked);
    void on_samplingButton_toggled(bool checked);
    void on_outputBrowseButton_clicked();
    void on_frameRateBox_activated(const QString &arg1);
    void on_frameRateEdit_valueChanged(double arg1);
    void on_videoQualitySlider_valueChanged(int value);
    void on_videoWidthButton_valueChanged(int val);
    void on_videoHeightButton_valueChanged(int val);
    void on_videoCodecsFilterBox_currentIndexChanged();
    void on_audioCodecsFilterBox_currentIndexChanged();
    void on_addParam_clicked();
    void on_formatsBox_currentIndexChanged(int index);
    void on_formatsFilterBox_currentIndexChanged();
    void on_videoCodecButton_toggled(bool checked);
    void on_videoBitrateButton_toggled(bool checked);
    void on_videoQualityButton_toggled(bool checked);
    void on_audioCodecButton_toggled(bool checked);
    void on_audioBitrateButton_toggled(bool checked);
    void on_presetsBox_currentIndexChanged(int index);
    void on_presetsFilterBox_activated();
    void on_videoCodecsBox_currentIndexChanged();
    void on_videoProfileButton_toggled(bool checked);
    void on_videoLoopsButton_toggled(bool checked);
    void on_videoLoopsEdit_valueChanged(int arg1);
    void on_startNumberButton_clicked(bool checked);
    void on_pixFmtButton_toggled(bool checked);
    void on_audioCodecsBox_currentIndexChanged();
    void on_pixFmtFilterBox_currentIndexChanged();
    void on_alphaButton_toggled(bool checked);
    void on_samplingBox_currentIndexChanged(int index);
    void on_videoProfileBox_currentIndexChanged(int index);
    void on_startNumberEdit_valueChanged(int arg1);
    void on_pixFmtBox_currentIndexChanged(int index);
    void on_videoBitRateEdit_valueChanged(double arg1);
    void on_audioBitRateEdit_valueChanged(int arg1);
    void on_unmultButton_toggled(bool checked);

private:
    // BLOCKS
    UIBlockWidget *blockResize;

    void updateOutputExtension(QString outputPath);
    void selectDefaultVideoCodec();
    void selectDefaultAudioCodec();
    void selectDefaultPixFmt();
    void updateAudioVideoOptions();
    void addNewParam(QString name = "",QString value = "");
    void init();

    QSettings settings;
    FFmpeg *_ffmpeg;
    MediaInfo *_mediaInfo;
    QList<QLineEdit *> _customParamEdits;
    QList<QLineEdit *> _customValueEdits;

    bool _freezeUI;
    bool _loadingPreset;

    int _index;
};

#endif // OUTPUTWIDGET_H
