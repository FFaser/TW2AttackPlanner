#include "tablevieweditor.h"

//TableviewEditor::TableviewEditor(QWidget *parent)
//    : QWidget(parent)
//{
//    setMouseTracking(true);
//    setAutoFillBackground(true);
//    setMouseTracking(true);
//    setAutoFillBackground(true);
//    btnOne = new QPushButton(this);
//    //btnOne->isEnabled(false);
//    btnTwo = new QPushButton(this);
//    //btnTwo->isEnabled(false);
//    btnThree = new QPushButton(this);
//    //btnThree->isEnabled(false);
//    btnFour = new QPushButton(this);
//    //btnFour->isEnabled(false);
//    btnFive = new QPushButton(this);
//    //btnFive->isEnabled(false);
//    btnSix = new QPushButton(this);
//    //btnSix->isEnabled(false);
//    btnSeven = new QPushButton(this);
//   // btnSeven->isEnabled(false);
//}

TableviewEditor::TableviewEditor(const QStyleOptionViewItem &option,
                                 const uint Marks, QWidget *parent)
    : QWidget(parent)
{
    this->rect = option.rect;
    this->Marks = Marks;
    setMouseTracking(true);
    setAutoFillBackground(true);
    btnOne = new QPushButton(this);
    btnOne->setObjectName("btnOne");

    btnTwo = new QPushButton(this);
    btnTwo->setObjectName("btnTwo");

    btnThree = new QPushButton(this);
    btnThree->setObjectName("btnThree");

    btnFour = new QPushButton(this);
    btnFour->setObjectName("btnFour");

    btnFive = new QPushButton(this);
    btnFive->setObjectName("btnFive");

    btnSix = new QPushButton(this);
    btnSix->setObjectName("btnSix");

    btnSeven = new QPushButton(this);
    btnSeven->setObjectName("btnSeven");

    connect(btnOne, SIGNAL(clicked(bool)),
             this, SLOT(buttonClicked()) );
    connect(btnTwo, SIGNAL(clicked(bool)),
             this, SLOT(buttonClicked()) );
    connect(btnThree, SIGNAL(clicked(bool)),
             this, SLOT(buttonClicked()) );
    connect(btnFour, SIGNAL(clicked(bool)),
             this, SLOT(buttonClicked()) );
    connect(btnFive, SIGNAL(clicked(bool)),
             this, SLOT(buttonClicked()) );
    connect(btnSix, SIGNAL(clicked(bool)),
             this, SLOT(buttonClicked()) );
    connect(btnSeven, SIGNAL(clicked(bool)),
             this, SLOT(buttonClicked()) );

    btnOne->resize(0,0);
    btnTwo->resize(0,0);
    btnThree->resize(0,0);
    btnFour->resize(0,0);
    btnFive->resize(0,0);
    btnSix->resize(0,0);
    btnSeven->resize(0,0);

}

void TableviewEditor::paint(QPainter *painter, const QRect &rect,
                                        const uint Marks) const
{
    QList<eDorfMark> list = helpers::uintMarkToFlags(Marks);
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

    QPixmap concatWhole = concat.copy(0, 0, rect.width(), rect.height());

    painter->drawPixmap(0, 0, concatWhole);
   // painter->drawPixmap(rect.x(), rect.y(), concatWhole);

//    btnOne->setFlat(true);
//    btnTwo->setFlat(true);
//    btnThree->setFlat(true);
//    btnFour->setFlat(true);
//    btnFive->setFlat(true);
//    btnSix->setFlat(true);
//    btnSeven->setFlat(true);

btnOne->setStyleSheet("background-color: rgba(255, 255, 255, 170);");
btnTwo->setStyleSheet("background-color: rgba(255, 255, 255, 170);");
btnThree->setStyleSheet("background-color: rgba(255, 255, 255, 170);");
btnFour->setStyleSheet("background-color: rgba(255, 255, 255, 170);");
btnFive->setStyleSheet("background-color: rgba(255, 255, 255, 170);");
btnSix->setStyleSheet("background-color: rgba(255, 255, 255, 170);");
btnSeven->setStyleSheet("background-color: rgba(255, 255, 255, 170);");


    point.setX(0);
    point.setY(0);
    QRect tempRect = rect;
    foreach(eDorfMark mark, list)
    {
        if(mark == mark1)
        {
            if((btnOne != nullptr) && (tempRect.width() > 3)  && (tempRect.height() > 3) )
            {

                setButton(*btnOne, tempRect, point);
            }
        }
        else if(mark == mark2)
        {
            if((btnOne != nullptr) && (tempRect.width() > 3)  && (tempRect.height() > 3) )
            {

                setButton(*btnTwo, tempRect, point);
            }
        }
        else if(mark == mark3)
        {
           if((btnOne != nullptr) && (tempRect.width() > 3)  && (tempRect.height() > 3) )
            {

                setButton(*btnThree, tempRect, point);
            }
        }
        else if(mark == mark4)
        {
            if((btnOne != nullptr) && (tempRect.width() > 3)  && (tempRect.height() > 3) )
            {

                setButton(*btnFour, tempRect, point);
            }
        }
        else if(mark == mark5)
        {
            if((btnOne != nullptr) && (tempRect.width() > 3)  && (tempRect.height() > 3) )
            {

                setButton(*btnFive, tempRect, point);
            }
        }
        else if(mark == mark6)
        {
            if((btnOne != nullptr) && (tempRect.width() > 3)  && (tempRect.height() > 3) )
            {

                setButton(*btnSix, tempRect, point);
            }
        }
        else if(mark == mark7)
        {
            if((btnOne != nullptr) && (tempRect.width() > 3)  && (tempRect.height() > 3) )
            {

                setButton(*btnSeven, tempRect, point);
            }
        }

    }

}

void TableviewEditor::setCurrentMark(eDorfMark Mark)
{
    currentMark = Mark;

}

eDorfMark TableviewEditor::getCurrentMark()
{
    return currentMark;
}

void TableviewEditor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    paint(&painter, rect, Marks);
}

void TableviewEditor::mouseMoveEvent(QMouseEvent *event)
{

}

void TableviewEditor::mouseReleaseEvent(QMouseEvent *event)
{

}

//void TableviewEditor::initButtons(const QRect &rect, const uint Marks)
//{
//    QPoint point();
//    point.setX(0);
//    point.setY(0);

//    foreach(eDorfMark mark, list)
//    {
//        if(mark == mark1)
//        {
//            if((btnOne == nullptr) && (rect.x() > 3)  && (rect.y() > 3) )
//            {

//                setButton(btnOne, rect, point);
//            }
//        }
//        else if(mark == mark2)
//        {
//            QPixmap temp(pixmapPath + "SK.png");
//            concatPainter.drawPixmap(point, temp);
//            point.setX(point.x() + 30);
//        }
//        else if(mark == mark3)
//        {
//            QPixmap temp(pixmapPath + "Speer.png");
//            concatPainter.drawPixmap(point, temp);
//            point.setX(point.x() + 30);
//        }
//        else if(mark == mark4)
//        {
//            QPixmap temp(pixmapPath + "Schwert.png");
//            concatPainter.drawPixmap(point, temp);
//            point.setX(point.x() + 30);
//        }
//        else if(mark == mark5)
//        {
//            QPixmap temp(pixmapPath + "Rammen.png");
//            concatPainter.drawPixmap(point, temp);
//            point.setX(point.x() + 30);
//        }
//        else if(mark == mark6)
//        {
//            QPixmap temp(pixmapPath + "AG.png");
//            concatPainter.drawPixmap(point, temp);
//            point.setX(point.x() + 30);
//        }
//        else if(mark == mark7)
//        {
//            QPixmap temp(pixmapPath + "Trebs.png");
//            concatPainter.drawPixmap(point, temp);
//            point.setX(point.x() + 30);
//        }

//    }
//}

void TableviewEditor::setButton(QPushButton &btn ,  QRect &rect, QPoint &point) const
{
    int remainXSpace = rect.width() /*- point.x()*/;
    int YSpace = rect.height();
    QSize size;
    QPoint tempPoint = point;
    if((btnOne != nullptr) && (remainXSpace > 3)  && (YSpace > 3) )
    {

        if((remainXSpace - 30) > 0)
        {

            size.setWidth(30);
            rect.setWidth(rect.width() - 30);


        }
        else
        {
            size.setWidth(remainXSpace);
            rect.setWidth(0);

        }

        if((YSpace - 30) > 0)
        {
            size.setHeight(30);
        }
        else
        {
            size.setHeight(YSpace);
        }

        btn.resize(size);
        btn.move(tempPoint);
        point.setX(point.x() + 30);

    }

}

void TableviewEditor::buttonClicked()
{
    QObject *senderObj = sender();
    QString senderObjName = senderObj->objectName();
    QString status = QString("Button %1 has been clicked").arg(senderObjName);
//    QMessageBox::information(0, "EditorButton", status);

    if(senderObjName == "btnOne")
        currentMark = eDorfMark::mark1;
    else if(senderObjName == "btnTwo")
        currentMark = eDorfMark::mark2;
    else if(senderObjName == "btnThree")
        currentMark = eDorfMark::mark3;
    else if(senderObjName == "btnFour")
        currentMark = eDorfMark::mark4;
    else if(senderObjName == "btnFive")
        currentMark = eDorfMark::mark5;
    else if(senderObjName == "btnSix")
        currentMark = eDorfMark::mark6;
    else if(senderObjName == "btnSeven")
        currentMark = eDorfMark::mark7;
    //TODO: test all cases!!!

    emit editingFinished();
}

