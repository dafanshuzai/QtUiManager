#include "addmajordialog.h"
#include "ui_addmajordialog.h"

AddmajorDialog::AddmajorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddmajorDialog)
{
    ui->setupUi(this);
}

AddmajorDialog::~AddmajorDialog()
{
    delete ui;
}

void AddmajorDialog::on_btnOK_clicked()
{
    QString name=ui->editmajor->text();
    Tmajor major(name);
    DbUtil::saveMajor(name);
    this->close();
}
