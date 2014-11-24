#include "ImageFactory.h"
#include "Image.h"




Image*  ImageFactory::buildNoteNew(QString& title)
{
    unsigned int id=NoteFactory::getNewId();
    QString type = (QString) "img";
    Image* im = new Image(getNewFilename(type,id),title, NotesManager::getInstance().getWorkPath(), id, (QString)"");
    im->setModified();
    return im;
}




