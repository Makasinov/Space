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
#include <QDir>
#include <QFont>
#include <QPalette>
#include <QPixmap>
#include <QGraphicsPixmapItem>

const int errorCounter = 200;
const QString FOLDER_PATH = ":\\ephemeris_TXT_formatted";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(myView,SIGNAL(resizeEvent(QResizeEvent*)),myView,SLOT(setGraphics()));
    QObject::connect(myView,SIGNAL(resizeEvent(QResizeEvent*)),myView,SLOT(drawLines()));
    QObject::connect(myView,SIGNAL(resizeEvent(QResizeEvent*)),myView,SLOT(drawSymbols()));
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
                                 "Неудалось открыть текущий год\n"
                                 "Проверьте путь -> " + filePath);
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
}

void GraphicsView::drawLines()
{
    int x = this->width(),y = this->height();
    scene.addEllipse(60,60,x-130,y-130);
    scene.addLine(x/2-5,0,x/2-5,y-10);
    scene.addLine(0,y/2-10,x-10,y/2-10);
    scene.addLine(0,y/4-10,x-10,y-(y/4)-10);
    scene.addLine(x/4-10,0,x-(x/4),y-15);
    scene.addLine(x-x/4,0,x/4-10,y-15);
    scene.addLine(x-10,y/4-5,0,y-y/4-10);
}

void GraphicsView::drawSymbols()
{
    int x = this->width(),y = this->height();
    auto znak = this->scene.addSimpleText(".");
    znak->setPos(x/2.5,y/1.4);

    QPixmap i1(":gif/sun.gif");
    auto sun = this->scene.addPixmap(i1);
    sun->setPos(x/4,y/4);

    QPixmap i2(":gif/mercury.gif");
    auto mercury = this->scene.addPixmap(i2);
    mercury->setPos(x-x/2.8,y/4);

    QPixmap i3(":gif/leo.gif");
    auto leo = this->scene.addPixmap(i3);
    leo->setPos(x-x/2.8,y-y/2.8);

    QPixmap i4(":gif/taurus.gif");
    auto taurus = this->scene.addPixmap(i4);
    taurus->setPos(x/4,y-y/2.8);

    QPixmap i5(":gif/mars.gif");
    auto mars = this->scene.addPixmap(i5);
    mars->setPos(x/6,y/2.7);

    QPixmap i6(":gif/jupiter.gif");
    auto jupiter = this->scene.addPixmap(i6);
    jupiter->setPos(x/1.36,y/2.7);

    QPixmap i7(":gif/saturn.gif");
    auto saturn = this->scene.addPixmap(i7);
    saturn->setPos(x/1.36,y/2);

    QPixmap i8(":gif/aries.gif");
    auto aries = this->scene.addPixmap(i8);
    aries->setPos(x/6,y/2);

    QPixmap i9(":gif/neptun1.gif");
    auto neptun = this->scene.addPixmap(i9);
    neptun->setPos(x/2.5,y/4.8);

    QPixmap i10(":gif/gemini.gif");
    auto gemini = this->scene.addPixmap(i10);
    gemini->setPos(x/2.5,y/1.4);

    QPixmap i11(":gif/comet.gif");
    auto comet = this->scene.addPixmap(i11);
    comet->setPos(x/2,y/4.8);

    QPixmap i12(":gif/cancer.gif");
    auto cancer = this->scene.addPixmap(i12);
    cancer->setPos(x/2,y/1.4);
}

bool GraphicsView::setGraphics()
{
    scene.clear();
    return 1;
}

void MainWindow::on_pushButton_2_clicked()
{
    this->setWindowTitle(tr("Эфемериды"));
    myView->setGeometry(1000,500,500,500);
    myView->setWindowTitle("Карта созвездий");
    QWidget::connect(this,SIGNAL(hideEvent(QHideEvent*)),myView,SLOT(close()));
    myView->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            myView->size(),
            qApp->desktop()->availableGeometry()
        )
    );
    myView->show();
    myView->setFocus();
}
