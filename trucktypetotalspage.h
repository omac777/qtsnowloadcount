#ifndef TRUCKTYPETOTALSPAGE_H
#define TRUCKTYPETOTALSPAGE_H

#include <QWizardPage>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>

#include "wizdata.h"

class TruckTypeTotalsPage : public QWizardPage
{
    Q_OBJECT
public:
    TruckTypeTotalsPage(QWidget *parent = 0, WizData *tmpWizData = 0);
    int nextId() const;
    bool validatePage();
    void sendSMS(QString phoneNumber, QString message);

signals:
    
public slots:
private:
    WizData *wizData;

    QLabel *lbl;
 //    Finish button sends sms/email snowLoadCountSummary to rick/gary.
//    Back buttons and Next buttons don't affect the total counts.
//    Back is expected to use to change the shift comments.
//    Next is expected to return to Finish button.
//    No corrections can be made to Truck Type count.
//    If errors were made, mention in the shift comments.
};

#endif // TRUCKTYPETOTALSPAGE_H
