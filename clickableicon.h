#ifndef CLICKABLEICON_H
#define CLICKABLEICON_H

#include <QLabel>
//#include <QFrame>
#include <QCoreApplication>

class ClickableIcon : public QLabel
{
    Q_OBJECT

public:
     explicit ClickableIcon( QWidget *parent = 0);
    void setCiEnabled(bool CiEnabled);
    bool isCiEnabled() const;

signals:
     void labelClicked();
protected:
     void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
private:
     bool ciEnabled = false;
};

#endif // CLICKABLEICON_H
