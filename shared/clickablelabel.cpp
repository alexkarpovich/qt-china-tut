#include "clickablelabel.h"

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    setText(text);
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClicked();
}
