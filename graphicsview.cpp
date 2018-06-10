#include "graphicsview.h"

void GraphicsView::drawLines()
{
    int w = this->size().width();
    int h = this->size().height();

    scene.addEllipse(60,60,w-130,h-130);
    scene.addLine(w/2,0,w/2,h);
    scene.addLine(0,h/2,w,h/2);
    scene.addLine(0,h/4,w,h-(h/4));
    scene.addLine(w/4,0,w-(w/4),h);
    scene.addLine(w-w/4,0,w/4-10,h);
    scene.addLine(w-10,h/4,0,h-h/4);
}

void GraphicsView::drawSymbols()
{
    int w = this->size().width();
    int h = this->size().height();

    auto znak = this->scene.addSimpleText(".");
    znak->setPos(w/2.5,h/1.4);
    /////////////////////////////////////////////////////
    QPixmap i1(":gif/sun.gif");
    auto sun = this->scene.addPixmap(i1);
    sun->setPos(w/4,h/4);
    sun->setOpacity(OPACITY);

    QPixmap i2(":gif/mercury.gif");
    auto mercury = this->scene.addPixmap(i2);
    mercury->setPos(w-w/2.8,h/4);
    mercury->setOpacity(OPACITY);

    QPixmap i3(":gif/leo.gif");
    auto leo = this->scene.addPixmap(i3);
    leo->setPos(w-w/2.8,h-h/2.8);
    leo->setOpacity(OPACITY);

    QPixmap i4(":gif/taurus.gif");
    auto taurus = this->scene.addPixmap(i4);
    taurus->setPos(w/4,h-h/2.8);
    taurus->setOpacity(OPACITY);

    QPixmap i5(":gif/mars.gif");
    auto mars = this->scene.addPixmap(i5);
    mars->setPos(w/6,h/2.7);
    mars->setOpacity(OPACITY);

    QPixmap i6(":gif/jupiter.gif");
    auto jupiter = this->scene.addPixmap(i6);
    jupiter->setPos(w/1.36,h/2.7);
    jupiter->setOpacity(OPACITY);

    QPixmap i7(":gif/saturn.gif");
    auto saturn = this->scene.addPixmap(i7);
    saturn->setPos(w/1.36,h/2);
    saturn->setOpacity(OPACITY);

    QPixmap i8(":gif/aries.gif");
    auto aries = this->scene.addPixmap(i8);
    aries->setPos(w/6,h/2);
    aries->setOpacity(OPACITY);

    QPixmap i9(":gif/neptun1.gif");
    auto neptun = this->scene.addPixmap(i9);
    neptun->setPos(w/2.5,h/4.8);
    neptun->setOpacity(OPACITY);

    QPixmap i10(":gif/gemini.gif");
    auto gemini = this->scene.addPixmap(i10);
    gemini->setPos(w/2.5,h/1.4);
    gemini->setOpacity(OPACITY);

    QPixmap i11(":gif/comet.gif");
    auto comet = this->scene.addPixmap(i11);
    comet->setPos(w/2,h/4.8);
    comet->setOpacity(OPACITY);

    QPixmap i12(":gif/cancer.gif");
    auto cancer = this->scene.addPixmap(i12);
    cancer->setPos(w/2,h/1.4);
    cancer->setOpacity(OPACITY);
}

bool GraphicsView::setGraphics()
{
    scene.clear();
    return 1;
}
