#pragma once

/* Qt */
#include <QDialog>

/* local */
#include "ui_MannschaftListeEditor.h"

class MannschaftListeEditor : public QDialog, public Ui::UI_MannschaftListeEditor
{
	Q_OBJECT
	
	public:
		MannschaftListeEditor(QDialog *parent = 0);
		~MannschaftListeEditor();

	private:
};