#include "DocumentFactory.h"


Document* DocumentFactory::buildNoteNew(QString& title)
{
    unsigned int id=NoteFactory::getNewId();
    QString type = (QString) "doc";
    Document* document = new Document(title,getNewFilename(type,id),NotesManager::getInstance().getWorkPath(),id);
    document->setModified(true);
    return document;
}

