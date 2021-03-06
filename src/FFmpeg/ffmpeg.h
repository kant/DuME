#ifndef FFMPEG_H
#define FFMPEG_H

#include <QSettings>
#include <QObject>
#include <QDir>
#include <QtDebug>

#include "Renderer/abstractrendererinfo.h"

#include "utils.cpp"

#include "ffcodec.h"
#include "ffmuxer.h"
#include "ffpixformat.h"

class FFmpeg : public AbstractRendererInfo
{
    Q_OBJECT
public:
    /**
     * @brief FFmpeg Constructs the FFmpeg manager. Note: This constructor does not initializes ffmpeg, you have to run init() before using it.
     * @param path The path to the FFmpeg binary executable
     * @param parent The parent QObject
     */
    explicit FFmpeg(QString path = "", QObject *parent = nullptr);
    ~FFmpeg();

    /**
     * @brief getMuxers Gets the list of available muxers
     * @return
     */
    QList<FFMuxer *> muxers();
    /**
     * @brief getMuxer Retrieves a muxer with its name
     * @param name
     * @return
     */
    FFMuxer *muxer(QString nameOrExtension);
    /**
     * @brief getMuxerDefaultCodec Checks what is the default codec for this muxer
     * @param muxer
     * @param ability
     * @return
     */
    FFCodec *muxerDefaultCodec(FFMuxer *muxer, FFCodec::Ability ability = FFCodec::Video);
    /**
     * @brief getMuxerDefaultCodec Checks what is the default codec for this muxer
     * @param name The name of the muxer
     * @param ability
     * @return
     */
    FFCodec *muxerDefaultCodec(QString name, FFCodec::Ability ability = FFCodec::Video);
    /**
     * @brief getEncoders Gets the list of encoders supported the current version of FFmpeg
     * @return The codec list
     */
    QList<FFCodec *> encoders();
    /**
     * @brief getVideoEncoders Gets the list of video encoders supported by the current version of FFmpeg
     * @return The video codec list
     */
    QList<FFCodec *> videoEncoders();
    /**
     * @brief getVideoEncoders Gets the list of audio encoders supported by the current version of FFmpeg
     * @return The audio codec list
     */
    QList<FFCodec *> audioEncoders();
    /**
     * @brief getInputPixFormats Gets the list of input pixel formats supported by the current version of FFmpeg
     * @return The pixel formats list
     */
    QList<FFPixFormat *> pixFormats();
    /**
     * @brief getCodec Gets a video encoder using its name
     * @param name The name of the codec
     * @return A pointer to the codec
     */
    FFCodec *videoEncoder(QString name);
    /**
     * @brief getCodec Gets an audio encoder using its name
     * @param name The name of the codec
     * @return A pointer to the codec
     */
    FFCodec *audioEncoder(QString name);
    /**
     * @brief getPixFormat Gets a pixel format using its name
     * @param name The name of the pixel format
     * @return A pointer to the pixel format
     */
    FFPixFormat *pixFormat(QString name);
    /**
     * @brief getHelp Gets the help text of FFmpeg
     * @return The documentation
     */
    QString help();
    /**
     * @brief getLongHelp Gets the longer help of FFmpeg
     * @return The longer version of the documentation
     */
    QString longHelp();
    /**
     * @brief analyseMedia Gets the information for the media
     * @param mediaPath The path to the media file
     * @return The information returned by FFmpeg
     */
    QString analyseMedia(QString mediaPath);
    /**
     * @brief getVersion Gets the current ffmpeg version
     * @return
     */
    QString version() const;
    /**
     * @brief status The current FFmpeg Status
     * @return
     */
    MediaUtils::Status status() const;

public slots:
    /**
     * @brief setBinaryFileName Sets the path to the FFmpeg binary
     * @param path The path to the binary executable file
     * @return true if the exe is found
     */
    bool setBinary(QString path, bool initialize = true);
    void init();

private:

    // === ATTRIBUTES ===

    QSettings settings;
    // The ffmpeg version
    QString _version;

    // The list of video encoders
    QList<FFCodec *> _videoEncoders;
    // The list of audio encoders
    QList<FFCodec *> _audioEncoders;
    // The list of video decoders
    QList<FFCodec *> _videoDecoders;
    // The list of audio decoders
    QList<FFCodec *> _audioDecoders;
    // The list of muxers
    QList<FFMuxer *> _muxers;
    // The list of pixel formats
    QList<FFPixFormat *> _pixFormats;
    // The help
    QString _help;
    // The documentation
    QString _longHelp;

    //=== Process outputs ===
    /**
     * @brief ffmpeg_gotVersion Parses the version
     * @param output The output of the FFmpeg process with the muxers list
     */
    QString gotVersion(QString output);
    /**
     * @brief ffmpeg_gotCodecs Parses the muxers list
     * @param output The output of the FFmpeg process with the muxers list
     * @param newVersion The version of ffmpeg from which tt output comes from
     */
    void gotMuxers(QString output, QString newVersion);
    /**
     * @brief ffmpeg_gotCodecs Parses the codec list
     * @param output The output of the FFmpeg process with the codecs list
     * @param newVersion The version of ffmpeg from which tt output comes from
     */
    void gotCodecs(QString output, QString newVersion);
    /**
     * @brief ffmpeg_gotPixFormats Parses the pix formats list
     * @param output The output of the FFmpeg process with the codecs list
     * @param newVersion The version of ffmpeg from which tt output comes from
     */
    void gotPixFormats(QString output, QString newVersion);

};

#endif // FFMPEG_H
