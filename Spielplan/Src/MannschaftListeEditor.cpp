#include "MannschaftListeEditor.h"

MannschaftListeEditor::MannschaftListeEditor(QDialog *parent)
: QDialog(parent)
{
	setupUi(this);
	connect(this, SIGNAL(listeChanged(QList<Mannschaft*>*)), this, SLOT(mannschaftListeChanged(QList<Mannschaft*>*)));
}

MannschaftListeEditor::~MannschaftListeEditor()
{

}

void MannschaftListeEditor::setMannschaftListe(QList<Mannschaft*> *liste)
{
	_mannschaftListe = liste;
	Q_EMIT listeChanged(liste);
}

void MannschaftListeEditor::mannschaftListeChanged(QList<Mannschaft*> *liste)
{
	//mach was mit der Anzeige
}