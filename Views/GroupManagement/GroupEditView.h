#ifndef GROUPEDITVIEW_H
#define GROUPEDITVIEW_H

#include <QTableView>
#include <QWidget>

#include <Models/TranslationModel.h>

class GroupEditView : public QWidget
{
    Q_OBJECT
    int groupId = 0;
    TranslationModel *translationModel;
    QTableView *wordTableView;
    QLineEdit* wordInput;

    void buildLayout();
public:
    explicit GroupEditView(QWidget *parent = nullptr);
    void setGroupId(int _groupId);

signals:

public slots:
    void onWordInputReturnPressed();

};

#endif // GROUPEDITVIEW_H