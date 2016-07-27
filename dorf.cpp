#include "dorf.h"



Dorf::Dorf()
{
    dorfName = "";
    x = 0;
    y = 0;
    isInitialized = false;
    dorfState = undefined;
    dorfMarks = (uint)empty;
    tempDorfMark = empty;
}

Dorf::Dorf(const Dorf *dorf)
{
    this->dorfName = dorf->getDorfName();
    this->x = dorf->getX();
    this->y = dorf->getY();
    this->isInitialized = true;
    this->dorfState = dorf->getState();
    this->dorfMarks = dorf->getMarks();
    this->tempDorfMark = dorf->getMark();
}

Dorf::Dorf(QString DorfName, int X, int Y)
{
    dorfName = DorfName;
    x = X;
    y = Y;
    isInitialized = true;
    dorfState = undefined;
    dorfMarks = (uint)empty;
    tempDorfMark = empty;
}

Dorf::Dorf(QString DorfName, int X, int Y, uint Marks, int State)
{
    dorfName = DorfName;
    x = X;
    y = Y;
    isInitialized = true;
    dorfState = static_cast<eDorfState>(State);
    dorfMarks = Marks;
    tempDorfMark = empty;
}

void Dorf::set(QString DorfName, int X, int Y)
{
    dorfName = DorfName;
    x = X;
    y = Y;
    isInitialized = true;
}

void Dorf::set(QString DorfName, int X, int Y, uint Marks, int State)
{
    dorfName = DorfName;
    x = X;
    y = Y;
    isInitialized = true;
    dorfState = static_cast<eDorfState>(State);
    dorfMarks = Marks;
}

bool Dorf::isInitializedProperly()
{
    return isInitialized;
}

QString Dorf::getDorfName()const
{
    return dorfName;
}

Dorf::getX()const
{
    return x;
}

Dorf::getY()const
{
    return y;
}

void Dorf::setDorfName(QString DorfName)
{
    dorfName = DorfName;
}

void Dorf::setX(int X)
{
    x = X;
}

void Dorf::setY(int Y)
{
    y = Y;
}

void Dorf::setSpeed(double C)
{
    this->c = C;
}

double Dorf::getSpeed() const
{
    return this->c;
}

void Dorf::setSlowestSpeed()
{
    double C = 0;

    if( (dorfMarks & eDorfMark::mark1) == eDorfMark::mark1)
    {
        c = 8;
    }
    if( (dorfMarks & eDorfMark::mark2) == eDorfMark::mark2)
    {
        c = 9;
    }
    if( (dorfMarks & eDorfMark::mark3) == eDorfMark::mark3)
    {
        c = 14;
    }
    if( (dorfMarks & eDorfMark::mark4) == eDorfMark::mark4)
    {
        c = 18;
    }
    if( (dorfMarks & eDorfMark::mark5) == eDorfMark::mark5)
    {
        c = 24;
    }
    if( (dorfMarks & eDorfMark::mark6) == eDorfMark::mark6)
    {
        c = 35;
    }
    if( (dorfMarks & eDorfMark::mark7) == eDorfMark::mark7)
    {
        c = 50;
    }

    this->c = C;
}

void Dorf::setNextSlowestMarksAndSpeedFrom(eDorfMark Mark)
{
    //TODO: fallprüfung falls Mark nicht [mark1, ... , mark7]
    //TODO:  hier auch edorfmark gleich mitsetzen
    double C = 0;

    if( (dorfMarks < Mark) && ( (dorfMarks & eDorfMark::mark7) == eDorfMark::mark7 ) )
    {
       C = 50;
    }
    else if( (dorfMarks < Mark) && ( (dorfMarks & eDorfMark::mark6) == eDorfMark::mark6 ) )
    {
        C = 35;
    }
    else if( (dorfMarks < Mark) && ( (dorfMarks & eDorfMark::mark5) == eDorfMark::mark5 ) )
    {
        C = 24;
    }
    else if( (dorfMarks < Mark) && ( (dorfMarks & eDorfMark::mark4) == eDorfMark::mark4 ) )
    {
        C = 18;
    }
    else if( (dorfMarks < Mark) && ( (dorfMarks & eDorfMark::mark3) == eDorfMark::mark3 ) )
    {
        C = 14;
    }
    else if( (dorfMarks < Mark) && ( (dorfMarks & eDorfMark::mark2) == eDorfMark::mark2 ) )
    {
        C = 9;
    }
    else if( (dorfMarks < Mark) && ( (dorfMarks & eDorfMark::mark1) == eDorfMark::mark1 ) )
    {
        C = 8;
    }

    this->c = C;
}

 bool Dorf::equals(Dorf A, Dorf B)
 {
     if ( A.getX() == B.getX()  &&  A.getY() == B.getY() )
         return true;
     else
         return false;
 }



 eDorfState Dorf::getState() const
 {
     return dorfState;
 }

 eDorfMark Dorf::getMark() const
 {
     return tempDorfMark;
 }

 uint Dorf::getMarks() const
 {
     return dorfMarks;
 }

 void Dorf::setState(eDorfState DorfState)
 {
     dorfState = DorfState;
 }

 void Dorf::setMark(eDorfMark Mark)
 {
     if(Mark == 0)
         QMessageBox::information(0, "Error dorf.cpp", "setMark failed, Mark = 0");

     tempDorfMark = Mark;
     setSpeed(eDorfMarkToSpeed(tempDorfMark));
 }

 void Dorf::setMarks(uint DorfMark)
 {
     dorfMarks = DorfMark;
 }

 double Dorf::eDorfMarkToSpeed(eDorfMark Mark)
 {
     double c = 0;

     if( Mark == eDorfMark::mark1)
     {
         c = 8;
     }
     else if( Mark == eDorfMark::mark2)
     {
         c = 9;
     }
     else if( Mark == eDorfMark::mark3)
     {
         c = 14;
     }
     else if( Mark == eDorfMark::mark4)
     {
         c = 18;
     }
     else if( Mark  == eDorfMark::mark5)
     {
         c = 24;
     }
     else if( Mark == eDorfMark::mark6)
     {
         c = 35;
     }
     else if( Mark == eDorfMark::mark7)
     {
         c = 50;
     }

     return c;
 }









 QList<eDorfMark> helpers::uintMarkToFlags(uint Mark)
 {
     QList<eDorfMark> list;

     if( (Mark & eDorfMark::mark1) == eDorfMark::mark1)
     {
         list.append(mark1);
     }
     if( (Mark & eDorfMark::mark2) == eDorfMark::mark2)
     {
         list.append(mark2);
     }
     if( (Mark & eDorfMark::mark3) == eDorfMark::mark3)
     {
         list.append(mark3);
     }
     if( (Mark & eDorfMark::mark4) == eDorfMark::mark4)
     {
         list.append(mark4);
     }
     if( (Mark & eDorfMark::mark5) == eDorfMark::mark5)
     {
         list.append(mark5);
     }
     if( (Mark & eDorfMark::mark6) == eDorfMark::mark6)
     {
         list.append(mark6);
     }
     if( (Mark & eDorfMark::mark7) == eDorfMark::mark7)
     {
         list.append(mark7);
     }

     return list;
 }


 eDorfMark helpers::uintToeDorfMark(uint Mark)
 {
     eDorfMark mark;
     mark = empty;

     if( (Mark & eDorfMark::mark1) == eDorfMark::mark1)
     {
         mark = mark1;
     }
     else if( (Mark & eDorfMark::mark2) == eDorfMark::mark2)
     {
         mark = mark2;
     }
     else if( (Mark & eDorfMark::mark3) == eDorfMark::mark3)
     {
         mark = mark3;
     }
     else if( (Mark & eDorfMark::mark4) == eDorfMark::mark4)
     {
         mark = mark4;
     }
     else if( (Mark & eDorfMark::mark5) == eDorfMark::mark5)
     {
         mark = mark5;
     }
     else if( (Mark & eDorfMark::mark6) == eDorfMark::mark6)
     {
         mark = mark6;
     }
     else if( (Mark & eDorfMark::mark7) == eDorfMark::mark7)
     {
         mark = mark7;
     }

     if(mark == 0)
         QMessageBox::information(0, "Error", "Error while converting uintToeDorfMark");

     return mark;
 }

 uint helpers::eDorfMarkToUint(eDorfMark Mark)
 {
     (uint)Mark;
 }



















