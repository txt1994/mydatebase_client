<<<<<<< HEAD
#ifndef QWSPINDOUBLEDELEGATE_HPP
#define QWSPINDOUBLEDELEGATE_HPP

#include <QStyledItemDelegate>

class QWspindoubleDelegate : public QStyledItemDelegate {
    Q_OBJECT

private:
    bool m_isEdit; //是否可编辑
public:
    QWspindoubleDelegate(QObject* parent = nullptr);

    void setItems(bool isEdit); //初始化设置列表内容，是否可编辑

    //自定义代理组件必须继承以下4个函数
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
                          const QModelIndex& index) const Q_DECL_OVERRIDE;

    void setEditorData(QWidget* editor, const QModelIndex& index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget* editor, QAbstractItemModel* model,
                      const QModelIndex& index) const Q_DECL_OVERRIDE;
    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
                              const QModelIndex& index) const Q_DECL_OVERRIDE;
};

#endif // QWSPINDOUBLEDELEGATE_HPP
=======
#ifndef QWSPINDOUBLEDELEGATE_HPP
#define QWSPINDOUBLEDELEGATE_HPP

#include <QStyledItemDelegate>

class QWspindoubleDelegate : public QStyledItemDelegate {
    Q_OBJECT

private:
    bool m_isEdit; //是否可编辑
public:
    QWspindoubleDelegate(QObject* parent = nullptr);

    void setItems(bool isEdit); //初始化设置列表内容，是否可编辑

    //自定义代理组件必须继承以下4个函数
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
                          const QModelIndex& index) const Q_DECL_OVERRIDE;

    void setEditorData(QWidget* editor, const QModelIndex& index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget* editor, QAbstractItemModel* model,
                      const QModelIndex& index) const Q_DECL_OVERRIDE;
    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
                              const QModelIndex& index) const Q_DECL_OVERRIDE;
};

#endif // QWSPINDOUBLEDELEGATE_HPP
>>>>>>> cfab85754b1f42782028c65854789f9532e06c94
