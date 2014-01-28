#include <QtGui>
#include <QFormLayout>
#include <QGroupBox>
#include <QScrollArea>
#include <QScrollBar>
#include "snowloadcountwiz.h"
#include "entryitempage.h"

EntryItemPage::EntryItemPage(QWidget *parent, WizData *tmpWizData) :
    QWizardPage(parent)
{
    wizData = tmpWizData;
    setTitle(tr("Site Info"));
    timeDisplayFormat = QString("HH:mm");

    QVBoxLayout *myVboxLayout3 = new QVBoxLayout();

    myVboxLayout3->addWidget(new QLabel(tr("Counting Totals For:")));
    passesRadio = new QRadioButton(tr("&Passes"));
    ticketsRadio = new QRadioButton(tr("&Tickets"));
    QGridLayout *myHboxLayout2 = new QGridLayout();
    myHboxLayout2->addWidget(passesRadio);
    myHboxLayout2->addWidget(ticketsRadio);
    QGroupBox *countForItemTypeGroupBox = new QGroupBox(tr("Item Type"));
    countForItemTypeGroupBox->setLayout(myHboxLayout2);
    myVboxLayout3->addWidget(countForItemTypeGroupBox);
    setLayout(myVboxLayout3);
}

int EntryItemPage::nextId() const
{
    return SnowLoadCountWiz::Page_TruckTypeCount;
}

bool EntryItemPage::validatePage()
{
    wizData->countForItemType = getCountForItemType();
    return true;
}

QString EntryItemPage::getCountForItemType()
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
