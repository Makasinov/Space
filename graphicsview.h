#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include <QTableWidget>
#include <QDebug>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0);
    void getXY(double * x, double * y,
                const int angle,
                const int ECLIPSE_RADIUSX,
                const int ECLIPSE_RADIUSY);
    void correctXY(const int angle,
                double * x,
                double * y,
                const int w,
                const int h);
    void setTable(QTableWidget * t)
    {
        this->table = t;
    }
    void setParams(int number, QGraphicsPixmapItem *planet);
    void getEllipse(double *x, double *y);
    QGraphicsScene scene;

private:
    QHash<int,QString> hash;
    QTableWidget * table;
    const double OPACITY = 0.1;
    QWidget * parent;
    QGraphicsEllipseItem ecl1,ecl2,ecl3,ecl4,ecl5,ecl6,ecl7,ecl8;

signals:
    void resizeEvent(QResizeEvent * event);

public slots:
    void myDebug()
    {
        qDebug() << "debugMe ;)";
    }
    void drawSpacePlanets();
    void drawLines();
    void drawPlanets();
    void drawSigns();
    bool setGraphics();
};

#endif // GRAPHICSVIEW_H
