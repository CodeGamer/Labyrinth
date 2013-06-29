
// Die zu includierenden Dateien entsprechen den Klassen, die man benutzen möchte

// Hauptklasse 
# include <QApplication>
// Textfenster zum reinschreiben
# include <QTextEdit>

int main(int argv, char **args)
{
	// Erzeugt das Hauptprogramm
    QApplication app(argv, args);
	// Erzeugt ein "Widgets" (z.B. Scrollbalken, Buttons - hier ein Textfeld/Fenster zum schreiben)
    QTextEdit textEdit;
	// Zeigt das Widgets an.
    textEdit.show();
	// Hier startet QT seine Hauptschleife, um Events abzufangen (Mausklick, Tastaturanschlag)
    return app.exec();
}