#ifndef MYENUMHELPER_H
#define MYENUMHELPER_H


#include <QStringList>
#include <dorf.h>
#include <QHash>

class MyEnumHelper
{
public:
    MyEnumHelper();

     QString eDorfMark_ItemName(eDorfMark Mark);
     eDorfMark eDorfMark_QStringToEnum(QString Str);
     QStringList eDorfMark_ItemNameList();

private:
     QHash<QString, eDorfMark> hash;
};

#endif // MYENUMHELPER_H
