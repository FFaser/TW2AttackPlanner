#ifndef TABLEVIEWEDITOR_H
#define TABLEVIEWEDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QStyleOptionViewItem>
#include <dorf.h>
#include <QCoreApplication>
#include <QPixmap>
#include <QPainter>
#include <QSize>
#include <QMessageBox>
#include <QString>

class TableviewEditor :  public QWidget
{
    Q_OBJECT

public:
//    TableviewEditor(QWidget *parent = 0);
    TableviewEditor(const QStyleOptionViewItem &option, const uint Marks,  QWidget *parent = 0);

    void paint(QPainter *painter, const QRect &rect , const uint Marks) const;

    void setCurrentMark(eDorfMark Mark);
    eDorfMark getCurrentMark();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
private:

    QRect rect;
    uint Marks;
    eDorfMark currentMark =  empty;
    QPushButton *btnOne = nullptr;
    QPushButton *btnTwo = nullptr;
    QPushButton *btnThree = nullptr;
    QPushButton *btnFour = nullptr;
    QPushButton *btnFive = nullptr;
    QPushButton *btnSix = nullptr;
    QPushButton *btnSeven = nullptr;

    int starPosition(int X);
    //void initButtons(const QRect &rect , const uint Marks);
    void setButton(QPushButton &btn , QRect &rect, QPoint &point) const;

signals:
    void editingFinished();

public slots:
    void buttonClicked();



};

#endif // TABLEVIEWEDITOR_H
