#ifndef WIDGETT_H
#define WIDGETT_H

#include <QWidget>

namespace Ui {
class Widgett;
}
class QCamera;
class  QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

class Widgett : public QWidget
{
    Q_OBJECT

public:
    explicit Widgett(QWidget *parent = nullptr);
    ~Widgett();

private:
    Ui::Widgett *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOptions;
    QAction *mEnterAction;
    QAction *mStop;
    QAction *mCapturer;
};

#endif // WIDGETT_H
