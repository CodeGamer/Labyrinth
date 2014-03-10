#include <QObject>

#include "MannschaftListeEditor.h"

MannschaftListeEditor::MannschaftListeEditor(QDialog *parent)
: QDialog(parent)
{
	setupUi(this);

	mannschaftListeTable->setRowCount(2);
	mannschaftListeTable->setColumnCount(2);

	mannschaftListeTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	mannschaftListeTable->setHorizontalHeaderLabels(QString("Mannschaft;Herkunft").split(";"));

	mannschaftListeTable->setItem(0, 0, new QTableWidgetItem("Hannover 1"));
	mannschaftListeTable->setItem(0, 1, new QTableWidgetItem("Hannover"));
	mannschaftListeTable->setItem(1, 0, new QTableWidgetItem("Hannover 2"));
	mannschaftListeTable->setItem(1, 1, new QTableWidgetItem("Hannover"));
}

MannschaftListeEditor::~MannschaftListeEditor()
{

}