class Mannschaft
{
public:
	Mannschaft(QString name, QString herkunft);
	~Mannschaft();
private:
	QString _name;
	QString _herkunft;
	bool _proRichter;
	bool _proRettung;
};
