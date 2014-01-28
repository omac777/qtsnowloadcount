#include <QtGui>
#include <QFormLayout>
#include <QGroupBox>
#include <QScrollArea>
#include <QScrollBar>
#include "snowloadcountwiz.h"
#include "guardshiftpage.h"

GuardShiftPage::GuardShiftPage(QWidget *parent, WizData *tmpWizData) :
    QWizardPage(parent)
{
    wizData = tmpWizData;
    setTitle(tr("Guard Shift"));
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
    setLayout(myVboxLayout3);
}

int GuardShiftPage::nextId() const
{
    return SnowLoadCountWiz::Page_SiteInfo;
}

bool GuardShiftPage::validatePage()
{
    wizData->shiftStartTime = shiftStartTimeEdit->time().toString(logtimeDisplayFormat);
    wizData->shiftEndTime = shiftEndTimeEdit->time().toString(logtimeDisplayFormat);
    wizData->shiftStartDate = shiftStartDateEdit->date().toString(logdateDisplayFormat);
    wizData->guardName = guardNameLineEdit->text();
    wizData->guardLicenseNumber = guardLicenceNumberLineEdit->text();
    wizData->shiftComment = guardShiftCommentsLineEdit->text();
    return true;
}
