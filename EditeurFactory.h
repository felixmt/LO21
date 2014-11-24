/**
 * \file	EditeurFactory.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	gestion de la creation des fenetres d'edition
 */

#ifndef EDITEURFACTORY_H
#define EDITEURFACTORY_H

#include"note.h"
#include "NotesEditeur.h"
#include "ArticleEditeur.h"
#include"ImageEditeur.h"
#include "VideoEditeur.h"
#include "AudioEditeur.h"
#include"documentEditeur.h"

/**
* \class EditeurFactory EditeurFactory.h
*/
class EditeurFactory
{
    //friend class NotesEditeur;
public:
    virtual NotesEditeur* buildEditeur(Note* n)=0;
    static EditeurFactory* chooseEditeur(QString& type);
};

/**
* \class ArticleEditeurFactory EditeurFactory.h
*/
class ArticleEditeurFactory : public EditeurFactory
{
public:
    ArticleEditeur* buildEditeur(Note* n);
};

/**
* \class DocumentEditeurFactory EditeurFactory.h
*/
class DocumentEditeurFactory : public EditeurFactory
{
public:
    DocumentEditeur* buildEditeur(Note* n);
};

/**
* \class ImageEditeurFactory EditeurFactory.h
*/
class ImageEditeurFactory : public EditeurFactory
{
public:
    ImageEditeur* buildEditeur(Note* n);
};


/**
* \class AudioEditeurFactory EditeurFactory.h
*/
class AudioEditeurFactory : public EditeurFactory
{
public:
    AudioEditeur* buildEditeur(Note* n);
};

/**
* \class VideoEditeurFactory EditeurFactory.h
*/
class VideoEditeurFactory : public EditeurFactory
{
public:
    VideoEditeur* buildEditeur(Note* n);
};

#endif // EDITEURFACTORY_H
