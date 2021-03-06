#include "uisplashscreen.h"

UISplashScreen::UISplashScreen(const QPixmap &pixmap, Qt::WindowFlags f) : QSplashScreen (pixmap,f)
{

}

void UISplashScreen::newMessage(QString message, LogUtils::LogType lt)
{
    if (lt == LogUtils::Debug) return;
    QString m = "DuMedia Encoder v";
    m += APPVERSION;
    m += "\n";
    showMessage(m + message, Qt::AlignBottom, Qt::black);
    qDebug() << message;
}
