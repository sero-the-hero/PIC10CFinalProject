#include "MyRect.h"
#include<qgraphicsscene.h>
#include<QKeyEvent> // allows access of ->key() member function
#include "Bullet.h" // alllows access to bullet child class
#include"Enemy.h" // allows access to Enenmy child class
#include"Game.h"

extern Game * game;

void MyRect::keyPressEvent(QKeyEvent *event){ // member funciton that is called in response to keys being pressed

    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A){ // checks if left key was pressed
        if (game->health->getHealth()){
        if (pos().x() > 0){ // checks if player is passing left boundaries
        setPos(x()-10,y());
        }
       }
    }

    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D){ // checks if right key was pressed
        if (game->health->getHealth()){
        if(pos().x() + 100 < 800){ // checks if player is passing right boundaries
        setPos(x()+10,y());
        }
        }
    }

    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W){ // checks if left up was pressed
        if (game->health->getHealth()){
        if (pos().y() > 0){ // checks if player is passing upper bounds
        setPos(x(),y()-10);
        }
       }
    }

    else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S){ // checks if down key was pressed
        if (game->health->getHealth()){
        if (pos().y()+100 < 600){ // checks if player is passing lower bounds
        setPos(x()+10,y()+10);
        }
       }
    }

    else if (event->key() == Qt::Key_Space){ // if space is pressed, bullet is created/fired
        //
        Bullet * bullet = new Bullet(); // creates new bullet NOT added to scene yet
        bullet->setPos(x(),y()); // sets bullet at same position as rectangle (center)
        scene()->addItem(bullet); // adds bullet to scene when created
    }

}

void MyRect::spawn()
{
    // creates enemy
   Enemy *enemy = new Enemy();

   // adds enemy to the scene
   scene()->addItem(enemy);
}
