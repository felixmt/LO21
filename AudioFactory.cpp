#include "Audio.h"
#include "AudioFactory.h"

Audio*  AudioFactory::buildNoteNew(QString& title)
{
    unsigned int id=NoteFactory::getNewId();
    QString type = (QString) "aud";
    Audio* au = new Audio(getNewFilename(type,id),title, NotesManager::getInstance().getWorkPath(), id, (QString)"");
    au->setModified();
    return au;
}
