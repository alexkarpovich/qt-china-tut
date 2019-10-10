#ifndef GROUPLISTITEM_H
#define GROUPLISTITEM_H

#include <QStyledItemDelegate>
#include <QtGui>

class GroupListItem : public QStyledItemDelegate
    {
public:
    GroupListItem();
    virtual ~GroupListItem();

    enum datarole {
        headerTextRole = Qt::UserRole + 100,
        subHeaderTextrole = Qt::UserRole + 101
    };

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index ) const;

};

#endif // GROUPLISTITEM_H
