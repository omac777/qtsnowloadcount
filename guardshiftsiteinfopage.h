#ifndef GUARDSHIFTSITEINFOPAGE_H
#define GUARDSHIFTSITEINFOPAGE_H
#include <QTime>
#include <QTimeEdit>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QRadioButton>
#include <QWizardPage>
#include "wizdata.h"

class GuardShiftSiteInfoPage : public QWizardPage
{
    Q_OBJECT
public:
    GuardShiftSiteInfoPage(QWidget *parent = 0, WizData *tmpWizData = 0);
    int nextId() const;
    bool validatePage();
    QString getLocationSelected();
    QString getCountForItemType();
    void debugPageFields();

signals:
    
public slots:

private:
    WizData *wizData;
    QString logFileName;
    QString logtimeDisplayFormat;
    QString logdateDisplayFormat;
    QString timeDisplayFormat;
    QTime shiftStartTime;
    QTimeEdit *shiftStartTimeEdit;
    QTime shiftEndTime;
    QTimeEdit *shiftEndTimeEdit;
    QDate shiftDateStart;
    QString dateDisplayFormat;
    QDate shiftStartDate;
    QDateEdit *shiftStartDateEdit;
    QLineEdit *guardNameLineEdit;
    QLineEdit *guardLicenceNumberLineEdit;
    QLineEdit *guardShiftCommentsLineEdit;
    //radiobuttons for location(conroy, michael strandherd, innes, clyde)
    QRadioButton *conroyRadio;
    QRadioButton *michaelRadio;
    QRadioButton *strandherdRadio;
    QRadioButton *innesRadio;
    QRadioButton *clydeRadio;
    //radiobuttons for Load Count Sheet Target(passes, tickets)
    QRadioButton *passesRadio;
    QRadioButton *ticketsRadio;
};

#endif // GUARDSHIFTSITEINFOPAGE_H
