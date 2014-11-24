/**
 * \file	VideoFactory.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	gestion de la creation des notes de type video, hérite de note factory
 */

#ifndef VIDEOFACTORY_H
#define VIDEOFACTORY_H

#include <QString>
#include "NoteFactory.h"
#include "Video.h"
#include "NotesManager.h"

/**
* \class VideoFactory VideoFactory.h
*/
class VideoFactory : public NoteFactory {
public:
/**
 * \brief		Fonction qui cree une nouvelle note video
 * \param		title		titre de la note à créer
 */	
   Video* buildNoteNew(QString& title);
};
#endif // VIDEOFACTORY_H
