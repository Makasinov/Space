#include "formula.h"

Formula::Formula(QWidget *parent)
{
    QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(clearGraphics()));
    QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(drawTable()));
    QObject::connect(this,SIGNAL(resizeEvent(QResizeEvent*)),this,SLOT(drawSigns()));

    this->parent = parent;
    this->setWindowTitle(tr("Формула души"));
    this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    this->setScene(&this->scene);
    QRect rec = QApplication::desktop()->screenGeometry();
    this->setGeometry(0, 0, rec.height() * 0.95, rec.height() * 0.75);
}

void Formula::drawTable()
{
    const int w = this->size().width();
    const int h = this->size().height();
    scene.addLine(0, 0, w, h,QPen(QColor(0xFF, 0, 0, 0)));  // Костыль - невидимая линия вдоль всего окна
    scene.addLine(0, h * 0.1, w, h * 0.1);
    auto centreText = scene.addSimpleText(tr("Центр"),QFont("Helvetica [Cronyx]", 20));
    centreText->setPos(w * 0.165, h * 0.035);
    centreText->setScale(h>w?w * 0.0015:h * 0.0015);
    scene.addLine(w * 0.1, 0, w * 0.1, h);
    scene.addLine(w * 0.3, 0, w * 0.3, h);
    scene.addLine(w * 0.4, 0, w * 0.4, h);
    scene.addLine(w * 0.5, 0, w * 0.5, h);
    scene.addLine(w * 0.6, 0, w * 0.6, h);
    scene.addLine(w * 0.7, 0, w * 0.7, h);
    scene.addLine(w * 0.8, 0, w * 0.8, h);
    scene.addLine(w * 0.9, 0, w * 0.9, h);
}

void Formula::clearGraphics()
{
    this->scene.clear();
}

void Formula::drawSigns()
{
    const int w = this->size().width();
    const int h = this->size().height();

    QPixmap i1(":gif/mercury.gif");
    QGraphicsPixmapItem * mercury1 = this->scene.addPixmap(i1);
    mercury1->setPos(w * 0.02, h * 0.035);
    mercury1->setScale(h>w?w * 0.001:h * 0.001);

    QPixmap i2(":gif/mercury.gif");
    QGraphicsPixmapItem * mercury2 = this->scene.addPixmap(i2);
    mercury2->setPos(w * 0.335, h * 0.035);
    mercury2->setScale(h>w?w * 0.001:h * 0.001);

    QPixmap i3(":gif/venus.gif");
    QGraphicsPixmapItem * venus = this->scene.addPixmap(i3);
    venus->setPos(w * 0.435, h * 0.035);
    venus->setScale(h>w?w * 0.001:h * 0.001);

    QPixmap i4(":gif/mars.gif");
    QGraphicsPixmapItem * mars = this->scene.addPixmap(i4);
    mars->setPos(w * 0.535, h * 0.035);
    mars->setScale(h>w?w * 0.001:h * 0.001);

    QPixmap i5(":gif/jupiter.gif");
    QGraphicsPixmapItem * jupiter = this->scene.addPixmap(i5);
    jupiter->setPos(w * 0.635, h * 0.035);
    jupiter->setScale(h>w?w * 0.001:h * 0.001);

    QPixmap i6(":gif/saturn.gif");
    QGraphicsPixmapItem * saturn = this->scene.addPixmap(i6);
    saturn->setPos(w * 0.735, h * 0.035);
    saturn->setScale(h>w?w * 0.001:h * 0.001);

    QPixmap i7(":gif/uran2.gif");
    QGraphicsPixmapItem * uran2 = this->scene.addPixmap(i7);
    uran2->setPos(w * 0.835, h * 0.035);
    uran2->setScale(h>w?w * 0.001:h * 0.001);

    QPixmap i8(":gif/neptun1.gif");
    QGraphicsPixmapItem * neptune = this->scene.addPixmap(i8);
    neptune->setPos(w * 0.935, h * 0.035);
    neptune->setScale(h>w?w * 0.001:h * 0.001);
}
