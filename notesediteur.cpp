#include "documentEditeur.h"
#include <QItemSelectionModel>

NotesEditeur::NotesEditeur(Note* n, QWidget* parent)
{
    title = new QLineEdit(n->getTitle());
    save = new QPushButton("Sauver");
    supp = new QPushButton("Mettre à la corbeille");
    addTag = new QPushButton("Ajout/Supp de tags");
    layout = new QVBoxLayout;
    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(save);
    buttonLayout->addWidget(supp);
    buttonLayout->addWidget(addTag);
}

bool NotesEditeur::setSaved(bool s) {
    if (s==true) saved=true;
    else saved=false;

    return saved;
}
