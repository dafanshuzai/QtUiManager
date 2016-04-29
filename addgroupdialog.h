#ifndef ADDGROUPDIALOG_H
#define ADDGROUPDIALOG_H

#include <QDialog>
#include "dbutil.h"
namespace Ui {
class AddGroupDialog;
}

class AddGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGroupDialog(QWidget *parent = 0);
    ~AddGroupDialog();

private slots:
    void on_btnOK_clicked();

    void on_comboxMajor_currentIndexChanged(int index);

private:
    Ui::AddGroupDialog *ui;
};

#endif // ADDGROUPDIALOG_H
