#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QObject>
#include<QPushButton>
#include<QString>
#include<QPropertyAnimation>

class MyPushButton : public QPushButton {
    Q_OBJECT
public:
    MyPushButton(QString normalImg);

    QString normalImgPath;

    void zoom1();

    void zoom2();

    signals:

};

#endif // MYPUSHBUTTON_H
