/* Spielplan */
#include "MannschaftListeEditor.h"

/* local */
#include "Manager.h"
#include <QDebug>

Manager::Manager(QMainWindow *parent)
: QMainWindow(parent)
{
	setupUi(this);
	connect(actionLoadSpielplan, SIGNAL(triggered()), this, SLOT(loadSpielplan()));
	connect(actionSaveSpielplan, SIGNAL(triggered()), this, SLOT(saveSpielplan()));
	connect(actionExit, SIGNAL(triggered()), this, SLOT(exitManager()));
	connect(actionLoadMannschaftsliste, SIGNAL(triggered()), this, SLOT(loadMannschaftsliste()));
	connect(actionSaveMannschaftsliste, SIGNAL(triggered()), this, SLOT(saveMannschaftsliste()));
	connect(actionEditMannschaftsliste, SIGNAL(triggered()), this, SLOT(editMannschaftsliste()));

	_fileformat = tr("XML-Datei (*.xml)");

	_listeMannschaften = new QList<Mannschaft*>;
}

Manager::~Manager()
{
	//delete _listeMannschaften;
}

void Manager::exitManager()
{
	qApp->exit();
}

void Manager::loadSpielplan()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Spielplan laden"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), _fileformat);
	loadFile(0, filename);
}

void Manager::saveSpielplan()
{
	QString filename = QFileDialog::getSaveFileName(this,
		tr("Spielplan speichern"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), _fileformat);
	saveFile(0, filename);
}

void Manager::loadMannschaftsliste()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Mannschaftsliste laden"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), _fileformat);
	loadFile(1, filename);
}

void Manager::saveMannschaftsliste()
{
	QString filename = QFileDialog::getSaveFileName(this,
		tr("Mannschaftsliste speichern"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), _fileformat);
	saveFile(1, filename);
}

void Manager::editMannschaftsliste()
{
	MannschaftListeEditor *dialogMannschaftsListeEditor = new MannschaftListeEditor();
	connect(dialogMannschaftsListeEditor, SIGNAL(listeChanged(QList<Mannschaft*>*)), this, SLOT(listeMannschaftenChanged(QList<Mannschaft*>*)));
	dialogMannschaftsListeEditor->setMannschaftListe(_listeMannschaften);
	dialogMannschaftsListeEditor->exec();
}

void Manager::listeMannschaftenChanged(QList<Mannschaft*> *liste)
{
	_listeMannschaften = liste;
}

bool Manager::loadFile(int i, QString filename)
{
	QFile file(filename);
	bool ret = file.open(QIODevice::ReadOnly);
	QXmlStreamReader xml(&file);
	switch (i)
	{
	case 0: // Spielplan
		break;
	case 1: // Mannschaftsliste
		QList<Mannschaft*> *liste = new QList<Mannschaft*>;
		while (!xml.atEnd() && !xml.hasError())
		{
			QXmlStreamReader::TokenType token = xml.readNext();
			if (token == QXmlStreamReader::StartDocument)
			{
				continue;
			}
			if (token == QXmlStreamReader::StartElement)
			{
				if (xml.name() == "mannschaftsliste")
				{
					continue;
				}
				if (xml.name() == "mannschaft")
				{
					liste->append(parseMannschaft(xml));
				}
			}
		}
		_listeMannschaften = liste;
		break;
	}
	if (xml.hasError())
	{
		return false;
	}
	xml.clear();
	file.close();
	return ret;
}

bool Manager::saveFile(int i, QString filename)
{
	QFile file(filename);
	bool ret = file.open(QIODevice::WriteOnly);
	QXmlStreamWriter xml(&file);
	xml.setAutoFormatting(true);
	xml.writeStartDocument();
	switch (i)
	{
	case 0: // Spielplan
		break;
	case 1: // Mannschaftsliste
		xml.writeStartElement("mannschaftsliste");
		QListIterator<Mannschaft*> i(*_listeMannschaften);
		while (i.hasNext())
		{
			Mannschaft* tmp = i.next();
			xml.writeStartElement("mannschaft");
			xml.writeTextElement("name", tmp->_name);
			xml.writeTextElement("herkunft", tmp->_herkunft);
			xml.writeTextElement("schiri", tmp->_hatSchiri ? "true" : "false");
			xml.writeEndElement();
		}
		xml.writeEndElement();
		break;
	}
	xml.writeEndDocument();
	file.close();
	return ret;
}

Mannschaft* Manager::parseMannschaft(QXmlStreamReader &xml)
{
	QString name, herkunft;
	bool hatSchiri;
	xml.readNext();
	while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "mannschaft"))
	{
		if (xml.tokenType() == QXmlStreamReader::StartElement)
		{
			if (xml.name() == "name")
			{
				xml.readNext();
				name = xml.text().toString();
			}
			if (xml.name() == "herkunft")
			{
				xml.readNext();
				herkunft = xml.text().toString();
			}
			if (xml.name() == "schiri")
			{
				xml.readNext();
				hatSchiri = xml.text().toString() == "true" ? true : false;
			}
		}
		xml.readNext();
	}
	return new Mannschaft(name, herkunft, hatSchiri);
}