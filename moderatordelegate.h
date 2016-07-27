#ifndef MODERATORDELEGATE_H
#define MODERATORDELEGATE_H

#include <dorf.h>
#include <QItemDelegate>
#include <QApplication>
#include <QDebug>
#include <QColor>
#include <QPainter>
#include <QTextOption>
#include <QBrush>
#include <QWidget>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QSpinBox>
#include <QComboBox>
#include <QPixmap>
#include <myenumhelper.h>
#include <clickableiconholder.h>

class ModeratorDelegate :  public QItemDelegate
{
    Q_OBJECT


public:
    ModeratorDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

   QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const;

   void setEditorData(QWidget *editor, const QModelIndex &index) const;

   void setModelData(QWidget *editor, QAbstractItemModel *model,
                     const QModelIndex &index) const;

   void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                             const QModelIndex &index) const;


private:


};

#endif // MODERATORDELEGATE_H
