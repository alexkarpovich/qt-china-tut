#ifndef TRANSLATIONITEMDELEGATE_H
#define TRANSLATIONITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QtGui>

class TranslationItemDelegate : public QStyledItemDelegate
{
public:
    TranslationItemDelegate(QObject *parent = nullptr);
//    QWidget *createEditor(QWidget *parent,
//                          const QStyleOptionViewItem &option,
//                          const QModelIndex &index) const override;

//    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
//    void setModelData(QWidget *editor,
//                      QAbstractItemModel *model,
//                      const QModelIndex &index) const override;

//    void updateEditorGeometry(QWidget *editor,
//                              const QStyleOptionViewItem &option,
//                              const QModelIndex &index) const override;

//    QSize sizeHint(const QStyleOptionViewItem &option,
//                   const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &option,
                 const QModelIndex &index);
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
};

#endif // TRANSLATIONITEMDELEGATE_H
