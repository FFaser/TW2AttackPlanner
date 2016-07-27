#include "dorfparser.h"

 QList<Dorf> DorfParser::parseToDatabase( const QString Input)
{
    QList<Dorf> tempDatabase;

    QString local = Input;
    QTextStream stream(&local, QIODevice::ReadOnly);
    QString temp;
    //QString Input1 = "013-04	608|542	11,105";

    while(! (temp = stream.readLine()).isEmpty() )
    {

        int trennzeichen = temp.indexOf("|");
        int x = temp.mid(trennzeichen-3, 3).toInt();
        int y = temp.mid(trennzeichen+1, 3).toInt();

        trennzeichen = temp.indexOf("\t");
        QString dorfname = temp.left(trennzeichen);

        tempDatabase.append(Dorf(dorfname, x, y));


    }

    return tempDatabase;
}

QList<Dorf> DorfParser::parseToDatabaseCorrectOptionsFileOnly( const QString Input)
{
   QList<Dorf> tempDatabase;

   QString local = Input;
   QTextStream stream(&local, QIODevice::ReadOnly);
   QString temp;
   //QString Input1 = "013-04	608|542	11,105";

   while(! (temp = stream.readLine()).isEmpty() )
   {

       int trennzeichen = temp.indexOf("|");
       int x = temp.mid(trennzeichen-3, 3).toInt();
       int y = temp.mid(trennzeichen+1, 3).toInt();

       int tabErster = temp.indexOf("\t");
       QString dorfname = temp.left(tabErster);

       int state = 0;
       int mark = 0;

       int tabZeiter = temp.indexOf("\t", tabErster + 1);
       if (tabZeiter == -1) QMessageBox::information(0, "DorfFile Error", "Some error occured while parsing DorfFile" );
       int tabDritter = temp.indexOf("\t", tabZeiter + 1);
       if (tabDritter == -1) QMessageBox::information(0, "DorfFile Error", "Some error occured while parsing DorfFile" );
       int newline = temp.indexOf("\n");
       QString markStr = temp.mid(tabZeiter + 1, tabDritter - tabZeiter - 1);
       mark = markStr.toInt();
       if (mark < 0 || mark > eDorfMark_MAX)
       {
           QMessageBox::information(0, "DorfFile Error", "Mark out of range" );
           mark = 0;
       }
       QString stateStr = temp.right(temp.length() - tabDritter - 1 );
       state = stateStr.toInt();
       if (state < 0 || state > eDorfState_MAX)
       {
           QMessageBox::information(0, "DorfFile Error", "State out of range" );
           state = 0;
       }
       tempDatabase.append(Dorf(dorfname, x, y, mark, state));


   }

   return tempDatabase;
}



 QString DorfParser::parseCheck(const  QString Input)
 {
    //here parse the input string for correctness
     //TODO later maybe more sophisticated parsechecker
     //e.g. where the first two lines are
     //more carefully checked

     QString local = Input;
     QTextStream stream(&local, QIODevice::ReadOnly);
     QString temp;
     QString result;
     while( ! (temp = stream.readLine()).isEmpty() )
     {
         int trennzeichen = temp.indexOf("|");
         int x = temp.mid(trennzeichen-3, 3).toInt();
         int y = temp.mid(trennzeichen+1, 3).toInt();

         trennzeichen = temp.indexOf("\t");
         QString dorfname = temp.left(trennzeichen);
         result += dorfname + "\t" + QString::number(x) + "|" + QString::number(y) + "\n";
     }
     return result;
 }
