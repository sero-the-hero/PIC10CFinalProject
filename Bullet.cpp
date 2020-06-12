#include "Bullet.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<Enemy.h>
#include<Score.h>
#include<Game.h>
#include<QMediaPlayer>
#include<QGraphicsPixmapItem>


extern Game * game; // allows game type game pointer to be accessed from the global declaration

Bullet::Bullet(): QObject(), QGraphicsPixmapItem(){ // Bullet object added to scene in parent cpp file

    QMediaPlayer * shoot = new QMediaPlayer(); // declares new mediaplayer pointer
    shoot->setMedia(QUrl("qrc:/sounds/shoot.mp3")); // sets shoot mp3 file to shoot mediaplayer object
    shoot->play(); // plays shoot sound when bullet is shot

    setPixmap(QPixmap(":/images/bullet.png")); //


    // connect
    QTimer *timer = new QTimer(); // it's signal will execute when timer goes to 0

    // connect function connects signal to slot with syntax connect(objects w/ signal, SIGNAL(condition()), this(bullets contructor), SLOT(result()))
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); // sets timer's time to 50 milliseconds
}

void Bullet::move(){
// check for collision. will destroy enemy and bullet
    QList<QGraphicsItem *> colliding_items = collidingItems(); // collidingitems member function returns list of pointers to colliding items

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){// dereference current pointer and checks if it enemy object

            QMediaPlayer * boom = new QMediaPlayer(); // declares new mediaplayer pointer
            boom->setMedia(QUrl("qrc:/sounds/boom.mp3")); // sets boom mp3 file to boom mediaplayer object
            boom->play(); // plays boom sound when plane is shot down is lost

            // increases player score
            game->score->increase();
            // both are removed
            scene()->removeItem(colliding_items[i]); // enemy is removed first
            scene()->removeItem(this); // bullet is removed next
            // they are removed from scene BUT NOT DELETED FROM MEMORY at this point
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);  // moves bullet up
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
