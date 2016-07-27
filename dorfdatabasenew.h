#ifndef DORFDATABASENEW_H
#define DORFDATABASENEW_H


#include <dorf.h>
#include <dorfparser.h>
#include <myfileio.h>
#include <QString>
#include <QDebug>
#include <dorfparser.h>

class DorfDatabaseNew
{
public:
   // DorfDatabaseNew();


public slots:
    void readFileDatabase(const QString &Path = QString("dorfFile.txt"));
    void updateDatabase(QString Input);
    void saveDatabase(QString Path);

    void copyDorflist(QList<Dorf> NewDatabase);

private:
    QList<Dorf> *dorfListDatabase;
    QList<Dorf> *tempDatabase;
    Dorf *tempDorf;

    void addDorf(QString temp);

};

#endif // DORFDATABASENEW_H
