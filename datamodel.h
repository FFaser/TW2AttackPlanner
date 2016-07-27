#ifndef DATAMODEL_H
#define DATAMODEL_H


#include <QAbstractTableModel>
#include <QAbstractListModel>

#include <dorf.h>
#include <calculatedistance.h>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
class DataModel : public QAbstractListModel
{
    Q_OBJECT

public:
    DataModel(QObject *parent = 0);

     //thise both are enough for a read-only model
        int rowCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;

   QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    bool addDorf(Dorf d);
  //  bool addDorf(int X, int Y, QString DorfName);

    Dorf *targetDorf;  //schlechter stil, später ändern

    void setZwischenDorfLaufzeit(double C);



public slots:
    void updateModelDatabase( QList<Dorf> NewDatabase );


private:
    double c;       // die kleineste laufzeit-einheit zwischen zwei dörfern in min
    QList< Dorf > *dorfList;


};

#endif // DATAMODEL_H
