#ifndef MODERATORMODEL_H
#define MODERATORMODEL_H

#include <QAbstractTableModel>
#include <dorf.h>
#include <QDebug>
#include <QMessageBox>


class ModeratorModel : public QAbstractTableModel
{

    Q_OBJECT

public:
  //  ModeratorModel(QObject *parent = 0);
    ModeratorModel(QList<Dorf> &DorfList, QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    //to make the model editable insert ->
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);


    QList<Dorf> moderatorModelUpdated(){ return *dorfList; }

private:
    QList<Dorf> *dorfList;





};

#endif // MODERATORMODEL_H
