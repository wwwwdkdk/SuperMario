#ifndef CASTLE_H
#define CASTLE_H

#include<QMap>
#include<QVector>

class Castle {
public:
    QMap<int, QVector<QVector < int>>> m;
    void Castle_Init();
    QVector<int> v;
    QVector <QVector<int>> v1;
    Castle();
};

#endif // CASTLE_H
