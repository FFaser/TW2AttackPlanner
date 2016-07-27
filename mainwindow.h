 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <datamodel.h>
#include <customdelegate.h>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QTimer>
#include <inputdialog.h>
#include <moderatordialog.h>
#include <myfileio.h>
#include <QDir>
#include <calculatedistance.h>
#include <dorf.h>
#include <dorfdatabase.h>
#include <tabledatamodel.h>
#include <tablecustomdelegate.h>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QModelIndex>
#include <moderatormodel.h>
#include <moderatordelegate.h>
#include <clickableiconholder.h>

//WARNING prüfen: view breaks down around midnight

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initialize();
    QString test;
    QDateTime *currentDT;
    QDateTime *targetDT;

    QDir *dir;

public slots:
    void updateAllTimerbased();
    void getTargetDT();

    void receiveInputDorfData(QString Data);
    void receiveInputDorfData(QList<Dorf> Database);

private slots:
    void on_btnInput_clicked();

    void on_btnSetTarget_clicked();

    void on_actionReadFile_triggered();

    void on_actionSaveFile_triggered();

    void slotZwischenDorfLaufzeitUpdated(int i);

    void on_pushButton_clicked();

    void on_chbIntervall_clicked();

    void timeeditChanged();

private:
    Ui::MainWindow *ui;
    InputDialog *inputDialog;
    ModeratorDialog *pModeratorDialog;
    DataModel *pModel;
    TableDataModel *pTableModel;
    CustomDelegate *customDelegate;

    TableCustomDelegate *tableCustomDelegate;
    QTimer *timer;
    dorfDatabase *dorfTempDatabase;

    QTime *von;
    QTime *bis;


};

#endif // MAINWINDOW_H
