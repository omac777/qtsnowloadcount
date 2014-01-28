#include "snowloadcountmw.h"
#include "ui_snowloadcountmw.h"

SnowLoadCountmw::SnowLoadCountmw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SnowLoadCountmw)
{
    ui->setupUi(this);
}

SnowLoadCountmw::~SnowLoadCountmw()
{
    delete ui;
}

void SnowLoadCountmw::showExpanded()
{
    wizard.show();
    wizard.setFocus();
}
