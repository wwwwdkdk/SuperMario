#include "brick.h"
#include<iostream>

using namespace std;

Brick::Brick() {

    BrickInit();
}

void Brick::BrickInit() {
    shatter_state = 0;
    int arr[51][2] = {{1000, 350},
                      {1100, 350},
                      {1200, 350},
                      {3200, 350},
                      {3250, 350},
                      {3600, 350},
                      {3700, 350},
                      {3750, 200},
                      {3800, 200},
                      {3850, 200},
                      {3900, 200},
                      {3950, 200},
                      {4000, 200},
                      {4050, 200},
                      {4300, 200},
                      {4350, 200},
                      {4400, 200},
                      {4450, 350},
                      {4750, 350},
                      {4800, 350},
                      {5600, 350},
                      {5750, 200},
                      {5800, 200},
                      {5850, 200},
                      {6050, 200},
                      {6100, 350},
                      {6150, 350},
                      {6200, 350},
                      {6400, 460},
                      {6450, 460},
                      {6500, 460},
                      {6550, 460},
                      {6700, 460},
                      {6750, 460},
                      {6800, 460},
                      {6850, 460},
                      {6450, 420},
                      {6500, 420},
                      {6550, 420},
                      {6700, 420},
                      {6750, 420},
                      {6800, 420},
                      {6500, 380},
                      {6550, 380},
                      {6700, 380},
                      {6750, 380},
                      {6550, 340},
                      {6700, 340},
                      {7250, 350},
                      {7300, 350},
                      {7400, 350},
    };

    for (int i = 0; i < 51; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v.push_back(1);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
}

void Brick::BrickShatter(QVector < QVector < int >> ::iterator
it)
{
left_shatter_x = *it->begin();
right_shatter_x = *it->begin() + 20;
left_shatter_y = right_shatter_y = *(it->begin() + 1);
shatter_state = 1;

}


void Brick::ShatterState() {
    if (shatter_state == 0) {
        return;
    }
    if (shatter_state > 0 && shatter_state < 10) {
        left_shatter_x -= 20 - shatter_state;
        right_shatter_x += 20 - shatter_state;
        left_shatter_y -= 20 - shatter_state;
        right_shatter_y -= 20 - shatter_state;
        shatter_state++;
    } else if (shatter_state >= 10 && left_shatter_y < 500) {
        left_shatter_y += shatter_state;
        right_shatter_y += shatter_state;
        shatter_state++;
    } else if (left_shatter_y >= 500) {
        left_shatter_x = right_shatter_x = left_shatter_y = right_shatter_y = 0;
        shatter_state = 0;
    }
}
