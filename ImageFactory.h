/**
 * \file	ImageFactory.h
 * \author	F�lix, Victor
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
 * \param		title		titre de la note � cr�er
 */	
   Image* buildNoteNew(QString& title);
};
#endif // IMAGEFACTORY_H
