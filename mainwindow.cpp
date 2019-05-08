#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupPersonModel();
    setupItemMOdel();
    setupStringListModel();
    bm = new BaseComboBoxModel();
    ui->comboBox_2->setModel(bm);
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &MainWindow::changeLineEditSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupPersonModel()
{
    personmodel = new QSqlTableModel(this);
    personmodel->setTable("person");
    personmodel->select();
    ui->tableView->setModel(personmodel);
}

void MainWindow::setupItemMOdel()
{
    itemsmodel = new QSqlTableModel(this);
    itemsmodel->setTable("items");
    itemsmodel->select();
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::changeModelSlot);
}

void MainWindow::setupStringListModel()
{
    stringListModel = new QStringListModel();
    QStringList list = DataBase::getPersonList();
    stringListModel->setStringList(list);
    ui->comboBox->setModel(stringListModel);
}

void MainWindow::changeModelSlot()
{
    ui->tableView->setModel(itemsmodel);
}

void MainWindow::changeLineEditSlot()
{
    ui->lineEdit->setText(ui->comboBox_2->currentData(Qt::DisplayRole).toString());
}
