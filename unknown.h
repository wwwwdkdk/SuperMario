#ifndef UNKNOWN_H
#define UNKNOWN_H

#include<QMap>
#include<QVector>

class Unknown {
public:
    int coin;
    int coin_x;
    int coin_y;
    int unknown_state;
    int coin_state;
    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;

    Unknown();

    void Unknown_Init();

    void Unknown_State();

    void Crash_state();

    void Unknown_crash(QVector<QVector < int>>

    ::
    iterator it
    );
};

#endif // UNKNOWN_H
