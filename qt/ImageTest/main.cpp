#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QElapsedTimer>
#include <QImage>
#include <QImageReader>
#include <QFile>
#include <QFileInfo>
#include <QDir>

void image_png_test()
{
    qDebug() << "----------" << __func__ << "----------";

    QString source(":/ENM_BG001_TS.png");
    QImage png;
    QElapsedTimer timer;
    timer.start();
    png.load(source);
    qDebug() << source << timer.elapsed();
}

void image_bmp_test()
{
    qDebug() << "----------" << __func__ << "----------";

    QString source(":/ENM_BG001_TS.bmp");
    QImage bmp;
    QElapsedTimer timer;
    timer.start();
    bmp.load(source);
    qDebug() << source << timer.elapsed();
}

void image_png2bmp()
{
    qDebug() << "----------" << __func__ << "----------";

    QString source(":/ENM_BG001_TS.png");
    QImage img(source);
    bool save = img.save(QString("bmp_01.bmp"), "BMP");
    qDebug() << "save" << save;
}

void image_save_bmp_test()
{
    qDebug() << "----------" << __func__ << "----------";

    QString source(":/bmp_01.bmp");
    QImage bmp;
    QElapsedTimer timer;
    timer.start();
    bmp.load(source);
    qDebug() << source << timer.elapsed();
}

void image_png_read_test()
{
    qDebug() << "----------" << __func__ << "----------";

    QString source(":/ENM_BG001_TS.png");
    QElapsedTimer timer;

    timer.start();
    QImageReader reader(source);
    qDebug() << "QImageReader" << source << timer.elapsed();

    timer.restart();
    QImage image = reader.read();
    qDebug() << "read" << source << timer.elapsed();

    timer.restart();
    image.operator=(image);
    qDebug() << "operator=" << source << timer.elapsed();
}

void image_bmp_read_test()
{
    qDebug() << "----------" << __func__ << "----------";

    QString source(":/ENM_BG001_TS.bmp");
    QElapsedTimer timer;

    timer.start();
    QImageReader reader(source);
    qDebug() << "QImageReader" << source << timer.elapsed();

    timer.restart();
    QImage image = reader.read();
    qDebug() << "read" << source << timer.elapsed();

    timer.restart();
    image.operator=(image);
    qDebug() << "operator=" << source << timer.elapsed();
}

void image_png_file_test()
{
    qDebug() << "----------" << __func__ << "----------";

    QString source(":/ENM_BG001_TS.png");
    QElapsedTimer timer;
    QFile file(source);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "QFile" << source << "open failed";
        return;
    }
    timer.start();
    file.readAll();
    qDebug() << "QFile" << source << timer.elapsed();
}

void image_bmp_file_test()
{
    qDebug() << "----------" << __func__ << "----------";

    QString source(":/ENM_BG001_TS.bmp");
    QElapsedTimer timer;
    QFile file(source);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "QFile" << source << "open failed";
        return;
    }
    timer.start();
    file.readAll();
    qDebug() << "QFile" << source << timer.elapsed();
}

void image_read_load_test()
{
    qDebug() << "----------" << __func__ << "----------";

    QElapsedTimer timer;

    QString pngSource(":/ENM_BG001_TS.png");
    QFile pngFile(pngSource);
    bool pngOpen = pngFile.open(QIODevice::ReadOnly);
    timer.start();
    QByteArray pngData = pngFile.readAll();
    qDebug() << pngSource << "QFile::readAll" << pngOpen << timer.elapsed();
    QImage pngImage;
    timer.restart();
    bool pngLoad = pngImage.loadFromData(pngData);
    qDebug() << pngSource << "QImage::loadFromData" << pngLoad << timer.elapsed();

    QString bmpSource(":/ENM_BG001_TS.bmp");
    QFile bmpFile(bmpSource);
    bool bmpOpen = bmpFile.open(QIODevice::ReadOnly);
    timer.restart();
    QByteArray bmpData = bmpFile.readAll();
    qDebug() << bmpSource << "QFile::readAll" << bmpOpen << timer.elapsed();
    QImage bmpImage;
    timer.restart();
    bool bmpLoad = bmpImage.loadFromData(bmpData);
    qDebug() << bmpSource << "QImage::loadFromData" << bmpLoad << timer.elapsed();
}

void image_read_load_test2()
{
    qDebug() << "----------" << __func__ << "----------";

    QElapsedTimer timer;

    QString pngSource("/home/hanjunjie/test/ImageTest/res/png/ENM_BG001_TS.png");
    QFile pngFile(pngSource);
    bool pngOpen = pngFile.open(QIODevice::ReadOnly);
    timer.start();
    QByteArray pngData = pngFile.readAll();
    qDebug() << pngSource << "QFile::readAll" << pngOpen << timer.elapsed();
    QImage pngImage;
    timer.restart();
    bool pngLoad = pngImage.loadFromData(pngData);
    qDebug() << pngSource << "QImage::loadFromData" << pngLoad << timer.elapsed();

    QString bmpSource("/home/hanjunjie/test/ImageTest/res/bmp/ENM_BG001_TS.bmp");
    QFile bmpFile(bmpSource);
    bool bmpOpen = bmpFile.open(QIODevice::ReadOnly);
    timer.restart();
    QByteArray bmpData = bmpFile.readAll();
    qDebug() << bmpSource << "QFile::readAll" << bmpOpen << timer.elapsed();
    QImage bmpImage;
    timer.restart();
    bool bmpLoad = bmpImage.loadFromData(bmpData);
    qDebug() << bmpSource << "QImage::loadFromData" << bmpLoad << timer.elapsed();
}

void qfileinfo_test()
{
    QElapsedTimer timer;
    timer.start();
    QFileInfo bmp(":/ENM_BG001_TS.bmp");
    qDebug() << "QFileInfo(bmp)" << timer.elapsed();
    timer.restart();
    QFileInfo png(":/ENM_BG001_TS.png");
    qDebug() << "QFileInfo(png)" << timer.elapsed();

    timer.restart();
    QString bmpS = QDir::fromNativeSeparators(":/ENM_BG001_TS.bmp");
    qDebug() << "fromNativeSeparators(bmp)" << timer.elapsed() << bmpS;

    timer.restart();
    QString pngS = QDir::fromNativeSeparators(":/ENM_BG001_TS.png");
    qDebug() << "fromNativeSeparators(png)" << timer.elapsed() << pngS;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    image_png_test();
//    image_bmp_test();
//    image_png2bmp();
//    image_save_bmp_test();
//    image_png_read_test();
//    image_bmp_read_test();
//    image_png_file_test();
//    image_bmp_file_test();
//    image_read_load_test();
//    image_read_load_test2();
    qfileinfo_test();

    return app.exec();
}
