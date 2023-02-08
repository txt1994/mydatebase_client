#ifndef ADDSQLFILEDIALOG_HPP
#define ADDSQLFILEDIALOG_HPP

#include <QDialog>

namespace Ui {
    class AddSQLfileDialog;
}

class AddSQLfileDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddSQLfileDialog(QWidget* parent = nullptr);
    ~AddSQLfileDialog();

    QString getfilepath();

private slots:
    void on_Btn_add_file_clicked();

private:
    Ui::AddSQLfileDialog* ui;
    QString sqlpath;
};

#endif // ADDSQLFILEDIALOG_HPP
