#ifndef DORFMAPDIALOG_H
#define DORFMAPDIALOG_H

#include <QDialog>

namespace Ui {
class DorfMapDialog;
}

class DorfMapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DorfMapDialog(QWidget *parent = 0);
    ~DorfMapDialog();

private:
    Ui::DorfMapDialog *ui;
};

#endif // DORFMAPDIALOG_H
