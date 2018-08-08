#ifndef FORMULA_H
#define FORMULA_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include <QTableWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QEvent>
#include <QMessageBox>
#include <QBrush>
#include <QPen>
#include <QPoint>
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include <QException>

class Formula : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Formula(QWidget *parent = nullptr);
    void   setTable(QTableWidget * t){this->table = t;}

private:
    QWidget * parent;
    QGraphicsScene scene;
    QTableWidget * table;
    bool ErrorRised = false;

    const QString C_ERROR1 = "Таблица заполнена не правильно, пример заполнения:\n"
                             "23 R j, где 23 - градус, R/D - Ретраград./Директ.\n"
                             "и j - знак зодиака";

signals:
    void resizeEvent(QResizeEvent * event);

public slots:
    void drawTable();
    void clearGraphics();
    void drawSigns();
};

#endif // FORMULA_H
