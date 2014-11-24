/**
 * \file	Fenetre.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Elements notes
 */

#ifndef NOTE_H
#define NOTE_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QList>
#include "Tag.h"
class Tag;
/**
* \class Note note.h
*/
class Note
{
public:
/**
* \brief		Constructeur de note
* \param		t		titre de la note
* \param		f		nom de fichier
* \param		ty		type de la note (article, document, video, ...)
* \param		p		chemin d'accès au fichier qui enregistre l'article
* \param		i		id de l'article
 */
    Note(const QString& t, const QString& f, const QString& ty, const QString& p, unsigned int i): title(t), type(ty), filename(f), id(i), modified(false), notePath(p){}
    //p sera appelé par le workPath de NotesManager
	
/**
 * \brief		Constructeur par recopie
 * \details		Construit une note à partir d'une note passee en paramètre
 * \param		n		note a recopier
 */	
    Note(const Note& n):title(n.title),filename(n.filename),type(n.type),id(n.id),modified(n.modified), notePath(n.notePath){}
	
	
    Note();
	
/**
 * \brief		Destructeur de note, fonction virtuelle, elle sera implémentee dans les classes filles
 */
    virtual ~Note(){}

//    Accesseurs
 /**
 * \brief		accesseur qui retourne le type de la note
 * \return		Un QString qui correspond au type de la note
 */
    QString getType() const {return type;}
	
 /**
 * \brief		accesseur qui retourne le filename
 * \return		Un QString qui correspond au filename de la note
 */
    QString getFilename() const {return filename;}
	
 /**
 * \brief		accesseur qui retourne l'attribut notePath
 * \return		Un QString qui correspond au notePath de la note
 */
    QString getNotePath() const {return notePath;}
	
 /**
 * \brief		accesseur qui retourne l'attribut html de la note
 * \return		Un QString qui correspond au code html de la note
 */
    QString getHtml() const { return html; }
	
 /**
 * \brief		accesseur qui retourne le type de la note
 * \return		Un QString qui correspond au type de la note
 */
    int getId() const {return id;}
	
 /**
 * \brief		accesseur qui retourne le type de la note
 * \return		Un integer qui correspond a l'id de la note
 */
    QString getTitle() const {return title;}
	
 /**
 * \brief		accesseur qui retourne le type d'une note sauvée dans un fichier
 * \param		path		chemin d'accès au fichier
 * \return		Un QString qui correspond au type de la note
 */
    QString getFileType(QString& path);
	
    QString getHtml() { return html; }
	
 /**
 * \brief		accesseur qui retourne l'attribut latex de la note
 * \return		Un QString qui correspond au code latex
 */
    QString getLatex() { return latex; }
	
    QString getTextContent() {return textContent;}
	
 /**
 * \brief		accesseur qui retourne le tag situé à la position i dans le tableau de tags de la note (tabTags)
 * \return		Un Tag
 */
    Tag* getTag(int i){ return tabTags[i];}

    //    Mutateurs
/**
 * \brief		Mutateur de l'attribut titre
 * \param		t	nouveau titre de l'article
 */
    void setTitle(const QString& t){title=t; setModified(true);}
	
/**
 * \brief		Mutateur de l'attribut NotePath
 * \param		p	nouveau NotePath de l'article
 */
    void setNotePath(QString& p) {notePath=p;}
	
/**
 * \brief		Mutateur de l'attribut modified
 * \param		b	booleen pour la nouvelle valeur de modified
 */
    void setModified(bool b){modified=b;}

/**
 * \brief		Mutateur de l'attribut id
 * \param		i	nouvel id à attribuer à l'article
 */
    void setId(int i){id=i;}
	
/**
 * \brief		Mutateur de l'attribut filename
 * \param		f	nouveau filename à attribuer à l'article
 */
    void setFilename(QString& f){filename=f;}

/**
 * \brief		Fonction virtuelle pure qui gérera l'export des notes au format texte
 */
    virtual QString exportText() =0 ;
	
/**
 * \brief		Fonction virtuelle qui gérera l'export des notes au format html
 * \param		appartenanceDoc		0 si la note n'appartient pas à un document, 1 sinon, 0 par défaut
 */
    virtual QString exportHtml(bool appartenanceDoc=0);
	
/**
 * \brief		Fonction virtuelle qui gérera l'export des notes au format latex
 * \param		appartenanceDoc		0 si la note n'appartient pas à un document, 1 sinon, 0 par défaut
 */
    virtual QString exportLatex(bool appartenanceDoc=0);

/**
 * \brief		Fonction qui sauve dans un fichier l'export au format texte
 */
    void saveExportText();
	
/**
 * \brief		Fonction qui sauve dans un fichier l'export au format html
 */
    void saveExportHtml();
	
/**
 * \brief		Fonction qui sauve dans un fichier l'export au format latex
 */
    void saveExportLatex();

/**
 * \brief		Accesseur de l'attribut modified, indique si la note a ete modifiee
 */
    bool isModified() const{return modified; }
	
/**
 * \brief		Fonction virtuelle pure qui sauve la note dans un fichier
 */
    virtual void save() =0;
	
/**
 * \brief		Fonction virtuelle pure qui charge une note depuis un fichier
 * \param		path	chemin d'accès au fichier
 */
    virtual void load(QString& path) =0;

/**
 * \brief		Fonction qui permet d'associer un nouveau tag a l'article (via le tableau tabtags)
 * \param		t		tag a associer
 */
    void addTag(Tag* t); // ajoute un tag associé à la note dans tabTags
	
/**
 * \brief		Fonction qui permet de dissocier un tag a l'article (via le tableau tabtags)
 * \param		t		tag a dissocier
 */
    void removeTag(Tag* t); // delete un tag associé à la note dans tabTags
	
/**
 * \brief		Fonction qui retourne la position du tag en parametre dans le tableau tabTags
 * \param		t		tag a localiser
 */
    int getTagPos(Tag* t); // renvoie la position dans tagTags du tag recherché
	
/**
 * \brief		Fonction qui retourne la taille du tableau tabTags
 */	
    int getSizeTabTags(){return tabTags.size();}


protected :


    QString title;
    QString filename;
    QString type;
    QString notePath;
    QString textContent;
    QString html;
    QString latex;
    unsigned int id;
    bool modified;
    QList <Tag*> tabTags;
};

#endif // NOTE_H
