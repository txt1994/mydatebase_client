#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QMessageBox>

extern QTranslator* translator;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QLabel* lab_datename = new QLabel(this);
    lab_datename->setText(tr("数据库列表: "));
    ui->toolBar->addWidget(lab_datename);
    data = new QComboBox(this);
    data->setFixedSize(100, 23);
    data->setEditable(true);
    ui->toolBar->addWidget(data);
    connect(data, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxindexchanged(int)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actOpenDB_triggered() {
    // 打开数据库
    QString aFile = QFileDialog::getOpenFileName(this, tr("选择数据库文件"), "",
                                                 tr("SQL Lite数据库(*.db *.db3)"));
    if (aFile.isEmpty()) //选择SQL Lite数据库文件
        return;

    //打开数据库
    DB = QSqlDatabase::addDatabase("QSQLITE"); //添加 SQL LITE数据库驱动
    DB.setDatabaseName(aFile);                 //设置数据库名称
                                               //    DB.setHostName();
                                               //    DB.setUserName();
                                               //    DB.setPassword();
    if (!DB.open())                            //打开数据库
    {
        QMessageBox::warning(this, tr("错误"), tr("打开数据库失败"), QMessageBox::Ok,
                             QMessageBox::NoButton);
        return;
    }

    QStringList list = DB.tables();
    data->addItems(list);
}

void MainWindow::openTable() {
    tabModel = new QSqlTableModel(this, DB); //数据表
    qryModel = new QSqlQueryModel(this);
    tabModel->setTable(data->currentText());
    tabModel->setEditStrategy(QSqlTableModel::OnManualSubmit); //数据保存方式，OnManualSubmit
                                                               //, OnRowChange
    tabModel->setSort(tabModel->fieldIndex("empNo"), Qt::AscendingOrder); //排序
    if (!(tabModel->select()))                                            //查询数据
    {
        QMessageBox::critical(this, tr("错误信息"),
                              tr("打开数据表错误,错误信息\n") + tabModel->lastError().text(),
                              QMessageBox::Ok, QMessageBox::NoButton);
        return;
    }

    theSelection = new QItemSelectionModel(tabModel); //关联选择模型
    // theSelection当前项变化时触发currentChanged信号
    connect(theSelection, &QItemSelectionModel::currentChanged, this,
            &MainWindow::on_currentChanged);
    //选择行变化时
    connect(theSelection, &QItemSelectionModel::currentRowChanged, this,
            &MainWindow::on_currentRowChanged);

    ui->tableView->setModel(tabModel);   //设置数据模型
    ui->tableView_2->setModel(qryModel); //设置数据模型
    ui->tableView_2->setDefaultDropAction(Qt::IgnoreAction);
    ui->tableView->setSelectionModel(theSelection);   //设置选择模型
    ui->tableView_2->setSelectionModel(theSelection); //设置选择模型
    ui->tableView_2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Memo"), true); //隐藏列
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Photo"),
                                   true);                                 //隐藏列
    ui->tableView_2->setColumnHidden(tabModel->fieldIndex("Memo"), true); //隐藏列
    ui->tableView_2->setColumnHidden(tabModel->fieldIndex("Photo"),
                                     true); //隐藏列

    //    // tableView上为“性别”和“部门”两个字段设置自定义代理组件
    //    QStringList strList;
    //    strList << "男"
    //            << "女";
    //    bool isEditable = false;
    //    delegateSex.setItems(strList, isEditable);
    //    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Gender"),
    //                                            &delegateSex); // Combbox选择型

    //    strList.clear();
    //    strList << "销售部"
    //            << "技术部"
    //            << "生产部"
    //            << "行政部";
    //    isEditable = true;
    //    delegateDepart.setItems(strList, isEditable);
    //    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Department"),
    //                                            &delegateDepart); // Combbox选择型

    //    delegateBirthdaty.setItems(isEditable);
    //    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Birthday"),
    //                                            &delegateBirthdaty); // 日期选择型

    //    delegateNO.setItems(isEditable);
    //    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("empNo"), &delegateNO); //
    //    NO选择型

    //    delegateSalary.setItems(isEditable);
    //    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Salary"),
    //                                            &delegateSalary); // Salary选择型

    //更新actions和界面组件的使能状态
    ui->actOpenDB->setEnabled(false);

    ui->actRecAppend->setEnabled(true);
    ui->actRecInsert->setEnabled(true);
    ui->actRecDelete->setEnabled(true);
    ui->actScan->setEnabled(true);
}

void MainWindow::on_currentChanged(const QModelIndex& current, const QModelIndex& previous) {
    Q_UNUSED(current);
    Q_UNUSED(previous);
    ui->actSubmit->setEnabled(tabModel->isDirty()); //有未保存修改时可用
    ui->actRevert->setEnabled(tabModel->isDirty());
}

void MainWindow::on_currentRowChanged(const QModelIndex& current, const QModelIndex& previous) {}

void MainWindow::on_actRevert_triggered() {
    tabModel->revertAll();

    ui->actSubmit->setEnabled(false);
    ui->actRevert->setEnabled(false);
}

void MainWindow::on_actSubmit_triggered() {
    tabModel->submitAll();
    ui->actSubmit->setEnabled(false);
    ui->actRevert->setEnabled(false);
}

void MainWindow::on_actRecAppend_triggered() {
    tabModel->insertRow(tabModel->rowCount(),
                        QModelIndex()); //在末尾添加一个记录

    QModelIndex curIndex = tabModel->index(tabModel->rowCount() - 1, 1); //创建最后一行的ModelIndex
    theSelection->clearSelection();                                      //清空选择项
    theSelection->setCurrentIndex(curIndex,
                                  QItemSelectionModel::Select); //设置刚插入的行为当前选择行

    int currow = curIndex.row(); //获得当前行
    tabModel->setData(tabModel->index(currow, 0),
                      2000 + tabModel->rowCount()); //自动生成编号
    tabModel->setData(tabModel->index(currow, 2), "男");
    // 插入行时设置缺省值，需要在primeInsert()信号里去处理
}

void MainWindow::on_actRecInsert_triggered() {
    QModelIndex curIndex = ui->tableView->currentIndex();

    tabModel->insertRow(curIndex.row(), QModelIndex());

    theSelection->clearSelection(); //清除已有选择
    theSelection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
}

void MainWindow::on_actQuit_triggered() {
    close();
}

void MainWindow::on_actFlush_database_triggered() {
    // 刷新显示新的数据库，不用再次手动选择数据库文件
    openTable();
}

void MainWindow::on_actScan_triggered() {
    // 涨工资
    if (tabModel->rowCount() == 0) return;

    for (int i = 0; i < tabModel->rowCount(); i++) {
        QSqlRecord aRec = tabModel->record(i); //获取当前记录
        float salary    = aRec.value("Salary").toFloat();
        salary          = salary * 1.1;
        aRec.setValue("Salary", salary);
        tabModel->setRecord(i, aRec);
    }
    if (tabModel->submitAll())
        QMessageBox::information(this, tr("消息"), tr("涨工资计算完毕"), QMessageBox::Ok,
                                 QMessageBox::NoButton);
}

void MainWindow::onComboBoxindexchanged(int index) {
    openTable();
}

void MainWindow::on_Btn_sqlsearch_clicked() {
    // 执行搜索命令
    QString commd = ui->plainTextEdit->toPlainText();
    if (!commd.isEmpty()) {

        qryModel->setQuery(commd);
        if (qryModel->lastError().isValid()) {
            QMessageBox::information(this, tr("错误"),
                                     tr("数据表查询错误,错误信息\n") + qryModel->lastError().text(),
                                     QMessageBox::Ok, QMessageBox::NoButton);
            return;
        }
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString& arg1) {
    // 语言热切换功能
    // 从json文件中读取设置
    qApp->removeTranslator(translator);
    delete translator;

    translator = new QTranslator;
    QString str;
    if (arg1 == "English") {
        translator->load("DataBase_GUI.en.qm", ":/locales", "", ".qm");
        str = "DataBase_GUI.en.qm";
    } else {
        translator->load("DataBase_GUI.cn.qm", ":/locales", "", ".qm");
        str = "DataBase_GUI.cn.qm";
    }
    updatesetting(str); // 写配置文件

    qApp->installTranslator(translator);
    ui->retranslateUi(this);
}

void MainWindow::updatesetting(QString& str) {
    QFile file(":/locales/settings.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开json文件!";
        return;
    } else {
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &err);
        if (err.error != QJsonParseError::NoError) {
            qDebug() << "json 格式错误";
            return;
        }
        QJsonObject obj = doc.object();
        obj.insert("language", str);
        QJsonDocument doc1(obj);
        QByteArray json = doc1.toJson();
        file.write(json);
    }
    file.close();
}
