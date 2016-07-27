#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H



#include <QItemDelegate>

#include <QStyleOptionProgressBar>
#include <QProgressBar>
#include <QApplication>
#include <QDateTime>
#include <QTime>
#include <QDebug>
#include <QColor>

class CustomDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    CustomDelegate(QObject *parent = 0, QDateTime *TargetDT = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

private:
    QDateTime *targetDT;

};

#endif // CUSTOMDELEGATE_H
