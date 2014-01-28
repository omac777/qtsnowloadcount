#ifndef SNOWLOADCOUNTMW_H
#define SNOWLOADCOUNTMW_H

#include <QtGui>
#include <QMainWindow>
#include "snowloadcountwiz.h"

namespace Ui {
class SnowLoadCountmw;
}

class SnowLoadCountmw : public QMainWindow
{
    Q_OBJECT
    
public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit SnowLoadCountmw(QWidget *parent = 0);
    ~SnowLoadCountmw();
    void showExpanded();

    
private:
    Ui::SnowLoadCountmw *ui;
    SnowLoadCountWiz wizard;
};

#endif // SNOWLOADCOUNTMW_H
