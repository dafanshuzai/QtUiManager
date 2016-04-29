#ifndef ADDCLASSDIALOG_H
#define ADDCLASSDIALOG_H

#include <QDialog>
#include "dbutil.h"

namespace Ui {
class AddClassDialog;
}

class AddClassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClassDialog(QWidget *parent = 0);
    ~AddClassDialog();

private slots:
    void on_btnOK_clicked();

private:
    Ui::AddClassDialog *ui;
};

#endif // ADDCLASSDIALOG_H
