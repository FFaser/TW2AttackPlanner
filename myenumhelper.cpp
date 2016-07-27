#include "myenumhelper.h"

MyEnumHelper::MyEnumHelper()
{
    hash.insert("empty", empty);
    hash.insert("mark1", mark1);
    hash.insert("mark2", mark2);
    hash.insert("mark3", mark3);
    hash.insert("mark4", mark4);
    hash.insert("mark5", mark6);
    hash.insert("mark6", mark6);
    hash.insert("mark7", mark7);
    hash.insert("mark8", mark8);
    hash.insert("mark9", mark9);
    hash.insert("mark10", mark10);
}

 QString MyEnumHelper::eDorfMark_ItemName(eDorfMark Mark)
{
     return hash.key(Mark);



//   QString str;
//   switch(Mark)
//   {
//       case 1:     str = "mark1";   break;
//       case 2:     str = "mark2";   break;
//       case 4:     str = "mark3";   break;
//       case 8:     str = "mark4";   break;
//       case 16:    str = "mark5";   break;
//       case 32:    str = "mark6";   break;
//       case 64:    str = "mark7";   break;
//       case 128:   str = "mark8";   break;
//       case 256:   str = "mark9";   break;
//       case 512:   str = "mark10";  break;

//   };
//   return str;
}

eDorfMark MyEnumHelper::eDorfMark_QStringToEnum(QString Str)
{
    return hash.value(Str);



//    eDorfMark mark;
//    switch(Str)
//    {
//        case "mark1":   mark = mark1;   break;
//        case "mark2":   mark = mark2;   break;
//        case "mark3":   mark = mark3;   break;
//        case "mark4":   mark = mark4;   break;
//        case "mark5":   mark = mark5;   break;
//        case "mark6":   mark = mark6;   break;
//        case "mark7":   mark = mark7;   break;
//        case "mark8":   mark = mark8;   break;
//        case "mark9":   mark = mark9;   break;
//        case "mark10":  mark = mark10;  break;

//    };
//    return mark;
}


 QStringList MyEnumHelper::eDorfMark_ItemNameList()
{
    QStringList strList;
    strList << "empty"
            << "mark1" << "mark2"
            << "mark3" << "mark4"
            << "mark5" << "mark6"
            << "mark7" << "mark8"
            << "mark9" << "mark10";
    return strList;
}
