/**
 * \file	AudioEditeur.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Fenetre dedition de note audio
 */

#ifndef AUDIOEDITEUR_H
#define AUDIOEDITEUR_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QFileDialog>

#include "NotesEditeur.h"
#include "Audio.h"
#include "NotesManager.h"

/**
* \class AudioEditeur AudioEditeur.h
*/
class AudioEditeur : public NotesEditeur {
    Q_OBJECT
    Audio * audio;
    QLabel *lien;
    QPushButton *lien_button;
    QHBoxLayout *lien_layout;

public:
/**
 * \brief		Constructeur par recopie
 * \param		a		Note a editer
 */
    AudioEditeur(Note* a, QWidget* parent=0);

/**
 * \brief		Accesseur de l'attribut lien
 * \return		Un QString qui correspond au texte du QLabel lien
 */	
    const QString& getLien() const {return lien->text();}
    Audio* getNote() const;

signals :

public slots :
   
/**
 * \brief		Slot qui sauve la note
 */
    void saveNote();
	
/**
 * \brief		Slot qui met a jour la note en fonction des modifs effectuees dans lediteur
 */
    void updateNote();
	
/**
 * \brief		Slot qui charge l'element audio
 */
    void loadAudio();

private slots :
    void activerSave(QString str="");
};



#endif // AUDIOEDITEUR_H
