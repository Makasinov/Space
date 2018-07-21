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
#include <QMouseEvent>
#include <QEvent>
#include <QMessageBox>
#include <QBrush>
#include <QPen>
#include <QPoint>
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

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
    void   setTable(QTableWidget * t){this->table = t;}
    void   setParams(int number, QGraphicsPixmapItem *planet);
    int    getEllipse(double *x, double *y, const QChar symbol, const int number);
    QPoint getEllipse(const int angle);
    QChar  correctSymbol(const int number);
    void   drawLineToPlanet(const QPoint planetPos, const int angle, const int width, const int heigth);

private:
    const QString SQUARE_PATH = ":gif/square.gif";
    const double OPACITY_1 = 0.1;
    const double OPACITY_3 = 0.3;
    QGraphicsScene scene;
    QTableWidget * table;
    QWidget * parent;
    QGraphicsEllipseItem ecl1,ecl2,ecl3,ecl4,ecl5,ecl6,ecl7,ecl8;
    QGraphicsPixmapItem * moon;
    QGraphicsPixmapItem * mercury;
    QGraphicsPixmapItem * venus;
    QGraphicsPixmapItem * mars;
    QGraphicsPixmapItem * jupiter;
    QGraphicsPixmapItem * saturn;
    QGraphicsPixmapItem * uranus;
    QGraphicsPixmapItem * neptune;
    QGraphicsPixmapItem * pluto;
    QGraphicsPixmapItem * sun;
    QString distanceArray[8][13] =      // Меркурий часто повторяется
    {
        { " ", "a",  "b",  "c",   "d",  "e",  "f",   "g",  "h",  "i",   "j",  "k",  "l"   },
        { "6", "EJ", "D",  "C",   "B",  "A",  "C",   "D",  "JE", "FI",  "GO", "OG", "IF"  },
        { "5", "A",  "B",  "C",   "F",  "J",  "C",   "G",  "O",  "?",   "E",  "I" , "D"   },
        { "4", "FI", "GC", "DGO", "JI", "FE", "GO",  "CO", "FI", "AEJ", "CD", "CD", "BJE" },
        { "3", "B",  "A",  "B",   "A",  "B",  "A",   "B",  "A",  "B",   "A",  "B",  "A"   },
        { "2", "CO", "FI", "AEJ", "CD", "CD", "BEJ", "FI", "GC", "DGO", "JI", "FE", "GO"  },
        { "1", "G",  "O",  "?",   "E",  "I",  "D",   "A",  "B",  "C",   "F",  "J",  "C"   },
        { "0", "D",  "EJ", "FI",  "GO", "GO", "FI",  "EJ", "D",  "C",   "B",  "A",  "C"   }
    };

signals:
    void resizeEvent(QResizeEvent * event);

public slots:
    void drawSpacePlanets();
    void drawLines();
    void drawPlanets();
    void drawSigns();
    bool setGraphics();
};

#endif // GRAPHICSVIEW_H
