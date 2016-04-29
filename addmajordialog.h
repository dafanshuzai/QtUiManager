#ifndef ADDMAJORDIALOG_H
#define ADDMAJORDIALOG_H

#include <QDialog>
#include "dbutil.h"
#include "tmajor.h"
namespace Ui {
class AddmajorDialog;
}

class AddmajorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddmajorDialog(QWidget *parent = 0);
    ~AddmajorDialog();

private slots:
    void on_btnOK_clicked();

private:
    Ui::AddmajorDialog *ui;
};

#endif // ADDMAJORDIALOG_H
