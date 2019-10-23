#ifndef WORDITEMDELEGATE_H
#define WORDITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QtGui>

#include <Models/WordModel.h>

class WordItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    WordModel::WordRoles getWordRoleByColumn(int column) const;
public:
    WordItemDelegate(QObject *parent = nullptr);
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

#endif // WORDITEMDELEGATE_H
