#include "widgett.h"
#include "ui_widgett.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

Widgett::Widgett(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widgett)
{
    ui->setupUi(this);
    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout;
    mOptions = new QMenu("Options",this);
    mEnterAction = new      QAction("Entrer",this);
    mStop = new QAction("Stop",this);
    mCapturer = new QAction("Captuer",this);
    mOptions->addActions({mEnterAction,mStop,mCapturer});
    ui->options->setMenu(mOptions);
mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);
    connect(mEnterAction, &QAction::triggered, [&](){
        mCamera->start();
    });
    connect(mStop, &QAction::triggered, [&](){
            mCamera->stop();
    });


    connect(mCapturer, &QAction::triggered, [&](){
        auto filename = QFileDialog::getSaveFileName(this, "Capture","/","Image(*.jpg;*.jpeg)");
        if(filename.isEmpty()){
                return;}
        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600,1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    });


}

Widgett::~Widgett()
{
    delete ui;
}
