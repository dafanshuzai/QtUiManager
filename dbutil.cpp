#include "dbutil.h"

QSqlDatabase DbUtil::db=QSqlDatabase::addDatabase("QSQLITE");
QString DbUtil::dbname="data.db";
DbUtil::DbUtil()
{

}

void DbUtil::initTable()
{
  DbUtil::db.setDatabaseName(DbUtil::dbname);
  if(DbUtil::db.open()){
      std::cout<<"db conn success"<<std::endl;
      QSqlQuery query;
      QString sql = "create table if not exists Tmajor (id INTEGER primary key NOT NULL, name varchar(30))";
      if(query.exec(sql)){
          std::cout<<"tmajor create success"<<std::endl;
      }
      sql = "create table if not exists Tclass (id INTEGER primary key NOT NULL, name varchar(30),score varchar(10),fk_majorid varchar(10))";
      if(query.exec(sql)){
          std::cout<<"Tclass create success"<<std::endl;
      }
      sql = "create table if not exists Tgroup (id INTEGER primary key NOT NULL, name varchar(30),score varchar(10),fk_classid varchar(10))";
      if(query.exec(sql)){
          std::cout<<"Tgroup create success"<<std::endl;
      }
      DbUtil::db.close();
  }

}

void DbUtil::saveMajor(QString majorname)
{
    DbUtil::db.setDatabaseName(DbUtil::dbname);
    if(DbUtil::db.open()){
       //QString majorname=major.getName();
       QString sql="insert into Tmajor(name)values('"+majorname+"')";
       QSqlQuery query;
       if(query.exec(sql)){
            std::cout<<sql.toStdString()<<" execute suceess"<<std::endl;
       }else{
           std::cout<<sql.toStdString()<<" execute error"<<std::endl;
       }
    }
    DbUtil::db.close();
}

void DbUtil::saveClass(QString classname,QString score,QString fkmajorid)
{
    DbUtil::db.setDatabaseName(DbUtil::dbname);
    if(DbUtil::db.open()){
       QString sql="insert into Tclass (name,score,fk_majorid)values('"+classname+"',"+score+","+fkmajorid+")";
       QSqlQuery query;
       if(query.exec(sql)){
            std::cout<<sql.toStdString()<<" execute suceess"<<std::endl;
       }else{
           std::cout<<sql.toStdString()<<" execute error"<<std::endl;
       }
    }
    DbUtil::db.close();
}

void DbUtil::saveGroup(QString name, QString score, QString classid)
{
    DbUtil::db.setDatabaseName(DbUtil::dbname);
    if(DbUtil::db.open()){
       QString sql="insert into Tgroup (name,score,fk_classid)values('"+name+"',"+score+","+classid+")";
       QSqlQuery query;
       if(query.exec(sql)){
            std::cout<<sql.toStdString()<<" execute suceess"<<std::endl;
       }else{
           std::cout<<sql.toStdString()<<" execute error"<<std::endl;
       }
    }
    DbUtil::db.close();
}

QVector<Tmajor *> DbUtil::findAllMajor()
{
    QVector<Tmajor*> v;
    DbUtil::db.setDatabaseName(DbUtil::dbname);
    if(DbUtil::db.open()){
       QString sql="select id,name from Tmajor";
       QSqlQuery query;
       if(query.exec(sql)){
            std::cout<<sql.toStdString()<<" execute suceess"<<std::endl;
            while(query.next()){
                int id=query.value(0).toInt();
                QString name=query.value(1).toString();
                Tmajor* m=new Tmajor();
                m->setId(id);
                m->setName(name);
                v.append(m);
            }
       }else{
           std::cout<<sql.toStdString()<<" execute error"<<std::endl;
       }
    }
    DbUtil::db.close();
    return v;
}

QVector<Tclass *> DbUtil::findbyId(QString id)
{
    QVector<Tclass *> v;
    DbUtil::db.setDatabaseName(DbUtil::dbname);

    if(DbUtil::db.open()){
       QString sql="select id,name from Tclass where fk_majorid="+id;
       QSqlQuery query;
       if(query.exec(sql)){
            std::cout<<sql.toStdString()<<" execute suceess"<<std::endl;
            while(query.next()){
                int id=query.value(0).toInt();
                QString name=query.value(1).toString();
                Tclass* tclass=new Tclass();
                tclass->setId(id);
                tclass->setName(name);
                v.append(tclass);
            }
       }else{
           std::cout<<sql.toStdString()<<" execute error"<<std::endl;
       }
    }
    DbUtil::db.close();
    return v;
}

QVector<Tvo *> DbUtil::find(QString sql)
{
    QVector<Tvo *> v;
    DbUtil::db.setDatabaseName(DbUtil::dbname);
    if(DbUtil::db.open()){
       QSqlQuery query;
       if(query.exec(sql)){
            std::cout<<sql.toStdString()<<" execute suceess"<<std::endl;
            while(query.next()){

                Tvo* vo=new Tvo();
                vo->majorname=query.value(0).toString();
                vo->classname=query.value(1).toString();
                vo->classscore=query.value(2).toString();
                vo->groupname=query.value(3).toString();
                vo->groupscore=query.value(4).toString();

                v.append(vo);
            }
       }else{
           std::cout<<sql.toStdString()<<" execute error"<<std::endl;
       }
    }
    DbUtil::db.close();
    return v;

}
