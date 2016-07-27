#ifndef TABLEDATAMODEL_H
#define TABLEDATAMODEL_H



#include <QAbstractTableModel>
#include <dorf.h>
#include <calculatedistance.h>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <QtAlgorithms>
#include <QModelIndex>
#include <QDateTime>
#include <QTime>
#include <QMessageBox>


class CompareTwoDorf
{
private:
    const Dorf tempTargetDorf;
public:
    CompareTwoDorf(const Dorf *dorf) : tempTargetDorf(dorf){}
    bool operator() (const Dorf &A, const Dorf &B)
    {
        bool result = false;
//        const int c = 8;    //const because its used only for sorting
//        double distanceA = calculateDistance::getCalculateDistance(A, tempTargetDorf, c);
//        double distanceB = calculateDistance::getCalculateDistance(B, tempTargetDorf, c);

        double distanceA = calculateDistance::getCalculateDistance(A, tempTargetDorf, (int)A.getSpeed());
        double distanceB = calculateDistance::getCalculateDistance(B, tempTargetDorf, (int)B.getSpeed());
        result = distanceA > distanceB;
        return result;
    }
};

class TableDataModel : public QAbstractTableModel
{
    Q_OBJECT


public:
    TableDataModel( QDateTime *TargetDT = 0, QTime *Von = 0, QTime *Bis = 0,
                    QObject *parent = 0);

     //these both are enough for a read-only model
        int rowCount(const QModelIndex &index /*&parent*/) const;
        int columnCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;

   QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    bool addDorf(Dorf d);
  //  bool addDorf(int X, int Y, QString DorfName);

    Dorf *targetDorf;  //schlechter stil, später ändern


    void setTempDorfMark(eDorfMark Mark);

    void sort(int column, Qt::SortOrder order);

//   static bool compareTwoDorfLessThan(const Dorf &A, const Dorf &B ) ;

    //to make the model editable insert following ->
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    void accountForTimeIntervall();

    eDorfMark getTempDorfMark() const;

signals:
    void emitPlanerModelChanged(QList<Dorf> oneChangedDorfInTheList);


public slots:
    void updateModelDatabase( QList<Dorf> NewDatabase );
    void emitFakeResetModelSignal(){ emit dataChanged(QModelIndex(), QModelIndex()); emit this->headerDataChanged(Qt::Vertical, int(), int()); };
    void updateForTimeIntervall();

private:
    double c;       // die kleineste laufzeit-einheit zwischen zwei dörfern in min
    eDorfMark tempDorfMark;
    QList< Dorf > *dorfList;
    QList< Dorf > *dorfListBackup;
    QDateTime *targetDT;
    QTime *von;
    QTime *bis;

    void setZwischenDorfLaufzeit(double C);
    void setMarkChangeForBackupList(Dorf D);
    void addNewDorf(Dorf D);
    void removeDorf(Dorf D);

};


#endif // TABLEDATAMODEL_H
