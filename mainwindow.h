#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QGraphicsView>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(int h, int w, QWidget *parent = 0)
    {
        this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        this->setScene(&scene);
    }
    QGraphicsScene scene;

signals:
    void resizeEvent(QResizeEvent * event);

public slots:
    void drawLines();
    void drawSymbols();
    bool setGraphics();
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GraphicsView * myView = new GraphicsView(500,500,this);
    void removeOtherRows(QTableWidget &table, const int number);

signals:
    void hideEvent(QHideEvent *event);

private slots:
    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
