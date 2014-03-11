/* Spielplan */
#include "MannschaftListeEditor.h"

/* local */
#include "Manager.h"

Manager::Manager(QMainWindow *parent)
: QMainWindow(parent)
{
	setupUi(this);
	connect(actionLoadSpielplan, SIGNAL(triggered()), this, SLOT(loadSpielplan()));
	connect(actionSaveSpielplan, SIGNAL(triggered()), this, SLOT(saveSpielplan()));
	connect(actionExit, SIGNAL(triggered()), this, SLOT(exitManager()));
	connect(actionLoadMannschaftsliste, SIGNAL(triggered()), this, SLOT(loadMannschaftsliste()));
	connect(actionSaveMannschaftsliste, SIGNAL(triggered()), this, SLOT(saveMannschaftsliste()));
	connect(actionEditMannschaftsliste, SIGNAL(triggered()), this, SLOT(editMannschaftsliste()));

	_listeMannschaften = new QList<Mannschaft*>;
	Mannschaft *man1 = new Mannschaft("wir", "clz", false);
	Mannschaft *man2 = new Mannschaft("foo", "bar", true);
	_listeMannschaften->append(man1);
	_listeMannschaften->append(man2);
}

Manager::~Manager()
{
	//delete _listeMannschaften;
}

void Manager::loadSpielplan()
{

}

void Manager::saveSpielplan()
{

}

void Manager::exitManager()
{
	qApp->exit();
}

void Manager::loadMannschaftsliste()
{

}

void Manager::saveMannschaftsliste()
{

}

void Manager::editMannschaftsliste()
{
	MannschaftListeEditor *dialogMannschaftsListeEditor = new MannschaftListeEditor();
	connect(dialogMannschaftsListeEditor, SIGNAL(listeChanged(QList<Mannschaft*>*)), this, SLOT(listeMannschaftenChanged(QList<Mannschaft*>*)));
	dialogMannschaftsListeEditor->setMannschaftListe(_listeMannschaften);
	dialogMannschaftsListeEditor->exec();
}

void Manager::listeMannschaftenChanged(QList<Mannschaft*> *liste)
{
	_listeMannschaften = liste;
}