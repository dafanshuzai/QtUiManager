#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"专业"<<"班级"<<"班级分数"<<"小组"<<"小组分数");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    QString sql="select  m.name as m_name,c_name,c_score,g_name,g_score from ( select g_name,g_score,c.name as c_name,c.score as c_score,c.fk_majorid as c_fk_majorid from( select g.name g_name,g.score g_score ,g.fk_classid  g_fk_classid from Tgroup as g) g ,Tclass c where g_fk_classid=c.id) as gc,Tmajor m  where m.id=c_fk_majorid";
    QVector<Tvo*> v=DbUtil::find(sql);
    for(int i=0;i<v.size();i++){
        Tvo* vo=v.at(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(vo->majorname));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(vo->classname));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(vo->classscore));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(vo->groupname));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(vo->groupscore));
        delete vo;
    }
    ui->tableWidget->selectRow(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAddMajor_clicked()
{
    //被回收并不代表别摧毁
   majorDialog=new AddmajorDialog(this);
   majorDialog->setModal(true);
   majorDialog->show();
}

void MainWindow::on_btnAddClass_clicked()
{
    classDialog=new AddClassDialog(this);
    classDialog->setModal(true);
    classDialog->show();
}

void MainWindow::on_btnAddGroup_clicked()
{
    groupDialog=new AddGroupDialog(this);
    groupDialog->setModal(true);
    groupDialog->show();
}
