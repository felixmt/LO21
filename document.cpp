#include "document.h"
#include <QFile>
#include <QTextStream>
#include <iostream>


Document&  Document::operator<<(Note* a)
{
    notes<<a;
    return *this ;
}

Note* Document::getNote(unsigned int i)
{
    return notes[i];
}

const Note* Document::getNote(unsigned int i) const
{
    return notes[i];
}

unsigned int Document::getPosNote(Note* note) const
{
    for (unsigned int i=0; i<notes.size();i++)
        if (notes[i]->getId()==note->getId()) return i;
    return -1;
}

void Document::removeNote(unsigned int i){
    if (i<notes.size()){
        Corbeille::getInstance().addNote(notes[i]); //Problème : supprime toutes les notes du document.
        notes.removeAt(i);
        setModified(true);
    }//else throw NotesException("error, removing an article");
}

void Document::moveNoteUp(unsigned int i)
{
    if (i<notes.size() && i>0){
        Note* n=notes[i];
        notes[i]=notes[i-1];
        notes[i-1]=n;
        modified=true;
    }//else throw NotesException("error, moving up an article");
}

void Document::moveNoteDown(unsigned int i)
{
    if (i>=0 && i<notes.size()-1){
        Note* n=notes[i];
        notes[i]=notes[i+1];
        notes[i+1]=n;
        modified=true;
    }//else throw NotesException("error, moving down an article");
}

Document& Document::operator=(const Document& d){
    if (this!=&d){
        filename=d.filename;
        title=d.title;
        notePath=d.notePath;
        QList <Note*> newNotes;
        for(unsigned int i=0; i<d.notes.size(); i++) newNotes[i]=d.notes[i];
        QList <Note*> old=notes;
        notes=newNotes;
        old.clear();
    }
    return *this;
}

void Document::save()
{
    if (this->isModified()) {
            // Création d'un objet QFile
            QString completePath = notePath +  this->getFilename() + (QString)".doc";
            QFile file(completePath);
            //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            std::cout <<"Erreur sauvegarde d'un article : impossible d'ouvrir un fichier en Ècriture";
            QTextStream flux(&file);
            flux<<this->getTitle() << "\n";
            for (unsigned int i =0 ; i<notes.size() ; i++)
            {
                flux << notePath + notes[i]->getFilename() + (QString)"." << notes[i]->getType() << endl;
                notes[i]->save();
            }
            file.close();
            std::cout << "Une sauvegarde d'un document a été effectuée sur le chemin suivant:" << qPrintable(completePath) ;
            this->setModified(false);

        }
}

void Document::load(QString& path)
{
    QFile fichier(path);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    //A FAIRE : Vérifier bonne ouverture et exceptions
    QTextStream flux(&fichier);
    QString title=flux.readLine();
    this->setTitle(title);
    QString fname = path.mid(0,path.size()-4);
    this->setFilename(fname);
    while (!flux.atEnd())
    {
        QString path = flux.readLine();
        QString type = getFileType(path);
        Note* n = NotesManager::getInstance().getFileNote(path,type);
        n->load(path);
        notes.push_back(n);
    }
    fichier.close();
}

void Document::addNote(Note *n)
{
   notes.push_back(n);
}

QString Document::exportText()
{
    textContent= this->getTitle()+"\n\n";
    for (unsigned int i=0; i<this->getSize(); i++)
        textContent+=notes[i]->exportText();
    return textContent;
}

QString Document::exportHtml(bool appartenanceDoc)
{
    Note::exportHtml(0); // sauf si un doc peut appartenir lui mm à un doc?--------------
    html += "<h1>" + title + "</h1>";
    for(int i=0; i<notes.size();i++)
        html += notes[i]->exportHtml(1);
    html += "</body></html>";

    return html;
}

QString Document::exportLatex(bool appartenanceDoc)
{
    Note::exportLatex(0); // sauf si un doc peut appartenir lui mm à un doc?--------------
    latex += "\\section{"+title+"}\n";
    for(int i=0; i<notes.size();i++)
        latex += notes[i]->exportLatex(1);
    latex += "\n \\end{document}";

    return latex;
}

