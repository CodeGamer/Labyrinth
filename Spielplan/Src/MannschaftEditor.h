#pragma once

/* Qt */
#include <QDialog>

/* Spielplan */
#include "Mannschaft.h"

/* local */
#include "ui_MannschaftEditor.h"

class MannschaftEditor : public QDialog, public Ui::UI_MannschaftEditor
{
	Q_OBJECT
	
	public:
		MannschaftEditor(QDialog *parent = 0);
		~MannschaftEditor();

		Q_SIGNAL void mannschaftChanged(int row, Mannschaft *mannschaft);
		Q_SLOT void on_saveButton_clicked();
		Q_SLOT void on_exitButton_clicked();

		void setMannschaft(int row, Mannschaft *mannschaft);

	private:
		int _row;
		Mannschaft *_mannschaft;
};