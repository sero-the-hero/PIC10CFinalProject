#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include<QGraphicsItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem{ // originally derived from RectItem, must inherit from QObject to allow signal/slots use
    Q_OBJECT // must be added to allow a class to support signals and slots
  public:
    Bullet();
  public slots: // slot member functions must be put under public slot
    void move();
};

#endif // BULLET_H
