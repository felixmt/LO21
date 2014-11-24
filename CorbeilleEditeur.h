/**
 * \file	CorbeilleEditeur.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Fenetre corbeille
 */

#ifndef CORBEILLEEDITEUR_H
#define CORBEILLEEDITEUR_H

#include <iostream>
#include "note.h"


#include <QWidget>
#include <QListWidget>

#include <QListWidgetItem>

#include <QHBoxLayout>
#include <QScrollArea>
#include <QPushButton>

#include "Corbeille.h"
/**
* \class CorbeilleEditeur CorbeilleEditeur.h
*/
class CorbeilleEditeur : public QWidget{
    Q_OBJECT

private:

    QListWidget* list;
    QVBoxLayout* lay;
    QScrollArea* scroll;
    QPushButton* supprimer;
    QPushButton* vider;
    QPushButton* restaurer;

public:
/**
 * \brief		Constructeur de Corbeille, construit la fenêtre de corbeille
 */
    CorbeilleEditeur(QWidget* parent=0);
    QListWidget* getList(){return list;}
    QPushButton* getSupCorbButton(){ return supprimer; }
    QPushButton* getViderButton() { return vider; }
    QPushButton* getRestaurer() { return restaurer; }

public slots :
/**
 * \brief		Slot qui supprime une note de la corbeille
 */
    void supp();
	
/**
 * \brief		Slot qui vide la corbeille
 */
    void vid();
	
/**
 * \brief		Slot qui restaure une note
 */
    Note* restor();
	
    void activerBoutons();
};

#endif // CORBEILLEEDITEUR_H
