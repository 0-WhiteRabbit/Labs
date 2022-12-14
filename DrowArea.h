#ifndef LAB_4_DROWAREA_H
#define LAB_4_DROWAREA_H


#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QDebug>
#include "Landscape.h"

class DrawArea : public QWidget
{
Q_OBJECT

public:
    DrawArea(Landscape *_landscape, QWidget *parent = nullptr);
    int phase = 0;
    void PressEvent(QKeyEvent * event);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void draw_Forest(int x, int y, QPainter &painter);
    void draw_Land(int x, int y, QPainter &painter);
    void draw_Road(int x, int y, QPainter &painter);
    void draw_help_message(QPainter &painter);
    void draw_Castle(int x, int y, QPainter &painter);
    void draw_Lair(int x, int y, QPainter &painter);
    void draw_Enemy(int x, int y, QPainter &painter, int hill);
    void draw_MagicTrap(int x, int y, QPainter &painter);
    void draw_SimpleTower(int x, int y, QPainter &painter);
    void draw_MagicTower(int x, int y, QPainter &painter);

    const int dx=5, dy=5, da = 60;
    int n, m;

    int choose_x=-1, choose_y=-1;

    Landscape *landscape;
};


#endif //LAB_4_DROWAREA_H
