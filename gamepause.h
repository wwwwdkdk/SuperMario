#ifndef GAMEPAUSE_H
#define GAMEPAUSE_H

#include <QWidget>
#include<QDialog>

class GamePause : public QDialog {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *);
    GamePause();
    signals:

};

#endif // GAMEPAUSE_H
