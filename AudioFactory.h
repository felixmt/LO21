/**
 * \file	AudioFactory.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Gestion de la creation des notes audio, hérite de NoteFactory
 */

#ifndef AUDIOFACTORY_H
#define AUDIOFACTORY_H

#include <QString>
#include "NoteFactory.h"
#include "Audio.h"
#include "NotesManager.h"

/**
* \class NoteFactory NoteFactory.h
*/
class AudioFactory : public NoteFactory {
public:
/**
 * \brief		Fonction qui cree une nouvelle note audio
 * \param		title		titre de la note a creer
 */	
   Audio* buildNoteNew(QString& title);
};

#endif // AUDIOFACTORY_H
