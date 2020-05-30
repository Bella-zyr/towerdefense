#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <QMediaPlayer>
#include<iostream>
#include<QMediaPlaylist>
using namespace std;

World::~World(){
    delete this->_player;
}

void World::initWorld(string mapFile){
    //TODO ���������Ӧ�ø�Ϊ�ӵ�ͼ�ļ�װ��
    //player 5 5
    this->_player->initObj("player");
    this->_player->setPosX(14);
    this->_player->setPosY(28);

    RPGObj *p1 = new RPGObj;
    p1->initObj("stone");
    p1->setPosX(4);
    p1->setPosY(12);

    RPGObj *p2 = new RPGObj;
    p2->initObj("stone");
    p2->setPosX(4);
    p2->setPosY(13);

    vector<RPGObj*> q;
    for(int i=0;i<7;i++)
    {
        q.push_back(new RPGObj);
        q[i]->initObj("stone");
        q[i]->setPosX(4);
        q[i]->setPosY(i+4);
    }

    RPGObj *p3 = new RPGObj;
    p3->initObj("stone");
    p3->setPosX(4);
    p3->setPosY(11);

    this->_objs.push_back(p1);
    this->_objs.push_back(p2);
    this->_objs.push_back(p3);
    for(int i=0;i<7;i++)
    {
        this->_objs.push_back(q[i]);
    }

     //QMediaPlaylist * playlist = new QMediaPlaylist;
    //playlist->setCurrentlndex(1);
    //playlist->setPlaybackMode(QMediaPlaylist::CurrentltemlnLoop);
    QMediaPlayer * player = new QMediaPlayer;
   // player->setPlaylist(playlist);
    player->setMedia(QUrl("qrc:/sounds/yin.mp3"));
    player->setVolume(30);
    player->play();


}


void World::show(QPainter * painter){
    int n = this->_objs.size();
    for (int i=0;i<n;i++){
        this->_objs[i]->show(painter);
    }
    this->_player->show(painter);



}

void World::eraseObj(int x, int y){
    vector<RPGObj*>::iterator it;
    it = _objs.begin();
    while(it!=_objs.end()){
        int flag1 = ((*it)->getObjType()!="stone"); //����ʯͷ
        int flag2 = ((*it)->getPosX() == x) && ((*it)->getPosY()==y);//λ���ص�

        if (flag1 && flag2){
            cout<<(*it)->getObjType()<<endl;
            (*it)->onErase();
            delete (*it);
            it = this->_objs.erase(it);
            break;
         }
        else{
            it++;
        }
    }

}

void World::handlePlayerMove(int direction, int steps){
    int x =  this->_player->getNextX(direction);
    int y = this->_player->getNextY(direction);
    this->eraseObj(x,y);
    this->_player->move(direction, steps);
}

