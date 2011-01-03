#include <QtCore/QCoreApplication>

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QChar>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QString infilePath(a.arguments().at(1));
	QString outfilePath(a.arguments().at(2));

	QFile infile(infilePath);
	QFile outfile(outfilePath);
	infile.open(QIODevice::ReadOnly);
	outfile.open(QIODevice::WriteOnly);

	QMap<QChar, QString> m;
	m.insert('a', "a,");
	m.insert('b', "b,");
	m.insert('c', "c,");
	m.insert('d', "d,");
	m.insert('e', "e,");
	m.insert('f', "f,");
	m.insert('g', "g,");
	m.insert('h', "a");
	m.insert('i', "b");
	m.insert('j', "c");
	m.insert('k', "d");
	m.insert('l', "e");
	m.insert('m', "f");
	m.insert('n', "g");
	m.insert('o', "a'");
	m.insert('p', "b'");
	m.insert('q', "c'");
	m.insert('r', "d'");
	m.insert('s', "e'");
	m.insert('t', "f'");
	m.insert('u', "g'");
	m.insert('v', "ais");
	m.insert('w', "bes");
	m.insert('x', "cis");
	m.insert('y', "des");
	m.insert('z', "eis");

	QString s(infile.readAll());
	QTextStream os(&outfile);

	foreach(const QChar& c, s)
	{
		if(m.contains(c))
			os << m.value(c) << " ";
	}


//	return a.exec();
}
