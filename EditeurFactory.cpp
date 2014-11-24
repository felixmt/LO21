#include "EditeurFactory.h"

EditeurFactory* EditeurFactory::chooseEditeur(QString& type) {
    QString typeArt = "art";
    QString typeVid = "vid";
    QString typeAud = "aud";
    QString typeImg = "img";
    QString typeDoc = "doc";

    if (type==typeArt) {
        ArticleEditeurFactory* editeurFactory = new ArticleEditeurFactory();
        return editeurFactory;
    }
    if (type==typeDoc) {
        DocumentEditeurFactory* editeurFactory = new DocumentEditeurFactory();
        return editeurFactory;
    }
    if (type==typeImg) {
        ImageEditeurFactory* editeurFactory = new ImageEditeurFactory();
        return editeurFactory;
    }
    if (type==typeAud) {
        AudioEditeurFactory* editeurFactory = new AudioEditeurFactory();
        return editeurFactory;
    }
    if (type==typeVid)  {
        VideoEditeurFactory* editeurFactory = new VideoEditeurFactory();
        return editeurFactory;
    }
}

ArticleEditeur* ArticleEditeurFactory::buildEditeur(Note* n) {
    ArticleEditeur* editeur = new ArticleEditeur(n);
    return editeur;
}

DocumentEditeur* DocumentEditeurFactory::buildEditeur(Note* n) {
    DocumentEditeur* editeur = new DocumentEditeur(n);
    return editeur;
}
ImageEditeur* ImageEditeurFactory::buildEditeur(Note* n) {
    ImageEditeur* editeur = new ImageEditeur(n);
    return editeur;
}

AudioEditeur* AudioEditeurFactory::buildEditeur(Note* n) {
    AudioEditeur* editeur = new AudioEditeur(n);
    return editeur;
}

VideoEditeur* VideoEditeurFactory::buildEditeur(Note* n) {
    VideoEditeur* editeur = new VideoEditeur(n);
    return editeur;
}
