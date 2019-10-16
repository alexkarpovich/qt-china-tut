#ifndef GROUPEDITVIEW_H
#define GROUPEDITVIEW_H

#include <QTableView>
#include <QWidget>

#include <Models/WordModel.h>

class GroupEditView : public QWidget
{
    Q_OBJECT
    int groupid;
    WordModel *wordModel;
    QTableView *wordTableView;
    QLineEdit* wordInput;

    void buildLayout();
public:
    explicit GroupEditView(QWidget *parent = nullptr);
    void switchGroup(int groupid);

signals:

public slots:
    void onWordInputReturnPressed();

};

#endif // GROUPEDITVIEW_H
