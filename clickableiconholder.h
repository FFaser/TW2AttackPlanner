#ifndef CLICKABLEICONHOLDER_H
#define CLICKABLEICONHOLDER_H

#include <QWidget>
#include <QHBoxLayout>
#include <clickableicon.h>
#include <dorf.h>
#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QDialog>

class ClickableIconHolder : public QDialog
{
    Q_OBJECT
public:
    ClickableIconHolder(/*uint Mark,*/ QWidget *parent = 0);
    QSize sizeHint() const Q_DECL_OVERRIDE;
    void setMark(uint Mark);
    uint getMark() const;
signals:
    void editingFinished();
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QHBoxLayout *hbLayout;
    ClickableIcon *ci1 = 0;
    ClickableIcon *ci2 = 0;
    ClickableIcon *ci3 = 0;
    ClickableIcon *ci4 = 0;
    ClickableIcon *ci5 = 0;
    ClickableIcon *ci6 = 0;
    ClickableIcon *ci7 = 0;
};

#endif // CLICKABLEICONHOLDER_H
