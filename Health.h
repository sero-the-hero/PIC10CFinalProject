#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsSimpleTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent = 0); // initiates null pointer, essentially making it an independent object
    void decrease();
    int getHealth();

private:
    int m_health;
};

#endif // SCORE_H
