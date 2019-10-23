#include <QVBoxLayout>
#include <QEvent>
#include <QKeyEvent>

#include "TranslationEditor.h"
#include "TranslationItemDelegate.h"

TranslationEditor::TranslationEditor(QList<int> groupids, int wordid, QWidget *parent) : QWidget(parent)
{
    this->groupids = groupids;
    this->wordid = wordid;
    wordDao = new WordDao;
    options = wordDao->translations(wordid);
    setWindowFlag(Qt::Popup);
    QVBoxLayout *rootLayout = new QVBoxLayout;
    rootLayout->setMargin(5);
    translationInput = new QLineEdit;
    optionsView = new QListView;
    optionsView->setItemDelegate(new TranslationItemDelegate);
    translationModel = new TranslationModel(groupids, wordid);
    optionsView->setModel(translationModel);
    translationInput->setPlaceholderText("Новый перевод");
    rootLayout->addWidget(translationInput, 0, Qt::AlignTop);
    rootLayout->addWidget(optionsView);
    setLayout(rootLayout);

    connect(translationInput, SIGNAL(returnPressed()), SLOT(onTranslationInputReturnPressed()));

}

void TranslationEditor::onTranslationInputReturnPressed()
{
    translationModel->addTranslation(translationInput->text());
}
