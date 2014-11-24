#include "Corbeille.h"
#include "NotesManager.h"
#include <QList>

Corbeille* Corbeille::instance = 0;
Corbeille::Corbeille(){}

Corbeille& Corbeille::getInstance(){if (!instance) instance= new Corbeille(); return *instance;}

Note* Corbeille::getNoteId(int id)
{
    for(int i=0; i<dust.size();i++)
    {
        if(dust[i]->getId()==id) return dust[i];
        else throw ("Erreur: la note demandée n'a pas été trouvée dans le corbeille.");
    }
}
Note* Corbeille::getNote(int i)
{

        if(i<dust.size()) return dust[i];
        else throw ("Erreur: la note demandée n'a pas été trouvée dans le corbeille.");

}

void Corbeille::addNote(Note* n)
{
    dust.append(n);
    std::cout<<dust.size()<<"taille de la corbeille";
  for (int i=0;i<n->getSizeTabTags();i++)
    {
        QString name = n->getTag(i)->getName();
        TagManager::getInstance().deleteAssociatedTag(name,n);
    }

   NotesManager::getInstance().deleteNote(n);
}

void Corbeille::putBackNote(Note* n)

{
    int j=getPosNote(n);
    NotesManager::getInstance().addNote(n);
     for (unsigned int i=0;i<n->getSizeTabTags();i++)
            {
                QString name = n->getTag(i)->getName();
                TagManager::getInstance().addAssociatedTag(name,n);
            }
            dust.removeAt(j);

}


int Corbeille::getPosNote(Note*n)
{
    for( int i=0;i<dust.size();i++)
        if(dust[i]==n) return i;
    throw("la note n'existe pas");
}


Note* Corbeille::getNoteViaName(QString name)
{
    for( int i=0; i<dust.size(); i++)
        if(dust[i]->getTitle()==name) return dust[i];
    throw("la note n'existe pas");
}


void Corbeille::deleteNote(Note* n)
{
    dust.removeAt(Corbeille::getInstance().getPosNote(n));
}

