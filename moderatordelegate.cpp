#include "moderatordelegate.h"

ModeratorDelegate::ModeratorDelegate(QObject *parent) : QItemDelegate(parent)
{

}

void ModeratorDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const
{
    if ( index.column() == 0 )
    {
        QTextOption opt;
        opt.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
        QString dorf = index.data(Qt::DisplayRole).toString();
        painter->drawText(option.rect, dorf, opt);




    }

    if ( index.column() == 1 )
    { //----Später ausschmücken-----
        QTextOption opt;
        opt.setAlignment(Qt::AlignVCenter | Qt::AlignCenter);
       // QString mark = index.data(Qt::DisplayRole).toString();
       // painter->drawText(option.rect, mark, opt);
        uint mark = (uint)index.data(Qt::DisplayRole).toInt();

        QList<eDorfMark> list = helpers::uintMarkToFlags(mark);
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
                point.setX(point.x() + 30);
            }
            else if(mark == mark2)
            {
                QPixmap temp(pixmapPath + "SK.png");
                concatPainter.drawPixmap(point, temp);
                point.setX(point.x() + 30);
            }
            else if(mark == mark3)
            {
                QPixmap temp(pixmapPath + "Speer.png");
                concatPainter.drawPixmap(point, temp);
                point.setX(point.x() + 30);
            }
            else if(mark == mark4)
            {
                QPixmap temp(pixmapPath + "Schwert.png");
                concatPainter.drawPixmap(point, temp);
                point.setX(point.x() + 30);
            }
            else if(mark == mark5)
            {
                QPixmap temp(pixmapPath + "Rammen.png");
                concatPainter.drawPixmap(point, temp);
                point.setX(point.x() + 30);
            }
            else if(mark == mark6)
            {
                QPixmap temp(pixmapPath + "AG.png");
                concatPainter.drawPixmap(point, temp);
                point.setX(point.x() + 30);
            }
            else if(mark == mark7)
            {
                QPixmap temp(pixmapPath + "Trebs.png");
                concatPainter.drawPixmap(point, temp);
                point.setX(point.x() + 30);
            }

        }


//        QString pixmapPath = QCoreApplication::applicationDirPath()
//                                + "/" + "bilder/"
//                                + "AG.png";


//        QPixmap pixMap(pixmapPath);




        QPixmap concatWhole = concat.copy(0, 0, option.rect.width(), option.rect.height());


        painter->drawPixmap(option.rect.x(), option.rect.y(), concatWhole);




        //        int i = point.x() + pixMap.size().width();
        //        point.setX(i);
        //        painter->drawPixmap(point, pixMap );

    }

    if ( index.column() == 2 )
    {
        QTextOption opt;
        opt.setAlignment(Qt::AlignCenter);

        QString state = index.data(Qt::DisplayRole).toString();
        painter->drawText(option.rect, state, opt);

    }
}

QWidget *ModeratorDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//    if(index.column() == 1)
//    {
//        QComboBox *editor = new QComboBox(parent);


//        return editor;
//    }

    if(index.column() == 1)
    {
         uint mark =  index.model()->data(index, Qt::EditRole).toInt();

        ClickableIconHolder *editor = new ClickableIconHolder(/*mark,*/ parent);


        return editor;
    }

    if(index.column() == 2)
    {
        QComboBox *editor = new QComboBox(parent);


        return editor;
    }

}

void ModeratorDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{


//    if (index.column() == 1)
//    {
//       QComboBox *pQComboBox = static_cast<QComboBox *>(editor);
//         int mark =  index.model()->data(index, Qt::EditRole).toInt();
//        MyEnumHelper eHelper;
//        QStringList list(eHelper.eDorfMark_ItemNameList());
//         for(int i = 0; i < list.length(); i++)
//         {

//             mark = eHelper.eDorfMark_QStringToEnum(list.at(i));
//            pQComboBox->addItem(list.at(i), mark);
//         }
//       pQComboBox->setCurrentIndex(0);
//    }

    if (index.column() == 1)
    {
       ClickableIconHolder *clickHolder = static_cast<ClickableIconHolder *>(editor);
         uint mark =  index.model()->data(index, Qt::EditRole).toInt();
         clickHolder->setMark(mark);


    }



    if (index.column() == 2)
    {
       QComboBox *pQComboBox = static_cast<QComboBox *>(editor);
         int state =  index.model()->data(index, Qt::EditRole).toInt();

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

void ModeratorDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
//    QComboBox *pQComboBox = static_cast<QComboBox *>(editor);
//    int value = pQComboBox->currentData().toInt();
//    model->setData(index, value, Qt::EditRole);

   if(index.column() == 1)
   {
       ClickableIconHolder *clickHolder = static_cast<ClickableIconHolder *>(editor);
        uint value = clickHolder->getMark();
        model->setData(index, value, Qt::EditRole);
   }
   if(index.column() == 2)
   {
            QComboBox *pQComboBox = static_cast<QComboBox *>(editor);
            int value = pQComboBox->currentData().toInt();
            model->setData(index, value, Qt::EditRole);
   }

}

void ModeratorDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);

        if(index.column() == 1)
        {
            QPoint point(editor->parentWidget()->mapToGlobal(editor->pos()));
            editor->setGeometry(point.x(), point.y(), 250, 40);

        }

//    if(index.column() == 1)
//    {
//        QPoint point(option.rect.topLeft());
//        editor->setGeometry(point.x(), point.y(), 300, 50);
//        editor->setAutoFillBackground(true);

//    }
//   QPoint one = editor->mapFromGlobal(editor->pos());
//   QPoint two = editor->mapFromParent(editor->pos());
//   QPoint three = editor->mapToGlobal( option.rect.topLeft());
//   QPoint four = editor->mapToParent(option.rect.topLeft());
//   QPoint five = editor->parentWidget()->mapToGlobal(editor->pos());

//   int i = 0;

}

