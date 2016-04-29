#include "tgroup.h"

Tgroup::Tgroup()
{

}

Tgroup::Tgroup(QString name, QString score, QString fk_classid)
{
    this->name=name;
    this->score=score;
    this->fk_classid=fk_classid;
}

QString Tgroup::getFk_classid() const
{
    return fk_classid;
}

void Tgroup::setFk_classid(const QString &value)
{
    fk_classid = value;
}

QString Tgroup::getScore() const
{
    return score;
}

void Tgroup::setScore(const QString &value)
{
    score = value;
}

QString Tgroup::getName() const
{
    return name;
}

void Tgroup::setName(const QString &value)
{
    name = value;
}

int Tgroup::getId() const
{
    return id;
}

void Tgroup::setId(int value)
{
    id = value;
}
