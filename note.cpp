#include "note.h"
#include <iostream>
#include "TagManager.h"



QString Note::getFileType(QString& path)
{
    QString type = path.mid(path.size()-7,3);
    return type;
}


void Note::addTag(Tag* t)
{
    if(TagManager::getInstance().getTag(t->getName()))
            TagManager::getInstance().addTag(t);
    for(int i=0;i<tabTags.size();i++){
        if(tabTags[i]->getName() == t->getName())
            return;
    }
    tabTags.append(t);
    t->AddNote(this);
}

void Note::removeTag(Tag* t)
{
    int i = getTagPos(t);
    tabTags.removeAt(i);
}

int Note::getTagPos(Tag* t)
{
    for (unsigned int i = 0 ; i<tabTags.size() ; i++)
    {
        if(tabTags[i]->getName()==t->getName()) return i;
    }
    return -1;
    throw ("Le tag recherché n'existe pas.");
}

QString Note::exportHtml(bool appartenanceDoc)
{
    if(!appartenanceDoc)
        html = "<html><head></head><body>";
    else
        html = "";
    return getHtml();
}

QString Note::exportLatex(bool appartenanceDoc)
{
    if(!appartenanceDoc)
        latex = "\\documentclass{article}\n\\usepackage[utf8]{inputenc}\n\\usepackage[T1]{fontenc}\n\\usepackage[francais]{babel}\n\\begin{document}\n";
    else
        latex = "";
    return latex;
}

void Note::saveExportText() {
    if (this->isModified()) {
            // Création d'un objet QFile
            QString completePath = notePath +  this->getFilename() + (QString)".txt";
            QFile file(completePath);
            //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            std::cout <<"Erreur export text : impossible d'ouvrir un fichier en écriture"; //A FAIRE : Gestion des exceptions
            QTextStream flux(&file);
            flux<<this->getTextContent() << "\n";
            file.close();
            this->setModified(false);
        }
}

void Note::saveExportHtml() {
    if (this->isModified()) {
            // Création d'un objet QFile
            QString completePath = notePath +  this->getFilename() + (QString)".html";
            QFile file(completePath);
            //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            std::cout <<"Erreur export html : impossible d'ouvrir un fichier en écriture"; //A FAIRE : Gestion des exceptions
            QTextStream flux(&file);
            flux<<this->getHtml() << "\n";
            file.close();
            this->setModified(false);
        }
}

void Note::saveExportLatex() {
    if (this->isModified()) {
            // Création d'un objet QFile
            QString completePath = notePath +  this->getFilename() + (QString)".tex";
            QFile file(completePath);
            //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            std::cout <<"Erreur export text : impossible d'ouvrir un fichier en écriture"; //A FAIRE : Gestion des exceptions
            QTextStream flux(&file);
            flux<<this->getLatex() << "\n";
            file.close();
            this->setModified(false);
        }
}
