#ifndef QWDATEDELEGATE_HPP
#define QWDATEDELEGATE_HPP

#include <QDateEdit>
#include <QStyledItemDelegate>

class QWDateDelegate : public QStyledItemDelegate {
    Q_OBJECT
private:
    bool m_isEdit; //是否可编辑
public:
    QWDateDelegate(QObject* parent = nullptr);

    void setItems(bool isEdit); //初始化设置列表内容，是否可编辑

    //自定义代理组件必须继承以下4个函数....
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
                          const QModelIndex& index) const Q_DECL_OVERRIDE;

    void setEditorData(QWidget* editor, const QModelIndex& index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget* editor, QAbstractItemModel* model,
                      const QModelIndex& index) const Q_DECL_OVERRIDE;
    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
                              const QModelIndex& index) const Q_DECL_OVERRIDE;
};

#endif // QWDATEDELEGATE_HPP
