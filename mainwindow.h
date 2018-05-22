#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool setGraphics();
    void removeOtherRows(QTableWidget &table, const int number);
    void drawLines(const int x, const int y);
    void drawSymbols(const int x, const int y);

signals:
    void hideEvent(QHideEvent *event);

private slots:
    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QFont font;
    QGraphicsView * view = new QGraphicsView;
    QGraphicsScene * scene = new QGraphicsScene(view);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
