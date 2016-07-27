#include "datamodel.h"

DataModel::DataModel(QObject *parent) : QAbstractListModel(parent)
{
    try
    {
        dorfList = new QList<Dorf>;
        targetDorf = new Dorf("TargetDorf", 498, 388 );

    }
    catch(...)
    {
        QMessageBox::information(0, "Error", "Some error occured while creting datamodel" );
    }
}

bool DataModel::addDorf(Dorf D)
{

    try
    {
        dorfList->append(D);

    }
    catch(...)
    {
        QMessageBox::information(0, "Error", "Some error occured while adding items to datamodel" );
    }

}



int DataModel::rowCount(const QModelIndex & /* parent */) const
{
     return dorfList->count();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if ( ! index.isValid() )
        return QVariant();

    if ( role == Qt::TextAlignmentRole )
    {
        return int( Qt::AlignRight | Qt::AlignCenter );
    }
    else if (role == Qt::DisplayRole)
    {
        //--------temp-----------\\\

                //int x = dorfList->at(index.row()).getX();
                Dorf tempStartDorf = dorfList->at(index.row());
                Dorf tempTargetDorf = *targetDorf;
                double distanceINminutes = calculateDistance::getCalculateDistance(tempStartDorf, tempTargetDorf, c);
                int distanceINseconds = int(distanceINminutes * 60);

                return distanceINseconds;      //return distance in seconds

        //-------temp-------------\\\



//        QString dorfName = "";
//        dorfName.append( dorfList->at(index.row()).getDorfName());
//        int x = dorfList->at(index.row()).getX();
//        int y = dorfList->at(index.row()).getY();

//       return QString("%1 %2|%3").arg( dorfName ).arg(QString::number(x)).arg(QString::number(y));
    }

    return QVariant();
}


QVariant DataModel::headerData(int section, Qt::Orientation orientation, int role) const
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
}

void DataModel::updateModelDatabase(QList<Dorf> NewDatabase)
{
    dorfList->clear();      //this only detaches elements from list, not delete them
    *dorfList = NewDatabase;

   // emit dataChanged();
}


void DataModel::setZwischenDorfLaufzeit(double C)
{
    this->c = C;
}









