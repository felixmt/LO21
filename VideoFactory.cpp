#include "Video.h"
#include "VideoFactory.h"

Video*  VideoFactory::buildNoteNew(QString& title)
{
    unsigned int id=NoteFactory::getNewId();
    QString type = (QString) "vid";
    Video* vi = new Video(getNewFilename(type,id),title, NotesManager::getInstance().getWorkPath(), id, (QString)"");
    vi->setModified();
    return vi;
}
