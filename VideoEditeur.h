#ifndef VIDEOEDITEUR_H
#define VIDEOEDITEUR_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QFileDialog>

#include "NotesEditeur.h"
#include "Video.h"
#include "NotesManager.h"


class NotesEditeur;

class VideoEditeur : public NotesEditeur {
    Q_OBJECT
    Video * video;
    QLabel *lien;
    QPushButton *lien_button;
    QHBoxLayout *lien_layout;

public:
    VideoEditeur(Note* v, QWidget* parent=0);
    const QString& getLien() const {return lien->text();}
    Video* getNote() const;

signals :

public slots :
    void saveNote();
    void updateNote();
    void loadVideo();

private slots :
    void activerSave(QString str="");
};



#endif // VIDEOEDITEUR_H
