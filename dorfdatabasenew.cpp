#include "dorfdatabasenew.h"



//DorfDatabaseNew::DorfDatabaseNew()
//{
//    dorfListDatabase = new QList<Dorf>();
//    tempDatabase = new QList<Dorf>();
//    tempDorf = new Dorf();

//    dorfListDatabase->append(Dorf("bla", 123, 456));
//}


void DorfDatabaseNew::copyDorflist(QList<Dorf> NewDatabase)
{
    dorfListDatabase->clear();
    *dorfListDatabase = NewDatabase;
}

void DorfDatabaseNew::readFileDatabase(const QString &Path)
{
    QString input = MyFileIO::readDorfFile();
   // qDebug() << input;

    copyDorflist(DorfParser::parseToDatabase(input));



    return;
}

//void DorfDatabaseNew::addDorf(QString temp)    //make it later "inline" perhaps
//{

//}
