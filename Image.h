/**
 * \file	Image.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	gestion des notes de type image, cette classe hérite de Note
 */

#ifndef IMAGE_H
#define IMAGE_H

#include "note.h"

/**
* \class Image Image.h
*/
class Image : public Note {
    friend class NotesManager;
    QString img;
	/**
 * \brief		Constructeur d'image par recopie
 * \param		i		Image a recopier
 */
    Image(const Image& i): Note(i.title,i.filename,"img",i.notePath,i.id),img(i.img){}
    Image& operator=(const Image&);
public:

	/**
 * \brief		Constructeur d'image
 * \param		f		nom du fichier
 * \param		ti		titre
 * \param		wp		chemin d'accès au fichier
 * \param		i		id de l'image
 * \param		p		chemin d'accès à l'image
 */
    Image(const QString& f, const QString& ti, const QString& wp,unsigned int i, const QString& p=(QString)""): Note(ti,f,"img",wp,i),img(p){}

	
	/**
 * \brief		Fonction qui lit un fichier pour recuperer les valeurs d'attributs a attribuer a l'instance courante
 * \param		path	chemin d'accès du fichier a lire
 */
    void load(QString& path);
	
/**
 * \brief		Fonction qui sauve l'article dans un fichier
 */
    void save();
	
    QString getImg() { return img;}

    void setImg(QString pImage) {img=pImage;}
    void setModified() {modified=true;}
	
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

#endif // IMAGE_H
