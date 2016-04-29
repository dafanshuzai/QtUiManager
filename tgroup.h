#ifndef TGROUP_H
#define TGROUP_H
#include <QString>

class Tgroup
{
public:
    Tgroup();
    Tgroup(QString name,QString score,QString fk_classid);
public:
    int id;
    QString name;
    QString score;
    QString fk_classid;
    int getId() const;
    void setId(int value);
    QString getName() const;
    void setName(const QString &value);
    QString getScore() const;
    void setScore(const QString &value);
    QString getFk_classid() const;
    void setFk_classid(const QString &value);
};

#endif // TGROUP_H
