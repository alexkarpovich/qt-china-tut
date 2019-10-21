#ifndef GROUPEDITVIEW_H
#define GROUPEDITVIEW_H

#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include <Models/WordModel.h>

class GroupEditView : public QWidget
{
    Q_OBJECT
    QList<int> groupids;
    WordModel *wordModel;
    QTableView *wordTableView;
    QLineEdit* wordInput;
    QPushButton *startTrainingBtn;
    QPushButton *startExamineBtn;

    void buildLayout();
public:
    explicit GroupEditView(QWidget *parent = nullptr);
    void switchGroup(QList<int> groupids);

signals:

public slots:
    void onWordInputReturnPressed();
    void onStartTrainingClicked();

};

#endif // GROUPEDITVIEW_H
