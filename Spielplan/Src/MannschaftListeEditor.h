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

	Q_SIGNAL void listeChanged(QList<Mannschaft> *liste);
	Q_SLOT void mannschaftListeChanged(QList<Mannschaft> *liste);

	void setMannschaftListe(QList<Mannschaft> *liste);

	private:
		QList<Mannschaft> *_mannschaftListe;
};