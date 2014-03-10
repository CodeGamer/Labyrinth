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
	mannschaftListeTable->setRowCount(2);
	mannschaftListeTable->setColumnCount(2);

	mannschaftListeTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	mannschaftListeTable->setHorizontalHeaderLabels(QString("Mannschaft;Herkunft").split(";"));

	mannschaftListeTable->setItem(0, 0, new QTableWidgetItem("Hannover 1"));
	mannschaftListeTable->setItem(0, 1, new QTableWidgetItem("Hannover"));
	mannschaftListeTable->setItem(1, 0, new QTableWidgetItem("Hannover 2"));
	mannschaftListeTable->setItem(1, 1, new QTableWidgetItem("Hannover"));
}