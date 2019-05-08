#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include "database.h"
#include "basecomboboxmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *personmodel;
    QSqlTableModel *itemsmodel;
    QStringListModel *stringListModel;
    BaseComboBoxModel *bm;
    void setupPersonModel();
    void setupItemMOdel();
    void setupStringListModel();



public slots:
    void changeModelSlot();
    void changeLineEditSlot();


};

#endif // MAINWINDOW_H
