#ifndef SITEINFOPAGE_H
#define SITEINFOPAGE_H

#include <QTime>
#include <QTimeEdit>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QRadioButton>


#include <QWizardPage>
#include "wizdata.h"

class SiteInfoPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit SiteInfoPage(QWidget *parent = 0, WizData *tmpWizData = 0);
    int nextId() const;
    bool validatePage();
    QString getLocationSelected();

signals:

public slots:

private:
    WizData *wizData;
    QString logFileName;
    QString logtimeDisplayFormat;
    QString logdateDisplayFormat;
    QString timeDisplayFormat;

    //radiobuttons for location(conroy, michael strandherd, innes, clyde)
    QRadioButton *conroyRadio;
    QRadioButton *michaelRadio;
    QRadioButton *strandherdRadio;
    QRadioButton *innesRadio;
    QRadioButton *clydeRadio;
};

#endif // SITEINFOPAGE_H
