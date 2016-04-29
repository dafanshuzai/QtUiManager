#include "tclass.h"

Tclass::Tclass()
{

}

Tclass::Tclass(QString name, QString score,QString fk_majorid)
{
    this->name=name;
    this->fk_majorid=fk_majorid;
    this->score=score;
}

QString Tclass::getScore() const
{
    return score;
}

void Tclass::setScore(const QString &value)
{
    score = value;
}

QString Tclass::getFk_majorid() const
{
    return fk_majorid;
}

void Tclass::setFk_majorid(const QString &value)
{
    fk_majorid = value;
}

QString Tclass::getName() const
{
    return name;
}

void Tclass::setName(const QString &value)
{
    name = value;
}

int Tclass::getId() const
{
    return id;
}

void Tclass::setId(int value)
{
    id = value;
}
