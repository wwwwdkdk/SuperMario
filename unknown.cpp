#include "unknown.h"
#include<iostream>

using namespace std;

Unknown::Unknown() {
    Unknown_Init();
}

void Unknown::Unknown_Init() {
    unknown_state = 0;
    coin_state = 0;
    coin = 0;
    int arr[38][3] = {{800,  350, 1},
                      {1050, 350, 2},
                      {1100, 200, 1},
                      {1150, 350, 1},
                      {3650, 350, 1},
                      {4450, 200, 1},
                      {5000, 350, 1},
                      {5150, 350, 2},
                      {5150, 200, 1},
                      {5300, 350, 1},
                      {6100, 200, 1},
                      {6150, 200, 1},
                      {7350, 350, 1},
                      {8400, 270, 1},
                      {8450, 270, 1},
                      {8500, 270, 1},
                      {8550, 270, 1},
                      {8600, 270, 1},
                      {8650, 270, 1},
                      {8700, 270, 1},
                      {8750, 270, 1},
                      {8800, 270, 1},
                      {8850, 270, 1},
                      {7800, 310, 1},
                      {8250, 150, 0},
                      {8300, 150, 0},
                      {7850, 310, 1},
                      {7900, 310, 1},
                      {7900, 270, 0},
                      {7950, 270, 0},
                      {8000, 270, 0},
                      {8000, 230, 0},
                      {8050, 230, 0},
                      {8100, 230, 0},
                      {8100, 190, 0},
                      {8150, 190, 0},
                      {8200, 190, 0},
                      {8200, 150, 0}};
    for (int i = 0; i < 38; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v.push_back(arr[i][2]);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
}


void Unknown::Unknown_State() {
    if (unknown_state == 750) {
        unknown_state = 0;
    }
    unknown_state += 50;
}


void Unknown::Unknown_crash(QVector < QVector < int >> ::iterator it){
    coin_state = 30;
    coin_x = *it->begin() + 10;
    coin_y = *(it->begin() + 1);
}

void Unknown::Crash_state() {

    if (coin_state > 0 && coin_state < 240) {
        cout << coin_y << endl;
        coin_state += 30;
        coin_y -= 20;
    } else if (coin_state == 240) {
        coin_state = 0;
    }
}
