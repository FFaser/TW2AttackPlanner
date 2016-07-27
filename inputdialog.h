#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <dorfparser.h>


namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();



private slots:


    void on_btnAddDorf_clicked();

signals:
    void sendInputDorfData(QString Data);
    void sendAddingDorfData(QString Data);
private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
