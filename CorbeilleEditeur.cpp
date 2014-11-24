#include "CorbeilleEditeur.h"



void CorbeilleEditeur::supp()
{
    if(!list->currentItem()==0){
        QListWidgetItem* selectedItem = list->currentItem() ;
        QString title = selectedItem->text();
        Note* n = Corbeille::getInstance().getNoteViaName(title);
        Corbeille::getInstance().deleteNote(n);
        list->takeItem(list->currentRow());
    }
}

void CorbeilleEditeur::vid()
{
    Corbeille::getInstance().viderCorbeille();
    list->clear();
}

void CorbeilleEditeur::activerBoutons()
{
    supprimer->setEnabled(true);
    restaurer->setEnabled(true);
}


Note* CorbeilleEditeur::restor()
{
    Note* n = 0;
    if(!list->currentItem()==0){
        QListWidgetItem* selectedItem = list->currentItem() ;
        QString title = selectedItem->text();
        n = Corbeille::getInstance().getNoteViaName(title);
        Corbeille::getInstance().putBackNote(n);
        list->takeItem(list->currentRow());
    }
    return n;

}

CorbeilleEditeur::CorbeilleEditeur(QWidget* parent)
{
    list = new QListWidget();
    QListWidgetItem* item;
    for(int i=0;i<Corbeille::getInstance().getSizeDust();i++)
        {
            Note* n = Corbeille::getInstance().getNoteByPos(i);
            QString noteTitle = n->getTitle();
            item = new QListWidgetItem(noteTitle,list); // ajoute l'item à la liste
        }

    lay=new QVBoxLayout();
    scroll=new QScrollArea();

    supprimer = new QPushButton("Supprimer");
    vider = new QPushButton("Vider");
    restaurer = new QPushButton("Restaurer");

    supprimer->setEnabled(false);
    restaurer->setEnabled(false);

    QObject::connect(vider, SIGNAL(clicked()), this, SLOT(vid()));
    QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(supp()));
    QObject::connect(list, SIGNAL(itemSelectionChanged()), this, SLOT(activerBoutons()));

    scroll->setWidget(list);

    lay->addWidget(scroll);
    lay->addWidget(restaurer);
    lay->addWidget(supprimer);
    lay->addWidget(vider);

    setLayout(lay);

}



