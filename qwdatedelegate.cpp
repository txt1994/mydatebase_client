#include "qwdatedelegate.hpp"
#include <QDateTimeEdit>

QWDateDelegate::QWDateDelegate(QObject* parent) : QStyledItemDelegate(parent) {}

void QWDateDelegate::setItems(bool isEdit) {
    m_isEdit = isEdit; //是否可编辑
}

QWidget* QWDateDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option,
                                      const QModelIndex& index) const {
    Q_UNUSED(option);
    Q_UNUSED(index);

    QDateTimeEdit* editor = new QDateTimeEdit(parent);
    editor->setDisplayFormat("yyyy-MM-dd"); //设置显示格式
    editor->setCalendarPopup(true);         //设置日历控件为悬空显示
    editor->installEventFilter(
        const_cast< QWDateDelegate* >(this)); //安装时间过滤器，使得代理能够获取定制控件的值
    editor->setEnabled(m_isEdit); //是否可编辑....
    return editor;
}

void QWDateDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const {
    QString datestr = index.model()->data(index, Qt::EditRole).toString();
    QDate date      = QDate::fromString(datestr, Qt::ISODate);

    QDateTimeEdit* edit = static_cast< QDateTimeEdit* >(editor);
    edit->setDate(date);
}

void QWDateDelegate::setModelData(QWidget* editor, QAbstractItemModel* model,
                                  const QModelIndex& index) const {
    QDateTimeEdit* edit = static_cast< QDateTimeEdit* >(editor);
    QDate date          = edit->date();
    model->setData(index, QVariant(date.toString(Qt::ISODate))); //将定制控件中的值展示到表格中
}

void QWDateDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
                                          const QModelIndex& index) const {
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
