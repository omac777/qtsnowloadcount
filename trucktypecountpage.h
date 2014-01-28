#ifndef TRUCKTYPECOUNTPAGE_H
#define TRUCKTYPECOUNTPAGE_H

#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QWizardPage>
#include "wizdata.h"

class TruckTypeCountPage : public QWizardPage
{
    Q_OBJECT
public:
    TruckTypeCountPage(QWidget *parent = 0, WizData *tmpWizData = 0);
    int nextId() const;
    bool validatePage();

signals:
    
public slots:
private slots:
    void handlesingleaxle();
    void handletandemaxle();
    void handletripleaxle();
    void handlecombotruck();
    void handlesemitrailer();

private:
    WizData *wizData;
    QLabel *mysingleTotalLabel;
    QLabel *mytandemTotalLabel;
    QLabel *mytripleTotalLabel;
    QLabel *mycomboTotalLabel;
    QLabel *mysemiTotalLabel;
};

#endif // TRUCKTYPECOUNTPAGE_H
