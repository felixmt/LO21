#include "article.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>




Article& Article::operator=(const Article& a)
{
    this->Note::operator=(a);
    text=a.text;
    return *this;
}


void Article::save()
{
    if (this->isModified()) {
            // Création d'un objet QFile
            QString completePath = notePath +  this->getFilename() + (QString)".art";
            QFile file(completePath);
            //On ouvre notre fichier en écriture et on vÈrifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            std::cout <<"Erreur sauvegarde d'un article : impossible d'ouvrir un fichier en Ècriture"; //A FAIRE : Gestion des exceptions
            QTextStream flux(&file);
            flux<<this->getTitle() << "\n";
            flux<<this->getText();
            file.close();
            std::cout << "Une sauvegarde d'un article' a été effectuée sur le chemin suivant:" << qPrintable(completePath)<<"/n";
            this->setModified(false);
        }
}

void Article::load(QString& path)
{
    QFile fichier(path);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    //A FAIRE : Vérifier la bonne ouverture du fichier et gérer les exceptions
    QTextStream flux(&fichier);
    QString title=flux.readLine();
    this->setTitle(title);
    QString text=flux.readAll();
    this->setText(text);
    QString fname = path.mid(0,path.size()-4);
    this->setFilename(fname);
    fichier.close();
}


QString Article::exportText() {
    textContent = this->getTitle() + "\n\n" + this->getText() + "\n";
    return textContent;
}


QString Article::exportHtml(bool appartenanceDoc)
{
    Note::exportHtml(appartenanceDoc);
    html += "<h2>" + title + "</h2>";
    QTextStream flux(&text);
    QString ligne_tmp;
    while (!flux.atEnd())
    {
        ligne_tmp = flux.readLine();
        if(ligne_tmp == "")
            html += "<br />";
        else
            html += "<p>" + ligne_tmp + "</p>";
    }
    if(!appartenanceDoc)
        html += "</body></html>";
    return html;
}

QString Article::exportLatex(bool appartenanceDoc)
{
    if(!appartenanceDoc)
        Note::exportLatex(appartenanceDoc);
    latex += "\\subsection{"+title+"}\n";
    QTextStream flux(&text);
    QString ligne_tmp;
    while (!flux.atEnd())
    {
        ligne_tmp = flux.readLine();
        if(ligne_tmp == "")
            latex += "\n";
        else
            latex += ligne_tmp + "\n \\newline \n";
    }
    if(!appartenanceDoc)
        latex += "\n \\end{document}";
    return latex;
}
