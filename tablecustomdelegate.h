#ifndef TABLECUSTOMDELEGATE_H
#define TABLECUSTOMDELEGATE_H

#include <QItemDelegate>

#include <QStyleOptionProgressBar>
#include <QProgressBar>
#include <QApplication>
#include <QDateTime>
#include <QTime>
#include <QDebug>
#include <QColor>
#include <QPainter>
#include <QTextOption>
#include <QBrush>
#include <QComboBox>
#include <dorf.h>
#include <tablevieweditor.h>
#include <QStyledItemDelegate>
#include <tabledatamodel.h>


class TableCustomDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    TableCustomDelegate(QObject *parent = 0, QDateTime *TargetDT = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;

private slots:
    void commitAndCloseEditor();

private:
    QDateTime *targetDT;

};

#endif // TABLECUSTOMDELEGATE_H
