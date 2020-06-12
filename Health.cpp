#include<Health.h>
#include<QFont>
#include<QMediaPlayer>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent) { // score item has Agraphics parent
    // initial health is 5
    m_health = 5;

    // Write the score text
    setPlainText("Health: ❒ ❒ ❒ ❒ ❒"); // displays health, each box represents 1hp
    setDefaultTextColor(Qt::green); // sets score display text to red
    setFont(QFont("times", 14)); // sets font style and size
}

void Health::decrease(){

    // plays planes crashing sound effect
    QMediaPlayer * crash = new QMediaPlayer(); // declares new mediaplayer pointer
    crash->setMedia(QUrl("qrc:/sounds/crash.mp3")); // sets crash mp3 file to bgmusic mediaplayer object
    crash->play(); // plays crash sound when health is lost
    m_health--;

    if (m_health == 4){
    setPlainText("Health: ❒ ❒ ❒ ❒"); // displays updated score,
    }
    else if (m_health == 3){
        setPlainText("Health: ❒ ❒ ❒"); // displays updated score

        setDefaultTextColor(Qt::darkYellow); // changes color to indicate damage level
        }
    else if (m_health == 2){
        setPlainText("Health: ❒ ❒"); // displays updated score
        setDefaultTextColor(Qt::darkYellow); // changes color to indicate damage level
        }
    else if (m_health == 1){
        setPlainText("Health: ❒"); // displays updated score
        setDefaultTextColor(Qt::red); // changes color to critical damage level

        }
    else if (m_health == 0){
        setPlainText("GAME OVER"); // indicate player has lost
        setPos(100,250);
        setFont(QFont("times", 40)); // sets font style and size

        QMediaPlayer * gameOver = new QMediaPlayer(); // declares new mediaplayer pointer
        gameOver->setMedia(QUrl("qrc:/sounds/gameOver.mp3")); // sets gameOver mp3 file to gameOver mediaplayer object
        gameOver->play(); // plays game over when all HP is gone
        }
}

int Health::getHealth(){
    return m_health;
}
