/**
 * \file	DocumentFactory.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Fenetre de la creation de documents
 */


#ifndef DOCUMENTFACTORY_H
#define DOCUMENTFACTORY_H

#include <QString>
#include "NoteFactory.h"
#include "document.h"

/**
* \class DocumentFactory DocumentFactory.h
*/
class DocumentFactory : public NoteFactory
{
public:
/**
 * \brief		Fonction qui cree une nouvelle note document
 * \param		title		titre de la note à créer
 */	
   Document* buildNoteNew(QString& title);
};


#endif // DOCUMENTFACTORY_H
