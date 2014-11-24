/**
 * \file	ImageEditeur.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	gestion de la fenetre d'edition des notes images
 */

#ifndef IMAGEEDITEUR_H
#define IMAGEEDITEUR_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QFileDialog>

#include "NotesEditeur.h"
#include "note.h"
#include "Image.h"
#include "NotesManager.h"
/**
* \class ImageEditeur ImageEditeur.h
*/
class ImageEditeur : public NotesEditeur {
    Q_OBJECT
    QLabel *imageDisplay;
    Image *image;
    QLabel *lien;
    QPushButton *lien_button;
    QHBoxLayout *lien_layout;

public:
/**
 * \brief		Constructeur d'image par recopie
 * \param		i		note a recopier
 */
    explicit ImageEditeur(Note* i, QWidget* parent=0);
    const QString& getLien() const {return lien->text();}
    Image* getNote() const;

signals :

public slots :
/**
 * \brief		Slot qui sauve la note image
 */
    void saveNote();
/**
 * \brief		Slot qui actualise la note en cours d'edition
 */
    void updateNote();
	
/**
 * \brief		Slot qui charge l'image
 */
    void loadImage();

private slots :
    void activerSave(QString str="");
};



#endif // IMAGEEDITEUR_H
