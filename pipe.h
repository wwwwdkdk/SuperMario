#ifndef PIPE_H
#define PIPE_H

#include<QMap>
#include<QVector>

class Pipe {
public:
    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> short_m;
    QMap<int, QVector<QVector < int>>> long_m;

    void Pipe_Init();

    Pipe();
};

#endif // PIPE_H
