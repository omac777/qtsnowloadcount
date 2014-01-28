#ifndef GUARDSHIFTPAGE_H
#define GUARDSHIFTPAGE_H

#include <QTime>
#include <QTimeEdit>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QRadioButton>

#include <QWizardPage>
#include "wizdata.h"

class GuardShiftPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit GuardShiftPage(QWidget *parent = 0, WizData *tmpWizData = 0);
    int nextId() const;
    bool validatePage();

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

#endif // GUARDSHIFTPAGE_H
