#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsSimpleTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent = 0); // initiates null pointer
    void increase();
    int getscore();

private:
    int m_score;
};

#endif // SCORE_H
