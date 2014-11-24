#include "Image.h"
#include "NotesManager.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>


Image& Image::operator=(const Image& i)
{
    this->Note::operator=(i);
    img=i.img;
    return *this;
}


void Image::save()
{
    if (this->isModified()) {
            // Création d'un objet QFile
            QString completePath = notePath +  this->getFilename() + (QString)".img";
            QFile file(completePath);
            //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            std::cout <<"Erreur sauvegarde d'un enregistrement image : impossible d'ouvrir un fichier en Ècriture"; //A FAIRE : Gestion des exceptions
            QTextStream flux(&file);
            flux<<this->getTitle() << "\n";
            flux<<this->getImg();
            file.close();
            std::cout << "Une sauvegarde d'un enregistrement image a été effectuée sur le chemin suivant:" << qPrintable(completePath)<<"/n";
        }
}



void Image::load(QString& path)
{
    QFile fichier(path);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    //A FAIRE : Vérifier la bonne ouverture du fichier et gérer les exceptions
    QTextStream flux(&fichier);
    QString title=flux.readLine();
    this->setTitle(title);
    QString text=flux.readAll();
    this->setImg(text);
    QString fname = path.mid(0,path.size()-4);
    this->setFilename(fname);
    fichier.close();
}

QString Image::exportText() {
    textContent = this->getTitle() + "\n\n" + this->getImg() + "\n";
    return textContent;
}

QString Image::exportHtml(bool appartenanceDoc)
{
    Note::exportHtml(appartenanceDoc);
    html += "<h2>" + title + "</h2>";
    html += "<p><img><source src=\"" + img + "\" /><p>"+ title +"</p></img></p>";
    if(!appartenanceDoc)
        html += "</body></html>";
    return html;
}

QString Image::exportLatex(bool appartenanceDoc)
{
    if(!appartenanceDoc)
        Note::exportLatex(appartenanceDoc);
    latex += "\\subsection{"+title+"}\n";
    latex +="\\begin{center}\n\\includegraphics{";
    latex+=getImg();
    latex+="}\\end{center}";
    if(!appartenanceDoc)
        latex += "\n \\end{document}";
    return latex;
}
