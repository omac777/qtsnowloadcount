#include <QtGui>
#include <QFormLayout>
#include <QGroupBox>
#include <QScrollArea>
#include <QScrollBar>
#include "snowloadcountwiz.h"
#include "siteinfopage.h"

SiteInfoPage::SiteInfoPage(QWidget *parent, WizData *tmpWizData) :
    QWizardPage(parent)
{
    wizData = tmpWizData;
    setTitle(tr("Site Info"));
    timeDisplayFormat = QString("HH:mm");

    QVBoxLayout *myVboxLayout3 = new QVBoxLayout();
    myVboxLayout3->addWidget(new QLabel(tr("Counting At Location:")));
    conroyRadio = new QRadioButton(tr("&Conroy"));
    michaelRadio = new QRadioButton(tr("&Micheal"));
    strandherdRadio = new QRadioButton(tr("&Strandherd"));
    innesRadio = new QRadioButton(tr("&Innes"));
    clydeRadio = new QRadioButton(tr("Cl&yde"));
    QGridLayout *myHboxLayout = new QGridLayout();
    myHboxLayout->addWidget(conroyRadio, 0,0);
    myHboxLayout->addWidget(michaelRadio, 0,1);
    myHboxLayout->addWidget(strandherdRadio, 1,0);
    myHboxLayout->addWidget(innesRadio, 1,1);
    myHboxLayout->addWidget(clydeRadio, 2,0);
    QGroupBox *locationGroupBox = new QGroupBox(tr("Location"));
    locationGroupBox->setLayout(myHboxLayout);
    myVboxLayout3->addWidget(locationGroupBox);
    setLayout(myVboxLayout3);
}

int SiteInfoPage::nextId() const
{
    return SnowLoadCountWiz::Page_EntryItem;
}

bool SiteInfoPage::validatePage()
{
    wizData->countLocation = getLocationSelected();
    return true;
}

QString SiteInfoPage::getLocationSelected()
{
    QString theLocation;
    if (conroyRadio->isChecked())
    {
        theLocation = "Conroy";
    }
    else if(michaelRadio->isChecked())
    {
        theLocation = "Michael";
    }
    else if(strandherdRadio->isChecked())
    {
        theLocation = "Strandherd";
    }
    else if(innesRadio->isChecked())
    {
        theLocation = "Innes";
    }
    else if(clydeRadio->isChecked())
    {
        theLocation = "Clyde";
    }
    return (theLocation);
}
