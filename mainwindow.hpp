#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "qwcomboboxdelegate.hpp"
#include "qwdatedelegate.hpp"
#include "qwintdelegate.hpp"
#include "qwspindoubledelegate.hpp"
#include <QComboBox>
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

    void openTable();

private slots:

    void on_actOpenDB_triggered();

    void on_actRevert_triggered();

    void on_actSubmit_triggered();

    void on_actRecAppend_triggered();

    void on_actRecInsert_triggered();

    void on_actQuit_triggered();

    void on_actFlush_database_triggered();

    void on_actScan_triggered();

    void onComboBoxindexchanged(int index);

    void on_Btn_sqlsearch_clicked();

    void on_comboBox_currentTextChanged(const QString& arg1);

private:
    Ui::MainWindow* ui;

    QSqlDatabase DB; //  数据库连接

    QSqlTableModel* tabModel; // 数据模型

    QSqlQueryModel* qryModel; //数据库模型

    QItemSelectionModel* theSelection; //选择模型

    QWComboBoxDelegate delegateSex;      // 自定义数据代理，性别
    QWComboBoxDelegate delegateDepart;   // 自定义数据代理，部门
    QWspindoubleDelegate delegateSalary; // 自定义数据代理，工资
    QWDateDelegate delegateBirthdaty;    // 自定义数据代理，生日
    QWIntDelegate delegateNO;            // 自定义数据代理, 编号

    QComboBox* data; // 数据库文件的数据库列表

    QStringList gettables();

    void updatesetting(QString& str);

    void on_currentChanged(const QModelIndex& current, const QModelIndex& previous);

    void on_currentRowChanged(const QModelIndex& current, const QModelIndex& previous);
};
#endif // MAINWINDOW_HPP
