#ifndef DORF_H
#define DORF_H

#include <QObject>
//#include <QMetaEnum>
#include <QStringList>
#include <QList>
#include <QMessageBox>

enum eDorfState{ undefined,
                 active ,
                 ontheway,
                       eDorfState_MAX = ontheway};

enum eDorfMark{ empty = 0,
                mark1 = 1 << 0,
                mark2 = 1 << 1,
                mark3 = 1 << 2,
                mark4 = 1 << 3,
                mark5 = 1 << 4,
                mark6 = 1 << 5,
                mark7 = 1 << 6,
                mark8 = 1 << 7,
                mark9 = 1 << 8,
                mark10 = 1 << 9,
                    eDorfMark_MAX = mark10};

namespace helpers
{
      QList<eDorfMark> uintMarkToFlags(uint Mark);
      eDorfMark uintToeDorfMark(uint Mark);
      uint eDorfMarkToUint(eDorfMark Mark);
}


class Dorf
{


public:
    Dorf();
     Dorf(QString DorfName, int X, int Y );
     Dorf(QString DorfName, int X, int Y, uint Marks, int State );
     Dorf(const Dorf *dorf);
    void set(QString DorfName, int X, int Y);
    void set(QString DorfName, int X, int Y, uint Marks, int State);
    bool isInitializedProperly();
    QString getDorfName()const;
    int getX()const;
    int getY()const;
    void setDorfName(QString DorfName);
    void setX(int X);
    void setY(int Y);
    void setSpeed(double C);
    double getSpeed() const;
    void setSlowestSpeed();
    void setNextSlowestMarksAndSpeedFrom(eDorfMark Mark);

    static bool equals(Dorf A, Dorf B);

    eDorfState getState() const ;
    eDorfMark getMark() const;
    uint getMarks() const;
    void setState(eDorfState DorfState);
    void setMark(eDorfMark Mark);        //WARNING think how to init this
    void setMarks(uint DorfMark);

    static double eDorfMarkToSpeed(eDorfMark Mark);




private:
    QString dorfName;
    int x;
    int y;
    bool isInitialized;

    eDorfState dorfState;
    eDorfMark tempDorfMark;
    uint dorfMarks;

    double c = 0;

};

#endif // DORF_H
