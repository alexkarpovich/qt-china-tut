#ifndef PAGEVIEW_H
#define PAGEVIEW_H

#include "PageAbstractView.h"


class PageView : public PageAbstractView
{
    Q_OBJECT
public:
    PageView(QWidget *parent = nullptr);
};

#endif // PAGEVIEW_H
