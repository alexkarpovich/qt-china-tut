#ifndef PAGEVIEW_H
#define PAGEVIEW_H

#include "AbstractMainView.h"


class PageView : public AbstractMainView
{
    Q_OBJECT
public:
    PageView(QWidget *parent = nullptr);
};

#endif // PAGEVIEW_H
