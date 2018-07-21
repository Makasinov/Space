#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent)
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
    QRect rec = QApplication::desktop()->screenGeometry();
    this->setGeometry(0,0,rec.height()*0.9,rec.height()*0.9);
    this->setWindowTitle(tr("Карта созвездий"));
}

void GraphicsView::getXY(double * x, double * y,
                         const int angle,
                         const int ECLIPSE_RADIUSX,
                         const int ECLIPSE_RADIUSY)
{
    int w = this->size().width();
    int h = this->size().height();
    *(x) = cos(2 * M_PI * angle / 360) * ECLIPSE_RADIUSX + w/2 - 2;
    *(y) = sin(2 * M_PI * angle / 360) * ECLIPSE_RADIUSY + h/2 - 2;
    correctXY(angle,x,y,w,h);
}

void GraphicsView::correctXY(const int angle,
                             double * x,
                             double * y,
                             const int w,
                             const int h)
{
    if (angle <= 10)
    {
        (*x) -= w * 0.03;
        (*y) -= h * 0.01;
    }
    else if (angle <= 20)
    {
        (*x) -= w * 0.025;
        (*y) -= h * 0.008;
    }
    else if (angle <= 30)
    {
        (*x) -= w * 0.028;
        (*y) -= h * 0.01;
    }
    else if (angle <= 40)
    {
        (*x) -= w * 0.028;
        (*y) -= h * 0.01;
    }
    else if (angle <= 50)
    {
        (*x) -= w * 0.028;
        (*y) -= h * 0.015;
    }
    else if (angle <= 60)
    {
        (*x) -= w * 0.01;
        (*y) -= h * 0.03;
    }
    else if (angle <= 70)
    {
        (*x) -= w * 0.01;
        (*y) -= h * 0.03;
    }
    else if (angle <= 80)
    {
        (*x) -= w * 0.01;
        (*y) -= h * 0.03;
    }
    else if (angle <= 100)
    {
        (*y) -= h * 0.025;
    }
    else if (angle <= 110)
    {
        (*x) += w * 0.01;
        (*y) -= h * 0.02;
    }
    else if (angle <= 120)
    {
        (*x) += w * 0.01;
        (*y) -= h * 0.025;
    }
    else if (angle <= 130)
    {
        (*x) += w * 0.005;
        (*y) -= h * 0.019;
    }
    else if (angle <= 140)
    {
        (*x) += w * 0.015;
        (*y) -= h * 0.005;
    }
    else if (angle <= 160)
    {
        (*x) += w * 0.005;
        (*y) -= h * 0.01;
    }
    else if (angle <= 170)
    {
        (*x) += w * 0.005;
    }
    else if (angle >= 280)
    {
        if (angle <= 290)
        {
            (*x) -= w * 0.005;
            (*y) += h * 0.005;
        }
        else if (angle <= 320)
        {
            (*x) -= w * 0.01;
            (*y) += h * 0.005;
        }
        else if (angle <= 330)
        {
            (*x) -= w * 0.018;
            (*y) += h * 0.005;
        }
        else if (angle <= 340)
        {
            (*x) -= w * 0.02;
            (*y) += h * 0.005;
        }
        else if (angle <= 350)
        {
            (*x) -= w * 0.025;
            (*y) += h * 0.005;
        }
        else if (angle <= 360)
        {
            (*x) -= w * 0.027;
        }
    }
}

QPoint GraphicsView::getEllipse(const int angle = 0)
{
    int w = this->size().width();
    int h = this->size().height();
    int varW = ( ( w - w / 4 ) / 2 );
    int varH = ( ( h - h / 4 ) / 2 );
    const double ECLIPSE_RADIUSX = varW - w * 0.002;       //
    const double ECLIPSE_RADIUSY = varH - h * 0.002;       //
    int x = cos(2 * M_PI * angle / 360) * ECLIPSE_RADIUSX + w / 2 - 2;
    int y = sin(2 * M_PI * angle / 360) * ECLIPSE_RADIUSY + h / 2 - 2;
    return QPoint(x,y);
}

int GraphicsView::getEllipse(double * x, double * y,const QChar planetSymbol, const int number)
{
    int w = this->size().width();
    int h = this->size().height();
    int varW = ( ( w - w / 4 ) / 2 );
    int varH = ( ( h - h / 4 ) / 2 );

    const double ECLIPSE_RADIUSX1 = varW - w * 0.002;       // 1 круг
    const double ECLIPSE_RADIUSY1 = varH - h * 0.002;       // 2 круг

    const double ECLIPSE_RADIUSX2 = varW - w * 0.035;       // 2 круг
    const double ECLIPSE_RADIUSY2 = varH - h * 0.035;       // 2 круг

    const double ECLIPSE_RADIUSX3 = varW - w * 0.075;       // 3 круг
    const double ECLIPSE_RADIUSY3 = varH - h * 0.075;       // 3 круг

    const double ECLIPSE_RADIUSX4 = varW - w * 0.107;       // 4 круг
    const double ECLIPSE_RADIUSY4 = varH - h * 0.107;       // 4 круг

    const double ECLIPSE_RADIUSX5 = varW - w * 0.145;       // 5 круг
    const double ECLIPSE_RADIUSY5 = varH - h * 0.145;       // 5 круг

    const double ECLIPSE_RADIUSX6 = varW - w * 0.18;        // 6 круг
    const double ECLIPSE_RADIUSY6 = varH - h * 0.18;        // 6 круг

    const double ECLIPSE_RADIUSX7 = varW - w * 0.215;       // 7 круг
    const double ECLIPSE_RADIUSY7 = varH - h * 0.215;       // 7 круг

    QChar zodiacSymbol = correctSymbol(number);
    if (zodiacSymbol == ' ')
    {
        QMessageBox::warning(this,"Ошибка","Ошибка составления карты - 0089");
        return -1;
    }
    for(int i = 1; i < 8; i++)
    {
        for(int j = 1; j < 13; j++)
        {
            if ( distanceArray[i][j].contains(zodiacSymbol,Qt::CaseSensitive) &&
                 distanceArray[0][j] == planetSymbol )
            {
                int number = distanceArray[i][0].toInt();
                switch( number )
                {
                case 0:
                    (*x) = ECLIPSE_RADIUSX1;
                    (*y) = ECLIPSE_RADIUSY1;
                    break;
                case 1:
                    (*x) = ECLIPSE_RADIUSX2;
                    (*y) = ECLIPSE_RADIUSY2;
                    break;
                case 2:
                    (*x) = ECLIPSE_RADIUSX3;
                    (*y) = ECLIPSE_RADIUSY3;
                    break;
                case 3:
                    (*x) = ECLIPSE_RADIUSX4;
                    (*y) = ECLIPSE_RADIUSY4;
                    break;
                case 4:
                    (*x) = ECLIPSE_RADIUSX5;
                    (*y) = ECLIPSE_RADIUSY5;
                    break;
                case 5:
                    (*x) = ECLIPSE_RADIUSX6;
                    (*y) = ECLIPSE_RADIUSY6;
                    break;
                case 6:
                    (*x) = ECLIPSE_RADIUSX7;
                    (*y) = ECLIPSE_RADIUSY7;
                    break;
                }
            }
        }
    }
    return number;
}

QChar GraphicsView::correctSymbol(const int number)
{
    switch(number)
    {
    case 1:
        return 'A'; // СОЛНЦЕ
    case 2:
        return 'B'; // ЛУНА
    case 3:
        return 'C'; // МЕРКУРИЙ
    case 4:
        return 'D'; // ВЕНЕРА
    case 5:
        return 'E'; // МАРС
    case 6:
        return 'F'; // ЮПИТЕР
    case 7:
        return 'G'; // САТУРН
    case 8:
        return 'O'; // УРАН
    case 9:
        return 'I'; // НЕПТУН
    case 10:
        return 'J'; // ПЛУТОН
    default:
        return '?';
    }
}

void GraphicsView::setParams(int number, QGraphicsPixmapItem * planet)
{
    QString dataString = this->table->item(0,number+1)->text();
    QChar symbol = dataString.at(dataString.length()-1);
    QVector<QChar> vec = {'a','b','c','d','e','f','g','h','i','j','k','l'};
    if (planet == NULL || !vec.contains(symbol.toLatin1()))
    {
        QMessageBox::warning(this,"Ошибка","Ошибка составления карты - 0180");
        qDebug() << "Error in if statement -> " << planet << "\n-> " << symbol;
        return;
    }
    int h = this->size().height();
    int w = this->size().width();
    double x = 0, y = 0;
    double radiusX = 0,radiusY = 0;
    int angle = 176;
    switch (symbol.toLatin1()) {
    case 'a':           // ОВЕН
        angle = 176;    // 154
        break;
    case 'b':           // ТЕЛЕЦ
        angle = 149;    // 120
        break;
    case 'c':           // БЛИЗНЕЦЫ
        angle = 114;     // 94
        break;
    case 'd':           // РАК
        angle = 90;     // 70
        break;
    case 'e':           // ЛЕВ
        angle = 65;     // 24
        break;
    case 'f':           // ДЕВА
        angle = 19;     // 0
        break;
    case 'g':           // ВЕСЫ
        angle = 359;    // 334
        break;
    case 'h':           // СКОРПИОН
        angle = 328;    // 299
        break;
    case 'i':           // СТРЕЛЕЦ
        angle = 290;    // 270
        break;
    case 'j':           // КОЗЕРОГ
        angle = 265;    // 245
        break;
    case 'k':           // ВОДОЛЕЙ
        angle = 239;    // 211
        break;
    case 'l':           // РЫБЫ
        angle = 205;    // 183
        break;
    }

    //angle = 360;                                     // ТЕСТ ПОТОМ УДАЛИТЬ

    QString mid = dataString;
    int pos = 0;
    for(auto it = mid.begin(); (*it).isNumber(); it++, pos++ );
    mid = mid.mid(0,pos);
    bool Retragrad = false;
    if (dataString.at(dataString.length()-2) == 'R') Retragrad = true;
    int degree = 0;
    if (!Retragrad) degree = mid.toInt();
        else degree = (30 - mid.toInt());
    degree *= 0.68;
    angle -= degree;

    int circle = getEllipse(&radiusX,&radiusY,symbol,number);
    getXY(&x,&y,angle,radiusX,radiusY);
    planet->setPos(x,y);
    planet->setScale(h>w?w * 0.0006:h * 0.0006);
    int width  = planet->pixmap().widthMM();
    int heigth = planet->pixmap().heightMM();
    drawLineToPlanet(planet->pos().toPoint(),
                     angle,
                     width,
                     heigth);
    planet->setZValue(1);
}

void GraphicsView::drawLineToPlanet(const QPoint planetPos,
                                    const int angle,
                                    const int width,
                                    const int heigth)
{
    QPoint point = getEllipse(angle);
    QGraphicsLineItem * line = this->scene.addLine(
                point.x(),
                point.y(),
                planetPos.x() + heigth,
                planetPos.y() + width,
                QPen(Qt::lightGray));
    line->setZValue(0);
}

void GraphicsView::drawSpacePlanets()
{
    QPixmap pixmap(":gif/sun.png");
    //QPixmap pixmap(SQUARE_PATH);
    sun = this->scene.addPixmap(pixmap);
    setParams(1,sun);
    sun->setToolTip("Солнце");

    pixmap.load(":gif/moon.png");                         // ТЕСТ ПОТОМ ПОУДАЛЯТЬ ВСЕ
    moon = this->scene.addPixmap(pixmap);
    setParams(2,moon);
    moon->setToolTip("Луна");

    pixmap.load(":gif/mercury.png");
    mercury = this->scene.addPixmap(pixmap);
    setParams(3,mercury);
    mercury->setToolTip("Меркурий");

    pixmap.load(":gif/venus.png");
    venus = this->scene.addPixmap(pixmap);
    setParams(4,venus);
    venus->setToolTip("Венера");

    pixmap.load(":gif/mars.png");
    mars = this->scene.addPixmap(pixmap);
    setParams(5,mars);
    mars->setToolTip("Марс");

    pixmap.load(":gif/jupiter.png");
    jupiter = this->scene.addPixmap(pixmap);
    setParams(6,jupiter);
    jupiter->setToolTip("Юпитер");

    pixmap.load(":gif/saturn.png");
    saturn= this->scene.addPixmap(pixmap);
    setParams(7,saturn);
    saturn->setToolTip("Сатурн");

    pixmap.load(":gif/uranus.png");
    uranus = this->scene.addPixmap(pixmap);
    setParams(8,uranus);
    uranus->setToolTip("Уран");

    pixmap.load(":gif/neptune.png");
    neptune = this->scene.addPixmap(pixmap);
    setParams(9,neptune);
    neptune->setToolTip("Нептун");

    pixmap.load(":gif/pluto.png");
    pluto = this->scene.addPixmap(pixmap);
    setParams(10,pluto);
    pluto->setToolTip("Плутон");
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
                                 ECLIPSE_SIZEY,QPen(),QBrush(Qt::lightGray,Qt::Dense4Pattern));
    auto ecl2 = scene.addEllipse(ECLIPSE_CORDX+w*0.035,
                                 ECLIPSE_CORDY+h*0.035,
                                 ECLIPSE_SIZEX-w*0.07,
                                 ECLIPSE_SIZEY-h*0.07,QPen(Qt::gray),QBrush(Qt::white));
    auto ecl3 = scene.addEllipse(ECLIPSE_CORDX+w*0.07,
                                 ECLIPSE_CORDY+h*0.07,
                                 ECLIPSE_SIZEX-w*0.14,
                                 ECLIPSE_SIZEY-h*0.14,QPen(Qt::gray),QBrush(Qt::lightGray,Qt::Dense4Pattern));
    auto ecl4 = scene.addEllipse(ECLIPSE_CORDX+w*0.105,
                                 ECLIPSE_CORDY+h*0.105,
                                 ECLIPSE_SIZEX-w*0.21,
                                 ECLIPSE_SIZEY-h*0.21,QPen(Qt::gray),QBrush(Qt::white));
    auto ecl5 = scene.addEllipse(ECLIPSE_CORDX+w*0.14,
                                 ECLIPSE_CORDY+h*0.14,
                                 ECLIPSE_SIZEX-w*0.28,
                                 ECLIPSE_SIZEY-h*0.28,QPen(Qt::gray),QBrush(Qt::lightGray,Qt::Dense4Pattern));
    auto ecl6 = scene.addEllipse(ECLIPSE_CORDX+w*0.175,
                                 ECLIPSE_CORDY+h*0.175,
                                 ECLIPSE_SIZEX-w*0.35,
                                 ECLIPSE_SIZEY-h*0.35,QPen(Qt::gray),QBrush(Qt::white));
    auto ecl7 = scene.addEllipse(ECLIPSE_CORDX+w*0.21,
                                 ECLIPSE_CORDY+h*0.21,
                                 ECLIPSE_SIZEX-w*0.42,
                                 ECLIPSE_SIZEY-h*0.42,QPen(Qt::gray),QBrush(Qt::lightGray,Qt::Dense4Pattern));
    auto ecl8 = scene.addEllipse(ECLIPSE_CORDX+w*0.245,
                                 ECLIPSE_CORDY+h*0.245,
                                 ECLIPSE_SIZEX-w*0.49,
                                 ECLIPSE_SIZEY-h*0.49,QPen(Qt::gray),QBrush(Qt::white));
    scene.addLine(0,h/2,w,h/2);
    scene.addLine(w/2,0,w/2,h);

    scene.addLine(0,h/5,w,h-(h/5));
    scene.addLine(w/5,0,w-(w/5),h);
    scene.addLine(w-w/5,0,w/5,h);
    scene.addLine(w,h/5,0,h-h/5);
}

void GraphicsView::drawPlanets()
{
    int w = this->size().width();
    int h = this->size().height();

    QPixmap i1(":gif/uran2.gif");
    QGraphicsPixmapItem * sun = this->scene.addPixmap(i1);
    sun->setPos(w/4,h/4);
    sun->setOpacity(OPACITY_1);

    QPixmap i2(":gif/pluto.gif");
    QGraphicsPixmapItem * mercury = this->scene.addPixmap(i2);
    mercury->setPos(w-w/2.8,h/4);
    mercury->setOpacity(OPACITY_1);

    QPixmap i3(":gif/sun.gif");
    QGraphicsPixmapItem * leo = this->scene.addPixmap(i3);
    leo->setPos(w-w/2.8,h-h/2.8);
    leo->setOpacity(OPACITY_1);

    QPixmap i4(":gif/venus.gif");
    QGraphicsPixmapItem * taurus = this->scene.addPixmap(i4);
    taurus->setPos(w/4,h-h/2.8);
    taurus->setOpacity(OPACITY_1);

    QPixmap i5(":gif/neptun1.gif");
    QGraphicsPixmapItem * mars = this->scene.addPixmap(i5);
    mars->setPos(w/6,h/2.55);
    mars->setOpacity(OPACITY_1);

    QPixmap i6(":gif/venus.gif");
    QGraphicsPixmapItem * jupiter = this->scene.addPixmap(i6);
    jupiter->setPos(w/1.36,h/2.55);
    jupiter->setOpacity(OPACITY_1);

    QPixmap i7(":gif/mercury.gif");
    QGraphicsPixmapItem * saturn = this->scene.addPixmap(i7);
    saturn->setPos(w/1.36,h/2);
    saturn->setOpacity(OPACITY_1);

    QPixmap i8(":gif/mars.gif");
    QGraphicsPixmapItem * aries = this->scene.addPixmap(i8);
    aries->setPos(w/6,h/2);
    aries->setOpacity(OPACITY_1);

    QPixmap i9(":gif/saturn.gif");
    QGraphicsPixmapItem * neptun = this->scene.addPixmap(i9);
    neptun->setPos(w/2.5,h/4.8);
    neptun->setOpacity(OPACITY_1);

    QPixmap i10(":gif/mercury.gif");
    QGraphicsPixmapItem * gemini = this->scene.addPixmap(i10);
    gemini->setPos(w/2.5,h/1.4);
    gemini->setOpacity(OPACITY_1);

    QPixmap i11(":gif/jupiter.gif");
    QGraphicsPixmapItem * comet = this->scene.addPixmap(i11);
    comet->setPos(w/2,h/4.8);
    comet->setOpacity(OPACITY_1);

    QPixmap i12(":gif/moon.gif");
    QGraphicsPixmapItem * cancer = this->scene.addPixmap(i12);
    cancer->setPos(w/2,h/1.4);
    cancer->setOpacity(OPACITY_1);
}

void GraphicsView::drawSigns()
{
    int w = this->size().width();
    int h = this->size().height();

    QPixmap i1(":gif/aries.gif");               // МАРС - ОВЕН - ARIES
    auto aries = this->scene.addPixmap(i1);
    aries->setPos(w*0.01,h/1.8);
    aries->setOpacity(OPACITY_3);

    QPixmap i2(":gif/taurus.gif");              // ВЕНЕРА - ТЕЛЕЦ - TAURUS
    auto taurus = this->scene.addPixmap(i2);
    taurus->setPos(w*0.1,h*0.77);
    taurus->setOpacity(OPACITY_3);

    QPixmap i3(":gif/gemini.gif");              // МЕРКУРИЙ - БЛИЗНЕЦЫ - GEMINI
    auto gemini = this->scene.addPixmap(i3);
    gemini->setPos(w/2.8,h-60);
    gemini->setOpacity(OPACITY_3);

    QPixmap i4(":gif/cancer.gif");              // ЛУНА - РАК - CANCER
    auto cancer = this->scene.addPixmap(i4);
    cancer->setPos(w/1.8,h-60);
    cancer->setOpacity(OPACITY_3);

    QPixmap i5(":gif/leo.gif");                 // СОЛНЦЕ - ЛЕВ - LEO
    auto leo = this->scene.addPixmap(i5);
    leo->setPos(w-w*0.15,h*0.77);
    leo->setOpacity(OPACITY_3);

    QPixmap i6(":gif/virgo.gif");               // МЕРКУРИЙ - ДЕВА - VIRGO
    auto virgo = this->scene.addPixmap(i6);
    virgo->setPos(w-60,h/1.8);
    virgo->setOpacity(OPACITY_3);

    QPixmap i7(":gif/libra.gif");               // ВЕНЕРА - ВЕСЫ - LIBRA
    auto libra = this->scene.addPixmap(i7);
    libra->setPos(w-60,h/2.7);
    libra->setOpacity(OPACITY_3);

    QPixmap i8(":gif/scorpio.gif");             // ПЛУТОН - СКОРПИОН - SCORPIO
    auto scorpio = this->scene.addPixmap(i8);
    scorpio->setPos(w-w*0.2,h/9);
    scorpio->setOpacity(OPACITY_3);

    QPixmap i9(":gif/sagittar.gif");             // ЮПИТЕР - СТРЕЛЕЦ - SAGITTAR
    auto sagittar = this->scene.addPixmap(i9);
    sagittar->setPos(w/1.8,10);
    sagittar->setOpacity(OPACITY_3);

    QPixmap i10(":gif/capricor.gif");            // САТУРН - КОЗЕРОГ - CAPRICOR
    auto capricor = this->scene.addPixmap(i10);
    capricor->setPos(w/2.8,10);
    capricor->setOpacity(OPACITY_3);

    QPixmap i11(":gif/aqua.gif");                // УРАН - ВОДОЛЕЙ- AQUA
    auto aqua = this->scene.addPixmap(i11);
    aqua->setPos(w*0.1,h*0.13);
    aqua->setOpacity(OPACITY_3);

    QPixmap i12(":gif/pisces.gif");              // НЕПТУН - РЫБЫ - PISCES
    auto pisces = this->scene.addPixmap(i12);
    pisces->setPos(w*0.01,h/2.7);
    pisces->setOpacity(OPACITY_3);
}

bool GraphicsView::setGraphics()
{
    scene.clear();
    return 1;
}
