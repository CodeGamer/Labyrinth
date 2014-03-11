/* local */
#include "MannschaftEditor.h"

MannschaftEditor::MannschaftEditor(QDialog *parent)
: QDialog(parent)
{
	setupUi(this);
}

MannschaftEditor::~MannschaftEditor()
{

}

void MannschaftEditor::setMannschaft(int row, Mannschaft *mannschaft)
{
	_row = row;
	_mannschaft = mannschaft;
	lineName->setText(_mannschaft->_name);
	lineHerkunft->setText(_mannschaft->_herkunft);
	if (_mannschaft->_hatSchiri)
	{
		checkBoxSchiri->setChecked(true);
	}
}

void MannschaftEditor::on_saveButton_clicked()
{
	_mannschaft->_name = lineName->text();
	_mannschaft->_herkunft = lineHerkunft->text();
	_mannschaft->_hatSchiri = checkBoxSchiri->isChecked();
	Q_EMIT mannschaftChanged(_row, _mannschaft);
	MannschaftEditor::close();
}

void MannschaftEditor::on_exitButton_clicked()
{
	MannschaftEditor::close();
}