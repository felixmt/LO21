/**
 * \file	Fenetre.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Gere laffichage de la fenetre de lapplication
 */

#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QFileDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QMdiSubWindow>
#include <QTextEdit>
#include <QMdiArea>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QKeySequence>
#include <QToolBar>
#include <QFontComboBox>
#include <QMessageBox>
#include <QLabel>
#include <QTimer>
#include <QListView>

#include "NotesEditeur.h"
#include "EditeurFactory.h"
#include "note.h"
#include "ArticleEditeur.h"
#include "documentEditeur.h"
#include "Corbeille.h"
#include "Image.h"
#include "TagEditeur.h"
#include "ImageEditeur.h"
#include "CorbeilleEditeur.h"

/**
* \class Fenetre Fenetre.h
*/
class Fenetre : public QMainWindow {
    Q_OBJECT
private :
    QTabWidget* onglets;
    QLabel *visualisateurText;
    QLabel *visualisateurHTML;
    QLabel *visualisateurLatex;
    QWidget* zoneCentrale;
    QGridLayout *layoutCentral;
    QWidget *pageEdition;
    QVBoxLayout *layEdition;
    NotesEditeur *onPage;
    CorbeilleEditeur *dustbin;
    TagEditeur* te;
    TagEditView* windowEditTag;
public :
/**
 * \brief		Constructeur de Fenetre
 */
    explicit Fenetre();
/**
 * \brief		accesseur qui retourne l'attribut Te (gestionnaire de tag)
 * \return		Un pointeur vers le tagEditeur
 */
    TagEditeur* getTe(){ return te; }
	
/**
 * \brief		Fonction qui cree un nouvel onglet dans la fenetre
 */
    void createTab();
	
/**
 * \brief		Fonction qui cree un nouvel onglet dans la fenetre
 */
    void clearWindow();
	
/**
 * \brief		Fonction qui gere les evenements déclenchés lors d'un clic sur un onglet, un clic sur les boutons de suppression de note ou d'ajout de tag
 */
    void connectEditeur();
	
/**
 * \brief		Fonction qui ouvre l'editeur de notes
 * \param		n	note a editer
 */
    void openEditeur(NotesEditeur* n);

signals :

public slots :
/**
 * \brief		Slot qui ouvre un article
 */
   void openArticle();
   
/**
 * \brief		Slot qui ouvre une note video
 */
   void openVideo();
   
/**
 * \brief		Slot qui ouvre une note audio
 */
   void openAudio();
   
/**
 * \brief		Slot qui ouvre une note image
 */
   void openImage();

/**
 * \brief		Slot qui ouvre un document
 */
   void openDocument();

/**
 * \brief		Slot qui cree un nouvel article
 */
   void newArticle();
   
/**
 * \brief		Slot qui cree une nouvelle video
 */
   void newVideo();
   
/**
 * \brief		Slot qui cree une nouvelle note audio
 */
   void newAudio();

/**
 * \brief		Slot qui cree une nouvelle image
 */
   void newImage();
   
/**
 * \brief		Slot qui cree un nouveau document
 */
   void newDocument();

/**
 * \brief		Slot qui change le repertoire de travail
 */
   void changeWorkspace();
   
/**
 * \brief		Slot qui cree un nouveau repertoire de travail
 */
   void newWorkspace();

/**
 * \brief		Slot qui gere l'export au format texte
 */
   void exportTextSlot();
   
/**
 * \brief		Slot qui gere l'export au format html
 */
   void exportHtmlSlot();
   
/**
 * \brief		Slot qui gere l'export au format latex
 */
   void exportLatexSlot();

/**
 * \brief		Slot qui gere le changement d'onglet
 * \param		i		index de l'onglet a afficher
 */
   void changeOnglet(int i);

/**
 * \brief		Slot qui gere la mise a la corbeille d'une note
 */
   void dustbinIn();
   
/**
 * \brief		Slot qui gere la restauration dune note placee dans la corbeille
 */
   void dustbinOut();
   
/**
 * \brief		Slot qui gere l'affichage de la fenetre de corbeille
 */
   void displayDustbin();
   
/**
 * \brief		Slot qui vide la corbeille
 */
   void clearDustbin();
   
   //   TAG MANAGER
/**
 * \brief		Slot qui recupere et affiche les notes associees au(x) tag(s) selectionne(s)
 */
   void getAssociatedNotes(const QModelIndex &);
   
/**
 * \brief		Slot qui ouvre une note
 */
   void openNote(const QModelIndex &);
   
//   TAGEDITVIEW
/**
 * \brief		Slot qui ouvre la fenetre d'ajout/suppression de tag
 */
   void openAddTag();
   
/**
 * \brief		Slot qui ajoute les tags selectionnes au tableau de tags de la note, et supprime ceux non selectionnes et qui etaient precedemment dans son tableau de tags
 */
   void selectedTags();

   /**
 * \brief		Slot qui cree un nouvel editeur de note suivant son type
 * \param		n		note a editer
 * \param		type	type de la note
 */
   NotesEditeur* getNewEditeur(Note* n, QString& type);
};



#endif // FENETRE_H
