#pragma once

/* Qt */
#include <QDialog>

/* Spielplan */


/* local */
#include "ui_MannschaftEditor.h"

class MannschaftEditor : public QDialog, public Ui::UI_MannschaftEditor
{
	Q_OBJECT
	
	public:
		MannschaftEditor(QDialog *parent = 0);
		~MannschaftEditor();
};