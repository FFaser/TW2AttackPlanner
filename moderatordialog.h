#ifndef MODERATORDIALOG_H
#define MODERATORDIALOG_H

#include <QDialog>
#include <moderatormodel.h>
#include <moderatordelegate.h>
#include <dorf.h>
#include <QDialogButtonBox>


namespace Ui {
class ModeratorDialog;
}

class ModeratorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModeratorDialog(QList<Dorf> DorfList ,QWidget *parent = 0);
    ~ModeratorDialog();

signals:
    void moderatorUpdated(QList<Dorf> Database);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ModeratorDialog *ui;

    ModeratorModel *pModeratorModel;
    ModeratorDelegate *pModeratorDelegate;

};

#endif // MODERATORDIALOG_H
