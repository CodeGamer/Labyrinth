#pragma once

#include <QDialog>

#include "ui_MannschaftListe.h"

class MannschaftListe : public QDialog, public Ui::UI_MannschaftListe
{
	Q_OBJECT
	
	public:
		MannschaftListe(QDialog *parent = 0);
		~MannschaftListe();

	private:
};