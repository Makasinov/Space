#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QGraphicsScene>

const int errorCounter = 200;

const QString FOLDER_PATH = "F:\\ephemeris_TXT_formatted";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Эфемериды"));
    this->view->setGeometry(1000,500,500,500);
    this->view->setWindowTitle("Карта созвездий");
    QWidget::connect(this,SIGNAL(hideEvent(QHideEvent*)),view,SLOT(close()));
    view->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            view->size(),
            qApp->desktop()->availableGeometry()
        )
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dateEdit_userDateChanged(const QDate &date){}

QString getMonth(int month)
{
    switch (month)
    {
    case 1:  return "JANUARY";
    case 2:  return "FEBRUARY";
    case 3:  return "MARCH";
    case 4:  return "APRIL";
    case 5:  return "MAY";
    case 6:  return "JUNE";
    case 7:  return "JULY";
    case 8:  return "AUGUST";
    case 9:  return "SEPTEMBER";
    case 10: return "OCTOBER";
    case 11: return "NOVEMBER";
    case 12: return "DECEMBER";
    default: return NULL;
    }
}

bool MainWindow::setGraphics()
{
    scene->clear();
    this->view->setScene(scene);

    return 1;
}

void MainWindow::on_dateEdit_editingFinished(){}

void MainWindow::removeOtherRows(QTableWidget &table, const int number)
{
    if ( this->ui->action_4->isChecked() ) {
        for(int i = 0; i < number-1; i++, table.removeRow(0));
        while(table.rowCount() != 1) table.removeRow(1);
    }
}

void MainWindow::on_pushButton_clicked()
{
    auto date = this->ui->dateEdit->date();
    QString year = QString::number(date.year());
    QString filePath = FOLDER_PATH + "\\" + year + "_formatted.txt";
    QFile * file = new QFile(filePath);
    if ( !file->open(QIODevice::ReadOnly) )
    {
        QMessageBox::information(this,
                                 "Ошибка",
                                 "Неудалось открыть текущий год");
        file->close();
        return;
    }
    auto table = this->ui->tableWidget;
    QTextStream stream(file);
    QString month = getMonth(date.month());
    this->ui->tabWidget->tabBar()->setTabText(0,month);
    QString line;
    if ( date.month() != 1 ) {
        do {
            line = stream.readLine();
        } while (line != month);
    } else line = stream.readLine();
    if (this->ui->action_3->isChecked()) table->setRowCount(0);
    int counter = 0;
    bool exit = false;
    //if ( getMonth( date.month()+1 ) != NULL )
        while ( !exit ) {
            table->insertRow(table->rowCount());
            counter++;
            if (counter >= errorCounter)
            {
                QMessageBox::information(this,"Ошибка","Произошла непредвиденная ошибка");
                return;
            }
            for(int i = 0; i < 16; ++i)
            {
                if ( i == 0 )
                {
                    line = stream.readLine();
                    if (line == "")
                    {
                        exit = true;
                        break;
                    }
                    table->setItem(table->rowCount()-1,
                                   0,
                                   new QTableWidgetItem(line));
                } else
                    if ( i == 1 )
                    {
                        QString newLine;
                        newLine = stream.readLine();
                        newLine += stream.readLine();
                        newLine += stream.readLine();
                        table->setItem(table->rowCount()-1,
                                       1,
                                       new QTableWidgetItem(newLine));
                        line = newLine;
                    } else
                    {
                        line = stream.readLine();
                        table->setItem(table->rowCount()-1,
                                       i,
                                       new QTableWidgetItem(line));
                    }
            }
        }
        file->close();
        if ( this->ui->action_6->isChecked() ) table->resizeColumnsToContents();
        table->removeRow(table->rowCount()-1);
        removeOtherRows(*table,this->ui->dateEdit->date().day());
        setGraphics();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->view->show();
    this->view->setFocus();
}
