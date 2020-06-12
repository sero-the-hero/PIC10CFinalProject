#include <QApplication>
// #include <qgraphicsscene.h>
#include "MyRect.h"
#include <qgraphicsview.h>
#include<QGraphicsScene>
#include<QTimer>
#include"Score.h"
#include<QMediaPlayer>
#include <QImage>
#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"

/*
Qt Notes
- QGraphicsScene: container for all gameobjects (character, trees, weapons, etc)
- QGraphicsItem: only QGraphicItems and subclasses can go inside scene
- QGraphicsView:  widget used to visualize scene
- QGraphicsItem (QGraphicsRectItem// inherits from QGraphics Item)
- events (keyPressEvent() and QKeyEvent) // reads user inputs during run only 1 item can respond to an event at a time, the focus item
- event propogation system // determines which object receives the event first and who does it pass it to and when the event has been handled so we can stop passing it around
- QDebug header file // used to print messages to console to test code/debug
- QTimer:
- signals and slots: slots receive signals to execute functions, for a class to use signal/slots must be derived from QObjects
- QObject inheritance and Q_ObJECT macro are required for signal/slot use
- folders in resource destintions are called prefixes
- to use Qmediaplayer, add multimedia module " \ endl multimedia"
- Qt provides two classes for displaying images, QPixMap and QImage. QPixMap is better for drawing on screen, QImage better for i/o and single pixels
*/

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); //  sets screen size to 800 x 600 when game starts

    setBackgroundBrush(QBrush(QImage(":/images/bg.PNG"))); // sets the background image

    // make the newly created scene the scene to visualize
    setScene(scene); // literally sets the scene
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // disables horizontal scrollbar
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // disables vertical scroll bar
    setFixedSize(800,600); // fixes the game screen to 800x600

    // create the player
    player = new MyRect();
    player->setPixmap(QPixmap(":/images/player")); // retrieves player image from q resource file

    player->setPos(350,500); // sets player to the bottom cetner of the screen when games starts
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable); // makes player focusable but IS NOT in focus
    player->setFocus(); // enables focus to the player

    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    score->setPos(0, 550); // places score on bottom left

    scene->addItem(score); // visualizes score

    health = new Health(); // creates health object

    health->setPos(450, 550); // places health on bottom right

    scene->addItem(health); // visualizes health

    // spawn enemies
    QTimer * timer = new QTimer(); // declares new qtimer pointer
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn())); // connects qtimer signal to spawn function slot
    timer->start(2500); // timer counts down repeatedly every 2500 ms

   // plays the background music
    QMediaPlayer * bgmusic = new QMediaPlayer(); // declares new mediaplayer pointer
    bgmusic->setMedia(QUrl("qrc:/sounds/bgmusic.mp3")); // sets bgmusic mp3 file to bgmusic mediaplayer object
    bgmusic->play(); // plays music on the game
    show();
}
