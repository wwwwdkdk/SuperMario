#ifndef MASTER_H
#define MASTER_H

#include<QMap>
#include<QVector>
#include<QString>
#include"mary.h"
#include"pipe.h"
#include"brick.h"

class Master {
public:
    QString direction;
    int die_state;
    Mary *mary;
    Pipe *pipe;
    Brick *brick;
    QVector <QVector<int>> v1;
    QMap<int, QVector<QVector < int>>> m;
    QVector<QVector < int>>::
    iterator itm;

    void Master_Init();

    void Master_State(Mary *m, Pipe *p, Brick *r);

    void Master_Move();

    Master();
};

#endif // MASTER_H
