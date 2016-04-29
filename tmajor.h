#ifndef TMAJOR_H
#define TMAJOR_H
#include <QString>

class Tmajor
{
public:
    Tmajor();
    Tmajor(QString name);
public:
    int id;
    QString name;
    QString getName() const;
    void setName(const QString &value);
    int getId() const;
    void setId(int value);
};

#endif // TMAJOR_H
