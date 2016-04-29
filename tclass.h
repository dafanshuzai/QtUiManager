#ifndef TCLASS_H
#define TCLASS_H
#include <QString>

class Tclass
{
public:
    Tclass();
    Tclass(QString name,QString score,QString fk_majorid);
public:
    int id;
    QString name;
    QString score;
    QString fk_majorid;
    int getId() const;
    void setId(int value);
    QString getName() const;
    void setName(const QString &value);
    QString getFk_majorid() const;
    void setFk_majorid(const QString &value);
    QString getScore() const;
    void setScore(const QString &value);
};

#endif // TCLASS_H
