#include "pipe.h"

Pipe::Pipe() {
    Pipe_Init();
}

void Pipe::Pipe_Init() {
    int arr_long[4][2] = {{1800, 400},
                          {2100, 400},
                          {2400, 400},
                          {2700, 400}};
    int arr_short[3][2] = {{1500, 450},
                           {7100, 450},
                           {7650, 450}};
    for (int i = 0; i < 4; i++) {
        v.push_back(arr_long[i][0]);
        v.push_back(arr_long[i][1]);
        v2.push_back(v);
        v.clear();
    }
    long_m.insert(1, v2);
    v2.clear();
    for (int i = 0; i < 3; i++) {
        v.push_back(arr_short[i][0]);
        v.push_back(arr_short[i][1]);
        v2.push_back(v);
        v.clear();
    }
    short_m.insert(1, v2);
    v2.clear();
}
