#include "TagManager.h"
#include "Tag.h"
#include "NotesManager.h"
#include <QFile>
#include <QTextStream>


TagManager* TagManager::instance = 0;
TagManager::TagManager(){}

 TagManager& TagManager::getInstance()
 {
    std::cout<<"J'ai utilisé getInstance()\n";
    if(!instance)
    {
        instance= new TagManager();
        QString path = NotesManager::getInstance().getWorkPath() + (QString) "describeTagFile";
        QFile fichier(path);
        fichier.open(QIODevice::ReadOnly | QIODevice::Text);
        //A FAIRE : Vérifier la bonne ouverture du fichier et gérer les exceptions
        QTextStream flux(&fichier);
        QString tmp;
        Tag* tag;
        bool test = 1;
        while(!flux.atEnd())
        {
            if(test)
            {
                QString tmpstr = (QString)tmp;
                tag = new Tag(tmpstr);
                instance->addTag(tag);
                test=0;
            }
            else if(!test && tmp == "\n")
            {
               test = 1;
               break;
            }
            else if(!test)
            {
                TagManager::getInstance().addAssociatedTag(tag->getName(),&NotesManager::getInstance().getNote(tmp.toInt()));
            }
            tmp =flux.readLine();
        }
        fichier.close();
    }
    return *instance;
}


Tag* TagManager::getTag(QString& name)
{
    std::cout<<"J'ai utilisé getTag(QString name)\n";
    for (unsigned int i = 0 ; i<tabTags.size() ; i++)
    {
        if(tabTags[i]->getName()==name) return tabTags[i];
    }
    return 0 ;
}

Tag* TagManager::getTag(int pos)
{
    std::cout<<"J'ai utilisé getTag(int pos)\n";
    if(pos < tabTags.size())
        return tabTags[pos];
    else
        throw "cette position n'existe pas";
}

void TagManager::addAssociatedTag(QString& name,Note* n)
{
    //Si le tag existe au nom demandé, on rajoute la note au tableau du tag
    Tag*t = getTag(name);
    if (t!=0)
    {
        std::cout<<"J'ai utilisé addAssociatedTag() avec un tag qui n'existe pas\n";
        t->AddNote(n);
    }

    //Si le tag n'existe pas, on crée le tag
    else
    {
        std::cout<<"J'ai utilisé addAssociatedTag() avec un tag qui existe\n";
        Tag* t1 = new Tag(name);
        t1->AddNote(n);
        tabTags<<t1;
        t=t1;
    }
    n->addTag(t);
}


void TagManager::deleteAssociatedTag(QString& name, Note* n)
{
    std::cout<<"J'ai utilisé deleteAssociatedTag()\n";
    Tag* t = getTag(name);
    int i = t->getPosNote(n);
    n->removeTag(t);
    t->deleteNote(i);

}

 /*void TagManager::deleteInstance()
{
     if(instance) instance=0;
}*/

int TagManager::getTagPos(Tag* t)
{
    std::cout<<"J'ai utilisé getTagPos()\n";
    for (unsigned int i = 0 ; i<tabTags.size() ; i++)
    {
        if(tabTags[i]==t) return i;
    }
    throw ("Le tag recherché n'existe pas.");
    return -1;
}

void TagManager::deleteTag(Tag* t)
{
    std::cout<<"J'ai utilisé deleteTag()\n";
     int i = getTagPos(t);
     for(unsigned int i=0;i<tabTags.size();i++)
     {
         Note* n = t->getNote(i);
         n->removeTag(t);
     }
    tabTags.removeAt(i);

}


void TagManager::addTag(Tag*t)
{
    std::cout<<"J'ai utilisé addTag()\n";
    for(int i=0;i<tabTags.size(); i++)
    {
        if(tabTags[i]->getName() == t->getName())
            return;
    }
    tabTags.append(t);

}

TagManager::~TagManager()
{
    QString completePath = NotesManager::getInstance().getWorkPath() + QString("describeTagFile");
    QFile file(completePath);
    //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout <<"Erreur sauvegarde tags : impossible d'ouvrir un fichier en Ècriture"; //A FAIRE : Gestion des exceptions
    QTextStream flux(&file);
    for(int i=0; i<tabTags.size();i++)
    {
//        std::cout << "\n\n tabtags names : " << qPrintable(tabTags[i]->getName());
        flux << tabTags[i]->getName() << "\n";
//        std::cout << "\n\n tabtags[i] size : " << qPrintable(tabTags[i]->getName());
        for(int j = 0; j<tabTags[i]->getSize(); j++)
            flux << tabTags[i]->getNote(j)->getId() << "\n";
        flux << "\n";
    }
    //suppression des tags
    file.close();
//    for( int i=0;i<tabTags.size();i++)
//        delete tabTags[i];
}

