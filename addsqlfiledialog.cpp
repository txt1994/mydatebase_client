#include "addsqlfiledialog.hpp"
#include "ui_addsqlfiledialog.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
AddSQLfileDialog::AddSQLfileDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::AddSQLfileDialog) {
    ui->setupUi(this);
    setAttribute(Qt::WA_AlwaysShowToolTips);
}

AddSQLfileDialog::~AddSQLfileDialog() {
    delete ui;
}

QString AddSQLfileDialog::getfilepath() {
    return sqlpath;
}

void AddSQLfileDialog::on_Btn_add_file_clicked() {
    // 查找sqlite文件
    sqlpath =
        QFileDialog::getOpenFileName(this, "打开一个SQLite文件", "", "数据库文件(*.db3 *.db)");
    if (sqlpath.isEmpty())
        QMessageBox::critical(this, "", "打开失败", QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    ui->sql_file_path->setText(sqlpath);
    QFile aFile(sqlpath);
    QFileInfo fileinfo(aFile);
    QString file = fileinfo.fileName();
    ui->sql_file->setText(file);
}
