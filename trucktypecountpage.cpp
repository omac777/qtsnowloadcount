#include <QtGui>
#include <QGridLayout>
#include "snowloadcountwiz.h"
#include "trucktypecountpage.h"

TruckTypeCountPage::TruckTypeCountPage(QWidget *parent, WizData *tmpWizData) :
    QWizardPage(parent)
{
    wizData = tmpWizData;
    setTitle(tr("Truck Type Count"));
    QPushButton *singleaxlebutton = new QPushButton("&1singleaxle", this);
    QPushButton *tandemaxlebutton = new QPushButton("&2tandemaxle", this);
    QPushButton *tripleaxlebutton = new QPushButton("&3tripleaxle", this);
    QPushButton *combotruckbutton = new QPushButton("&4combotruck", this);
    QPushButton *semitrailerbutton = new QPushButton("&5semitrailer", this);
    connect(singleaxlebutton, SIGNAL(released()), this, SLOT(handlesingleaxle()));
    connect(tandemaxlebutton, SIGNAL(released()), this, SLOT(handletandemaxle()));
    connect(tripleaxlebutton, SIGNAL(released()), this, SLOT(handletripleaxle()));
    connect(combotruckbutton, SIGNAL(released()), this, SLOT(handlecombotruck()));
    connect(semitrailerbutton, SIGNAL(released()), this, SLOT(handlesemitrailer()));
    mysingleTotalLabel = new QLabel();
    mytandemTotalLabel = new QLabel();
    mytripleTotalLabel = new QLabel();
    mycomboTotalLabel = new QLabel();
    mysemiTotalLabel = new QLabel();
    QGridLayout *mygridlayout = new QGridLayout;
    mygridlayout->addWidget(singleaxlebutton, 0, 0 );
    mygridlayout->addWidget(mysingleTotalLabel, 0, 1);

    mygridlayout->addWidget(tandemaxlebutton, 1, 0);
    mygridlayout->addWidget(mytandemTotalLabel, 1, 1);

    mygridlayout->addWidget(tripleaxlebutton, 2, 0);
    mygridlayout->addWidget(mytripleTotalLabel, 2, 1);

    mygridlayout->addWidget(combotruckbutton, 3, 0);
    mygridlayout->addWidget(mycomboTotalLabel, 3, 1);

    mygridlayout->addWidget(semitrailerbutton, 4, 0);
    mygridlayout->addWidget(mysemiTotalLabel, 4, 1);

    setLayout(mygridlayout);
}

int TruckTypeCountPage::nextId() const
{
    return SnowLoadCountWiz::Page_TruckTypeTotals;
}

bool TruckTypeCountPage::validatePage()
{
    return true;
}

void TruckTypeCountPage::handlesingleaxle()
{
    wizData->singleAxleArrived();
    mysingleTotalLabel->setText(QString::number(wizData->getSingleAxleTotal()));
}

void TruckTypeCountPage::handletandemaxle()
{
    wizData->tandemAxleArrived();
    mytandemTotalLabel->setText(QString::number(wizData->getTandemAxleTotal()));
}

void TruckTypeCountPage::handletripleaxle()
{
    wizData->tripleAxleArrived();
    mytripleTotalLabel->setText(QString::number(wizData->getTripleAxleTotal()));
}

void TruckTypeCountPage::handlecombotruck()
{
    wizData->comboTruckArrived();
    mycomboTotalLabel->setText(QString::number(wizData->getComboTruckTotal()));
}

void TruckTypeCountPage::handlesemitrailer()
{
    wizData->semiTrailerArrived();
    mysemiTotalLabel->setText(QString::number(wizData->getSemiTrailerTotal()));
}
