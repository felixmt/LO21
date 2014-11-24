/**
 * \file	NoteFactory.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	gestion de la creation des notes, classe abstraite
 */

#include "note.h"
#include <QString>

#ifndef NOTEFACTORY_H
#define NOTEFACTORY_H
/**
* \class NoteFactory NoteFactory.h
*/
class NoteFactory
{
    friend class NoteManager;
public:
/**
 * \brief		Fonction qui genere un nouvel id pour une note
 */	
    static unsigned int getNewId();
/**
 * \brief		Fonction virtuelle pure qui cree une nouvelle note
 * \param		title		titre de la note a creer
 */	
    virtual Note* buildNoteNew(QString& title)=0;
	
/**
 * \brief		Fonction static qui permet de choisir la bonne fabrique pour construire le type d'objet demande
 * \param		title		titre de la note a creer
 * \param		type		type de la note a creer
 */	
    static NoteFactory* chooseFactory(QString& title,QString& type); // choisi la bonne fabrique pour construire le type d'objet demandé par noteManager
	
/**
 * \brief		Fonction qui permet de generer le nom de fichier d'une note
 * \param		id			id de la note a creer
 * \param		type		type de la note a creer
 * \return 		Un QString qui est le nom de fichier genere
 */
    QString getNewFilename(QString& type, unsigned int id);
};

#endif // NOTEFACTORY_H
