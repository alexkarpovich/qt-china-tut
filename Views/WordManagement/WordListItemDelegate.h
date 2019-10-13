#ifndef WORDLISTITEMDELEGATE_H
#define WORDLISTITEMDELEGATE_H


#include <QStyledItemDelegate>
#include <QtGui>

#include <Models/WordTableModel.h>

class WordListItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    WordTableModel::WordRoles getWordRoleByColumn(int column) const;
public:
    WordListItemDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

};

#endif // WORDLISTITEMDELEGATE_H
