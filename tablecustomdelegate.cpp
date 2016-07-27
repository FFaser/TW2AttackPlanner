#include "tablecustomdelegate.h"

TableCustomDelegate::TableCustomDelegate (QObject *parent, QDateTime *TargetDT)
                : QItemDelegate(parent)
{
    targetDT = TargetDT;
}

//CustomDelegate::CustomDelegate (QObject *parent) : QItemDelegate(parent)
//{

//}

void TableCustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
    int distanceINseconds = index.data(Qt::DisplayRole).toInt();
    QDateTime sendeDT = targetDT->addSecs( -distanceINseconds);

    if (index.column() == 0)
    {


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
//        progressBar.text =  QString::number(tage) + " Tage " + QTime(0,0,0,0).addSecs(secondsTOtarget).toString();
        if (secondsTOtarget >= 0)
             progressBar.text =  QString::number(tage) + " Tage " + QTime(0,0,0,0).addSecs(secondsTOtarget).toString();
          else
            progressBar.text =  "xxx";

        progressBar.textVisible = true;

     //   later try to disable the animation or use a different
     //   progressBar or create a cstom one

    //    QPalette &pal = progressBar.palette;
    //    const QColor color( Qt::red);
    //    pal.setColor(QPalette::Highlight, color );
    //    progressBar.s

    //    check what this line actually does
        if ( progress < progBarMax )
        {
            QApplication::style()->drawControl(QStyle::CE_ProgressBar,
                                               &progressBar, painter);
        }
        else
        {
            QBrush brush(Qt::red);
            painter->fillRect(option.rect, brush);
        }

    }
     if (index.column() == 1)
    {
        QTextOption opt;
        opt.setAlignment(Qt::AlignCenter);
        QString sendezeit = sendeDT.toString("dd MMMM hh:mm:ss");
        painter->drawText(option.rect, sendezeit, opt);
        // QString daysLeft = "";
        // int secondsTOtarget = sendeDT.toTime_t() - QDateTime::currentDateTime().toTime_t();
        // int tage = secondsTOtarget / 86400;
        // secondsTOtarget %= 86400;
        // if (secondsTOtarget >= 0)
        //      daysLeft =  QString::number(tage) + " Tage " + QTime(0,0,0,0).addSecs(secondsTOtarget).toString();
        //  else
        //  daysLeft = "xxx";
        // painter->drawText(option.rect, daysLeft, opt);
    }

     if(index.column() == 2)
    {
//        QTextOption opt;
//        opt.setAlignment(Qt::AlignVCenter | Qt::AlignCenter);
//        QString mark = index.data(Qt::DisplayRole).toString();
//        painter->drawText(option.rect, mark, opt);

         uint marks = (uint)index.data(Qt::DisplayRole).toInt();
         QList<eDorfMark> list = helpers::uintMarkToFlags(marks);

         eDorfMark Mark = helpers::uintToeDorfMark((uint)index.data(Qt::EditRole).toInt());
         uint tempDorfMark = (uint)index.data(Qt::UserRole).toInt();
         eDorfMark tableModelTempDorfMark = empty;
         if(tempDorfMark != 0)
            tableModelTempDorfMark = helpers::uintToeDorfMark( tempDorfMark);
         //assuming here all my pixmaps have same and known size (30x30 pixels)
         QString pixmapPath = QCoreApplication::applicationDirPath() + "/bilder/";
         QPixmap concat( 30 * list.length(), 30 );
         QPoint point(0,0);
         QPainter concatPainter(&concat);

         int countFlags = 0;
         foreach(eDorfMark mark, list)
         {
             if(mark == mark1)
             {
                 QPixmap temp(pixmapPath + "LK.png");
                 concatPainter.drawPixmap(point, temp);
                 if(mark == Mark && Mark != tableModelTempDorfMark)
                     concatPainter.fillRect(point.x(), point.y(), 30, 30, Qt::CrossPattern );
                 point.setX(point.x() + 30);
             }
             else if(mark == mark2)
             {
                 QPixmap temp(pixmapPath + "SK.png");
                 concatPainter.drawPixmap(point, temp);
                 if(mark == Mark && Mark != tableModelTempDorfMark)
                     concatPainter.fillRect(point.x(), point.y(), 30, 30, Qt::CrossPattern );
                 point.setX(point.x() + 30);
             }
             else if(mark == mark3)
             {
                 QPixmap temp(pixmapPath + "Speer.png");
                 concatPainter.drawPixmap(point, temp);
                 if(mark == Mark && Mark != tableModelTempDorfMark)
                     concatPainter.fillRect(point.x(), point.y(), 30, 30, Qt::CrossPattern );
                 point.setX(point.x() + 30);
             }
             else if(mark == mark4)
             {
                 QPixmap temp(pixmapPath + "Schwert.png");
                 concatPainter.drawPixmap(point, temp);
                 if(mark == Mark && Mark != tableModelTempDorfMark)
                     concatPainter.fillRect(point.x(), point.y(), 30, 30, Qt::CrossPattern );
                 point.setX(point.x() + 30);
             }
             else if(mark == mark5)
             {
                 QPixmap temp(pixmapPath + "Rammen.png");
                 concatPainter.drawPixmap(point, temp);
                 if(mark == Mark && Mark != tableModelTempDorfMark)
                     concatPainter.fillRect(point.x(), point.y(), 30, 30, Qt::CrossPattern );
                 point.setX(point.x() + 30);
             }
             else if(mark == mark6)
             {
                 QPixmap temp(pixmapPath + "AG.png");
                 concatPainter.drawPixmap(point, temp);
                 if(mark == Mark && Mark != tableModelTempDorfMark)
                     concatPainter.fillRect(point.x(), point.y(), 30, 30, Qt::CrossPattern );
                 point.setX(point.x() + 30);
             }
             else if(mark == mark7)
             {
                 QPixmap temp(pixmapPath + "Trebs.png");
                 concatPainter.drawPixmap(point, temp);
                 if(mark == Mark && Mark != tableModelTempDorfMark)
                     concatPainter.fillRect(point.x(), point.y(), 30, 30, Qt::CrossPattern );
                 point.setX(point.x() + 30);
             }

         }

         QPixmap concatWhole = concat.copy(0, 0, option.rect.width(), option.rect.height());


         painter->drawPixmap(option.rect.x(), option.rect.y(), concatWhole);

    }

     if(index.column() == 3)
    {
        QTextOption opt;
        opt.setAlignment(Qt::AlignCenter);

        QString state = index.data(Qt::DisplayRole).toString();
        painter->drawText(option.rect, state, opt);
    }
}

QWidget *TableCustomDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

     if(index.column() == 2)
    {
        TableviewEditor *editor = new TableviewEditor(option, (uint)index.data(Qt::DisplayRole).toInt(), parent);
        int mark =  index.data(Qt::EditRole).toInt();
        if (mark != 0)
            editor->setCurrentMark( helpers::uintToeDorfMark( mark));
        return editor;

        connect(editor, &TableviewEditor::editingFinished,
                 this, &TableCustomDelegate::commitAndCloseEditor  );
    }

     if(index.column() == 3)
    {
        QComboBox *editor = new QComboBox(parent);

        return editor;
    }


   // return QItemDelegate::createEditor(parent, option, index);

}

void TableCustomDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.column() == 2)
    {
        //all set in the createEditor()

    }


    if (index.column() == 3)
    {
       QComboBox *pQComboBox = static_cast<QComboBox *>(editor);
         int state =  index.model()->data(index, Qt::EditRole).toInt();
        if(pQComboBox->count() == 0)
        {
         for(int state = eDorfState::undefined; state < eDorfState_MAX + 1; state++ )
         {
                 QString stateStr = "";
                 if (state == eDorfState::undefined)
                     stateStr = "undefined";
                 else if (state == eDorfState::active)
                     stateStr = "active";
                 else if (state == eDorfState::ontheway)
                     stateStr = "ontheway";


                pQComboBox->addItem(stateStr, state);
             }
           pQComboBox->setCurrentIndex(state);
        }
    }
}

void TableCustomDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(index.column() == 2)
    {
        TableviewEditor *pEditor = qobject_cast<TableviewEditor *>(editor);
        model->setData(index, pEditor->getCurrentMark(), Qt::EditRole );

    }

    if (index.column() == 3)
    {
        QComboBox *pQComboBox = static_cast<QComboBox *>(editor);
        int value = pQComboBox->currentData().toInt();
        model->setData(index, value, Qt::EditRole);
    }
}

void TableCustomDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

void TableCustomDelegate::commitAndCloseEditor()
{
   TableviewEditor *editor = qobject_cast<TableviewEditor *>(sender());
   emit commitData(editor);
   emit closeEditor(editor);
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
