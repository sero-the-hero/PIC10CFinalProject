#include<Score.h>
#include<QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) { // score item has Agraphics parent
    // initial score is 0
    m_score = 0;

    // Write the score text
    setPlainText("Score: " + QString::number(m_score)); // displays score, QString::number casts integer as string
    setDefaultTextColor(Qt::red); // sets score display text to red
    setFont(QFont("times", 14)); // sets font style and size
}

void Score::increase(){
    m_score++;
    setPlainText("Score: " + QString::number(m_score)); // displays updated score, QString::number casts integer as string
}

int Score::getscore(){
    return m_score;
}
