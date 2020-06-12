#ifndef MYRECT_H
#define MYRECT_H

#include<QGraphicsRectItem> // inheriting from
#include<QGraphicsPixmapItem>

class MyRect: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    void keyPressEvent(QKeyEvent *event); // Allows rectangle object to repspond to key presses

public slots:
    void spawn(); // spawn slot connected to timer, to periodically spawn enemies at the top of the screen
};


#endif // MYRECT_H
// @8:49 pt5
