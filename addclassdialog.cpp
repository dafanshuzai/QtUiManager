#include "addclassdialog.h"
#include "ui_addclassdialog.h"

AddClassDialog::AddClassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClassDialog)
{
    ui->setupUi(this);
    // 让分数只能输入数字
    QValidator *validator=new QIntValidator(0,1000,this); // 0-100 only accept number
    ui->editScore->setValidator(validator);

    QVector<Tmajor*> majors=DbUtil::findAllMajor();
    for(int i=0;i<majors.size();i++){
        Tmajor* major=majors.at(i);
        ui->cboxMajor->addItem(major->getName(),major->getId());
        delete major;
    }
}

AddClassDialog::~AddClassDialog()
{
    delete ui;
}

void AddClassDialog::on_btnOK_clicked()
{
    int index=ui->cboxMajor->currentIndex();
    QString majorid=ui->cboxMajor->itemData(index).toString();
    QString classname=ui->editClass->text();
    QString score=ui->editScore->text();
    DbUtil::saveClass(classname,score,majorid);
    std::cout<<"index:"<<index<<"majorid:"<<majorid.toStdString()<<std::endl;
    this->close();

}
