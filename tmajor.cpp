#include "tmajor.h"

Tmajor::Tmajor()
{

}

Tmajor::Tmajor(QString name)
{
    this->name=name;
}

int Tmajor::getId() const
{
    return id;
}

void Tmajor::setId(int value)
{
    id = value;
}

QString Tmajor::getName() const
{
    return name;
}

void Tmajor::setName(const QString &value)
{
    name = value;
}
