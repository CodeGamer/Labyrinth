#pragma once

/* Qt */
#include <QDialog>

/* Spielplan */
#include "Mannschaft.h"

/* local */
#include "ui_MannschaftListeEditor.h"

class MannschaftListeEditor : public QDialog, public Ui::UI_MannschaftListeEditor
{
	Q_OBJECT
	
	public:
		MannschaftListeEditor(QDialog *parent = 0);
		~MannschaftListeEditor();

		Q_SIGNAL void listeChanged(QList<Mannschaft*> *liste);
		Q_SLOT void mannschaftListeChanged(QList<Mannschaft*> *liste);
		Q_SLOT void on_addButton_clicked();
		Q_SLOT void on_editButton_clicked();
		Q_SLOT void on_deleteButton_clicked();
		Q_SLOT void on_exitButton_clicked();
		Q_SLOT void on_mannschaftListeTable_cellDoubleClicked(int row, int column);
		Q_SLOT void on_mannschaftListeTable_cellClicked(int row, int column);
		Q_SLOT void addMannschaft(int row, Mannschaft *mannschaft);
		Q_SLOT void editMannschaft(int row, Mannschaft *mannschaft);

		void setMannschaftListe(QList<Mannschaft*> *liste);

	private:
		QList<Mannschaft*> *_mannschaftListe;
		QChar *_checkSymbol;
};