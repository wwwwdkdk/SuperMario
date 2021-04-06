#ifndef MUSHROOM_H
#define MUSHROOM_H
#include<QVector>
#include<QMap>
#include"brick.h"
#include"unknown.h"
#include"mary.h"
class MushRoom
{
public:
    QMap<int,QVector<QVector<int>>>m;
    int mushroom_kind;
    int mushroom_x;
    int mushroom_y;
    int mushroom_state;
    int mushroom_fall_down_distance;
    Brick *brick;
    Unknown *unknown;
    Mary *mary;
    MushRoom();
    void MushRoom_Init();
    void Move_state();
    void MushRoom_Move(QVector<QVector<int>>::iterator it,Unknown *u,Brick *r, Mary *m);
};

#endif // MUSHROOM_H
