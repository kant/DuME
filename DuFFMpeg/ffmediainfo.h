#ifndef MEDIAINFO_H
#define MEDIAINFO_H

#include "ffobject.h"

#include <QRegularExpression>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "ffcodec.h"
#include "ffmuxer.h"

class FFMediaInfo : public FFObject
{
    Q_OBJECT
public:
    explicit FFMediaInfo(QString ffmpegOutput = "",QObject *parent = nullptr);

    /**
     * @brief The unit used for bitrates
     */
    enum BitrateUnit { Bits, Kbps, Mbps};
    Q_ENUM(BitrateUnit)

    /**
     * @brief The unit used for sizes
     */
    enum SizeUnit { Bytes, KB, MB};
    Q_ENUM(SizeUnit)

    //setters
    void setMuxer(FFMuxer *muxer);
    void updateInfo(QString ffmpegOutput);
    void setContainer(QStringList container);
    void setVideoWidth(int width);
    void setVideoHeight(int height);
    void setVideoFramerate(double fps);
    void setAudioSamplingRate(int sampling);
    void setDuration(double duration);
    void setFileName(QString fileName);
    void setVideoCodec(FFCodec *codec);
    void setAudioCodec(FFCodec *codec);
    void setVideoBitrate(double bitrate, BitrateUnit unit = Bits);
    void setAudioBitrate(double bitrate, BitrateUnit unit = Bits);
    void setSize(double size, SizeUnit unit = Bytes);
    void setFFmpegOptions(QStringList options);
    void setVideo(bool video = true);
    void setAudio(bool audio = true);
    void addFFmpegOption(QString option);
    void removeFFmpegOpstion(QString option);
    void clearFFmpegOptions();
    //getters
    FFMuxer *muxer() const;
    int videoWidth();
    int videoHeight();
    double videoFramerate();
    int audioSamplingRate();
    double duration();
    QString ffmpegOutput();
    QString fileName();
    FFCodec *videoCodec();
    FFCodec *audioCodec();
    double audioBitrate(BitrateUnit unit = Bits);
    double videoBitrate(BitrateUnit unit = Bits);
    double size(SizeUnit unit = Bytes);
    QStringList ffmpegOptions();
    bool hasVideo();
    bool hasAudio();
    bool isImageSequence();
    QStringList extensions() const;

    //utils
    QJsonDocument exportToJson();
    void exportToJson(QFile jsonFile);
    void loadJson(QString json);
    void loadJson(QFile jsonFile);


signals:

public slots:

private:
    QString _duFFmpegVersion;
    QStringList _extensions;
    FFMuxer *_muxer;
    double _duration;
    int _size;
    bool _video;
    bool _audio;
    bool _imageSequence;
    FFCodec *_videoCodec;
    int _videoWidth;
    int _videoHeight;
    double _videoFramerate;
    int _videoBitrate;
    FFCodec *_audioCodec;
    int _audioSamplingRate;
    int _audioBitrate;
    QString _ffmpegOutput;
    QString _fileName;
    QStringList _ffmpegOptions;

};

#endif // MEDIAINFO_H
