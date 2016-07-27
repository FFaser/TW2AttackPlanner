#include "clickableicon.h"

ClickableIcon::ClickableIcon(QWidget *parent) : QLabel(parent)
{
    if(ciEnabled == true)
    {
        this->setFrameStyle(QFrame::Panel | QFrame::Raised);
        this->setStyleSheet("background-color : red;");
        this->setLineWidth(3);
    }
    else
    {
        this->setFrameStyle(QFrame::Panel | QFrame::Raised);
        this->setStyleSheet("background-color : lightgrey;");
        this->setLineWidth(3);
    }
}

void ClickableIcon::setCiEnabled(bool CiEnabled)
{
    ciEnabled = CiEnabled;
    if(ciEnabled == true)
    {
        this->setFrameStyle(QFrame::Panel | QFrame::Raised);
        this->setStyleSheet("background-color : red;");
        this->setLineWidth(3);
    }
    else
    {
        this->setFrameStyle(QFrame::Panel | QFrame::Raised);
        this->setStyleSheet("background-color : lightgrey;");
        this->setLineWidth(3);
    }
}

bool ClickableIcon::isCiEnabled() const
{
    return ciEnabled;
}

void ClickableIcon::mouseReleaseEvent(QMouseEvent *e)
{
    if(ciEnabled == true)
    {
        this->setFrameStyle(QFrame::Panel | QFrame::Raised);
        this->setStyleSheet("background-color : lightgrey;");
        this->setLineWidth(3);
        ciEnabled = false;
    }
    else
    {
        this->setFrameStyle(QFrame::Panel | QFrame::Raised);
        this->setStyleSheet("background-color : red;");
        this->setLineWidth(3);
        ciEnabled = true;
    }

    emit labelClicked();
}

