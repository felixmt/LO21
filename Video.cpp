#include "Video.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>

void Video::save()
{
    if (this->isModified()) {
            // Création d'un objet QFile
            QString completePath = notePath +  this->getFilename() + (QString)".vid";
            QFile file(completePath);
            //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            std::cout <<"Erreur sauvegarde d'un enregistrement video : impossible d'ouvrir un fichier en écriture"; //A FAIRE : Gestion des exceptions
            QTextStream flux(&file);
            flux<<this->getTitle() << "\n";
            flux<<this->getVid();
            file.close();
            std::cout << "Une sauvegarde d'un enregistrement video' a été effectuée sur le chemin suivant:" << qPrintable(completePath)<<"/n";
        }
}



void Video::load(QString& path)
{
    QFile fichier(path);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    //A FAIRE : Vérifier la bonne ouverture du fichier et gérer les exceptions
    QTextStream flux(&fichier);
    QString title=flux.readLine();
    this->setTitle(title);
    QString text=flux.readAll();
    this->setVid(text);
    QString fname = path.mid(0,path.size()-4);
    this->setFilename(fname);
    fichier.close();
}

QString Video::exportText() {
    textContent = this->getTitle() + "\n\n" + this->getVid() + "\n";
    return textContent;
}


QString Video::exportHtml(bool appartenanceDoc)
{
    Note::exportHtml(appartenanceDoc);
    html += "<p><video controls><source src=\"" + vid + "\" type=’video/mp4; codecs=\"avc1.4D401E, mp4a.40.2\"’/><p>" + title + "</p></video></p></body></html>";
    if(!appartenanceDoc)
        html += "</body></html>";
    return html;
}

QString Video::exportLatex(bool appartenanceDoc)
{
    if(!appartenanceDoc)
        Note::exportLatex(appartenanceDoc);
    latex += "\\subsection{"+title+"}\n";
    latex += vid + "\n \\newline \n";
    if(!appartenanceDoc)
        latex += "\n \\end{document}";
    return latex;
}
