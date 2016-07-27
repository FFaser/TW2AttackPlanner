#include "moderatormodel.h"

//ModeratorModel::ModeratorModel(QObject *parent)
//{

//}

ModeratorModel::ModeratorModel(QList<Dorf> &DorfList, QObject *parent) : QAbstractTableModel(parent)
{

    dorfList = new QList<Dorf>;
    *dorfList = DorfList;
    //WARNING hier prob memoryleak
}



int ModeratorModel::rowCount(const QModelIndex &parent) const
{
    return dorfList->count();
}

int ModeratorModel::columnCount(const QModelIndex &parent) const
{
   return int(3);   //erstmal drei columns eingeplannt
}

QVariant ModeratorModel::data(const QModelIndex &index, int role) const
{
    if ( ! index.isValid())
        return QVariant();

    if ( role == Qt::TextAlignmentRole )
        return int(Qt::AlignRight | Qt::AlignCenter);
    else if ( role == Qt::DisplayRole || role == Qt::EditRole )
    {
        if (index.column() == 0)
        {
            QString dorfInfoBasic = "";

            dorfInfoBasic += dorfList->at(index.row()).getDorfName();
            dorfInfoBasic += "(";
            dorfInfoBasic += QString::number(dorfList->at(index.row()).getX());
            dorfInfoBasic += "|";
            dorfInfoBasic += QString::number(dorfList->at(index.row()).getY());
            dorfInfoBasic += ")";

           return dorfInfoBasic;

        }
        if (index.column() == 1)
        {
            return dorfList->at(index.row()).getMarks();
        }
        if (index.column() == 2)
        {
            return dorfList->at(index.row()).getState();
        }
    }
//    else if (role == Qt::EditRole)
//    {
//        if (index.column() == 1)
//        {
//            eDorfState state = dorfList->at(index.row()).getState();
//            return state;
//        }
//        if (index.column() == 2)
//        {
//            return
//        }
//    }
   return QVariant();
}

QVariant ModeratorModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if ( role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Vertical)
    {
        return section;
    }
    if ( orientation == Qt::Horizontal)
    {
        //evtl später ergänzen
        return section;

        }
     return QVariant();
}

Qt::ItemFlags ModeratorModel::flags(const QModelIndex &index) const
{
    if ( ! index.isValid())
        return Qt::ItemIsEnabled;


        return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool ModeratorModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        if(index.column() == 1)
        {



            //dorfList->operator[](index.row()).setMark(mark);
            (*dorfList)[index.row()].setMarks( static_cast<uint>(value.toInt()) );


            emit dataChanged(index, index);
            return true;

        }



        if(index.column() == 2)
        {
            eDorfState state;
            switch(value.toInt())
            {
                case 0:     state = eDorfState::undefined;      break;
                case 1:     state = eDorfState::active;         break;
                case 2:     state = eDorfState::ontheway;       break;


            }


            //dorfList->operator[](index.row()).setMark(mark);
            (*dorfList)[index.row()].setState(state);


            emit dataChanged(index, index);
            return true;

        }

    }

    return false;
}

