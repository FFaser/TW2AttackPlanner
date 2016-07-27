#ifndef DORFPARSER_H
#define DORFPARSER_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QList>
#include <dorf.h>
#include <QMessageBox>


class DorfParser
{
public:
   // DorfParser(QString Input);
    static QList<Dorf> parseToDatabase(const  QString Input = QString("013-04\t608|542\t11,105\nbladorf\t456|8789\tasdfg"));
    static QList<Dorf> parseToDatabaseCorrectOptionsFileOnly(const  QString Input = QString("013-04\t608|542\t11,105\nbladorf\t456|8789\tasdfg"));
    static QString parseCheck(const QString Input);


};

#endif // DORFPARSER_H
