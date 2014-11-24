#include "ArticleFactory.h"
#include "Article.h"

Article*  ArticleFactory::buildNoteNew(QString& title)
{
    unsigned int id=NoteFactory::getNewId();
    QString type = (QString) "art";
    std::cout<<"La note est cree avec le path"<<qPrintable(NotesManager::getInstance().getWorkPath());
    Article* article = new Article(getNewFilename(type,id),title,"",NotesManager::getInstance().getWorkPath(), id);
    article->setModified(true);
    return article;
}



