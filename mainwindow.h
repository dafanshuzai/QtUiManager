#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addmajordialog.h"
#include "addclassdialog.h"
#include "addgroupdialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnAddMajor_clicked();

    void on_btnAddClass_clicked();

    void on_btnAddGroup_clicked();

private:
    Ui::MainWindow *ui;
    AddmajorDialog* majorDialog;
    AddClassDialog* classDialog;
    AddGroupDialog* groupDialog;
};

#endif // MAINWINDOW_H
