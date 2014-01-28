#include <QtGui>
#include <QLabel>
#include <QVBoxLayout>
//#include <QtCore/private/qjnihelpers_p.h>
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>

#include "snowloadcountwiz.h"
#include "trucktypetotalspage.h"

TruckTypeTotalsPage::TruckTypeTotalsPage(QWidget *parent, WizData *tmpWizData) :
    QWizardPage(parent)
{
    wizData = tmpWizData;

    QVBoxLayout *layout = new QVBoxLayout;

    setTitle(tr("Truck Type Totals"));

    lbl = new QLabel(tr("label test"));
    lbl->setWordWrap(true);
    layout->addWidget(lbl);

    setLayout(layout);
}

int TruckTypeTotalsPage::nextId() const
{
    return -1;
}

bool TruckTypeTotalsPage::validatePage()
{
    qDebug() << "TruckTypeTotalsPage::validatePage()";
    QString logFileName;
    QString logtimeDisplayFormat;
    QString logdateDisplayFormat;
    //QString timeDisplayFormat;
    logtimeDisplayFormat = QString("HHmm");
    logdateDisplayFormat = QString("ddMMyyyy");
    logFileName = "snowLoadCountLog";
    logFileName += wizData->shiftStartTime;//Edit->time().toString(logtimeDisplayFormat);
    logFileName += wizData->shiftStartDate;//Edit->date().toString(logdateDisplayFormat);
    logFileName += ".txt";
    wizData->logFileName = logFileName;

    wizData->debugDataFields();
    //wizData->writeStream();
    //wizData->readStream();
    sendSMS("6132187497", "blah");
    return true;
}

void TruckTypeTotalsPage::sendSMS(QString phoneNumber, QString message)
{
    QAndroidJniEnvironment env;

    //SmsManager smsManager = SmsManager.getDefault();
    QAndroidJniObject mySmsManager = QAndroidJniObject::callStaticObjectMethod("android/telephony/SmsManager", "getDefault", "()Landroid/telephony/SmsManager;" );
    QAndroidJniObject myPhoneNumber = QAndroidJniObject::fromString(phoneNumber);
    QAndroidJniObject myTextMessage = QAndroidJniObject::fromString(message);
    QAndroidJniObject scAddress = NULL;
    QAndroidJniObject sentIntent = NULL;
    QAndroidJniObject deliveryIntent = NULL;

    //smsManager.sendTextMessage("Phone Number", null, "Message", null, null);
    //in background (Not showing message composer)
    //<uses-permission android:name="android.permission.SEND_SMS"/>

    //mySmsManager.callObjectMethod<void>("sendTextMessage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V", myPhoneNumber, scAddress, myTextMessage, sentIntent, deliveryIntent );
    //mySmsManager.callMethod<void>("sendTextMessage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V" , myPhoneNumber, scAddress, myTextMessage, sentIntent, deliveryIntent );
    mySmsManager.callMethod<void>("sendTextMessage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V" , myPhoneNumber.object<jstring>(), scAddress.object<jstring>(), myTextMessage.object<jstring>(), NULL, NULL );



    //mySmsManager.callStaticObjectMethod<void>("sendTextMessage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V", myPhoneNumber, scAddress, myTextMessage, sentIntent, deliveryIntent );

    //mySmsManager.callObjectMethod("sendTextMessage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V", myPhoneNumber, scAddress, myTextMessage, sentIntent, deliveryIntent );
    //mySmsManager.callMethod("sendTextMessage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V" , myPhoneNumber, scAddress, myTextMessage, sentIntent, deliveryIntent );
    //mySmsManager.callStaticObjectMethod("sendTextMessage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V", myPhoneNumber, scAddress, myTextMessage, sentIntent, deliveryIntent );

}

