#include "dorfmapdialog.h"
#include "ui_dorfmapdialog.h"

DorfMapDialog::DorfMapDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DorfMapDialog)
{
    ui->setupUi(this);
}

DorfMapDialog::~DorfMapDialog()
{
    delete ui;
}
