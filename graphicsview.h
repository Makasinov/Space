#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include <QDebug>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0)
    {
        QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(setGraphics()));
        QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(drawLines()));
        QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(drawPlanets()));
        QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(drawSigns()));
        QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(drawSpacePlanets()));
        this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        this->setScene(&scene);
        this->parent = parent;
        this->setWindowTitle(tr("Эфемериды"));
        this->setGeometry(1000,500,500,500);
        this->setWindowTitle("Карта созвездий");
    }
    static void getXY(double * x, double * y,
                      const int angle,
                      const int ECLIPSE_RADIUSX,
                      const int ECLIPSE_RADIUSY,
                      const int w,
                      const int h);
    static void correctXY(const int angle,
                          double * x,
                          double * y,
                          const int w,
                          const int h);
    QGraphicsScene scene;
private:
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
