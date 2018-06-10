#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0)
    {
        QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(setGraphics()));
        QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(drawLines()));
        QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(drawSymbols()));
        this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        this->setScene(&scene);
        this->parent = parent;
        this->setWindowTitle(tr("Эфемериды"));
        this->setGeometry(1000,500,500,500);
        this->setWindowTitle("Карта созвездий");
    }
    QGraphicsScene scene;
private:
    const double OPACITY = 0.2;
    QWidget * parent;

signals:
    void resizeEvent(QResizeEvent * event);

public slots:
    void drawLines();
    void drawSymbols();
    bool setGraphics();
};

#endif // GRAPHICSVIEW_H
