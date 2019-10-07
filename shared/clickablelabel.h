#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QWidget>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(const QString& text="", QWidget* parent=nullptr);
    ~ClickableLabel();
signals:
    void doubleClicked();
protected:
    void mouseDoubleClickEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL_H
