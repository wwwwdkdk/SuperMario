#ifndef Brick_H
#define Brick_H

#include<QMap>
#include<QVector>

class Brick {
public:
    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;
    int left_shatter_x;
    int left_shatter_y;
    int right_shatter_x;
    int right_shatter_y;
    int shatter_state;
    Brick();
    void BrickInit();
    void ShatterState();
    void BrickShatter(QVector<QVector <int>>::iterator it
    );
};

#endif // Brick_H
