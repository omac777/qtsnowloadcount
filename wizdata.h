#ifndef WIZDATA_H
#define WIZDATA_H

#include <QDebug>
#include <QFile>
#include <QTime>
#include <QDate>
#include <sstream>
#include <QObject>

#define SINGLEAXLE "singleaxle"
#define TANDEMAXLE "tandem2axle"
#define TRIPLEAXLE "tripleaxle"
#define COMBOTRUCK "combotruck"
#define SEMITRAILER "semitrailer"

class WizData : public QObject
{
    Q_OBJECT
public:
    explicit WizData(QObject *parent = 0);
    void debugDataFields();
    void writeStream();
    void readStream();
    int singleAxleArrived();
    int tandemAxleArrived();
    int tripleAxleArrived();
    int comboTruckArrived();
    int semiTrailerArrived();

    int getSingleAxleTotal();
    int getTandemAxleTotal();
    int getTripleAxleTotal();
    int getComboTruckTotal();
    int getSemiTrailerTotal();


    QString logFileName;
    //Log file name: "snowLoadCountLog022920122013"
    QString shiftStartTime;
    //Shift Start Time: "0229"
    QString shiftEndTime;
    //Shift End Time: "1029"
    QString shiftStartDate;
    //Shift Start Date: "20122013"
    QString guardName;
    //Guard Name: "a"
    QString guardLicenseNumber;
    //Guard License#: "b"
    QString shiftComment;
    //Shift Comment: "c"
    QString countLocation;
    //Location: "Clyde"
    QString countForItemType;
    //Counting totals for: "tickets"
    QMap<QString, QString> truckTypeTotalMap;

signals:
    
public slots:

private:
    QString dateOfArrival;
    std::stringstream ss;
};

#endif // WIZDATA_H
