#ifndef TAGEDITEUR_H
#define TAGEDITEUR_H
#include <QWidget>
#include <QListView>
#include <QVBoxLayout>
#include <QStringListModel>
#include <QStringList>
#include <QPushButton>
#include <QLineEdit>

class TagEditeur : public QWidget
{
public:
    TagEditeur();
    QListView* getVueTags(){ return vueTags; }
    QListView* getVueNotes(){ return vueNotes; }

    QStringListModel* getModeleNotes(){ return modeleNotes; }
    QStringListModel* getModeleTags(){ return modeleTags; }

    void updateListeTags();
    void updateListeNotes();

private :
    QVBoxLayout* layout;

    QListView* vueTags;
    QListView* vueNotes;

    QStringListModel* modeleNotes;
    QStringListModel* modeleTags;

    QStringList listeTags;
    QStringList listeNotes;

};

class TagEditView : public QWidget
{
public :
    TagEditView();
    QPushButton* getValider(){ return valider; }
    QListView* getVueTags(){ return vueTags; }
    QStringListModel* getModeleTags() { return modeleTags; }
    QLineEdit* getNvTag(){ return nvTag; }

private :
    QVBoxLayout* layout;
    QListView* vueTags;
    QStringListModel* modeleTags;
    QPushButton* valider;
    QLineEdit* nvTag;
};

#endif // TAGEDITEUR_H
