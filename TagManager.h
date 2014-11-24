/**
 * \file	TagManager.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Gestionnaire de tags, classe singleton
 */

#ifndef TAGMANAGER_H
#define TAGMANAGER_H

#include <QList>

#include "Tag.h"
/**
* \class TagManager TagManager.h
*/
class TagManager
{
    static TagManager* instance;
    TagManager();

    TagManager& operator=(const TagManager&);
    QList <Tag*> tabTags ;

public:
    ~TagManager();
/**
 * \brief		Fonction qui cree une instance de TagManager s'il n'en existe pas une (TagManager est une classe singleton)
 */
    static TagManager& getInstance();
	/**
 * \brief		Fonction qui supprime une instance de TagManager s'il en existe une.
 */
    static void deleteInstance(){if(instance) instance->~TagManager(),instance=0;}
	

    Tag* getTag(QString& name);
    Tag* getTag(int pos);
	
/**
 * \brief		Fonction qui associe un tag a une note
 * \param		name	nom du tag a associer
 * \param		n		note a associer au tag
 */
    void addAssociatedTag(QString& name,Note* n);
	
/**
 * \brief		Fonction qui dissocie un tag a une note
 * \param		name	nom du tag a associer
 * \param		n		note a associer au tag
 */
    void deleteAssociatedTag(QString& name, Note* n);
	
	/**
 * \brief		Fonction qui supprime un tag
 * \param		n	 tag a supprimer
 */
    void deleteTag(Tag* n);
    int getTagPos(Tag* t);
	
	/**
 * \brief		Fonction qui ajoute un tag
 * \param		n	 tag a ajouter
 */
    void addTag(Tag*t);
    //void creatTag();
    int getTabTagsSize(){ return tabTags.size(); }
    Tag* getTagByPos(int i){ return tabTags[i]; }
};


#endif // TAGMANAGER_H
