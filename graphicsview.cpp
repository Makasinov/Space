#include "graphicsview.h"
#include <QtMath>

void GraphicsView::getXY(double * x, double * y,
                         const int angle,
                         const int ECLIPSE_RADIUSX,
                         const int ECLIPSE_RADIUSY,
                         const int w,
                         const int h)
{
    *(x) = cos(2 * M_PI * angle / 360) * ECLIPSE_RADIUSX + w/2 - 2;
    *(y) = sin(2 * M_PI * angle / 360) * ECLIPSE_RADIUSY + h/2 - 2;
    correctXY(angle,x,y,w,h);
}

void GraphicsView::correctXY(const int angle, double * x, double * y, const int w, const int h)
{
    if (angle >= 345 || angle <= 4)
        *(x) -= w * 0.03;
    else if (angle >= 5 && angle <= 24)
        *(x) -= w * 0.035;
    else if (angle >= 25 && angle <= 34)
        *(x) -= w * 0.04;
    else if (angle >= 35 && angle <= 44)
        *(x) -= w * 0.045;
    else if (angle >= 45 && angle <= 54)
        *(x) -= w * 0.055;
    else if (angle <= 79)
        *(y) -= h * 0.04;
    else if (angle <= 119)
        *(y) -= h * 0.035;
    else if (angle <= 149)
        *(y) -= h * 0.03;
    else if (angle <= 169)
        *(y) -= h * 0.04;
    else if (angle <= 189)
        *(y) -= h * 0.015;
    else if (angle >= 295)
        *(x) -= w * 0.02;
}

void GraphicsView::drawSpacePlanets()
{
    int w = this->size().width();
    int h = this->size().height();

    double scaling = 0;
    if (h > w) scaling = w * 0.0006;
        else scaling = h * 0.0006;

    double angle = 130;
    double x = 0, y = 0;

    const double ECLIPSE_RADIUSX1 = ( ( w - w / 4 ) / 2 ) - w * 0.002;       // 1 круг
    const double ECLIPSE_RADIUSY1 = ( ( h - h / 4 ) / 2 ) - h * 0.002;       // 2 круг

    const double ECLIPSE_RADIUSX2 = ( ( w - w / 4 ) / 2 ) - w * 0.035;       // 2 круг
    const double ECLIPSE_RADIUSY2 = ( ( h - h / 4 ) / 2 ) - h * 0.035;       // 2 круг

    const double ECLIPSE_RADIUSX3 = ( ( w - w / 4 ) / 2 ) - w * 0.075;       // 3 круг
    const double ECLIPSE_RADIUSY3 = ( ( h - h / 4 ) / 2 ) - h * 0.075;       // 3 круг

    const double ECLIPSE_RADIUSX4 = ( ( w - w / 4 ) / 2 ) - w * 0.107;       // 4 круг
    const double ECLIPSE_RADIUSY4 = ( ( h - h / 4 ) / 2 ) - h * 0.107;       // 4 круг

    const double ECLIPSE_RADIUSX5 = ( ( w - w / 4 ) / 2 ) - w * 0.145;       // 5 круг
    const double ECLIPSE_RADIUSY5 = ( ( h - h / 4 ) / 2 ) - h * 0.145;       // 5 круг

    const double ECLIPSE_RADIUSX6 = ( ( w - w / 4 ) / 2 ) - w * 0.18;        // 6 круг
    const double ECLIPSE_RADIUSY6 = ( ( h - h / 4 ) / 2 ) - h * 0.18;        // 6 круг

    const double ECLIPSE_RADIUSX7 = ( ( w - w / 4 ) / 2 ) - w * 0.215;       // 7 круг
    const double ECLIPSE_RADIUSY7 = ( ( h - h / 4 ) / 2 ) - h * 0.215;       // 7 круг

    QPixmap pixmap(":gif/earth.png");
    QGraphicsPixmapItem * earth = this->scene.addPixmap(pixmap);
    getXY(&x,&y,130,ECLIPSE_RADIUSX1,ECLIPSE_RADIUSY1,w,h);
    earth->setPos(x,y);
    earth->setScale(scaling);

    pixmap.load(":gif/mars.png");
    QGraphicsPixmapItem * mars = this->scene.addPixmap(pixmap);
    getXY(&x,&y,180,ECLIPSE_RADIUSX2,ECLIPSE_RADIUSY2,w,h);
    mars->setPos(x,y);
    mars->setScale(scaling);

    pixmap.load(":gif/mercury.png");
    QGraphicsPixmapItem * mercury = this->scene.addPixmap(pixmap);
    getXY(&x,&y,220,ECLIPSE_RADIUSX3,ECLIPSE_RADIUSY3,w,h);
    mercury->setPos(x,y);
    mercury->setScale(scaling);

    pixmap.load(":gif/saturn.png");
    QGraphicsPixmapItem * saturn= this->scene.addPixmap(pixmap);
    getXY(&x,&y,270,ECLIPSE_RADIUSX6,ECLIPSE_RADIUSY6,w,h);
    saturn->setPos(x,y);
    saturn->setScale(scaling);

    pixmap.load(":gif/neptune.png");
    QGraphicsPixmapItem * neptune = this->scene.addPixmap(pixmap);
    getXY(&x,&y,250,ECLIPSE_RADIUSX5,ECLIPSE_RADIUSY5,w,h);
    neptune->setPos(x,y);
    neptune->setScale(scaling);

    pixmap.load(":gif/pluto.png");
    QGraphicsPixmapItem * pluto = this->scene.addPixmap(pixmap);
    getXY(&x,&y,50,ECLIPSE_RADIUSX4,ECLIPSE_RADIUSY4,w,h);
    pluto->setPos(x,y);
    pluto->setScale(scaling);

    pixmap.load(":gif/venus.png");
    QGraphicsPixmapItem * venus = this->scene.addPixmap(pixmap);
    getXY(&x,&y,20,ECLIPSE_RADIUSX7,ECLIPSE_RADIUSY7,w,h);
    venus->setPos(x,y);
    venus->setScale(scaling);

    pixmap.load(":gif/uranus.png");
    QGraphicsPixmapItem * uranus = this->scene.addPixmap(pixmap);
    getXY(&x,&y,100,ECLIPSE_RADIUSX3,ECLIPSE_RADIUSY3,w,h);
    uranus->setPos(x,y);
    uranus->setScale(scaling);

    pixmap.load(":gif/sun.png");
    QGraphicsPixmapItem * sun = this->scene.addPixmap(pixmap);
    sun->setPos(w/2-w*0.04, h/2-h*0.04);
    sun->setScale(scaling * 1.7);
}

void GraphicsView::drawLines()
{
    int w = this->size().width();
    int h = this->size().height();

    const int    ECLIPSE_CORDX = w/8;
    const int    ECLIPSE_CORDY = h/8;
    const double ECLIPSE_SIZEX = w-w/4;
    const double ECLIPSE_SIZEY = h-h/4;

    auto ecl1 = scene.addEllipse(ECLIPSE_CORDX,
                                 ECLIPSE_CORDY,
                                 ECLIPSE_SIZEX,
                                 ECLIPSE_SIZEY);
    auto ecl2 = scene.addEllipse(ECLIPSE_CORDX+w*0.035,
                                 ECLIPSE_CORDY+h*0.035,
                                 ECLIPSE_SIZEX-w*0.07,
                                 ECLIPSE_SIZEY-h*0.07);
    auto ecl3 = scene.addEllipse(ECLIPSE_CORDX+w*0.07,
                                 ECLIPSE_CORDY+h*0.07,
                                 ECLIPSE_SIZEX-w*0.14,
                                 ECLIPSE_SIZEY-h*0.14);
    auto ecl4 = scene.addEllipse(ECLIPSE_CORDX+w*0.105,
                                 ECLIPSE_CORDY+h*0.105,
                                 ECLIPSE_SIZEX-w*0.21,
                                 ECLIPSE_SIZEY-h*0.21);
    auto ecl5 = scene.addEllipse(ECLIPSE_CORDX+w*0.14,
                                 ECLIPSE_CORDY+h*0.14,
                                 ECLIPSE_SIZEX-w*0.28,
                                 ECLIPSE_SIZEY-h*0.28);
    auto ecl6 = scene.addEllipse(ECLIPSE_CORDX+w*0.175,
                                 ECLIPSE_CORDY+h*0.175,
                                 ECLIPSE_SIZEX-w*0.35,
                                 ECLIPSE_SIZEY-h*0.35);
    auto ecl7 = scene.addEllipse(ECLIPSE_CORDX+w*0.21,
                                 ECLIPSE_CORDY+h*0.21,
                                 ECLIPSE_SIZEX-w*0.42,
                                 ECLIPSE_SIZEY-h*0.42);
    auto ecl8 = scene.addEllipse(ECLIPSE_CORDX+w*0.245,
                                 ECLIPSE_CORDY+h*0.245,
                                 ECLIPSE_SIZEX-w*0.49,
                                 ECLIPSE_SIZEY-h*0.49);
    scene.addLine(w/2,0,w/2,h);
    scene.addLine(0,h/2,w,h/2);
    scene.addLine(0,h/4,w,h-(h/4));
    scene.addLine(w/4,0,w-(w/4),h);
    scene.addLine(w-w/4,0,w/4,h);
    scene.addLine(w,h/4,0,h-h/4);
}

void GraphicsView::drawPlanets()
{
    int w = this->size().width();
    int h = this->size().height();

    QPixmap i1(":gif/uran2.gif");
    auto sun = this->scene.addPixmap(i1);
    sun->setPos(w/4,h/4);
    sun->setOpacity(OPACITY);

    QPixmap i2(":gif/pluto.gif");
    auto mercury = this->scene.addPixmap(i2);
    mercury->setPos(w-w/2.8,h/4);
    mercury->setOpacity(OPACITY);

    QPixmap i3(":gif/sun.gif");
    auto leo = this->scene.addPixmap(i3);
    leo->setPos(w-w/2.8,h-h/2.8);
    leo->setOpacity(OPACITY);

    QPixmap i4(":gif/venus.gif");
    auto taurus = this->scene.addPixmap(i4);
    taurus->setPos(w/4,h-h/2.8);
    taurus->setOpacity(OPACITY);

    QPixmap i5(":gif/neptun1.gif");
    auto mars = this->scene.addPixmap(i5);
    mars->setPos(w/6,h/2.55);
    mars->setOpacity(OPACITY);

    QPixmap i6(":gif/venus.gif");
    auto jupiter = this->scene.addPixmap(i6);
    jupiter->setPos(w/1.36,h/2.55);
    jupiter->setOpacity(OPACITY);

    QPixmap i7(":gif/mercury.gif");
    auto saturn = this->scene.addPixmap(i7);
    saturn->setPos(w/1.36,h/2);
    saturn->setOpacity(OPACITY);

    QPixmap i8(":gif/mars.gif");
    auto aries = this->scene.addPixmap(i8);
    aries->setPos(w/6,h/2);
    aries->setOpacity(OPACITY);

    QPixmap i9(":gif/saturn.gif");
    auto neptun = this->scene.addPixmap(i9);
    neptun->setPos(w/2.5,h/4.8);
    neptun->setOpacity(OPACITY);

    QPixmap i10(":gif/mercury.gif");
    auto gemini = this->scene.addPixmap(i10);
    gemini->setPos(w/2.5,h/1.4);
    gemini->setOpacity(OPACITY);

    QPixmap i11(":gif/jupiter.gif");
    auto comet = this->scene.addPixmap(i11);
    comet->setPos(w/2,h/4.8);
    comet->setOpacity(OPACITY);

    QPixmap i12(":gif/moon.gif");
    auto cancer = this->scene.addPixmap(i12);
    cancer->setPos(w/2,h/1.4);
    cancer->setOpacity(OPACITY);
}

void GraphicsView::drawSigns()
{
    int w = this->size().width();
    int h = this->size().height();

    QPixmap i1(":gif/aries.gif");               // МАРС - ОВЕН - ARIES
    auto aries = this->scene.addPixmap(i1);
    aries->setPos(w*0.01,h/1.8);
    aries->setOpacity(OPACITY);

    QPixmap i2(":gif/taurus.gif");              // ВЕНЕРА - ТЕЛЕЦ - TAURUS
    auto taurus = this->scene.addPixmap(i2);
    taurus->setPos(w*0.1,h*0.77);
    taurus->setOpacity(OPACITY);

    QPixmap i3(":gif/gemini.gif");              // МЕРКУРИЙ - БЛИЗНЕЦЫ - GEMINI
    auto gemini = this->scene.addPixmap(i3);
    gemini->setPos(w/2.8,h-60);
    gemini->setOpacity(OPACITY);

    QPixmap i4(":gif/cancer.gif");              // ЛУНА - РАК - CANCER
    auto cancer = this->scene.addPixmap(i4);
    cancer->setPos(w/1.8,h-60);
    cancer->setOpacity(OPACITY);

    QPixmap i5(":gif/leo.gif");                 // СОЛНЦЕ - ЛЕВ - LEO
    auto leo = this->scene.addPixmap(i5);
    leo->setPos(w-w*0.15,h*0.77);
    leo->setOpacity(OPACITY);

    QPixmap i6(":gif/virgo.gif");               // МЕРКУРИЙ - ДЕВА - VIRGO
    auto virgo = this->scene.addPixmap(i6);
    virgo->setPos(w-60,h/1.8);
    virgo->setOpacity(OPACITY);

    QPixmap i7(":gif/libra.gif");               // ВЕНЕРА - ВЕСЫ - LIBRA
    auto libra = this->scene.addPixmap(i7);
    libra->setPos(w-60,h/2.7);
    libra->setOpacity(OPACITY);

    QPixmap i8(":gif/scorpio.gif");             // ПЛУТОН - СКОРПИОН - SCORPIO
    auto scorpio = this->scene.addPixmap(i8);
    scorpio->setPos(w-w*0.2,h/9);
    scorpio->setOpacity(OPACITY);

    QPixmap i9(":gif/sagittar.gif");             // ЮПИТЕР - СТРЕЛЕЦ - SAGITTAR
    auto sagittar = this->scene.addPixmap(i9);
    sagittar->setPos(w/1.8,10);
    sagittar->setOpacity(OPACITY);

    QPixmap i10(":gif/capricor.gif");            // САТУРН - КОЗЕРОГ - CAPRICOR
    auto capricor = this->scene.addPixmap(i10);
    capricor->setPos(w/2.8,10);
    capricor->setOpacity(OPACITY);

    QPixmap i11(":gif/aqua.gif");                // УРАН - ВОДОЛЕЙ- AQUA
    auto aqua = this->scene.addPixmap(i11);
    aqua->setPos(w*0.1,h*0.13);
    aqua->setOpacity(OPACITY);

    QPixmap i12(":gif/pisces.gif");              // НЕПТУН - РЫБЫ - PISCES
    auto pisces = this->scene.addPixmap(i12);
    pisces->setPos(w*0.01,h/2.7);
    pisces->setOpacity(OPACITY);
}

bool GraphicsView::setGraphics()
{
    scene.clear();
    return 1;
}
