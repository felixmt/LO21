#include"Fenetre.h"
#include <iostream>
#include <QScrollArea>
#include <QItemSelectionModel>
Fenetre::Fenetre(){

setWindowTitle("Note Manager");
setWindowState(Qt::WindowMaximized);
//setFixedHeight(1000);

zoneCentrale = new QWidget;
setCentralWidget(zoneCentrale);
layoutCentral = new QGridLayout;
zoneCentrale->setLayout(layoutCentral);

windowEditTag = new TagEditView(); //fenetre ajout de tags
te = new TagEditeur();
layoutCentral->addWidget(te, 0, 0);

onglets = new QTabWidget(this);
layoutCentral->addWidget(onglets,0,1);

pageEdition = new QWidget;
layEdition = new QVBoxLayout;
pageEdition->setLayout(layEdition);
onglets->addTab(pageEdition, "Editeur");

visualisateurText = new QLabel("", onglets);
visualisateurHTML = new QLabel("", onglets);
visualisateurLatex = new QLabel("", onglets);
onglets->addTab(visualisateurText, "Texte");
onglets->addTab(visualisateurHTML, "HTML");
onglets->addTab(visualisateurLatex, "Latex");



//MENU----------------------------------------------------------------------------------

/** Définition des menus **/
    QMenu *menuFichier = new QMenu;
    menuFichier = menuBar()->addMenu("&Fichier");
    QMenu *menuEdition = new QMenu;
    menuEdition = menuBar()->addMenu("&Edition");
    QMenu *menuExport = new QMenu;
    menuExport = menuBar()->addMenu("&Export");
    QMenu *menuCorbeille = new QMenu;
    menuCorbeille = menuBar()->addMenu("&Corbeille");

/** Définition des sous-menus **/
    QMenu *creerFichiers = menuFichier->addMenu("&Nouveau");
    QMenu *ouvrirFichiers = menuFichier->addMenu("&Ouvrir");
    QMenu *workSpace = menuFichier->addMenu("&Espace de Travail");

/** Définition des actions **/
    //Creer fichiers
    QAction *actionCreerArticle = new QAction("Article", this);
    creerFichiers->addAction(actionCreerArticle);
    actionCreerArticle->setIcon(QIcon("icons/article.png"));
    QAction *actionCreerAudio = new QAction("Enregistrement audio", this);
    creerFichiers->addAction(actionCreerAudio);
    actionCreerAudio->setIcon(QIcon("icons/audio.png"));
    QAction *actionCreerVideo = new QAction("Enregistrement video", this);
    creerFichiers->addAction(actionCreerVideo);
    actionCreerVideo->setIcon(QIcon("icons/video.png"));
    QAction *actionCreerImage = new QAction("Enregistrement image", this);
    creerFichiers->addAction(actionCreerImage);
    actionCreerImage->setIcon(QIcon("icons/image.png"));
    QAction *actionCreerDocument = new QAction("Document", this);
    creerFichiers->addAction(actionCreerDocument);
    actionCreerDocument->setIcon(QIcon("icons/document.png"));

    //Ouvrir fichiers
    QAction *actionOuvrirArticle = new QAction("Article", this);
    ouvrirFichiers->addAction(actionOuvrirArticle);
    actionOuvrirArticle->setIcon(QIcon("icons/article.png"));
    QAction *actionOuvrirAudio = new QAction("Enregistrement audio", this);
    ouvrirFichiers->addAction(actionOuvrirAudio);
    actionOuvrirAudio->setIcon(QIcon("icons/audio.png"));
    QAction *actionOuvrirVideo = new QAction("Enregistrement video", this);
    ouvrirFichiers->addAction(actionOuvrirVideo);
    actionOuvrirVideo->setIcon(QIcon("icons/video.png"));
    QAction *actionOuvrirImage = new QAction("Enregistrement image", this);
    ouvrirFichiers->addAction(actionOuvrirImage);
    actionOuvrirImage->setIcon(QIcon("icons/image.png"));
    QAction *actionOuvrirDocument = new QAction("Document", this);
    ouvrirFichiers->addAction(actionOuvrirDocument);
    actionOuvrirDocument->setIcon(QIcon("icons/document.png"));

    //Espaces de travail
    QAction *creerWorkspace = new QAction("Créer un nouvel espace de travail", this);
    workSpace->addAction(creerWorkspace);
    QAction *creerWorkspaceDepuis = new QAction("Changer d'espace de travail", this);
    workSpace->addAction(creerWorkspaceDepuis);

    //Quitter
    QAction *actionQuitter = new QAction("&Quitter", this);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionQuitter->setIcon(QIcon("icons/quitter.png"));

    //Edition
    QAction *annuler = new QAction("&Annuler", this);
    menuEdition->addAction(annuler);
    QAction *retablir = new QAction("&Retablir", this);
    menuEdition->addAction(retablir);

    //Exports
    QAction *exportHTML = new QAction("&HTML", this);
    menuExport->addAction(exportHTML);
    QAction *exportLatex = new QAction("&Latex", this);
    menuExport->addAction(exportLatex);
    QAction *exportText = new QAction("&Text", this);
    menuExport->addAction(exportText);

    //Corbeille
    QAction *corbeilleIn = new QAction("&Mettre a la corbeille", this);
    menuCorbeille->addAction(corbeilleIn);
    QAction *afficherCorbeille = new QAction("&Afficher le contenu", this);
    menuCorbeille->addAction(afficherCorbeille);
    QAction *viderCorbeille = new QAction("&Vider la corbeille", this);
    menuCorbeille->addAction(viderCorbeille);

/** Connexions **/
	QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
	QObject::connect(creerWorkspace, SIGNAL(triggered()), this, SLOT(newWorkspace()));
	QObject::connect(creerWorkspaceDepuis, SIGNAL(triggered()), this, SLOT(changeWorkspace()));
	QObject::connect(actionOuvrirArticle, SIGNAL(triggered()), this, SLOT(openArticle()));
	QObject::connect(actionOuvrirVideo, SIGNAL(triggered()), this, SLOT(openVideo()));
	QObject::connect(actionOuvrirAudio, SIGNAL(triggered()), this, SLOT(openAudio()));
	QObject::connect(actionOuvrirImage, SIGNAL(triggered()), this, SLOT(openImage()));
	QObject::connect(actionOuvrirDocument, SIGNAL(triggered()), this, SLOT(openDocument()));
	QObject::connect(actionCreerArticle, SIGNAL(triggered()), this, SLOT(newArticle()));
	QObject::connect(actionCreerVideo, SIGNAL(triggered()), this, SLOT(newVideo()));
	QObject::connect(actionCreerAudio, SIGNAL(triggered()), this, SLOT(newAudio()));
	QObject::connect(actionCreerImage, SIGNAL(triggered()), this, SLOT(newImage()));
	QObject::connect(actionCreerDocument, SIGNAL(triggered()), this, SLOT(newDocument()));
	QObject::connect(corbeilleIn, SIGNAL(triggered()), this, SLOT(dustbinIn()));
    QObject::connect(afficherCorbeille, SIGNAL(triggered()), this, SLOT(displayDustbin()));
	QObject::connect(viderCorbeille, SIGNAL(triggered()), this, SLOT(clearDustbin()));
    //Export
    QObject::connect(exportText, SIGNAL(triggered()), this, SLOT(exportTextSlot()));
    QObject::connect(exportHTML, SIGNAL(triggered()), this, SLOT(exportHtmlSlot()));
    QObject::connect(exportLatex, SIGNAL(triggered()), this, SLOT(exportLatexSlot()));
    //Tag Editeur
	QObject::connect(te->getVueTags(),SIGNAL(clicked(const QModelIndex &)), this, SLOT(getAssociatedNotes(const QModelIndex &)));
    QObject::connect(te->getVueNotes(),SIGNAL(clicked(const QModelIndex &)), this, SLOT(openNote(const QModelIndex &)));

	 QObject::connect(windowEditTag->getValider(),SIGNAL(clicked()), this, SLOT(selectedTags()));

	//BARRE D'OUTILS----------------------------------------------------------------------
	QToolBar *toolBarFichier = addToolBar("Fichier");
	toolBarFichier->addAction(actionQuitter);

	toolBarFichier->addSeparator();

	toolBarFichier->addAction(actionOuvrirArticle);
	toolBarFichier->addAction(actionOuvrirAudio);
	toolBarFichier->addAction(actionOuvrirVideo);
	toolBarFichier->addAction(actionOuvrirImage);
	toolBarFichier->addAction(actionOuvrirDocument);


	onPage=0;

}

void Fenetre::createTab() {
    layEdition->addWidget(onPage);
    visualisateurText->setText(onPage->getNote()->exportText());
    visualisateurHTML->setText(onPage->getNote()->exportHtml());
    visualisateurLatex->setText(onPage->getNote()->exportLatex());
}

void Fenetre::clearWindow() {
    if (onPage!=0) {
        layEdition->removeWidget(onPage);
        onPage->setParent(0);
    }
}

void Fenetre::connectEditeur() {
    QObject::connect(onglets,SIGNAL(currentChanged(int)),this,SLOT(changeOnglet(int)));
    QObject::connect(onPage->getAddTag(),SIGNAL(clicked()), this, SLOT(openAddTag()));
    QObject::connect(onPage->getSuppButton(), SIGNAL(clicked()), this, SLOT(dustbinIn()));
}

void Fenetre::openEditeur(NotesEditeur* n) {
    clearWindow();
    onPage = n;
    onPage->adjustSize();
    createTab();
    connectEditeur();
}

//SLOTS-------------------------------------------------------------------------------
void Fenetre::openArticle()
{
    QString file="";
    file=QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Article (*.art)");
    if (!file.isEmpty())
    {
        QString type = (QString) "art";
        Note* tmp=NotesManager::getInstance().getFileNote(file, type);
        ArticleEditeur* editeur = new ArticleEditeur(tmp);
        openEditeur(editeur);
    }
    QObject::connect(onPage->getAddTag(),SIGNAL(clicked()), this, SLOT(openAddTag()));
}

void Fenetre::openAudio()
{
    QString file="";
    file=QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Audio (*.aud)");
    if (!file.isEmpty())
    {
        QString type = (QString) "aud";
        Note* tmp=NotesManager::getInstance().getFileNote(file, type);
        AudioEditeur* editeur = new AudioEditeur(tmp);
        openEditeur(editeur);
    }
}

void Fenetre::openVideo()
{
    QString file="";
    file=QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Video (*.vid)");
    if (!file.isEmpty())
    {
        QString type = (QString) "vid";
        Note* tmp=NotesManager::getInstance().getFileNote(file, type);
        VideoEditeur* editeur = new VideoEditeur(tmp);
        openEditeur(editeur);
    }
}

void Fenetre::openImage()
{
    QString file="";
    file=QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Image (*.img)");
    if (!file.isEmpty())
    {
        QString type = (QString) "img";
        Note* tmp=NotesManager::getInstance().getFileNote(file, type);
        ImageEditeur* editeur = new ImageEditeur(tmp);
        openEditeur(editeur);
    }
}

void Fenetre::openDocument()
{
    QString file="";
    file=QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Document (*.doc)");
    if (!file.isEmpty())
    {
        QString type = (QString) "doc";
        Note* tmp=NotesManager::getInstance().getFileNote(file, type);
        DocumentEditeur* editeur = new DocumentEditeur(tmp);
        openEditeur(editeur);
    }
}


void Fenetre::newArticle()
{
    QString type = (QString) "art";
    QString newTitle = (QString)"";
    Note* tmp=NotesManager::getInstance().getNewNote(newTitle, type);
    ArticleEditeur* editeur = new ArticleEditeur(tmp);
    openEditeur(editeur);
}

void Fenetre::newImage() {
    QString type = (QString) "img";
    QString newTitle = (QString)"";
    Note* tmp=NotesManager::getInstance().getNewNote(newTitle, type);
    ImageEditeur* editeur = new ImageEditeur(tmp);
    openEditeur(editeur);
}

void Fenetre::newVideo() {
    QString type = (QString) "vid";
    QString newTitle = (QString)"";
    Note* tmp=NotesManager::getInstance().getNewNote(newTitle, type);
    VideoEditeur* editeur = new VideoEditeur(tmp);
    openEditeur(editeur);
}

void Fenetre::newAudio() {
    QString type = (QString) "aud";
    QString newTitle = (QString)"";
    Note* tmp=NotesManager::getInstance().getNewNote(newTitle, type);
    AudioEditeur* editeur = new AudioEditeur(tmp);
    openEditeur(editeur);
}

void Fenetre::newDocument() {
    QString type = (QString) "doc";
    QString newTitle = (QString)"";
    Note* tmp=NotesManager::getInstance().getNewNote(newTitle, type);
    DocumentEditeur* editeur = new DocumentEditeur(tmp);
    openEditeur(editeur);
}


void Fenetre::changeOnglet(int i)
{
    onPage->updateNote();
    if(i==1) visualisateurText->setText(onPage->getNote()->exportText());
    else if (i==2) visualisateurHTML->setText(onPage->getNote()->exportHtml());
    else if (i==3) visualisateurLatex->setText(onPage->getNote()->exportLatex());
}


void Fenetre::changeWorkspace() {
    QString wp=(QString)"";
    wp = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"", QFileDialog::ShowDirsOnly)+"/";
    NotesManager::getInstance().createNewWorkspaceFrom(wp);
    clearWindow();
}

void Fenetre::newWorkspace() {
    QString wp=(QString)"";
    wp = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"", QFileDialog::ShowDirsOnly)+"/";
    NotesManager::getInstance().createNewWorkspace(wp);
    clearWindow();
}

void Fenetre::exportTextSlot() {
    if (onPage!=0)  {
        onPage->getNote()->saveExportText();
        QMessageBox::warning(this, "Succès", "Votre note a bien été exportée au format texte");
    }
    else QMessageBox::warning(this, "Export impossible", "Aucune note à exporter.");
}

void Fenetre::exportHtmlSlot() {
    if (onPage!=0) {
        onPage->getNote()->saveExportHtml();
        QMessageBox::warning(this, "Succès", "Votre note a bien été exportée au format html");
    }
    else QMessageBox::warning(this, "Export impossible", "Aucune note à exporter.");
}

void Fenetre::exportLatexSlot() {
    if (onPage!=0) {
        onPage->getNote()->saveExportLatex();
        QMessageBox::warning(this, "Succès", "Votre note a bien été exportée au format latex");
    }
    else QMessageBox::warning(this, "Export impossible", "Aucune note à exporter.");
}


void Fenetre::dustbinIn() {
    Note* note = onPage->getNote();
    Corbeille::getInstance().addNote(note);
    layEdition->removeWidget(onPage);
    onPage->setParent(0);
}

void Fenetre::dustbinOut() {
    QString typeArt = "art";
    QString typeVid = "vid";
    QString typeAud = "aud";
    QString typeImg = "img";
    QString typeDoc = "doc";

    Note* n = dustbin->restor();
    QString type = n->getType();
    NotesEditeur* editeur = this->getNewEditeur(n, type);
    openEditeur(editeur);
    setWindowState(Qt::WindowMaximized);
}

void Fenetre::displayDustbin() {
    dustbin = new CorbeilleEditeur();
    dustbin->show();
    QObject::connect(dustbin->getRestaurer(), SIGNAL(clicked()), this, SLOT(dustbinOut()));
}

void Fenetre::clearDustbin() {
    Corbeille::getInstance().viderCorbeille();
}


//TAG MANAGER SLOTS------------A Corriger : lors de la selection de plusieurs tags, si une note appartient à plusieurs des tags sélectionnés, elle apparaît plusieurs fois
void Fenetre::getAssociatedNotes(const QModelIndex &)
{
    std::cout<<"J'utilise getAssociatednote()\n";
    QItemSelectionModel *selection = te->getVueTags()->selectionModel();
    QModelIndexList listeSelections = selection->selectedIndexes();
    QString tagName;
    QStringList listeNotes;
    for (int i = 0 ; i < listeSelections.size() ; i++)
    {
        QVariant elementSelectionne = te->getModeleTags()->data(listeSelections[i], Qt::DisplayRole);
        tagName = elementSelectionne.toString();
        for(int i=0;i<TagManager::getInstance().getTag(tagName)->getSize();i++)
            listeNotes << TagManager::getInstance().getTag(tagName)->getNote(i)->getTitle();

    }
    te->getModeleNotes()->setStringList(listeNotes);
    te->getVueNotes()->setModel(te->getModeleNotes());
}

void Fenetre::openNote(const QModelIndex &)
{
    std::cout<<"J'utilise openNote()\n";
    if (onPage!=0)
    {
        layEdition->removeWidget(onPage);
        onPage->setParent(0);
    }

    QItemSelectionModel *selection = te->getVueNotes()->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = te->getModeleNotes()->data(indexElementSelectionne, Qt::DisplayRole);
    QString el = elementSelectionne.toString();
    Note* n = NotesManager::getInstance().getNoteByTitle(el);
    QString type = n->getType();
    NotesEditeur* editeur = this->getNewEditeur(n, type);
    openEditeur(editeur);
    setWindowState(Qt::WindowMaximized);
}

//Tag Edit View

void Fenetre::selectedTags()
{
        std::cout<<"J'utilise selectedTags()\n";
        QItemSelectionModel *selection = windowEditTag->getVueTags()->selectionModel();
        QModelIndexList listeSelections = selection->selectedIndexes();
        QString tagName;
        QString title = onPage->getTitle().text();
        Note* n = NotesManager::getInstance().getNoteByTitle(title);
        bool garderTag=0;
        for(int j=0; j< n->getSizeTabTags();j++)
        {
            for (int i = 0 ; i < listeSelections.size() ; i++)
            {
                QVariant elementSelectionne = windowEditTag->getModeleTags()->data(listeSelections[i], Qt::DisplayRole);
                tagName = elementSelectionne.toString();
                Tag* t = TagManager::getInstance().getTag(tagName);
                n->addTag(t);
                if(n->getTag(j) == t)
                    garderTag=1;
            }
            if(!garderTag)
                TagManager::getInstance().deleteAssociatedTag(n->getTag(j)->getName(), n);
            garderTag = 0;
        }

        if(!windowEditTag->getNvTag()->text().isEmpty()) {
            std::cout<<"Je rentre dans !windowEditTag->getNvTag()->text().isEmpty()";
            QString tagname = windowEditTag->getNvTag()->text();
            TagManager::getInstance().addAssociatedTag(tagname,n);
        }
        QStringList listeTags;
        for (int i = 0; i < TagManager::getInstance().getTabTagsSize(); i++)
            listeTags << TagManager::getInstance().getTag(i)->getName();

        te->getModeleTags()->setStringList(listeTags);
        te->getVueTags()->setModel(te->getModeleTags());

        windowEditTag->getModeleTags()->setStringList(listeTags);
        windowEditTag->getVueTags()->setModel(windowEditTag->getModeleTags());
        windowEditTag->getNvTag()->clear();
        windowEditTag->close();
}

void Fenetre::openAddTag()
{
    std::cout<<"J'utilise openAddTag()\n";
//    Permet de pré-sélectionner les tags auxquels la note est déjà associée
    QItemSelectionModel* itemSelectionModel = windowEditTag->getVueTags()->selectionModel();
    for(int i = 0;i<TagManager::getInstance().getTabTagsSize(); i++)
    {
        for(int j = 0;j<onPage->getNote()->getSizeTabTags();j++)
        {
            if(TagManager::getInstance().getTagByPos(i)->getName() == onPage->getNote()->getTag(j)->getName())
            {
                QModelIndex modelIndex = windowEditTag->getModeleTags()->index(i, 0, QModelIndex());
                itemSelectionModel->select(modelIndex, QItemSelectionModel::Select);
            }
        }
    }
    windowEditTag->getVueTags()->setSelectionModel(itemSelectionModel );


    windowEditTag->show();

}

NotesEditeur* Fenetre::getNewEditeur(Note* n, QString& type)
{
    EditeurFactory* ef = EditeurFactory::chooseEditeur(type);
    NotesEditeur* editeur = ef->buildEditeur(n);
    return editeur;
}

