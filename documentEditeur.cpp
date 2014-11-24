#include "documentEditeur.h"

DocumentEditeur::DocumentEditeur(Note* d, QWidget *parent) : NotesEditeur(d) {
   scrollArea = new QScrollArea();
   conteneur = new QWidget(scrollArea);
   conteneur->setWindowState(Qt::WindowMaximized);
   layConteneur = new QVBoxLayout(this);

   document = dynamic_cast<Document*>(d);
   layout->addWidget(title);

   mapper = new QSignalMapper();

   for(unsigned int i=0; i<document->getSize(); i++) {
       QString typeArt = "art";
       QString typeVid = "vid";
       QString typeAud = "aud";
       QString typeImg = "img";
       Note* n = document->getNote(i);
       if (document->getNote(i)->getType()==typeArt) {
           ArticleEditeur* editeur = new ArticleEditeur(document->getNote(i));
           editeur->setFixedWidth(800);
           liste.push_back(editeur);
           layConteneur->addWidget(liste[i]);
           QObject::connect(editeur->getSuppButton(), SIGNAL(clicked()), mapper, SLOT(map()));
           mapper->setMapping(editeur->getSuppButton(), i);
       }
       if (document->getNote(i)->getType()==typeVid) {
           VideoEditeur* editeur = new VideoEditeur(document->getNote(i));
           editeur->setFixedWidth(800);
           liste.push_back(editeur);
           layConteneur->addWidget(liste[i]);
           QObject::connect(editeur->getSuppButton(), SIGNAL(clicked()), mapper, SLOT(map()));
           mapper->setMapping(editeur->getSuppButton(), i);
       }
       if (document->getNote(i)->getType()==typeAud) {
           AudioEditeur* editeur = new AudioEditeur(document->getNote(i));
           editeur->setFixedWidth(800);
           liste.push_back(editeur);
           layConteneur->addWidget(liste[i]);
           QObject::connect(editeur->getSuppButton(), SIGNAL(clicked()), mapper, SLOT(map()));
           mapper->setMapping(editeur->getSuppButton(), i);
       }
       if (document->getNote(i)->getType()==typeImg) {
           ImageEditeur* editeur = new ImageEditeur(document->getNote(i));
           editeur->setFixedWidth(800);
           liste.push_back(editeur);
           layConteneur->addWidget(liste[i]);
           QObject::connect(editeur->getSuppButton(), SIGNAL(clicked()), mapper, SLOT(map()));
           mapper->setMapping(editeur->getSuppButton(), i);
       }
       connect(mapper, SIGNAL(mapped(int)), this, SLOT(removeEditor(int)));
   }

   conteneur->setLayout(layConteneur);
   scrollArea->setWidget(conteneur);
   layout->addWidget(scrollArea);

   layout_add = new QHBoxLayout;
   QLabel* ajouter = new QLabel;
   const QString textAjout= (const QString)"Ajouter au document :";
   ajouter->setText(textAjout);
   addArticle = new QPushButton("Article");
   addImage = new QPushButton("Image");
   addVideo = new QPushButton("Video");
   addAudio = new QPushButton("Audio");
   addFrom = new QPushButton("Ouvrir");
   layout_add->addWidget(ajouter);
   layout_add->addWidget(addArticle);
   layout_add->addWidget(addImage);
   layout_add->addWidget(addVideo);
   layout_add->addWidget(addAudio);
   layout_add->addWidget(addFrom);
   layout->addLayout(layout_add);

   layout->addLayout(buttonLayout);

   setLayout(layout);

   QObject::connect(addArticle, SIGNAL(clicked()), this, SLOT(addEmptyArticle()));
   QObject::connect(addImage, SIGNAL(clicked()), this, SLOT(addEmptyImage()));
   QObject::connect(addAudio, SIGNAL(clicked()), this, SLOT(addEmptyAudio()));
   QObject::connect(addVideo, SIGNAL(clicked()), this, SLOT(addEmptyVideo()));
   QObject::connect(addFrom, SIGNAL(clicked()), this, SLOT(addExistingFrom()));
   QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveNote()));
   QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(updateNote()));
   QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(activerSave(QString)));
   save->setEnabled(false);
}

void DocumentEditeur::saveNote() {
   document->setTitle(title->text());
   NotesManager::getInstance().saveNote(*document);
   QMessageBox::information(this, "Sauvegarde", "Votre document a bien été sauvé");
   save->setEnabled(false);
   saved=true;
   for (unsigned int i=0; i<liste.size();i++) {
       liste[i]->getSaveButton()->setEnabled(false);
       liste[i]->setSaved(true);
   }
}

void DocumentEditeur::activerSave(QString str) {
    save->setEnabled(true);
    saved=false;
}

void DocumentEditeur::updateNote() {
    document->setTitle(title->text());
    for (unsigned int i=0; i<document->getSize(); i++) {
        NotesEditeur* editeur = this->getEditeur(i);
        editeur->updateNote();
    }
}

Document* DocumentEditeur::getNote() const {
    return document;
}

void DocumentEditeur::addEmptyArticle() {
    QString type = (QString) "art";
    QString newTitle = (QString)"";
    Note* tmp=NotesManager::getInstance().getNewNote(newTitle, type);
    ArticleEditeur* artEditeur = new ArticleEditeur(tmp);
    artEditeur->setFixedWidth(800);
    this->getNote()->addNote(tmp);
    liste.push_back(artEditeur);
    addEditor();
    QObject::connect(artEditeur->getSuppButton(), SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(artEditeur->getSuppButton(), (int)liste.size()-1);
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(removeEditor(int)));
    activerSave();
}

void DocumentEditeur::addEmptyImage() {
    QString type = (QString) "img";
    QString newTitle = (QString)"";
    Note* tmp=NotesManager::getInstance().getNewNote(newTitle, type);
    ImageEditeur* imgEditeur = new ImageEditeur(tmp);
    imgEditeur->setFixedWidth(800);
    this->getNote()->addNote(tmp);
    liste.push_back(imgEditeur);
    addEditor();
    activerSave();
}

void DocumentEditeur::addEmptyAudio() {
    QString type = (QString) "aud";
    QString newTitle = (QString)"";
    Note* tmp=NotesManager::getInstance().getNewNote(newTitle, type);
    AudioEditeur* audEditeur = new AudioEditeur(tmp);
    audEditeur->setFixedWidth(800);
    liste.push_back(audEditeur);
    this->getNote()->addNote(tmp);
    addEditor();
    activerSave();
}

void DocumentEditeur::addEmptyVideo() {
    QString type = (QString) "vid";
    QString newTitle = (QString)"";
    Note* tmp=NotesManager::getInstance().getNewNote(newTitle, type);
    VideoEditeur* vidEditeur = new VideoEditeur(tmp);
    vidEditeur->setFixedWidth(800);
    liste.push_back(vidEditeur);
    this->getNote()->addNote(tmp);
    addEditor();
    activerSave();
}

void DocumentEditeur::addExistingFrom() {
    QString file="";
    file=QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Note (*.art *.img *.aud *.vid)");
    if (!file.isEmpty())
    {
        Note* n;
        QString type = n->getFileType(file);
        n=NotesManager::getInstance().getFileNote(file, type);
        if (type==(QString)"art")
        {
            ArticleEditeur* editeur = new ArticleEditeur(n);
            editeur->setFixedWidth(800);
            liste.push_back(editeur);
            this->getNote()->addNote(n);
        }
        if (type==(QString)"doc")
        {
            DocumentEditeur* editeur = new DocumentEditeur(n);
            editeur->setFixedWidth(800);
            liste.push_back(editeur);
            this->getNote()->addNote(n);
        }
        if (type==(QString)"img")
        {
            ImageEditeur* editeur = new ImageEditeur(n);
            editeur->setFixedWidth(800);
            liste.push_back(editeur);
            this->getNote()->addNote(n);
        }
        if (type==(QString)"aud")
        {
            AudioEditeur* editeur = new AudioEditeur(n);
            editeur->setFixedWidth(800);
            liste.push_back(editeur);
            this->getNote()->addNote(n);
        }
        if (type==(QString)"vid")
        {
            VideoEditeur* editeur = new VideoEditeur(n);
            editeur->setFixedWidth(800);
            liste.push_back(editeur);
            this->getNote()->addNote(n);
        }
        addEditor();
        activerSave();
    }
}

void DocumentEditeur::addEditor() {
    int i = liste.size()-1;
    layConteneur->addWidget(liste[i]);
    conteneur->setLayout(layConteneur);
    //conteneur->setFixedHeight(600);
    conteneur->setBaseSize(800,400);
    conteneur->adjustSize();
    scrollArea->setWidget(conteneur);
}

void DocumentEditeur::removeEditor(int i) {
    liste[i]->setParent(0);
    document->removeNote(document->getPosNote(liste[i]->getNote()));
    layConteneur->removeWidget(liste[i]);
    for (unsigned int i=0; i<liste.size();i++)
        liste[i]->adjustSize();
    conteneur->setLayout(layConteneur);
    conteneur->setBaseSize(800,400);
    conteneur->adjustSize();
    activerSave();
}

