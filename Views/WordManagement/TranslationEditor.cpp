#include <QVBoxLayout>
#include <QEvent>
#include <QKeyEvent>
#include "TranslationEditor.h"

TranslationEditor::TranslationEditor(int wordid, QWidget *parent) : QWidget(parent)
{
    this->wordid = wordid;
    wordDao = new WordDao;
    options = wordDao->translations(wordid);
    setWindowFlag(Qt::Popup);
    QVBoxLayout *rootLayout = new QVBoxLayout;
    rootLayout->setMargin(5);
    translationInput = new QLineEdit;
    optionsView = new QListView;
    translationModel = new TranslationModel(wordid);
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
