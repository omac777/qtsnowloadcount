#include <QtGui>
#include "snowloadcountwiz.h"

SnowLoadCountWiz::SnowLoadCountWiz(QWidget *parent) : QWizard(parent)
{
    theWizData = new WizData;
    page1 = new GuardShiftPage(0, theWizData);
    setPage(Page_GuardShift, page1);

    page2 = new SiteInfoPage(0, theWizData);
    setPage(Page_SiteInfo, page2);

    page3 = new EntryItemPage(0, theWizData);
    setPage(Page_EntryItem, page3);

    //page1 = new GuardShiftSiteInfoPage(0, theWizData);
    //setPage(Page_GuardShiftSiteInfo, page1);

    page4 = new TruckTypeCountPage(0, theWizData);
    setPage(Page_TruckTypeCount, page4);

    page5 = new TruckTypeTotalsPage(0, theWizData);
    setPage(Page_TruckTypeTotals, page5);
}
