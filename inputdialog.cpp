#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);


}

InputDialog::~InputDialog()
{
    delete ui;
}



void InputDialog::on_btnAddDorf_clicked()
{
    QString text = ui->plainTextEdit->toPlainText();


    emit sendAddingDorfData(text);
}
