/**
 * \file	Tag.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Definit les tags qui peuvent être attribués aux notes.
 * \details	les fonctions qui permettent de manipuler les tags (association à des fichiers, suppression, ...) sont également implémentées ici.
 */

#ifndef TAG_H
#define TAG_H

#include <QString>
#include <QList>
#include "note.h"


class Note;
/**
* \class Tag Tag.h
*/
class Tag
{
    QString name ; /**< Nom du tag */
    QList <Note*> tabNotes; /**< Liste des notes auxquelles le tag est attribue */
public:
/**
 * \brief		Constructeur de tag
 * \details		Construit un tag avec pour nom le QString passe en parametre
 * \param		n		nom a donner au tag qui est instancie
 */
    Tag(QString& n):name(n){}
	
 /**
 * \brief		accesseur qui retourne le nom du tag
 * \return		Un QString qui correspond au nom du tag
 */
    QString& getName(){return name;}
	
 /**
 * \brief		accesseur qui retourne la position d'une note dans le tableau tabNotes
 * \return		Un int qui correspond a la position de la note
 */	
    int getPosNote(Note* n);

 /**
 * \brief		Fonction qui permet d'associer une note n a un tag
 * \details		ajoute la note n au tableau de notes tabNotes
 * \param		n	note a associer au tag
 */
 
/**
 * \brief		accesseur qui qui retourne une note
 * \param		i	position de la note dans le tableau tabNotes
 * \return		Une note qui correspond a la note situee à la position i dans le tableau tabNotes
 */
    Note* getNote(int i);
	
/**
 * \brief		accesseur qui qui retourne la taille du tableau de notes
 * \return		Un int qui correspond a la taille du tableau tabNotes
 */
    int getSize(){ return tabNotes.size(); }
	
/**
 * \brief		Fonction qui associe une note a un tag
 * \details		Ajoute la note n au tableau tabNotes
 * \param		n	note a associer au tag
 */
    void AddNote(Note* n);
	
 /**
 * \brief		Fonction qui permet de dissocier une note d'un tag
 * \details		retire une note du tableau de tag tabNotes
 * \param		i	position de la note dans le tableau tabNotes
 */
    void deleteNote(int i);

 /**
 * \brief		Destructeur de tag
 * \details		désalloue le tableau de tag tabNotes (les pointeurs vers les notes)
 */	
    ~Tag(){tabNotes.clear();}
};

#endif // TAG_H
