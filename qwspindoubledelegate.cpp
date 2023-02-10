#include "qwspindoubledelegate.hpp"
#include <QDoubleSpinBox>
QWspindoubleDelegate::QWspindoubleDelegate(QObject* parent) : QStyledItemDelegate(parent) {}

void QWspindoubleDelegate::setItems(bool isEdit) {
    m_isEdit = isEdit;
}

QWidget* QWspindoubleDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option,
                                            const QModelIndex& index) const {
    Q_UNUSED(option);
    Q_UNUSED(index);

    QDoubleSpinBox* editor = new QDoubleSpinBox(parent);
    editor->setEnabled(m_isEdit); //是否可编辑
    return editor;
}

void QWspindoubleDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const {
    auto datestr = index.model()->data(index, Qt::EditRole).toDouble();

    QDoubleSpinBox* edit = static_cast< QDoubleSpinBox* >(editor);
    edit->setRange(0.0, 999999999999999999.99);
    edit->setValue(datestr);
}

void QWspindoubleDelegate::setModelData(QWidget* editor, QAbstractItemModel* model,
                                        const QModelIndex& index) const {
    QDoubleSpinBox* edit = static_cast< QDoubleSpinBox* >(editor);
    auto value           = edit->value();
    model->setData(index, value, Qt::EditRole);
}

void QWspindoubleDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
                                                const QModelIndex& index) const {
    editor->setGeometry(option.rect);
}
