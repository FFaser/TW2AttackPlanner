#include "dorfdatabase.h"


dorfDatabase::dorfDatabase(/*QObject *parent*/)// : QObject(parent)
{
        dorfListDatabase = new QList<Dorf>();
        tempDatabase = new QList<Dorf>();
        tempDorf = new Dorf();

        //dorfListDatabase->append(Dorf("bla", 123, 456));
}


void dorfDatabase::copyDorflist(QList<Dorf> NewDatabase)
{
    delete dorfListDatabase;
    dorfListDatabase = new QList<Dorf> (NewDatabase);
}

void dorfDatabase::readFileDatabase(const QString &Path)
{
    QString input = MyFileIO::readDorfFile();
   // qDebug() << input;

//    copyDorflist(DorfParser::parseToDatabase(input));
      copyDorflist(DorfParser::parseToDatabaseCorrectOptionsFileOnly(input));

emit sendDorfDatabase(*dorfListDatabase);

    return;
}

void dorfDatabase::updateDatabase(QString Input)
{

    delete tempDatabase;    //TODO: delete? maybe delete later?
    tempDatabase = new QList<Dorf>(DorfParser::parseToDatabase(Input));

    Dorf A, B;
    bool match =  false;

    for(int i = 0; i < tempDatabase->length(); i++)
    {
         A = tempDatabase->at(i);

        for(int k = 0; k < dorfListDatabase->length(); k++)
        {

            B = dorfListDatabase->at(k);

            match = Dorf::equals(A, B);
            if ( match == true  )
            {
                //TODO: here maybe later a string comparison befor setting new dorfname
                //dorfListDatabase->operator [](k).setDorfName(A.getDorfName());
                (*dorfListDatabase)[k].setDorfName(A.getDorfName());
                break;
            }
        }
        if (match == false)
        {
            //dorfListDatabase->append(tempDatabase->at(i));
            dorfListDatabase->append(A);
            qDebug() << "Dorf was added";
        }
        else
        {
            match = false;
        }

    }
sortDorfList();
emit sendDorfDatabase(*dorfListDatabase);

}

void dorfDatabase::updateDatabase(QList<Dorf> TempDatabase)
{


    Dorf A, B;
    bool match =  false;

    for(int i = 0; i < TempDatabase.length(); i++)
    {
        for(int k = 0; k < dorfListDatabase->length(); k++)
        {
            A = TempDatabase.at(i);
            B = dorfListDatabase->at(k);

            match = Dorf::equals(A, B);
            if ( match == true  )
            {
                if (A.getMarks() != B.getMarks())
                    //dorfListDatabase->operator [](k).setMark(A.getMark());
                    (*dorfListDatabase)[k].setMarks(A.getMarks());
                if (A.getState() != B.getState())
                    //dorfListDatabase->operator [](k).setState(A.getState());
                    (*dorfListDatabase)[k].setState(A.getState());

               // A.setDorfName(B.getDorfName());   //von moderator zu database erstmal keine namensänderung mögl.
                match = false;
                break;
            }
        }


    }
sortDorfList();
emit sendDorfDatabase(*dorfListDatabase);
}

void dorfDatabase::saveDatabase(  const QString &Path)
{
    MyFileIO::writeDorfFileFromDatabase(*dorfListDatabase);
}

QList<Dorf> dorfDatabase::getAllItems() const
{
    QList<Dorf> temp = *dorfListDatabase;
    //WARNING check is this is working
    return temp;
}

QList<Dorf> dorfDatabase::getSelectedItems(QList<int> indexList)
{
    QList<Dorf> temp;
    foreach(int i, indexList)
        temp.append(dorfListDatabase->at(i));
    return temp;

}

void dorfDatabase::saveDatabaseSlot()
{
    saveDatabase();
}

void dorfDatabase::sortDorfList()
{
    //qSort(dorfList->begin(), dorfList->end(), CompareTwoDorf(targetDorf));
    qSort(dorfListDatabase->begin(), dorfListDatabase->end(), compareByDorfname);

}

bool dorfDatabase::compareByDorfname(const Dorf &A, const Dorf &B)
{
    return A.getDorfName().toLower() < B.getDorfName().toLower();
}



Dorf dorfDatabase::getDorfAt(int Row)
{
    return Dorf(dorfListDatabase->at(Row));
}

void dorfDatabase::updateDorfAt(Dorf TempDorf)
{
    int X = TempDorf.getX();
    int Y = TempDorf.getY();
    foreach (Dorf currentDorf, *dorfListDatabase)
    {
        if (currentDorf.getX() == X && currentDorf.getY() == Y)
            currentDorf = TempDorf;
    }
}

void dorfDatabase::deleteDorfAt(int X, int Y)
{

    for(int i = 0; i < dorfListDatabase->length(); i++)
    {
       const Dorf &currentDorf = dorfListDatabase->at(i);
        if (currentDorf.getX() == X && currentDorf.getY() == Y)
            dorfListDatabase->removeAt(i);
    }
}











