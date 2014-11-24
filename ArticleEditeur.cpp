#include "ArticleEditeur.h"

ArticleEditeur::ArticleEditeur(Note* a, QWidget* parent) : NotesEditeur(a) {
    article = dynamic_cast<Article*>(a);
    setWindowState(Qt::WindowMaximized);

    text = new QTextEdit;
    text->setText(article->getText());

    layout->addWidget(title);
    layout->addWidget(text);
    layout->addLayout(buttonLayout);
    title->setText(a->getTitle());

    setLayout(layout);

    QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveNote()));
    QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(updateNote()));
    QObject::connect(text, SIGNAL(textChanged()), this, SLOT(updateNote()));
    QObject::connect(text, SIGNAL(textChanged()), this, SLOT(activerSave()));
    QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(activerSave(QString)));
    save->setEnabled(false);
}

void ArticleEditeur::saveNote() {
    article->setTitle(title->text());
    article->setText(text->toPlainText());
    NotesManager::getInstance().saveNote(*article);
    QMessageBox::information(this, "Sauvegarde", "Votre article a bien été sauvé");
    save->setEnabled(false);
    saved=true;
}

void ArticleEditeur::updateNote() {
    article->setTitle(title->text());
    article->setText(text->toPlainText());
    activerSave();
}

void ArticleEditeur::activerSave(QString str) {
    save->setEnabled(true);
    saved=false;
}

Article* ArticleEditeur::getNote() const {
    return article;
}
