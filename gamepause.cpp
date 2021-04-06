#include "gamepause.h"
#include<QKeyEvent>
#include"mypushbutton.h"
#include<QTimer>
#include<QPainter>

GamePause::GamePause() {
    this->setWindowTitle("游戏暂停");
    this->setFixedSize(200, 240);
    this->setWindowModality(Qt::ApplicationModal);

}

void GamePause::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Escape:
            break;
        default:
            QDialog::keyPressEvent(event);
    }

}

void GamePause::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/photo/dlg.png"));
}
