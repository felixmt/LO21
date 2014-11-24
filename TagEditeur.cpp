#include "TagEditeur.h"
#include "TagManager.h"
#include "NotesManager.h"

TagEditeur::TagEditeur()
{
    setFixedWidth(300);

    layout = new QVBoxLayout;

    vueTags = new  QListView();
    vueNotes = new QListView();

    vueTags->setSelectionMode(QAbstractItemView::ExtendedSelection);

    updateListeTags();
    updateListeNotes();

    modeleTags = new QStringListModel(listeTags);
    modeleNotes = new QStringListModel(listeNotes);

    vueTags->setModel(modeleTags);
    vueNotes->setModel(modeleNotes);

        layout->addWidget(vueTags);
        layout->addWidget(vueNotes);

        this->setLayout(layout);
}


void TagEditeur::updateListeTags()
{
    listeTags.clear();
    for (int i = 0; i < TagManager::getInstance().getTabTagsSize(); i++)
        listeTags << TagManager::getInstance().getTag(i)->getName();

//    modeleTags->setStringList(listeTags);
//    vueTags->setModel(modeleTags);
}

void TagEditeur::updateListeNotes()
{
    for (int i=0;i<NotesManager::getInstance().getTabSize();i++)
        listeNotes << NotesManager::getInstance().getNoteByPos(i)->getTitle();
}

TagEditView::TagEditView()
{
    setFixedWidth(300);

    QStringList listeTags;
    layout = new QVBoxLayout;
    vueTags = new QListView();
    valider = new QPushButton("Valider");
    nvTag = new QLineEdit();

    vueTags->setSelectionMode(QAbstractItemView::ExtendedSelection);

    for (int i = 0; i < TagManager::getInstance().getTabTagsSize(); i++)
        listeTags << TagManager::getInstance().getTag(i)->getName();

    modeleTags = new QStringListModel(listeTags);
    vueTags->setModel(modeleTags);

    layout->addWidget(vueTags);
    layout->addWidget(nvTag);
    layout->addWidget(valider);

    this->setLayout(layout);
}


