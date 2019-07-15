#include "mywidget.h"
#include "mainwindow.h"
#include <iostream>
#include <cmath>
//#include <QPainter>

void MyWidget::p1(int x, int y, int x1, int y1, int level)
{
    if (level > 0)
    {
        p1( x,  y,  x + (x1 - x) / 3,  y + (y1 - y) / 3, level - 1);
        p1(x + 2*(x1 - x) / 3,  y + 2*(y1 - y) / 3, x1, y1, level - 1);
        p1(x + (x1 - x) / 3,y + (y1 - y) / 3, x + (x1 - x) / 3+ (x1-x)/3*0.5+(y1-y)*sqrt(3)/3/2, y + (y1 - y) / 3-(x1-x)*sqrt(3)/3/2+(y1-y)/6,  level - 1);
        p1(x + (x1 - x) / 3+ (x1-x)/3*0.5+(y1-y)*sqrt(3)/3/2,y + (y1 - y) / 3-(x1-x)*sqrt(3)/3/2+(y1-y)/6 ,x + 2*(x1 - x) / 3, y+ 2*(y1 - y) / 3, level-1);
    }
    else
    {
        QPainter painter(this);
        painter.drawLine(x, y, x1, y1);
    }

}
MyWidget::MyWidget(mainwindow *parent) : QWidget(parent)
{

    ab = parent;
    setFixedHeight(Y);
    setFixedWidth(X);
}

void MyWidget::slot2()
{
    setFixedHeight(ab->height());
    setFixedWidth(ab->width());
    repaint();
}
void MyWidget::paintEvent(QPaintEvent * event)
{

    int kek =std::min(1.0*width(), height() / sqrt(3)*6);
    p1(width() / 2 - kek / 2, height()/2+sqrt(3)*kek/12, width() / 2 + kek / 2, height()/2+sqrt(3)*kek/12, leveler);

}
void MyWidget::slot1(int a)
{
    leveler = a;
    repaint();
}

