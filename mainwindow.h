#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <graphicsview.h>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GraphicsView * myView = new GraphicsView(this);
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
