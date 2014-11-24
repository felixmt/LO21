#include "AudioEditeur.h"

AudioEditeur::AudioEditeur(Note* a, QWidget* parent) : NotesEditeur(a) {
    audio = dynamic_cast<Audio*>(a);

    lien = new QLabel(this);
    lien->setText(audio->getAud());
    lien_button = new QPushButton("lien");
    lien_layout = new QHBoxLayout;
    lien_layout->addWidget(lien);
    lien_layout->addWidget(lien_button);

    layout->addWidget(title);
    layout->addLayout(lien_layout);
    layout->addLayout(buttonLayout);

    setLayout(layout);

    QObject::connect(lien_button, SIGNAL(clicked()), this, SLOT(loadAudio()));
    QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveNote()));
    QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(activerSave(QString)));
    QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(updateNote()));
    QObject::connect(lien_button, SIGNAL(clicked()), this, SLOT(updateNote()));
    save->setEnabled(false);
}

Audio* AudioEditeur::getNote() const {
    return audio;
}

void AudioEditeur::loadAudio() {
    QString au="";
    au=QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), tr("Audio (*.mp3 *.aac)"));
    if (!au.isEmpty())
    {
        this->getNote()->setAud(au);
        lien->setText(getNote()->getAud());
    }
}

void AudioEditeur::saveNote() {
    audio->setTitle(title->text());
    audio->setAud(lien->text());
    NotesManager::getInstance().saveNote(*audio);
    QMessageBox::information(this, "Sauvegarde", "Votre audio a bien été sauvée");
    save->setEnabled(false);
    saved=true;
}

void AudioEditeur::updateNote() {
    audio->setTitle(title->text());
    audio->setAud(lien->text());
}

void AudioEditeur::activerSave(QString str) {
    save->setEnabled(true);
    saved=false;
}

