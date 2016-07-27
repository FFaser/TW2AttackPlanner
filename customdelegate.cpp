#include "customdelegate.h"

CustomDelegate::CustomDelegate (QObject *parent, QDateTime *TargetDT)
                : QItemDelegate(parent)
{
    targetDT = TargetDT;
}

//CustomDelegate::CustomDelegate (QObject *parent) : QItemDelegate(parent)
//{

//}

void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
    int distanceINseconds = index.data(Qt::DisplayRole).toInt();
    QDateTime sendeDT = targetDT->addSecs( -distanceINseconds);

    int timeintervall = 8 * 60 * 60; //in seconds

//    int progBarMax = targetDT->toTime_t() - targetDT->addSecs( - timeintervall).toTime_t();
    int progBarMax = sendeDT.toTime_t() - sendeDT.addSecs( - timeintervall).toTime_t();
//    int secondsTOtarget = targetDT->toTime_t() - QDateTime::currentDateTime().toTime_t();
    int secondsTOtarget = sendeDT.toTime_t() - QDateTime::currentDateTime().toTime_t();

    //QTime secTOtargetQTime( secondsTOtarget * 1000 );
    //secTOtargetQTime.toString()

    int progress = progBarMax - secondsTOtarget;
    QStyleOptionProgressBar  progressBar;
    //QProgressBar progressBar;
    progressBar.rect = option.rect;
    progressBar.minimum = 0;
    progressBar.maximum = progBarMax;
    progressBar.progress = progress;
    //progressBar.text = "bla";
   // qDebug() << QTime(0,0,0,0).addSecs(secondsTOtarget).toString();
    int tage = secondsTOtarget / 86400;
    secondsTOtarget %= 86400;
    progressBar.text =  QString::number(tage) + " Tage " + QTime(0,0,0,0).addSecs(secondsTOtarget).toString();
    progressBar.textVisible = true;

 //   later try to disable the animation or use a different
 //   progressBar or create a custom one


//    check what this line actually does
    QApplication::style()->drawControl(QStyle::CE_ProgressBar,
                                       &progressBar, painter);

}



//void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
//           const QModelIndex &index) const
//{
//    int progress = index.data().toInt();
//    QStyleOptionProgressBar  progressBar;
//    progressBar.rect = option.rect;
//    progressBar.minimum = 0;
//    progressBar.maximum = 1000;
//    progressBar.progress = progress;
//    progressBar.text = "bla";
//    progressBar.textVisible = true;
//    //later try to disable the animation or use a different
//    //progressBar or create a cstom one

//    //check what this line actually does
//    QApplication::style()->drawControl(QStyle::CE_ProgressBar,
//                                       &progressBar, painter);

//}
