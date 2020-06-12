#include "Enemy.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h> // rand() returns really large int
#include"Game.h"
#include<QMediaPlayer>
#include<QGraphicsPixmapItem>

extern Game * game;

Enemy::Enemy(){ // Bullet object added to scene in parent cpp file

    QMediaPlayer * woosh = new QMediaPlayer(); // declares new mediaplayer pointer
    woosh->setMedia(QUrl("qrc:/sounds/woosh.mp3")); // sets woosh mp3 file to woosh mediaplayer object
    woosh->play(); // plays woosh sound when enemy appears

    // set random position for enemy spawn
    int random_number = rand() % 700; // sets random number between 0-700

    setPos(random_number,0); // sets postion of enemy at random location somewhere at the top of the screen

   setPixmap(QPixmap(":/images/enemy"));

    // connect
    QTimer *timer = new QTimer(); // it's signal will execute when timer goes to 0

    // connect function connects signal to slot with syntax connect(objects w/ signal, SIGNAL(condition()), this(bullets contructor), SLOT(result()))
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); // sets timer's time to 50 milliseconds
}

void Enemy::move(){

    setPos(x(),y()+5);  // moves enemy down

    if (pos().y() > 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
