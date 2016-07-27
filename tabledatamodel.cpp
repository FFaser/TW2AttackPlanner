#include "tabledatamodel.h"

TableDataModel::TableDataModel(QDateTime *TargetDT, QTime *Von, QTime *Bis, QObject *parent) : QAbstractTableModel(parent)
{
    try
    {
        dorfList = new QList<Dorf>;
        dorfListBackup = new QList<Dorf>;
        targetDorf = new Dorf("TargetDorf", 498, 388 );
        targetDT = TargetDT;
        von = Von;
        bis = Bis;
        tempDorfMark = empty;
        this->c = 0;

    }
    catch(...)
    {
        QMessageBox::information(0, "Error", "Some error occured while creting datamodel" );
    }
}

bool TableDataModel::addDorf(Dorf D)
{

    try
    {
        dorfList->append(D);

    }
    catch(...)
    {
        QMessageBox::information(0, "Error", "Some error occured while adding items to datamodel" );
    }
return false;
}



int TableDataModel::rowCount(const QModelIndex & index/* parent */) const
{

        return dorfList->count();

}

int TableDataModel::columnCount(const QModelIndex &/* parent */) const
{
    return int(4);      //for now ill just have 2 columns
}

QVariant TableDataModel::data(const QModelIndex &index, int role) const
{
    if ( ! index.isValid() )
        return QVariant();

    if ( role == Qt::TextAlignmentRole )
    {
        return int( Qt::AlignRight | Qt::AlignCenter );
    }
    else if (role == Qt::DisplayRole || role == Qt::EditRole || role == Qt::UserRole)
    {
        if(this->c == 0)
            QMessageBox::information(0, "Error Datamodel", "Speen in Tablemodel is 0");
        if(this->tempDorfMark == 0)
            QMessageBox::information(0, "Error datamodel", "TempEDorfMark is empty(=0)");






        if(index.column() == 0 || index.column() == 1)
        {


                //int x = dorfList->at(index.row()).getX();


            int distanceINseconds = 0;
            Dorf tempStartDorf = dorfList->at(index.row());
            Dorf tempTargetDorf = *targetDorf;
            if(tempStartDorf.getMark() == empty)
            {
                distanceINseconds = 60 * calculateDistance::getCalculateDistance(tempStartDorf, tempTargetDorf, this->c);
            }
            else
            {
                double dorfSpeed = tempStartDorf.getSpeed();
                if(dorfSpeed == 0)
                    QMessageBox::information(0, "Error tablemodel", "tempstartdorf speed is 0");
                distanceINseconds = 60 * calculateDistance::getCalculateDistance(tempStartDorf, tempTargetDorf, dorfSpeed);

            }



            return distanceINseconds;      //return distance in seconds




//        QString dorfName = "";
//        dorfName.append( dorfList->at(index.row()).getDorfName());
//        int x = dorfList->at(index.row()).getX();
//        int y = dorfList->at(index.row()).getY();

//       return QString("%1 %2|%3").arg( dorfName ).arg(QString::number(x)).arg(QString::number(y));
        }





        if(index.column() == 2)
        {
            if (role == Qt::DisplayRole )
                return dorfList->at(index.row()).getMarks();
            if ( role == Qt::EditRole)
                return dorfList->at(index.row()).getMark();
            if (role == Qt::UserRole)
                return tempDorfMark;
        }
        if(index.column() == 3)
        {
            return dorfList->at(index.row()).getState();
        }
    }

    return QVariant();
}


//QVariant TableDataModel::data(const QModelIndex &index, int role) const
//{
//    if ( ! index.isValid() )
//        return QVariant();

//    if ( role == Qt::TextAlignmentRole )
//    {
//        return int( Qt::AlignRight | Qt::AlignCenter );
//    }
//    else if (role == Qt::DisplayRole || role == Qt::EditRole)
//    {
//        if(index.column() == 0 || index.column() == 1)
//        {


//                //int x = dorfList->at(index.row()).getX();
//                Dorf tempStartDorf = dorfList->at(index.row());
//                Dorf tempTargetDorf = *targetDorf;
//                double distanceINminutes = calculateDistance::getCalculateDistance(tempStartDorf, tempTargetDorf, c);
//                int distanceINseconds = int(distanceINminutes * 60);
//               // qDebug() << "distance from tablemodel: " << distanceINminutes;
//                return distanceINseconds;      //return distance in seconds




////        QString dorfName = "";
////        dorfName.append( dorfList->at(index.row()).getDorfName());
////        int x = dorfList->at(index.row()).getX();
////        int y = dorfList->at(index.row()).getY();

////       return QString("%1 %2|%3").arg( dorfName ).arg(QString::number(x)).arg(QString::number(y));
//        }

//        if(index.column() == 2)
//        {
//            return dorfList->at(index.row()).getMark();
//        }
//        if(index.column() == 3)
//        {
//            return dorfList->at(index.row()).getState();
//        }
//    }

//    return QVariant();
//}


QVariant TableDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if ( orientation == Qt::Vertical )
    {
        QString dorfName = "";
        dorfName.append( dorfList->at(section).getDorfName() );
        dorfName.append("(" + QString::number(dorfList->at(section).getX()) + "|" + QString::number(dorfList->at(section).getY()) + ")"  );
        return dorfName;
    }
    if(orientation == Qt::Horizontal)
    {
        if(section == 0)
        {
            return QString(tr("Remaining time"));
        }
        if(section == 1)
        {
            return QString(tr("Sendoff time"));
        }
        if(section == 2)
        {
            return QString(tr("Marks"));
        }
        if(section == 3)
        {
            return QString(tr("Status"));
        }
    }

    return QVariant();
}

void TableDataModel::updateModelDatabase(QList<Dorf> NewDatabase)
{

    emit beginResetModel();



   foreach(Dorf dorf, NewDatabase)
   {
       if (dorf.getState() == eDorfState::active)
       {
            addNewDorf(dorf);   //WARNING: here can be problems
       }
   }
    accountForTimeIntervall();
    sort(0, Qt::DescendingOrder);

    emit endResetModel();


//    emit beginResetModel();
//    dorfList->clear();      //this only detaches elements from list, not delete them
//    dorfListBackup->clear();    //WARNING possible memoryleak
//    //*dorfList = NewDatabase;
//   foreach(Dorf dorf, NewDatabase)
//   {
//       if (dorf.getState() == eDorfState::active)
//       {
//            dorf.setMark(tempDorfMark);
//            dorfList->append(dorf);
//            dorfListBackup->append(dorf);
//       }
//   }
//    accountForTimeIntervall();

//    emit endResetModel();

}


void TableDataModel::setZwischenDorfLaufzeit(double C)
{
    this->c = C;
}

void TableDataModel::setMarkChangeForBackupList(Dorf D)
{
    for(int i = 0; i < dorfListBackup->length(); i++)
    {
        if( Dorf::equals( dorfListBackup->at(i), D))
        {
            (*dorfListBackup)[i].setMark(D.getMark());
        }
    }
}

void TableDataModel::addNewDorf(Dorf D)
{
    bool dorfAlreadyExists = false;
    foreach(Dorf dorf, *dorfListBackup)
    {
        if(Dorf::equals(dorf, D))
        {
            dorfAlreadyExists = true;
            break;
        }
    }
    if(dorfAlreadyExists == false)
    {
        D.setMark(tempDorfMark);
        dorfListBackup->append(D);

    }

    dorfAlreadyExists = false;
    foreach(Dorf dorf, *dorfList)
    {
        if(Dorf::equals(dorf, D))
        {
            dorfAlreadyExists = true;
            break;
        }
    }
    if(dorfAlreadyExists == false)
    {
        D.setMark(tempDorfMark);
        dorfList->append(D);

    }
}

void TableDataModel::removeDorf(Dorf D)
{
    for(int i = 0; i < dorfListBackup->length(); i++)
    {
        if(Dorf::equals(dorfListBackup->at(i), D))
        {
            dorfListBackup->removeAt(i);
            break;
        }
    }

    for(int i = 0; i < dorfList->length(); i++)
    {
        if(Dorf::equals(dorfList->at(i), D))
        {
            dorfList->removeAt(i);
            break;
        }
    }


}

void TableDataModel::setTempDorfMark(eDorfMark Mark)
{
    this->tempDorfMark = Mark;
    this->c = Dorf::eDorfMarkToSpeed(Mark); //this maybe obsolete

    for(int i = 0; i < dorfList->length(); i++)
    {
        (*dorfList)[i].setMark(Mark);
    }

    for(int i = 0; i < dorfListBackup->length(); i++)
    {
        (*dorfListBackup)[i].setMark(Mark);
    }
}

 void TableDataModel::sort(int column, Qt::SortOrder order)
 {
     qSort(dorfList->begin(), dorfList->end(), CompareTwoDorf(targetDorf));

 }

 Qt::ItemFlags TableDataModel::flags(const QModelIndex &index) const
 {
     if ( ! index.isValid())
         return Qt::ItemIsEnabled;


         return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
 }

 bool TableDataModel::setData(const QModelIndex &index, const QVariant &value, int role)
 {
     //goal here. set update to database each time a single dorf is edited
     //so the main database cachange apply to all planertables at once

     if(index.isValid() && role == Qt::EditRole)
     {
         if(index.column() == 2)
         {
            (*dorfList)[index.row()].setMark( helpers::uintToeDorfMark( (uint)value.toInt() ) );

             Dorf D = dorfList->at(index.row());
             D.setMark(helpers::uintToeDorfMark( (uint)value.toInt() ));
             setMarkChangeForBackupList( D );

             //WARNING: maybe start refresh here, if view doesnt update after change
             //well, it does, but one has to unmark the row/cell first, weird...
         }



        if(index.column() == 3)
        {
             QList<Dorf> temp;
             Dorf dorf = dorfList->at(index.row());
             eDorfState state;
             switch(value.toInt())
             {
                 case 0:     state = eDorfState::undefined;      break;
                 case 1:     state = eDorfState::active;         break;
                 case 2:     state = eDorfState::ontheway;       break;


             }
             dorf.setState(state);
             temp.append(dorf);
            // emit dataChanged(index, index);
            removeDorf(dorf);
             emit emitPlanerModelChanged(temp);

             return true;
        }
     }
     return false;
 }


 void TableDataModel::updateForTimeIntervall()
 {
     emit beginResetModel();
     accountForTimeIntervall();
     emit endResetModel();
 }


 void TableDataModel::accountForTimeIntervall()
 {
     //WARNING rewrite here so applying TimeIntervall doesnt remove villages from the list
     //but rather somehow hide them, while in same time offering the possibility to
     // push them in in sight by suggesting change troops-kind
     if(von->isValid() && bis->isValid() )
     {
        if( von != bis )
        {
            (*dorfList)=(*dorfListBackup);
             for(int i = 0; i < dorfList->length(); i++)
             {
                 //Dorf tempStartDorf = dorfList->at(index.row());
                 Dorf tempStartDorf = dorfList->at(i);
                 Dorf tempTargetDorf = *targetDorf;
                 double distanceINminutes = calculateDistance::getCalculateDistance(tempStartDorf, tempTargetDorf, tempStartDorf.getSpeed());
                 int distanceINseconds = int(distanceINminutes * 60);
                 QDateTime sendeDT = targetDT->addSecs(-distanceINseconds);
                 if( ! (((*von) < (*bis) && (sendeDT.time() > (*von) && sendeDT.time() < (*bis)))
                         ||  ( (*von) > (*bis)  && (sendeDT.time() > (*von) || sendeDT.time() < (*bis)) )) )
                 {
                     dorfList->removeAt(i);
                     i--;
                 }

             }
        }

     }
     else
     {
        (*dorfList)=(*dorfListBackup);
     }
 }

 eDorfMark TableDataModel::getTempDorfMark() const
 {
     return tempDorfMark;
 }


