#ifndef DBUTIL_H
#define DBUTIL_H
#include <QtSql/QtSql>
#include <iostream>
#include "tmajor.h"
#include "tclass.h"
#include "tvo.h"
#include <QVector>
class DbUtil
{
public:
    DbUtil();
public:
    static QSqlDatabase db;
    static QString dbname;
    static void initTable();
    static void saveMajor(QString);
    static void saveClass(QString,QString,QString);
    static void saveGroup(QString,QString,QString);
    static QVector<Tmajor *> findAllMajor();
    static QVector<Tclass *> findbyId(QString id);
    static QVector<Tvo *> find(QString sql);
};

#endif // DBUTIL_H
