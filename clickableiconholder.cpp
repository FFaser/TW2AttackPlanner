#include "clickableiconholder.h"

ClickableIconHolder::ClickableIconHolder(/*uint Mark,*/ QWidget *parent)
    : QDialog(parent, Qt::FramelessWindowHint)
   // : QWidget(parent)
{




   // int MarkBits = sizeof(Mark) * 8;

//    QRect localRect( this->geometry().topLeft(), this->geometry().bottomRight());
//    localRect.setHeight(localRect.height() + 100);
//    localRect.setWidth(localRect.width() + 200);
//    //this->setBaseSize(200, 200);
//    this->setGeometry(localRect);
    QString pixmapPath = QCoreApplication::applicationDirPath()
                            + "/" + "bilder/";

    hbLayout = new QHBoxLayout(this);

    ci1 = new ClickableIcon(this);
    ci2 = new ClickableIcon(this);
    ci3 = new ClickableIcon(this);
    ci4 = new ClickableIcon(this);
    ci5 = new ClickableIcon(this);
    ci6 = new ClickableIcon(this);
    ci7 = new ClickableIcon(this);

    ci1->setPixmap(pixmapPath + "LK.png" );
    ci2->setPixmap(pixmapPath + "SK.png" );
    ci3->setPixmap(pixmapPath + "Speer.png" );
    ci4->setPixmap(pixmapPath + "Schwert.png" );
    ci5->setPixmap(pixmapPath + "Rammen.png" );
    ci6->setPixmap(pixmapPath + "AG.png" );
    ci7->setPixmap(pixmapPath + "Trebs.png" );


    hbLayout->addWidget(ci1);
    hbLayout->addWidget(ci2);
    hbLayout->addWidget(ci3);
    hbLayout->addWidget(ci4);
    hbLayout->addWidget(ci5);
    hbLayout->addWidget(ci6);
    hbLayout->addWidget(ci7);

    hbLayout->setMargin(7);


}



void ClickableIconHolder::setMark(uint Mark)
{
    if( (Mark & eDorfMark::mark1) == eDorfMark::mark1)
    {
        ci1->setCiEnabled(true);
    }
    if( (Mark & eDorfMark::mark2) == eDorfMark::mark2)
    {
        ci2->setCiEnabled(true);
    }
    if( (Mark & eDorfMark::mark3) == eDorfMark::mark3)
    {
        ci3->setCiEnabled(true);
    }
    if( (Mark & eDorfMark::mark4) == eDorfMark::mark4)
    {
        ci4->setCiEnabled(true);
    }
    if( (Mark & eDorfMark::mark5) == eDorfMark::mark5)
    {
        ci5->setCiEnabled(true);
    }
    if( (Mark & eDorfMark::mark6) == eDorfMark::mark6)
    {
        ci6->setCiEnabled(true);
    }
    if( (Mark & eDorfMark::mark7) == eDorfMark::mark7)
    {
        ci7->setCiEnabled(true);
    }

}

uint ClickableIconHolder::getMark() const
{
    uint Mark = 0;
    if(ci1->isCiEnabled() == true)
        Mark = Mark | eDorfMark::mark1;
    if(ci2->isCiEnabled() == true)
        Mark = Mark | eDorfMark::mark2;
    if(ci3->isCiEnabled() == true)
        Mark = Mark | eDorfMark::mark3;
    if(ci4->isCiEnabled() == true)
        Mark = Mark | eDorfMark::mark4;
    if(ci5->isCiEnabled() == true)
        Mark = Mark | eDorfMark::mark5;
    if(ci6->isCiEnabled() == true)
        Mark = Mark | eDorfMark::mark6;
    if(ci7->isCiEnabled() == true)
        Mark = Mark | eDorfMark::mark7;

    return Mark;

}

void ClickableIconHolder::paintEvent(QPaintEvent *event)
{
int bla = 1;


}



QSize ClickableIconHolder::sizeHint() const
{
    return QSize(250, 70);
}
