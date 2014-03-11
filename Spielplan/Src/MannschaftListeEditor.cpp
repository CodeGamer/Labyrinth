/* Spielplan */
#include "MannschaftEditor.h"

/* local */
#include "MannschaftListeEditor.h"

MannschaftListeEditor::MannschaftListeEditor(QDialog *parent)
: QDialog(parent)
{
	setupUi(this);
	connect(this, SIGNAL(listeChanged(QList<Mannschaft*>*)), this, SLOT(mannschaftListeChanged(QList<Mannschaft*>*)));
	
	_checkSymbol = new QChar(10003);
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
	mannschaftListeTable->setRowCount(liste->size());
	mannschaftListeTable->setColumnCount(3);

	mannschaftListeTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	mannschaftListeTable->setHorizontalHeaderLabels(QString("Mannschaft;Herkunft;Schiedsrichter").split(";"));

	QListIterator<Mannschaft*> i(*liste);
	int row = 0;
	while (i.hasNext())
	{
		Mannschaft* tmp = i.next();
		mannschaftListeTable->setItem(row, 0, new QTableWidgetItem(tmp->_name));
		mannschaftListeTable->setItem(row, 1, new QTableWidgetItem(tmp->_herkunft));
		if (tmp->_hatSchiri)
		{
			mannschaftListeTable->setItem(row, 2, new QTableWidgetItem(QString(_checkSymbol,1)));
		}
		else
		{
			mannschaftListeTable->setItem(row, 2, new QTableWidgetItem(""));
		}
		mannschaftListeTable->item(row, 2)->setTextAlignment(Qt::AlignCenter);
		row++;
	}

	mannschaftListeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	
	QHeaderView* headerView = new QHeaderView(Qt::Horizontal);
	headerView->setSectionResizeMode(QHeaderView::Stretch);
	mannschaftListeTable->setHorizontalHeader(headerView);
	headerView = new QHeaderView(Qt::Vertical);
	headerView->setSectionResizeMode(QHeaderView::ResizeToContents);
	mannschaftListeTable->setVerticalHeader(headerView);
	mannschaftListeTable->resizeColumnsToContents();
}

void MannschaftListeEditor::on_addButton_clicked()
{
	MannschaftEditor *dialogMannschaftsEditor = new MannschaftEditor();
	connect(dialogMannschaftsEditor, SIGNAL(mannschaftChanged(int, Mannschaft*)), this, SLOT(addMannschaft(int, Mannschaft*)));
	Mannschaft *mannschaft = new Mannschaft("", "", false);
	dialogMannschaftsEditor->setMannschaft(mannschaftListeTable->rowCount(), mannschaft);
	dialogMannschaftsEditor->exec();
}

void MannschaftListeEditor::on_editButton_clicked()
{
	MannschaftEditor *dialogMannschaftsEditor = new MannschaftEditor();
	connect(dialogMannschaftsEditor, SIGNAL(mannschaftChanged(int, Mannschaft*)), this, SLOT(editMannschaft(int, Mannschaft*)));
	dialogMannschaftsEditor->setMannschaft(mannschaftListeTable->currentRow(), _mannschaftListe->at(mannschaftListeTable->currentRow()));
	dialogMannschaftsEditor->exec();
}

void MannschaftListeEditor::on_deleteButton_clicked()
{
	int currRow = mannschaftListeTable->currentRow();
	Mannschaft *tmp = _mannschaftListe->takeAt(currRow);
	tmp->~Mannschaft();
	mannschaftListeTable->removeRow(currRow);
}

void MannschaftListeEditor::on_exitButton_clicked()
{
	MannschaftListeEditor::close();
}

void MannschaftListeEditor::on_mannschaftListeTable_cellDoubleClicked(int row, int column)
{
	row++;
	column++;
	on_editButton_clicked();
}

void MannschaftListeEditor::addMannschaft(int row, Mannschaft *mannschaft)
{
	_mannschaftListe->append(mannschaft);
	mannschaftListeTable->setRowCount(row+1);
	mannschaftListeTable->setItem(row, 0, new QTableWidgetItem(mannschaft->_name));
	mannschaftListeTable->setItem(row, 1, new QTableWidgetItem(mannschaft->_herkunft));
	if (mannschaft->_hatSchiri)
	{
		mannschaftListeTable->setItem(row, 2, new QTableWidgetItem(QString(_checkSymbol,1)));
		mannschaftListeTable->item(row, 2)->setTextAlignment(Qt::AlignCenter);
	}
}

void MannschaftListeEditor::editMannschaft(int row, Mannschaft *mannschaft)
{
	mannschaftListeTable->item(row, 0)->setText(mannschaft->_name);
	mannschaftListeTable->item(row, 1)->setText(mannschaft->_herkunft);
	if (mannschaft->_hatSchiri)
	{
		mannschaftListeTable->item(row, 2)->setText(QString(_checkSymbol,1));
	}
	else
	{
		mannschaftListeTable->item(row, 2)->setText("");
	}
}