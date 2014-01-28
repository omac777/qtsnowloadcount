#ifndef SNOWLOADCOUNTWIZ_H
#define SNOWLOADCOUNTWIZ_H

#include <QWizard>
#include "wizdata.h"
#include "guardshiftpage.h"
#include "siteinfopage.h"
#include "entryitempage.h"
#include "guardshiftsiteinfopage.h"
#include "trucktypecountpage.h"
#include "trucktypetotalspage.h"

class SnowLoadCountWiz : public QWizard
{
    Q_OBJECT
public:
    //enum { Page_GuardShift, Page_SiteInfo, Page_GuardShiftSiteInfo, Page_TruckTypeCount, Page_TruckTypeTotals };
    enum { Page_GuardShift, Page_SiteInfo, Page_EntryItem, Page_TruckTypeCount, Page_TruckTypeTotals };

    SnowLoadCountWiz(QWidget *parent = 0);
    
signals:
    
public slots:
private:
    GuardShiftPage* page1;
    SiteInfoPage* page2;
    EntryItemPage* page3;
    //GuardShiftSiteInfoPage* page1;
    TruckTypeCountPage* page4;
    TruckTypeTotalsPage* page5;
    WizData* theWizData;
};

#endif // SNOWLOADCOUNTWIZ_H
