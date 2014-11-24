/**
 * \file	ImageFactory.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	gestion de la creation des notes de type image
 */

#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H
#include <QString>
#include "NoteFactory.h"
#include "Image.h"
#include "NotesManager.h"

/**
* \class ImageFactory ImageFactory.h
*/
class ImageFactory : public NoteFactory
{
public:
/**
 * \brief		Fonction qui cree une nouvelle note image
 * \param		title		titre de la note à créer
 */	
   Image* buildNoteNew(QString& title);
};
#endif // IMAGEFACTORY_H
