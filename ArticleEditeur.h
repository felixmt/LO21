/**
 * \file	ArticleEditeur.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	fenetre d'edition d'article, herite de NotesEditeur
 */

#ifndef ARTICLEEDITEUR_H
#define ARTICLEEDITEUR_H
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

#include "note.h"
#include "article.h"
#include "NotesManager.h"
#include "NotesEditeur.h"

/**
* \class ArticleEditeur ArticleEditeur.h
*\ brief herite de NotesEditeur
*/
class ArticleEditeur : public NotesEditeur {
private :
    Q_OBJECT
    Article* article;
    QTextEdit *text;
    bool saved;
public:
/**
 * \brief		Constructeur d'ArticleEditeur
 * \param		a note a recopier
 * \param		parent QWidget, 0 par defaut
 */
    explicit ArticleEditeur(Note* a, QWidget* parent=0);
	
 /**
 * \brief		accesseur qui retourne l'attribut texte
 * \return		Un QTextEdit qui correspond au texte dans la fenetre d'edition du texte
 */
    QTextEdit& getText() const {return *text;}
	
 /**
 * \brief		accesseur qui retourne l'article en cours d'edition
 * \return		un pointeur vers l'article en cours d'edition
 */
    Article* getNote() const;
	
 /**
 * \brief		accesseur qui retourne l'attribut saved
 * \return		un booleen, qui indique si l'article est sauve ou non
 */
    bool getSaved() {return saved;}
signals :

public slots :
 /**
 * \brief		Slot qui sauve l'article en cours d'edition
 */
    void saveNote();
	
 /**
 * \brief		Slot qui actualise la note en fonction des modifications effectuees par l'utilisateur dans l'editeur
 */
    void updateNote();

private slots :
 /**
 * \brief		Slot qui active la sauvegarde
 */
    void activerSave(QString str="");
    //void activerSave();

};

#endif // ARTICLEEDITEUR_H
