#include <QtCore/QCoreApplication>

#include <QString>
#include <QStringList>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QMap>
#include <QChar>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QString infilePath(a.arguments().at(1));
	QString outfilePath(QString("blabla.tmpfile%1.ly" ).arg(qrand()));
//	QFileInfo finfo(infilePath);
	QString pdfFile(infilePath);

	QFile infile(infilePath);
	QFile outfile(outfilePath);
	infile.open(QIODevice::ReadOnly);
	outfile.open(QIODevice::WriteOnly);

	QMap<QChar, QString> m;
	m.insert('a', "a");
	m.insert('b', "b");
	m.insert('c', "c");
	m.insert('d', "d");
	m.insert('e', "e");
	m.insert('f', "f");
	m.insert('g', "g");
	m.insert('h', "a'");
	m.insert('i', "b'");
	m.insert('j', "c'");
	m.insert('k', "d'");
	m.insert('l', "e'");
	m.insert('m', "f'");
	m.insert('n', "g'");
	m.insert('o', "a''");
	m.insert('p', "b''");
	m.insert('q', "c''");
	m.insert('r', "d''");
	m.insert('s', "e''");
	m.insert('t', "f''");
	m.insert('u', "g''");
	m.insert('v', "ais");
	m.insert('w', "bes");
	m.insert('x', "cis");
	m.insert('y', "des");
	m.insert('z', "eis");

	QString s(infile.readAll());
	QTextStream os(&outfile);

	os << "\\version \"2.12.3\"\n";
	os << "\\paper{\n";
	os << "	paper-width = 300\\pt\n";
	os << "	paper-height = 420\\pt\n";
	os << "	left-margin = 0\n";
	os << "	right-margin = 0\n";
	os << "	line-width = 300\\pt\n";
	os << "	indent = 0\n";
	os << "	top-margin = 0\n";
	os << "	page-top-space = 0\n";
	os << "	head-separation = 0\n";
	os << "	bottom-margin = 0\n";
	os << "	}\n";

	os << "{\n";
	int counter(0);
	foreach(const QChar& c, s)
	{
		if(m.contains(c))
		{
			os << m.value(c) << " ";
		}
		if(counter == 8)
		{
			os << "\n";
			counter = -1;
		}
		++counter;
	}
	os << "\n}\n";
	os << "\\addlyrics {\n";
	os << s ;
	os << "\n}\n";

	os.flush();
	outfile.close();

	outfile.open(QIODevice::ReadOnly);
	qDebug()<<outfile.readAll();


	QProcess proc;
	proc.setProcessChannelMode(QProcess::ForwardedChannels);
	QStringList pArgs;
	pArgs << "--verbose"<< "-o" << pdfFile << outfilePath;
	qDebug()<<"lilypond"<< pArgs.join(" ");
	proc.start("lilypond", pArgs);
	if(proc.waitForStarted())
		qDebug()<< "SUCCESSFULY STARTED!!!!!";
	if(proc.waitForFinished())
		qDebug()<< "SUCCESSFULY FINISHED!!!!!";


	outfile.remove();
//	return a.exec();
}
