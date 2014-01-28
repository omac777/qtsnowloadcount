#ifndef ENTRYITEMPAGE_H
#define ENTRYITEMPAGE_H

#include <QTime>
#include <QTimeEdit>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QRadioButton>

#include <QWizardPage>
#include "wizdata.h"

class EntryItemPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit EntryItemPage(QWidget *parent = 0, WizData *tmpWizData = 0);
    int nextId() const;
    bool validatePage();
    QString getCountForItemType();

signals:

public slots:

private:
    WizData *wizData;
    QString logFileName;
    QString logtimeDisplayFormat;
    QString logdateDisplayFormat;
    QString timeDisplayFormat;

    //radiobuttons for Load Count Sheet Target(passes, tickets)
    QRadioButton *passesRadio;
    QRadioButton *ticketsRadio;
};

#endif // ENTRYITEMPAGE_H
