/**
 * \file	article.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Definit les notes de type article.
 * \details	les fonctions qui permettent de manipuler les tags (association à des fichiers, suppression, ...) sont également implémentees ici. La classe herite de Note
 */

#ifndef ARTICLE_H
#define ARTICLE_H

#include "note.h"
/**
* \class Article article.h
*/
class Article: public Note {
    friend class NotesManager;
    QString text; /**< Texte de l'article */
	
/**
 * \brief		Constructeur d'article par recopie
 * \param		a		Article a recopier
 */
    Article(const Article& a): Note(a.title,a.filename,"art",a.notePath,a.id),text(a.text){}
	
/**
 * \brief		Surcharge de l'operateur =
 * \param		a		Article de la partie droite du =
 */
    Article& operator=(const Article&);
	
public:
/**
 * \brief		Constructeur d'article
 * \param		f		nom du fichier associe à l'article
 * \param		ti		titre de l'article
 * \param		te		texte de l'article
 * \param		p		chemin d'accès au fichier
 * \param		i		id de l'article
 */
    Article(const QString& f, const QString& ti, const QString& te, const QString& p, unsigned int i):Note(ti,f,"art",p,i),text(te){}
	
/**
 * \brief		Accesseur de l'attribut texte
 * \return		Un QString qui correspond au texte de l'article
 */
    const QString& getText() const { return text;}
	
/**
 * \brief		Mutateur de l'attribut texte
 * \param		t	nouveau texte à attribuer à l'article
 */
    void setText(const QString& t){text=t; setModified(true);}
	
/**
 * \brief		Fonction qui lit un fichier pour recuperer les valeurs d'attributs a attribuer a l'instance courante
 * \param		path	chemin d'accès du fichier a lire
 */
    void load(QString& path);
	
/**
 * \brief		Fonction qui sauve l'article dans un fichier
 */
    void save();

/**
 * \brief		Fonction qui exporte un article au format texte
 * \return		Un QString correspondant au contenu de l'article
 */
    QString exportText();
	
/**
 * \brief		Fonction qui exporte un article au format html
 * \param		appartenanceDoc		booléen a zero si l'article n'appartient pas a un document, 1 sinon
 * \return		Un QString correspondant au html
 */
    QString exportHtml(bool appartenanceDoc=0);
	
/**
 * \brief		Fonction qui exporte un article au format latex
 * \param		appartenanceDoc		booléen a zero si l'article n'appartient pas a un document, 1 sinon
 * \return		Un QString correspondant au latex
 */
    QString exportLatex(bool appartenanceDoc=0);
};
#endif // ARTICLE_H
