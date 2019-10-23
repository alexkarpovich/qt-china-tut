#ifndef GROUPEDITVIEW_H
#define GROUPEDITVIEW_H

#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include <Models/WordModel.h>
#include "GroupAbstractView.h"


class GroupEditView : public GroupAbstractView
{
    Q_OBJECT
    WordModel *wordModel;
    QTableView *wordTableView;
    QLineEdit* wordInput;
    QPushButton *startTrainingBtn;
    QPushButton *startExamineBtn;

    void buildLayout();
public:
    explicit GroupEditView(GroupAbstractView *view);
    void switchGroup(QList<int> groupids);

signals:

public slots:
    void onWordInputReturnPressed();
    void onStartTrainingClicked();

};

#endif // GROUPEDITVIEW_H
