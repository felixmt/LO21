#include "ImageEditeur.h"

ImageEditeur::ImageEditeur(Note* i, QWidget* parent) : NotesEditeur(i) {
    image = dynamic_cast<Image*>(i);

    imageDisplay = new QLabel(this);
    imageDisplay->setPixmap(QPixmap(image->getImg()));
    lien = new QLabel(this);
    lien->setText(image->getImg());
    lien_button = new QPushButton("lien");
    lien_layout = new QHBoxLayout;
    lien_layout->addWidget(lien);
    lien_layout->addWidget(lien_button);

    layout->addWidget(title);
    layout->addWidget(imageDisplay);
    layout->addLayout(lien_layout);
    layout->addLayout(buttonLayout);

    setLayout(layout);

    QObject::connect(lien_button, SIGNAL(clicked()), this, SLOT(loadImage()));
    QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveNote()));
    QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(activerSave(QString)));
    QObject::connect(title, SIGNAL(textEdited(QString)), this, SLOT(updateNote()));
    QObject::connect(lien_button, SIGNAL(clicked()), this, SLOT(updateNote()));
    save->setEnabled(false);

}

Image* ImageEditeur::getNote() const {
    return image;
}

void ImageEditeur::loadImage() {
    QString im="";
    im=QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), tr("Image (*.jpg *.jpeg *.png *.bmp)"));
    if (!im.isEmpty())
    {
        this->getNote()->setImg(im);
        lien->setText(getNote()->getImg());
        imageDisplay->setPixmap(QPixmap(getNote()->getImg()));
    }
}

void ImageEditeur::saveNote() {
    image->setTitle(title->text());
    image->setImg(lien->text());
    NotesManager::getInstance().saveNote(*image);
    QMessageBox::information(this, "Sauvegarde", "Votre image a bien été sauvée");
    save->setEnabled(false);
    saved=true;
}

void ImageEditeur::updateNote() {
    image->setTitle(title->text());
    image->setImg(lien->text());
    activerSave();
}

void ImageEditeur::activerSave(QString str) {
    save->setEnabled(true);
    saved=false;
}
