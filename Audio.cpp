#include "Audio.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>

void Audio::save()
{
    if (this->isModified()) {
            // Création d'un objet QFile
            QString completePath = notePath +  this->getFilename() + (QString)".aud";
            QFile file(completePath);
            //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            std::cout <<"Erreur sauvegarde d'un enregistrement audio : impossible d'ouvrir un fichier en écriture"; //A FAIRE : Gestion des exceptions
            QTextStream flux(&file);
            flux<<this->getTitle() << "\n";
            flux<<this->getAud();
            file.close();
            std::cout << "Une sauvegarde d'un enregistrement audio' a été effectuée sur le chemin suivant:" << qPrintable(completePath)<<"/n";
        }
}



void Audio::load(QString& path)
{
    QFile fichier(path);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    //A FAIRE : Vérifier la bonne ouverture du fichier et gérer les exceptions
    QTextStream flux(&fichier);
    QString title=flux.readLine();
    this->setTitle(title);
    QString text=flux.readAll();
    this->setAud(text);
    QString fname = path.mid(0,path.size()-4);
    this->setFilename(fname);
    fichier.close();
}


QString Audio::exportText() {
    textContent = this->getTitle() + "\n\n" + this->getAud() + "\n";
    return textContent;
}

QString Audio::exportHtml(bool appartenanceDoc)
{
    Note::exportHtml(appartenanceDoc);
    html += "<p><audio controls><source src=\"" + aud + "\" /><p>"+ title +"</p></audio></p></body></html>";
    if(!appartenanceDoc)
        html += "</body></html>";
    return html;
}


QString Audio::exportLatex(bool appartenanceDoc)
{
    if(!appartenanceDoc)
        Note::exportLatex(appartenanceDoc);
    latex += "\\subsection{"+title+"}\n";
    latex += aud + "\n \\newline \n";
    if(!appartenanceDoc)
        latex += "\n \\end{document}";
    return latex;
}
