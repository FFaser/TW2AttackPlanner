#include "myfileio.h"

//MyFileIO::MyFileIO()
//{

//}

const QString MyFileIO::dorfFile ( "dorfFile.txt");


QString MyFileIO::readDorfFile(const QString &Path)
{
    //for now filepath is hardcoded and QDir Path unused
    QString temp;
    QString str1 = QCoreApplication::applicationDirPath();
    QString str2 = "dorfFile.txt";
    QString str3 = str1 + "/" + str2;
    QFile file( str3 );
    if ( ! file.open(QIODevice::ReadOnly | QIODevice::Text ) )
           return QString();

    QTextStream in(&file);

    temp = in.readAll();

    file.close();
    return temp;
}



QString MyFileIO::writeDorfFileFromDatabase(const QList<Dorf> & Database , const QString &Path)
{
    //for now filepath is hardcoded and QDir Path unused
    QString str1 = QCoreApplication::applicationDirPath();
    QString str2 = "dorfFile.txt";
    QString str3 = str1 + "/" + str2;
    QFile file( str3);
    if ( ! file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        return QString();

    QTextStream out(&file);
    for(int i = 0; i < Database.length(); i++)
    {
        out << Database.at(i).getDorfName() << "\t"
            <<  Database.at(i).getX() << "|"
            << Database.at(i).getY() << "\t"
            << static_cast<int> (Database.at(i).getMarks()) << "\t"
            << static_cast<int> (Database.at(i).getState()) << "\n";
    }



    //out << "Str";

    file.flush();
    file.close();
    return QString();
}

QString MyFileIO::writeDorfFile(const QString &Input,  const QString &Path)
{
    //for now filepath is hardcoded and QDir Path unused
    QString str1 = QCoreApplication::applicationDirPath();
    QString str2 = "dorfFile.txt";
    QString str3 = str1 + "/" + str2;
    QFile file( str3);
    if ( ! file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        return QString();

    QTextStream out(&file);
    out << Input;

    file.flush();
    file.close();
    return QString();
}






