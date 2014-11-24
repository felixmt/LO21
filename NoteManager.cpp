#include "NotesManager.h"
#include "TagManager.h"

#include<QFile>
#include <iostream>
#include <QTextStream>
#include <QDir>



NotesManager* NotesManager::instance= 0; // pointeur sur l'unique instance

 NotesManager::~NotesManager(){
     NotesManager::saveWorkSpace();

    //Destruction des notes
    for(unsigned int i=0; i<tab.size(); i++)
    {
//        std::cout << "taille : " << tab.size();
        tab[i]->save();
//        delete tab[i];
    }
//    tab.clear();

}
QString NotesManager::getLastNameWS(){
    QString CurrentDir = QDir::currentPath();

    QString describeFileWorkPath = CurrentDir  + (QString) "/describeFileWorkPath";
    QFile file(describeFileWorkPath );
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        std::cout << "Erreur lors de la creation du note Manager" << "\n" ;
    QTextStream flux(&file);
    QString WSpath;
     WSpath=flux.readLine();
    file.close();
    return WSpath;

}


int NotesManager::getFileId(QString& path)
{
        int id = path.mid(path.size()-17,10).toInt();
        return id;
}


void NotesManager::saveNote(Note& n)
{
    n.save();
}


Note& NotesManager::getNote(unsigned int id)
{
    for (unsigned int i=0; i<tab.size(); i++)
    {
        if (id==tab[i]->getId()) return *tab[i];
    }
    throw ("L'objet recherché est inexistant.");
}

Note* NotesManager::getNoteByPos(int pos)
{
    if(pos < tab.size())
        return tab[pos];
    else
        throw "indice passé en paramètre plus grand que la taille du tableau";
}

Note* NotesManager::getNewNote(QString& title,QString& type)
{
    NoteFactory* nf = NoteFactory::chooseFactory(title,type);
    Note* n = nf->buildNoteNew(title);
    instance->addNote(n);
    return n;
}


void NotesManager::addNote(Note* n)
{
    tab.append(n);
}

void NotesManager::deleteNote(Note* n){
    for(int i=0;i<tab.size();i++) {
        if(tab[i]==n) tab.removeAt(i);
    }
}

Note* NotesManager::getFileNote(QString& path,QString& type)
{
    QString title = (QString) "title";
    Note* n = getNewNote(title,type);
    n->load(path);
    return n;
}


void NotesManager::createNewWorkspace(QString& wp) {

    NotesManager::saveWorkSpace();
    //set workPath
    workPath=wp;
}

void NotesManager::createNewWorkspaceFrom(QString& wp) {
    //création du fichier de description du workspace
    NotesManager::saveWorkSpace();
    QString name=NotesManager::getLastNameWS();
    NotesManager::loadWorkSpace(name);
    //set workPath
    workPath=wp;
}

QString NotesManager::getFileType(QString& path)
{
    QString type = path.mid(path.size()-7,3);
    return type;
}

void NotesManager::loadWorkSpace(QString& workPath)
{


    //Chargement des notes
    QString describeFilePath = workPath + (QString)"describeFilePath";
    QFile file(describeFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        std::cout << "Erreur d'un chargement d'un espace de travail" << "\n" ;
    QTextStream flux(&file);
    while (!flux.atEnd())
    {
        QString path = flux.readLine();
        QString type = instance->getFileType(path);
        Note* n=instance->getFileNote(path,type);
        int id=getFileId(path);
        n->setId(id);
        QString fileName=id+type;
        n->setFilename(fileName);

        //Chargement des tags
        QString describeFileTag = workPath + (QString)"describeFileTag";
        QFile file2(describeFileTag);
        if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
            std::cout << "Erreur d'un chargement d'un espace de travail" << "\n" ;
        QTextStream flux2(&file2);
        while (!flux2.atEnd())
        {
            QString ligne = flux2.readLine();
            QString espace=(QString)" ";
            int z=0;
            int i=ligne.indexOf(espace,z);

            QString tag;
            int size=ligne.size();
            for(int j=0;j<i;j++)
            {

                tag+=ligne[j];

            }
            z++;
            int finDeMot=i;

            while(finDeMot<size)
            {
                int k=ligne.indexOf(espace,z);
                QString mot;
                for(int l=finDeMot;l<k;l++)
                {
                    mot+=ligne[l];
                    finDeMot++;

                }

                int id=mot.toInt();
                Note& n1=NotesManager::getInstance().getNote(id);
                Note* pointeur=&n1;
                TagManager::getInstance().addAssociatedTag(tag,pointeur);
            }


    }
    file2.close();

}

 }


void NotesManager::saveWorkSpace()
{
    //création du fichier de description du workspace
    QString describeFilePath = workPath + (QString) "describeFile.txt";
    QFile file(describeFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    std::cout <<"Erreur sauvegarde d'un article : impossible d'ouvrir un fichier en Ècriture"; //A FAIRE : Gestion des exceptions
    //Sauvegarder et référencer les Notes dans le describeFile et détruire chaque note
    QTextStream flux(&file);
    std::cout<<"Le nombre de note est "<<tab.size()<<"/n";
    for (unsigned int i=0; i<tab.size(); i++) {
        tab[i]->save();
        QString path=tab[i]->getNotePath()+tab[i]->getFilename()+(QString)"."+tab[i]->getType();
        std::cout<<"la note est "<<qPrintable(path)<<"/n";

        flux<<path << "\n"; //A VERIFIER POUR LA TERMINAISON
        delete tab[i];
    }
    file.close();
    QString completePath = NotesManager::getInstance().getWorkPath() +(QString)"describeTagFile";
    QFile file2(completePath);
    //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout <<"Erreur sauvegarde tags : impossible d'ouvrir un fichier en Ècriture"; //A FAIRE : Gestion des exceptions
    QTextStream flux2(&file2);
    for(int i=0; i<TagManager::getInstance().getTabTagsSize();i++)
    {       flux2 << TagManager::getInstance().getTagByPos(i)->getName()<< "\n";
        for(int j = 0; j<TagManager::getInstance().getTagByPos(i)->getSize(); j++)
            flux2 <<TagManager::getInstance().getTagByPos(i)->getNote(j)->getId() << "\n";
        flux2<< "\n";
    }
    //suppression des tags
    file2.close();

}

Note* NotesManager::getNoteByTitle(QString& title)
{
    for(int i=0; i< tab.size();i++)
        if(tab[i]->getTitle() == title)
            return tab[i];
}
