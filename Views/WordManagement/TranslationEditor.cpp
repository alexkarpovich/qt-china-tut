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
    translationInput = new QLineEdit;
    translationInput->setPlaceholderText("Новый перевод");
    rootLayout->addWidget(translationInput, 0, Qt::AlignTop);
    setLayout(rootLayout);
}
