#include "VideoEditeur.h"

VideoEditeur::VideoEditeur(Note* v, QWidget* parent) : NotesEditeur(v) {
    video = dynamic_cast<Video*>(v);

    lien = new QLabel(this);
    lien->setText(video->getVid());
    lien_button = new QPushButton("lien");
    lien_layout = new QHBoxLayout;
    lien_layout->addWidget(lien);
    lien_layout->addWidget(lien_button);

    layout->addWidget(title);
    layout->addLayout(lien_layout);
    layout->addLayout(buttonLayout);

    setLayout(layout);

    QObject::connect(lien_button, SIGNAL(clicked()), this, SLOT(loadVideo()));
    QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveNote()));
    QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(activerSave(QString)));
    QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(updateNote()));
    QObject::connect(lien_button, SIGNAL(clicked()), this, SLOT(updateNote()));
    save->setEnabled(false);
}

Video* VideoEditeur::getNote() const {
    return video;
}

void VideoEditeur::loadVideo() {
    QString vi="";
    vi=QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), tr("Video (*.mpeg4 *.mp4 *.mov *.wav *.avi *.m4v)"));
    if (!vi.isEmpty())
    {
        this->getNote()->setVid(vi);
        lien->setText(getNote()->getVid());
    }
}

void VideoEditeur::saveNote() {
    video->setTitle(title->text());
    video->setVid(lien->text());
    NotesManager::getInstance().saveNote(*video);
    QMessageBox::information(this, "Sauvegarde", "Votre enregistrement video a bien été sauvée");
    save->setEnabled(false);
    saved=true;
}

void VideoEditeur::updateNote() {
    video->setTitle(title->text());
    video->setVid(lien->text());
}

void VideoEditeur::activerSave(QString str) {
    save->setEnabled(true);
    saved=false;
}

