#ifndef DORFDATABASE_H
#define DORFDATABASE_H

#include <dorf.h>
#include <dorfparser.h>
#include <myfileio.h>
#include <QString>
#include <QDebug>
#include <dorfparser.h>
#include <QObject>
#include <QSet>
#include <QtAlgorithms>

class dorfDatabase : public QObject
{
    Q_OBJECT

public:
    dorfDatabase(/*QObject *parent = 0*/);
    void saveDatabase(const QString &Path = QString("dorfFile.txt"));

    QList<Dorf> getAllItems() const ;
    QList<Dorf> getSelectedItems(QList<int> indexList);

    void sortDorfList();

    //getter und setter für das moderatormodel
    Dorf getDorfAt(int Row);
    void updateDorfAt(Dorf TempDorf);
    void deleteDorfAt(int X, int Y);



signals:
    void sendDorfDatabase(QList<Dorf> Database);


public slots:
    void readFileDatabase(const QString &Path = QString("dorfFile.txt"));
    void updateDatabase(QString Input);
    void updateDatabase(QList<Dorf>  TempDatabase);
    void saveDatabaseSlot();

    void copyDorflist(QList<Dorf> NewDatabase);

private:
    QList<Dorf> *dorfListDatabase;
    QList<Dorf> *tempDatabase;
    Dorf *tempDorf;

   // void addDorf(QString temp);
    static bool compareByDorfname(const Dorf &A, const Dorf &B);

};

#endif // DORFDATABASE_H
