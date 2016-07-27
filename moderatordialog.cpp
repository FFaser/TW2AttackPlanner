#include "moderatordialog.h"
#include "ui_moderatordialog.h"

ModeratorDialog::ModeratorDialog(QList<Dorf> DorfList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModeratorDialog)
{
    ui->setupUi(this);

    pModeratorModel = new ModeratorModel(DorfList, this);

    pModeratorDelegate = new ModeratorDelegate(this);


    ui->tableModeratorView->setModel(pModeratorModel);
    ui->tableModeratorView->setItemDelegate(pModeratorDelegate);
    //ui->tableModeratorView->setEditTriggers(QAbstractItemView::);


}

ModeratorDialog::~ModeratorDialog()
{
    delete ui;
}


void ModeratorDialog::on_buttonBox_accepted()
{
    emit moderatorUpdated(pModeratorModel->moderatorModelUpdated());
    this->close();
}

void ModeratorDialog::on_buttonBox_rejected()
{
    this->close();
    //TODO: here dialogbuttonbox with a confirmation request.
    //and same on close on the cross
}
