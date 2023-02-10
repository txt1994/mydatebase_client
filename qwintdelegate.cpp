#include "qwintdelegate.hpp"
#include <QSpinBox>

QWIntDelegate::QWIntDelegate(QObject* parent) : QStyledItemDelegate(parent) {}

void QWIntDelegate::setItems(bool isEdit) {
    m_isEdit = isEdit;
}

QWidget* QWIntDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option,
                                     const QModelIndex& index) const {
    Q_UNUSED(option);
    Q_UNUSED(index);

    QSpinBox* editor = new QSpinBox(parent);
    editor->setEnabled(m_isEdit); // 是否可编辑
    return editor;
}

void QWIntDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const {
    auto datestr = index.model()->data(index, Qt::EditRole).toInt();

    QSpinBox* edit = static_cast< QSpinBox* >(editor);
    edit->setRange(0, 1316134911);
    edit->setValue(datestr);
}

void QWIntDelegate::setModelData(QWidget* editor, QAbstractItemModel* model,
                                 const QModelIndex& index) const {
    QSpinBox* edit = static_cast< QSpinBox* >(editor);
    auto value     = edit->value();
    model->setData(index, value, Qt::EditRole);
}

void QWIntDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
                                         const QModelIndex& index) const {
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
