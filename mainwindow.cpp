#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "starting main constructor";
    test = "test";


    ui->cbTruppenart->addItem("LC/LK",         (uint)eDorfMark::mark1);
    ui->cbTruppenart->addItem("HK/SK",         (uint)eDorfMark::mark2);
    ui->cbTruppenart->addItem("Spear/Speer",      (uint)eDorfMark::mark3);
    ui->cbTruppenart->addItem("Sword/Schwert",    (uint)eDorfMark::mark4);
    ui->cbTruppenart->addItem("Ram/Ramme",      (uint)eDorfMark::mark5);
    ui->cbTruppenart->addItem("Nobleman/AG",         (uint)eDorfMark::mark6);
    ui->cbTruppenart->addItem("Trebuchet",  (uint)eDorfMark::mark7);

//    ui->cbTruppenart->addItem("Paladin", double(8));
//    ui->cbTruppenart->addItem("SKav", double(9));
//    ui->cbTruppenart->addItem("Speer", double(14));
//    ui->cbTruppenart->addItem("Schwert", double(18));
//    ui->cbTruppenart->addItem("Ramme", double(24));
//    ui->cbTruppenart->addItem("AG", double(35));
//    ui->cbTruppenart->addItem("Trebuchet", double(50));

    currentDT = new QDateTime();
    currentDT->currentDateTime();
    ui->labelForTime->setText( currentDT->currentDateTime().toString());

    ui->teVon->setEnabled(false);
    ui->teBis->setEnabled(false);
    von = new QTime(-1,-1,-1);  //creates an invalid time
    bis = new QTime(-1,-1,-1);  //creates an invalid time

    targetDT = new QDateTime(QDateTime::currentDateTime());
    targetDT->setDate(QDateTime::currentDateTime().date());
    targetDT->setTime(QDateTime::currentDateTime().addSecs(1000).time());
    ui->labelTargetDT->setText("TargetTime:  " + targetDT->toString());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    qDebug() << "starting initialize main";

    ui->targetDateTimeEdit->setMinimumDateTime(QDateTime::currentDateTime());
    ui->targetDateTimeEdit->setCalendarPopup(true);


//    pModel = new DataModel();
//    pModel->addDorf(Dorf("erstes", 458, 407));
//    pModel->addDorf(Dorf("zweites", 479, 416));
//    pModel->addDorf(Dorf("drittes", 479, 417));
//    pModel->addDorf(Dorf("viertes", 481, 414));
//    pModel->addDorf(Dorf("fünftes", 472, 414));

    //pTableModel = new TableDataModel(this, targetDT );
    pTableModel = new TableDataModel( targetDT, von, bis, this );
//    pTableModel->addDorf(Dorf("erstes", 458, 407));
//    pTableModel->addDorf(Dorf("zweites", 479, 416));
//    pTableModel->addDorf(Dorf("drittes", 479, 417));
//    pTableModel->addDorf(Dorf("viertes", 481, 414));
//    pTableModel->addDorf(Dorf("fünftes", 472, 414));

    //qDebug() << "my c = " << ui->cbTruppenart->currentData().toDouble();
  //  pModel->setZwischenDorfLaufzeit(ui->cbTruppenart->currentData().toDouble());
    pTableModel->setTempDorfMark( helpers::uintToeDorfMark( ui->cbTruppenart->currentData().toUInt()));
    qDebug() << "datamodel done";

    customDelegate = new CustomDelegate(this, targetDT);
    tableCustomDelegate = new TableCustomDelegate(this, targetDT);
    qDebug() << "customdelegate done";
//    ui->listView->setModel(pModel);
//    ui->listView->setItemDelegate(customDelegate);
//    ui->listView->setAlternatingRowColors(true);

    ui->tableView->setModel(pTableModel);
    ui->tableView->setItemDelegate(tableCustomDelegate);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setSortingEnabled(true);
    qDebug() << "views done";

    //example selectionmode
    //ui->listWidgetModerator->setSelectionMode(QAbstractItemView::ExtendedSelection);


    //connects
    connect(ui->targetDateTimeEdit, SIGNAL(dateTimeChanged(QDateTime)),
            this, SLOT(getTargetDT()));
    qDebug() << "first  connect done";

    dorfTempDatabase = new dorfDatabase();
   // dorfTempDatabase->readFileDatabase();

    connect( ui->cbTruppenart, SIGNAL(currentIndexChanged(int)),
             this, SLOT(slotZwischenDorfLaufzeitUpdated(int))  );

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(updateAllTimerbased()));

    connect ( timer, SIGNAL(timeout()),
               pTableModel, SLOT(emitFakeResetModelSignal())  );

    timer->start(1000);
    qDebug() << "connects and timer done";

    connect( dorfTempDatabase, SIGNAL(sendDorfDatabase(QList<Dorf>)),
             pTableModel, SLOT(updateModelDatabase(QList<Dorf>)) );

    connect( pTableModel, SIGNAL(emitPlanerModelChanged(QList<Dorf>)),
             dorfTempDatabase, SLOT(updateDatabase(QList<Dorf>))  );
    connect( ui->teVon, SIGNAL(timeChanged(QTime)),
             this, SLOT(timeeditChanged())   );
    connect( ui->teBis, SIGNAL(timeChanged(QTime)),
             this, SLOT(timeeditChanged())   );

}

void MainWindow::updateAllTimerbased()
{
    ui->labelForTime->setText("CurrentTime:  " + currentDT->currentDateTime().toString());


    timer->start(1000);
}

void MainWindow::getTargetDT()
{
    targetDT->setDate( ui->targetDateTimeEdit->date());
    targetDT->setTime(ui->targetDateTimeEdit->time());
    ui->labelTargetDT->setText("TargetTime:  " + targetDT->toString());
}



void MainWindow::on_btnInput_clicked()
{

    inputDialog = new InputDialog(this);

    inputDialog->setModal(true);
    connect( inputDialog, SIGNAL(sendInputDorfData(QString)),
             this, SLOT(receiveInputDorfData(QString)) );
    connect( inputDialog, SIGNAL(sendAddingDorfData(QString)),
             dorfTempDatabase, SLOT(updateDatabase(QString)) );


    inputDialog->exec();
    inputDialog->deleteLater();

}


void MainWindow::receiveInputDorfData(QString Data)
{
 //  pModel->updateModelDatabase( DorfParser::parseToDatabase(Data) );

}

void MainWindow::receiveInputDorfData(QList<Dorf> Database)
{
  //  pModel->updateModelDatabase(Database);
}


void MainWindow::on_btnSetTarget_clicked()
{
    bool ok;
    int tempX, tempY;
    tempX = ui->leTargetX->text().toInt(&ok);
    if (!ok)
    {
        QMessageBox::information(0, "Error", "Die eingegebene Zahl ist kein gültiger Integer-Wert");
        tempX = -1;
    }
    tempY = ui->leTargetY->text().toInt(&ok);
    if (!ok)
    {
        QMessageBox::information(0, "Error", "Die eingegebene Zahl ist kein gültiger Integer-Wert");
        tempY = -1;
    }

    if(tempX != -1 && tempY != -1)
 //   pModel->targetDorf->set("TargetDorf", tempX, tempY);
    pTableModel->targetDorf->set("TargetDorf", tempX, tempY);

}


void MainWindow::on_actionReadFile_triggered()
{
    dorfTempDatabase->readFileDatabase();
}


void MainWindow::on_actionSaveFile_triggered()
{
    dorfTempDatabase->saveDatabaseSlot();
}


void MainWindow::slotZwischenDorfLaufzeitUpdated(int i)
{
//  pModel->setZwischenDorfLaufzeit(ui->cbTruppenart->currentData().toDouble());
//    uint Mark = ui->cbTruppenart->currentData().toUInt();
//    qDebug() << "Gui uint Mark = " << Mark;
//    eDorfMark mark = helpers::uintToeDorfMark(Mark );
//    qDebug() << "GUI mark = " << mark;
    pTableModel->setTempDorfMark( helpers::uintToeDorfMark(ui->cbTruppenart->currentData().toUInt() ));
}



void MainWindow::on_pushButton_clicked()
{
    pModeratorDialog = new ModeratorDialog(dorfTempDatabase->getAllItems() ,this);
   pModeratorDialog->setModal(true);

    connect( pModeratorDialog, SIGNAL(moderatorUpdated(QList<Dorf>)),
                dorfTempDatabase, SLOT(updateDatabase(QList<Dorf>)) );

    pModeratorDialog->exec();
    pModeratorDialog->deleteLater();

}


void MainWindow::on_chbIntervall_clicked()
{

    if (ui->chbIntervall->isChecked())
    {
        ui->teVon->setEnabled(true);
        ui->teBis->setEnabled(true);

    }
    else
    {
        ui->teVon->setEnabled(false);
        ui->teBis->setEnabled(false);
        ui->teVon->setTime(QTime(0, 0, 0, 0) );
        ui->teBis->setTime(QTime(0, 0, 0, 0));
        (*von).setHMS(-1, -1, -1);  //creates an invalid time
        (*bis).setHMS(-1, -1, -1);  //creates an invalid time
        pTableModel->updateForTimeIntervall();
    }
}

void MainWindow::timeeditChanged()
{
    *von = ui->teVon->time();
    *bis = ui->teBis->time();
    pTableModel->updateForTimeIntervall();
}






















