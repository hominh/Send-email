#include <QtCore/QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include <QFile>
#include <QObject>
#include <QThread>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMutex>
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include "cprtfcdatabase.h"
static void messageHandler(QtMsgType type, const char *msg)
{
    QString datetime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString logFileName=QDateTime::currentDateTime().toString("./log/yyyyMMdd.log");
    QFile syslogFile(logFileName);
    if (syslogFile.open(QFile::Append | QFile::Text)) {
        QTextStream out(&syslogFile);
        out << datetime << " " << msg << "\n";
        syslogFile.close();
    }
}
                                            
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qApp->addLibraryPath(qApp->applicationDirPath()+"/plugins");
    QDir logDir(qApp->applicationDirPath()+"/log");
    logDir.mkpath("./");
    qInstallMsgHandler(messageHandler);
    CprTfcDatabase *localDatabase = new CprTfcDatabase(qApp->applicationDirPath()+ "/SendMail.ini", "LocalDatabase", "SendMailLocalDatabase", true);
    if(!localDatabase->isOpen()){
        qDebug() << "Open database error ::exit(1);";
        ::exit(1);
    }
    QDateTime syslogTime = QDateTime::currentDateTime().addSecs(-120);
    QDateTime cameraTime = QDateTime::currentDateTime();
    cameraTime.setTime(QTime(QTime::currentTime().hour(), QTime::currentTime().minute(), 0));
    cameraTime = cameraTime.addSecs(-60);
    for(int i=0;i<1000000000;i++){
        QSqlQuery thamSoQuery;
        localDatabase->execQuery(thamSoQuery, "select thamso_giatri from tbl_thamso where thamso_ten='SMSList'");
        QStringList SMSList, EmailList;
        int SMSEvent=0, EmailEvent=0;
        if(thamSoQuery.next())
            SMSList = thamSoQuery.value(0).toString().split("|");
        if(thamSoQuery.exec("select thamso_giatri from tbl_thamso where thamso_ten='EmailList'") && thamSoQuery.next())
            EmailList = thamSoQuery.value(0).toString().split("|");
        if(thamSoQuery.exec("select thamso_giatri from tbl_thamso where thamso_ten='SMSEvent'") && thamSoQuery.next())
            SMSEvent = thamSoQuery.value(0).toInt();
        if(thamSoQuery.exec("select thamso_giatri from tbl_thamso where thamso_ten='EmailEvent'") && thamSoQuery.next())
            EmailEvent = thamSoQuery.value(0).toInt();
        if(i%300==0)
            qDebug()<< "LOOP" << i << "SMSList" << SMSList <<"EmailList" << EmailList<< "SMSEvent" << SMSEvent<< "EmailEvent" <<EmailEvent;
        if(cameraTime.secsTo(QDateTime::currentDateTime())>=60){
            localDatabase->execQuery("update tbl_cam set cam_video_stat=0 where cam_video_stat=1 and cam_videotime<subtime(now(),'00:03:00')");
            localDatabase->execQuery("update tbl_cam set cam_analytics_stat=0 where cam_analytics_stat=1 and cam_analytics_time<subtime(now(),'00:05:00')");
            if(QTime::currentTime().hour()>=7 && QTime::currentTime().hour()<=17)
                localDatabase->execQuery("update tbl_cam set cam_vehicle_stat=0 where cam_vehicle_stat=1 and cam_vehicle_time<subtime(now(),'00:20:00')");
            if((EmailEvent&8) || (SMSEvent&8)){
                QString EmailStr, SMSStr;
                /*
                QSqlQuery cameraQuery(QString("select cam_sohieu, cam_ten, cam_videolen, cam_videotime from tbl_cam where cam_stat=0 and cam_videotime>='%1' and cam_videotime<'%2'").arg(cameraTime.addSecs(-120).toString("yyyy-MM-dd hh:mm:ss")).arg(cameraTime.addSecs(-60).toString("yyyy-MM-dd hh:mm:ss")),localDatabase);
                while(cameraQuery.next()){
                    EmailStr += QString::fromUtf8("CAM %1(%2) không ghi hình từ %3\n").arg(cameraQuery.value(0).toString()).arg(cameraQuery.value(1).toString()).arg(cameraQuery.value(3).toDateTime().addSecs(cameraQuery.value(2).toInt()).toString("yyyy-MM-dd hh:mm:ss"));
                    SMSStr += cameraQuery.value(0).toString() + "\n";
                }
                QSqlQuery cameraQuery2(QString("select cam_sohieu, cam_ten, cam_videolen, cam_analytics_time from tbl_cam where cam_analytics_time>='%1' and cam_analytics_time<'%2'").arg(cameraTime.addSecs(-120).toString("yyyy-MM-dd hh:mm:ss")).arg(cameraTime.addSecs(-60).toString("yyyy-MM-dd hh:mm:ss")),localDatabase);
                while(cameraQuery2.next()){
                    EmailStr += QString::fromUtf8("CAM %1(%2) không phân tích dữ liệu từ %3\n").arg(cameraQuery2.value(0).toString()).arg(cameraQuery2.value(1).toString()).arg(cameraQuery2.value(3).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                    SMSStr += cameraQuery2.value(0).toString() + "\n";
                }
                if(QTime::currentTime().hour()>=7 && QTime::currentTime().hour()<=19){
                    QSqlQuery cameraQuery3(QString("select cam_sohieu, cam_ten, cam_videolen, cam_vehicle_time from tbl_cam where cam_vehicle_time>='%1' and cam_vehicle_time<'%2'").arg(cameraTime.addSecs(-1200).toString("yyyy-MM-dd hh:mm:ss")).arg(cameraTime.addSecs(-1200+60).toString("yyyy-MM-dd hh:mm:ss")),localDatabase);
                    while(cameraQuery3.next()){
                        EmailStr += QString::fromUtf8("CAM %1(%2) không có dữ liệu xe từ %3\n").arg(cameraQuery3.value(0).toString()).arg(cameraQuery3.value(1).toString()).arg(cameraQuery3.value(3).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                        SMSStr += cameraQuery3.value(0).toString() + "\n";
                    }
                }
                */
                QSqlQuery syslogQuery;
                localDatabase->execQuery(syslogQuery, QString("select syslog_time, syslog_type, syslog_msg from tbl_syslog where syslog_time>='%1' and syslog_time<'%2' and syslog_type like 'CAMERA_%' order by syslog_time").arg(cameraTime.toString("yyyy-MM-dd hh:mm:ss")).arg(cameraTime.addSecs(60).toString("yyyy-MM-dd hh:mm:ss")));
                while (syslogQuery.next()){
                    EmailStr += syslogQuery.value(2).toString() + "\n";
                    SMSStr += syslogQuery.value(2).toString() + "\n";
                }
                if((SMSEvent&8)&&SMSStr.length()>2){
                    for(int i=0;i<SMSList.size();i++){
                        if(SMSList[i].length()>8){
                            system(QString("echo \" Camera %1 mat ket noi \" | gnokii --sendsms %2").arg(SMSStr).arg(SMSList[i]).toAscii().data());
                        }
                    }
                }
                if((EmailEvent&8) && EmailStr.length()>2){
                    for(int i=0;i<EmailList.size();i++){
                        if(EmailList[i].length()>3){
                            QFile file("/tmp/mail.txt");
                            if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
                                file.write(QString("%1 \nSubject: CadProTMMS event %2 \n%3\n").arg(EmailList[i]).arg("CAMERA").arg(EmailStr).toUtf8());
                                file.close();
                                system("/usr/bin/python /usr/local/sbin/sendmail.py");
                            }
                        }
                    }
                }
            }
            cameraTime=cameraTime.addSecs(60);
        }
        QSqlQuery syslogQuery;
        localDatabase->execQuery(syslogQuery, QString("select syslog_time, syslog_type, syslog_msg from tbl_syslog where syslog_time>'%1' and syslog_time<now() order by syslog_time").arg(syslogTime.toString("yyyy-MM-dd hh:mm:ss")));
        if(!syslogQuery.isActive()){
            qDebug() <<  "SQL error" << syslogQuery.lastError().text();
            return 1;
        }
        while (syslogQuery.next()){
            syslogTime = syslogQuery.value(0).toDateTime();
            if(syslogQuery.value(1).toString()=="NVR_DOWN" || syslogQuery.value(1).toString()=="NVR_UP"){
                if(SMSEvent&1){
                    for(int i=0;i<SMSList.size();i++){
                        if(SMSList[i].length()>8){
                            system(QString("echo \" %1 \" | gnokii --sendsms %2").arg(syslogQuery.value(2).toString()).arg(SMSList[i]).toAscii().data());
                        }
                    }
                }
                if(EmailEvent&1){
                    for(int i=0;i<EmailList.size();i++){
                        if(EmailList[i].length()>3){
                            QFile file("/tmp/mail.txt");
                            if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
                                file.write(QString("%1 \nCadProTMMS event %2 \n%3 \n").arg(EmailList[i]).arg(syslogQuery.value(1).toString()).arg(syslogQuery.value(2).toString()).toUtf8());
                                file.close();
                                system("/usr/bin/python /usr/local/sbin/sendmail.py");
                            }
                        }
                    }
                }
            }
            if(syslogQuery.value(1).toString()=="NVR_OVER_QUOTA"){
                if(SMSEvent&2){
                    for(int i=0;i<SMSList.size();i++){
                        if(SMSList[i].length()>8){
                            system(QString("echo \" %1 \" | gnokii --sendsms %2").arg(syslogQuery.value(2).toString()).arg(SMSList[i]).toAscii().data());
                        }
                    }
                }
                if(EmailEvent&2){
                    for(int i=0;i<EmailList.size();i++){
                        if(EmailList[i].length()>3){
                            QFile file("/tmp/mail.txt");
                            if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
                                file.write(QString("%1 \nCadProTMMS event %2 \n%3 \n").arg(EmailList[i]).arg(syslogQuery.value(1).toString()).arg(syslogQuery.value(2).toString()).toUtf8());
                                file.close();
                                system("/usr/bin/python /usr/local/sbin/sendmail.py");
                            }
                        }
                    }
                }
            }
            if(syslogQuery.value(1).toString()=="NVR_DISK_FULL"){
                if(SMSEvent&4){
                    for(int i=0;i<SMSList.size();i++){
                        if(SMSList[i].length()>8){
                            system(QString("echo \" %1 \" | gnokii --sendsms %2").arg(syslogQuery.value(2).toString()).arg(SMSList[i]).toAscii().data());
                        }
                    }
                }
                if(EmailEvent&4){
                    for(int i=0;i<EmailList.size();i++){
                        if(EmailList[i].length()>3){
                            QFile file("/tmp/mail.txt");
                            if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
                                file.write(QString("%1 \nCadProTMMS event %2 \n%3 \n").arg(EmailList[i]).arg(syslogQuery.value(1).toString()).arg(syslogQuery.value(2).toString()).toUtf8());
                                file.close();
                                system("/usr/bin/python /usr/local/sbin/sendmail.py");
                            }
                        }
                    }
                }
            }
            if(syslogQuery.value(1).toString()=="CLEAN_VIDEO"){
                if(SMSEvent&16){
                    for(int i=0;i<SMSList.size();i++){
                        if(SMSList[i].length()>8){
                            system(QString("echo \" %1 \" | gnokii --sendsms %2").arg(syslogQuery.value(2).toString()).arg(SMSList[i]).toAscii().data());
                        }
                    }
                }
                if(EmailEvent&16){
                    for(int i=0;i<EmailList.size();i++){
                        if(EmailList[i].length()>3){
                            QFile file("/tmp/mail.txt");
                            if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
                                file.write(QString("%1 \nCadProTMMS event %2 \n%3 \n").arg(EmailList[i]).arg(syslogQuery.value(1).toString()).arg(syslogQuery.value(2).toString()).toUtf8());
                                file.close();
                                system("/usr/bin/python /usr/local/sbin/sendmail.py");
                            }
                        }
                    }
                }
            }
        }
        sleep(1);
    }
    return 0;
}
