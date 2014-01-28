#include <QDebug>
#include <QFile>
#include <QTime>
#include <QDate>
#include <sstream>
#include "wizdata.h"

WizData::WizData(QObject *parent) :
    QObject(parent)
{
}

void WizData::debugDataFields()
{
    qDebug() << "Log file name:" << logFileName;
    qDebug() << "Shift Start Time:" << shiftStartTime;
    qDebug() << "Shift End Time:" << shiftEndTime;
    qDebug() << "Shift Start Date:" << shiftStartDate;
    qDebug() << "Guard Name:" << guardName;
    qDebug() << "Guard License#:" << guardLicenseNumber;
    qDebug() << "Shift Comment:" << shiftComment;
    qDebug() << "Location:" << countLocation;
    qDebug() << "Counting totals for:" << countForItemType;
    qDebug() << "single total:" << getSingleAxleTotal();
    qDebug() << "tandem total:" << getTandemAxleTotal();
    qDebug() << "triple total:" << getTripleAxleTotal();
    qDebug() << "combo total:"  << getComboTruckTotal();
    qDebug() << "semi total:" << getSemiTrailerTotal();
}

void WizData::writeStream()
{
    qDebug() << "WizData::writeStream()";
    QFile file(logFileName);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);   // we will serialize the data into the file
    out << shiftStartTime;
    out << shiftEndTime;
    out << shiftStartDate;
    out << guardName;
    out << guardLicenseNumber;
    out << shiftComment;
    out << countLocation;
    out << countForItemType;

    out << this->getSingleAxleTotal();
    QMap<QString, QString>::iterator iterSingle = truckTypeTotalMap.find(SINGLEAXLE);
    while (iterSingle != truckTypeTotalMap.end() && iterSingle.key() == SINGLEAXLE) {
        qDebug() << "single" << iterSingle.value();
        out << iterSingle.value();
        ++iterSingle;
    }

    out << this->getTandemAxleTotal();
    QMap<QString, QString>::iterator iterTandem = truckTypeTotalMap.find(TANDEMAXLE);
    while (iterTandem != truckTypeTotalMap.end() && iterTandem.key() == TANDEMAXLE) {
        qDebug() << "tandem" << iterTandem.value();
        out << iterTandem.value();
        ++iterTandem;
    }

    out << this->getTripleAxleTotal();
    QMap<QString, QString>::iterator iterTriple = truckTypeTotalMap.find(TRIPLEAXLE);
    while (iterTriple != truckTypeTotalMap.end() && iterTriple.key() == TRIPLEAXLE) {
        qDebug() << "triple" << iterTriple.value();
        out << iterTriple.value();
        ++iterTriple;
    }

    out  << this->getComboTruckTotal();
    QMap<QString, QString>::iterator iterCombo = truckTypeTotalMap.find(COMBOTRUCK);
    while (iterCombo != truckTypeTotalMap.end() && iterCombo.key() == COMBOTRUCK) {
        qDebug() << "combo" << iterCombo.value();
        out << iterCombo.value();
        ++iterCombo;
    }

    out << this->getSemiTrailerTotal();
    QMap<QString, QString>::iterator iterSemi = truckTypeTotalMap.find(SEMITRAILER);
    while (iterSemi != truckTypeTotalMap.end() && iterSemi.key() == SEMITRAILER) {
         qDebug() << "semi" << iterSemi.value();
         out << iterSemi.value();
         ++iterSemi;
    }
}

void WizData::readStream()
{
    QFile file(logFileName);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);    // read the data serialized from the file
    QString testreaddateOfArrival;
    QString testreadshiftStartTime;
    QString testreadshiftEndTime;
    QString testreadshiftStartDate;
    QString testreadguardName;
    QString testreadguardLicenseNumber;
    QString testreadshiftComment;
    QString testreadcountLocation;
    QString testreadcountForItemType;
    int testreadSingleAxleTotal;
    int testreadTandemAxleTotal;
    int testreadTripleAxleTotal;
    int testreadComboTruckTotal;
    int testreadSemiTrailerTotal;
    QMap<QString, QString> testreadtruckTypeTotalMap;

    in >> testreadshiftStartTime;
    in >> testreadshiftEndTime;
    in >> testreadshiftStartDate;
    in >> testreadguardName;
    in >> testreadguardLicenseNumber;
    in >> testreadshiftComment;
    in >> testreadcountLocation;
    in >> testreadcountForItemType;
    testreaddateOfArrival = "";
    in >> testreadSingleAxleTotal;
    for(int tc = 0; tc < testreadSingleAxleTotal; tc++)
    {
        in >> testreaddateOfArrival;
        testreadtruckTypeTotalMap.insertMulti(SINGLEAXLE, testreaddateOfArrival);
    }
    testreaddateOfArrival = "";
    in >> testreadTandemAxleTotal;
    for(int tc2 = 0; tc2 < testreadTandemAxleTotal; tc2++)
    {
        in >> testreaddateOfArrival;
        testreadtruckTypeTotalMap.insertMulti(TANDEMAXLE, testreaddateOfArrival);
    }
    testreaddateOfArrival = "";
    in >> testreadTripleAxleTotal;
    for(int tc3 = 0; tc3 < testreadTripleAxleTotal; tc3++)
    {
        in >> testreaddateOfArrival;
        testreadtruckTypeTotalMap.insertMulti(TRIPLEAXLE, testreaddateOfArrival);
    }
    testreaddateOfArrival = "";
    in >> testreadComboTruckTotal;
    for(int tc4 = 0; tc4 < testreadComboTruckTotal; tc4++)
    {
        in >> testreaddateOfArrival;
        testreadtruckTypeTotalMap.insertMulti(COMBOTRUCK, testreaddateOfArrival);
    }
    testreaddateOfArrival = "";
    in >> testreadSemiTrailerTotal;
    for(int tc5 = 0; tc5 < testreadSemiTrailerTotal; tc5++)
    {
        in >> testreaddateOfArrival;
        testreadtruckTypeTotalMap.insertMulti(SEMITRAILER, testreaddateOfArrival);
    }
}


int WizData::singleAxleArrived()
{
    ss.str( std::string() );
    ss << QDate::currentDate().toString().toStdString();
    ss << QTime::currentTime().toString().toStdString();
    ss << QDateTime::currentMSecsSinceEpoch();
    dateOfArrival = QString::fromStdString(ss.str());
    truckTypeTotalMap.insertMulti(SINGLEAXLE, dateOfArrival);
    QList<QString> values = truckTypeTotalMap.values(SINGLEAXLE);
    return values.size();
}

int WizData::tandemAxleArrived()
{
    ss.str( std::string() );
    ss << QDate::currentDate().toString().toStdString();
    ss << QTime::currentTime().toString().toStdString();
    ss << QDateTime::currentMSecsSinceEpoch();
    dateOfArrival = QString::fromStdString(ss.str());
    truckTypeTotalMap.insertMulti(TANDEMAXLE, dateOfArrival);
    QList<QString> values = truckTypeTotalMap.values(TANDEMAXLE);
    return values.size();
}

int WizData::tripleAxleArrived()
{
    ss.str( std::string() );
    ss << QDate::currentDate().toString().toStdString();
    ss << QTime::currentTime().toString().toStdString();
    ss << QDateTime::currentMSecsSinceEpoch();
    dateOfArrival = QString::fromStdString(ss.str());
    truckTypeTotalMap.insertMulti(TRIPLEAXLE, dateOfArrival);
    QList<QString> values = truckTypeTotalMap.values(TRIPLEAXLE);
    return values.size();
}

int WizData::comboTruckArrived()
{
    ss.str( std::string() );
    ss << QDate::currentDate().toString().toStdString();
    ss << QTime::currentTime().toString().toStdString();
    ss << QDateTime::currentMSecsSinceEpoch();
    dateOfArrival = QString::fromStdString(ss.str());
    truckTypeTotalMap.insertMulti(COMBOTRUCK, dateOfArrival);
    QList<QString> values = truckTypeTotalMap.values(COMBOTRUCK);
    return values.size();
}

int WizData::semiTrailerArrived()
{
    ss.str( std::string() );
    ss << QDate::currentDate().toString().toStdString();
    ss << QTime::currentTime().toString().toStdString();
    ss << QDateTime::currentMSecsSinceEpoch();
    dateOfArrival = QString::fromStdString(ss.str());
    truckTypeTotalMap.insertMulti(SEMITRAILER, dateOfArrival);
    QList<QString> values = truckTypeTotalMap.values(SEMITRAILER);
    return values.size();
}

int WizData::getSingleAxleTotal()
{
    QList<QString> values = truckTypeTotalMap.values(SINGLEAXLE);
    return values.size();
}

int WizData::getTandemAxleTotal()
{
    QList<QString> values = truckTypeTotalMap.values(TANDEMAXLE);
    return values.size();
}

int WizData::getTripleAxleTotal()
{
    QList<QString> values = truckTypeTotalMap.values(TRIPLEAXLE);
    return values.size();
}

int WizData::getComboTruckTotal()
{
    QList<QString> values = truckTypeTotalMap.values(COMBOTRUCK);
    return values.size();
}

int WizData::getSemiTrailerTotal()
{
    QList<QString> values = truckTypeTotalMap.values(SEMITRAILER);
    return values.size();
}
