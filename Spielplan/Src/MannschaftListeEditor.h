#pragma once

#include <QDialog>

#include "ui_MannschaftListeEditor.h"

class MannschaftListeEditor : public QDialog, public Ui::UI_MannschaftListeEditor
{
	Q_OBJECT
	
	public:
		MannschaftListeEditor(QDialog *parent = 0);
		~MannschaftListeEditor();

	private:
};