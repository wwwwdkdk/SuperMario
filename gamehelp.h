#ifndef GAMEHELP_H
#define GAMEHELP_H

#include <QMainWindow>
#include <QWidget>
#include<QPainter>

class GameHelp : public QWidget {
    Q_OBJECT
public:
    explicit GameHelp(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    signals:
            void back();
};

#endif // GAMEHELP_H
