#include "NoteFactory.h"
#include "ArticleFactory.h"
#include "DocumentFactory.h"
#include "ImageFactory.h"
#include "VideoFactory.h"
#include "AudioFactory.h"
#include "time.h"

 unsigned int NoteFactory::getNewId()
 {
     return time(NULL);
 }

 QString NoteFactory::getNewFilename(QString& type, unsigned int id)
 {
     QString n=QString::number(id);
     QString res=n+type;
     return res;
 }

NoteFactory* NoteFactory::chooseFactory(QString& title,QString& type)
  {
      if(type==(QString) "art") {
          ArticleFactory* artFact = new ArticleFactory;
          return artFact;
      }

      if(type==(QString) "doc") {
          DocumentFactory* docFact = new DocumentFactory;
          return docFact;
      }

      if(type==(QString) "img") {
          ImageFactory* imgFact = new ImageFactory;
          return imgFact;
      }

      if(type==(QString) "aud") {
          AudioFactory* audFact = new AudioFactory;
          return audFact;
      }

      if(type==(QString) "vid") {
          VideoFactory* vidFact = new VideoFactory;
          return vidFact;
      }

  }
/*
  QString NoteFactory::exportHtml(int id)
  {
     return NotesManager::getInstance().getNote(id).exportHtml(id);
  }
*/
