#include "MannschaftListeEditor.h"

MannschaftListeEditor::MannschaftListeEditor(QDialog *parent)
: QDialog(parent)
{
	setupUi(this);
	connect(this, SIGNAL(listeChanged()), this, SLOT(mannschaftListeChanged()));
}

MannschaftListeEditor::~MannschaftListeEditor()
{

}

void MannschaftListeEditor::setMannschaftListe(QList<Mannschaft> *liste)
{
	_mannschaftListe = liste;
	Q_EMIT listeChanged(liste);
}

void MannschaftListeEditor::mannschaftListeChanged(QList<Mannschaft> *liste)
{
	//mach was mit der Anzeige
}