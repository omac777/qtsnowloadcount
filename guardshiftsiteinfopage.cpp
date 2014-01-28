#include <QtGui>
#include <QFormLayout>
#include <QGroupBox>
#include <QScrollArea>
#include <QScrollBar>
#include "snowloadcountwiz.h"
#include "guardshiftsiteinfopage.h"

GuardShiftSiteInfoPage::GuardShiftSiteInfoPage(QWidget *parent, WizData *tmpWizData) :
    QWizardPage(parent)
{
    wizData = tmpWizData;
    setTitle(tr("Guard Shift and Site Info"));
    timeDisplayFormat = QString("HH:mm");
    shiftStartTime = QTime::currentTime (); //QTime(23,59);
    shiftStartTimeEdit = new QTimeEdit();
    shiftStartTimeEdit->setDisplayFormat(timeDisplayFormat);
    shiftStartTimeEdit->setTime(shiftStartTime);

    shiftEndTime = QTime( QTime::currentTime().hour() + 8,QTime::currentTime().minute() ); //QTime(23,59);
    shiftEndTimeEdit = new QTimeEdit();
    shiftEndTimeEdit->setDisplayFormat(timeDisplayFormat);
    shiftEndTimeEdit->setTime(shiftEndTime);

    dateDisplayFormat = QString("dd.MM.yyyy");
    shiftStartDate = QDate::currentDate();
    shiftStartDateEdit = new QDateEdit();
    shiftStartDateEdit->setDisplayFormat(dateDisplayFormat);
    shiftStartDateEdit->setDate(shiftStartDate);

    guardNameLineEdit = new QLineEdit();
    guardLicenceNumberLineEdit = new QLineEdit();
    guardShiftCommentsLineEdit = new QLineEdit();

    QVBoxLayout *myVboxLayout3 = new QVBoxLayout();
    myVboxLayout3->addWidget(new QLabel(tr("Shift Start Time:")));
    myVboxLayout3->addWidget(shiftStartTimeEdit);
    myVboxLayout3->addWidget(new QLabel(tr("Shift End Time:")));
    myVboxLayout3->addWidget(shiftEndTimeEdit);
    myVboxLayout3->addWidget(new QLabel(tr("Shift Start Date:")));
    myVboxLayout3->addWidget(shiftStartDateEdit);
    myVboxLayout3->addWidget(new QLabel(tr("Guard Name:")));
    myVboxLayout3->addWidget(guardNameLineEdit);
    myVboxLayout3->addWidget(new QLabel(tr("Guard License #:")));
    myVboxLayout3->addWidget(guardLicenceNumberLineEdit);
    myVboxLayout3->addWidget(new QLabel(tr("Shift Comments:")));
    myVboxLayout3->addWidget(guardShiftCommentsLineEdit);

    myVboxLayout3->addWidget(new QLabel(tr("Counting At Location:")));
    conroyRadio = new QRadioButton(tr("&Conroy"));
    michaelRadio = new QRadioButton(tr("&Micheal"));
    strandherdRadio = new QRadioButton(tr("&Strandherd"));
    innesRadio = new QRadioButton(tr("&Innes"));
    clydeRadio = new QRadioButton(tr("Cl&yde"));
    QHBoxLayout *myHboxLayout = new QHBoxLayout();
    myHboxLayout->addWidget(conroyRadio);
    myHboxLayout->addWidget(michaelRadio);
    myHboxLayout->addWidget(strandherdRadio);
    myHboxLayout->addWidget(innesRadio);
    myHboxLayout->addWidget(clydeRadio);
    QGroupBox *locationGroupBox = new QGroupBox(tr("Location"));
    locationGroupBox->setLayout(myHboxLayout);
    myVboxLayout3->addWidget(locationGroupBox);

    myVboxLayout3->addWidget(new QLabel(tr("Counting Totals For:")));
    passesRadio = new QRadioButton(tr("&Passes"));
    ticketsRadio = new QRadioButton(tr("&Tickets"));
    QHBoxLayout *myHboxLayout2 = new QHBoxLayout();
    myHboxLayout2->addWidget(passesRadio);
    myHboxLayout2->addWidget(ticketsRadio);
    QGroupBox *countForItemTypeGroupBox = new QGroupBox(tr("Item Type"));
    countForItemTypeGroupBox->setLayout(myHboxLayout2);
    myVboxLayout3->addWidget(countForItemTypeGroupBox);
    setLayout(myVboxLayout3);
}

int GuardShiftSiteInfoPage::nextId() const
{
    return SnowLoadCountWiz::Page_TruckTypeCount;
}

bool GuardShiftSiteInfoPage::validatePage()
{
    logtimeDisplayFormat = QString("HHmm");
    logdateDisplayFormat = QString("ddMMyyyy");
    logFileName = "snowLoadCountLog";
    logFileName += shiftStartTimeEdit->time().toString(logtimeDisplayFormat);
    logFileName += shiftStartDateEdit->date().toString(logdateDisplayFormat);
    logFileName += ".txt";
    wizData->logFileName = logFileName;
    wizData->shiftStartTime = shiftStartTimeEdit->time().toString(logtimeDisplayFormat);
    wizData->shiftEndTime = shiftEndTimeEdit->time().toString(logtimeDisplayFormat);
    wizData->shiftStartDate = shiftStartDateEdit->date().toString(logdateDisplayFormat);
    wizData->guardName = guardNameLineEdit->text();
    wizData->guardLicenseNumber = guardLicenceNumberLineEdit->text();
    wizData->shiftComment = guardShiftCommentsLineEdit->text();
    wizData->countLocation = getLocationSelected();
    wizData->countForItemType = getCountForItemType();

    //wizData->debugDataFields();
    //open a log file "snowLoadCountLoghhmmDDMMYYYY.txt"
    //then write the guardshift and siteinfo to the log
    return true;
}

QString GuardShiftSiteInfoPage::getLocationSelected()
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

QString GuardShiftSiteInfoPage::getCountForItemType()
{
    QString theCountForItemType;
    if(passesRadio->isChecked())
    {
        theCountForItemType = "passes";
    }
    else if(ticketsRadio->isChecked())
    {
        theCountForItemType = "tickets";
    }
    return (theCountForItemType);
}

void GuardShiftSiteInfoPage::debugPageFields()
{
    qDebug() << "Log file name:" << logFileName;
    qDebug() << "Shift Start Time:" << shiftStartTimeEdit->time().toString(logtimeDisplayFormat);
    qDebug() << "Shift End Time:" << shiftEndTimeEdit->time().toString(logtimeDisplayFormat);
    qDebug() << "Shift Start Date:" << shiftStartDateEdit->date().toString(logdateDisplayFormat);
    qDebug() << "Guard Name:" << guardNameLineEdit->text();
    qDebug() << "Guard License#:" << guardLicenceNumberLineEdit->text();
    qDebug() << "Shift Comment:" << guardShiftCommentsLineEdit->text();
    qDebug() << "Location:" << getLocationSelected();
    qDebug() << "Counting totals for:" << getCountForItemType();
}
