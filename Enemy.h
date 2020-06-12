#ifndef ENEMY_H
#define ENEMY_H

#include<QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem{ // originally derived from RectItem, must inherit from QObject to allow signal/slots use
    Q_OBJECT // must be added to allow a class to support signals and slots
  public:
    Enemy();
  public slots: // slot member functions must be put under public slot
    void move();
};

#endif // BULLET_H
