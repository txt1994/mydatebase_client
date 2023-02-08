#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    tab_Model     = new QSqlTableModel(this);
    the_Selection = new QItemSelectionModel(tab_Model);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actOpen_Database_triggered() {
    sqlname = new AddSQLfileDialog(this);
    sqlname->show();
    QString file = sqlname->getfilepath();
    if (file.isEmpty()) return;
}
