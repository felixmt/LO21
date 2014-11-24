/**
 * \file	ArticleFactory.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	gere la fabrication des articles, la classe herite de NoteFactory
 */

#ifndef ARTICLEFACTORY_H
#define ARTICLEFACTORY_H

#include <QString>
#include "NoteFactory.h"
#include "article.h"
#include "NotesManager.h"

/**
* \class ArticleFactory ArticleFactory.h
*/
class ArticleFactory : public NoteFactory {
public:

/**
 * \brief		Fonction qui cree un nouvel article
 * \param		title		titre de l'article a creer
 */	
   Article* buildNoteNew(QString& title);
};

#endif // ARTICLEFACTORY_H
