#ifndef MYFILEIO_H
#define MYFILEIO_H

#include <QDir>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QApplication>
#include <QList>
#include <dorf.h>

class MyFileIO
{
    public:
     //   MyFileIO(QDir Path,  );
        static const QString dorfFile  ;

        static QString readDorfFile( const QString &Path = QString("dorfFile.txt") );
        static QString writeDorfFile( const QString &Input,  const QString &Path = QString("dorfFile.txt"));
        static QString writeDorfFileFromDatabase(const QList<Dorf> & Database ,  const QString &Path = QString("dorfFile.txt"));

};

#endif // MYFILEIO_H
