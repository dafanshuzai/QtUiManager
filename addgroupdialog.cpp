#include "addgroupdialog.h"
#include "ui_addgroupdialog.h"

AddGroupDialog::AddGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGroupDialog)
{
    ui->setupUi(this);

    QVector<Tmajor*> majors=DbUtil::findAllMajor();
    for(int i=0;i<majors.size();i++){
        Tmajor* m=majors.at(i);
        ui->comboxMajor->addItem(m->getName(),m->getId());
        delete m;
    }
}

AddGroupDialog::~AddGroupDialog()
{
    delete ui;
}

void AddGroupDialog::on_btnOK_clicked()
{
    int i=ui->comboxClass->currentIndex();
    QString classid=ui->comboxClass->itemData(i).toString();
    QString name=ui->editname->text();
    QString score=ui->editScore->text();
    DbUtil::saveGroup(name,score,classid);
    this->close();
}

void AddGroupDialog::on_comboxMajor_currentIndexChanged(int index)
{
    ui->comboxClass->clear();
    QString majorid=ui->comboxMajor->itemData(index).toString();
    QVector<Tclass *> tclasses=DbUtil::findbyId(majorid);
    for(int i=0;i<tclasses.size();i++){
        Tclass* c=tclasses.at(i);
        ui->comboxClass->addItem(c->getName(),c->getId());
        delete c;
    }

}
