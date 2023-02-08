#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "addsqlfiledialog.hpp"
#include <QMainWindow>
#include <QtSql>
QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_actOpen_Database_triggered();

private:
    Ui::MainWindow* ui;

    AddSQLfileDialog* sqlname;
    QSqlTableModel* tab_Model;          // 数据模型
    QItemSelectionModel* the_Selection; //选择模型
};
#endif // MAINWINDOW_HPP
