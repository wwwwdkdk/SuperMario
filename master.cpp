#include "master.h"
#include"mary.h"
#include"QDebug"

Master::Master() {
    Master_Init();
}


void Master::Master_Init() {
    die_state = 0;
    direction = "left";
    QVector<int> v;
    int arr[10][2] = {{2370, 460},
                      {2670, 460},
                      {3000, 460},
                      {3200, 460},
                      {3230, 460},
                      {3600, 460},
                      {4000, 460},
                      {4500, 460},
                      {5500, 460},
                      {6200, 460}};
    for (int i = 0; i < 10; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v.push_back(1);
        v.push_back(0);//0代表左
        v.push_back(0);//0代表没有展示压扁的master
        v1.push_back(v);
        v.clear();
    }
    m.insert(1, v1);
    v1.clear();
}


void Master::Master_State(Mary *m, Pipe *p, Brick *r) {
    mary = m;
    pipe = p;
    brick = r;
}

void Master::Master_Move() {
    if (die_state != 0) {
        die_state++;
    }
    for (itm = m.begin()->begin(); itm != m.begin()->end(); itm++) {

        if (die_state == 25 && *(itm->begin() + 4) == 1) {
            die_state = 0;
            *(itm->begin() + 4) = 2;
        }
        if (*itm->begin() - mary->x > -40 && *(itm->begin()) - mary->x < 800 && *(itm->begin() + 2) == 1) {
            if (*itm->begin() - mary->x <= 340 && (*itm->begin() - mary->x >= 270) && mary->y > 410 && mary->y < 455 &&
                !mary->is_jump) {
                die_state = 1;
                *(itm->begin() + 4) = 1;
                mary->is_jump_end = false;//跳跃状态开始
                mary->distance = 1;
                *(itm->begin() + 2) = 0;
                return;
            }
            if (((*itm->begin() - mary->x >= 330 && *itm->begin() - mary->x <= 340) ||
                 (*itm->begin() - mary->x >= 270 && *itm->begin() - mary->x <= 280)) && mary->y == 455) {
                if (mary->colour == 1 && !mary->is_invincible) {
                    mary->is_die = true;
                } else if (mary->colour != 1 && !mary->is_invincible) {
                    mary->colour = 1;
                    mary->is_invincible = true;
                }
            }
            if (*(itm->begin() + 3) == 1) {
                *itm->begin() += 1;
            } else if (*(itm->begin() + 3) == 0) {
                *(itm->begin()) -= 1;
            }
            for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();
            it++)
            {
                if (*it->begin() - *itm->begin() == 40 && *(it->begin() + 2) == 1 && *(it->begin() + 1) == 460) {
                    *(itm->begin() + 3) = 0;
                    return;
                } else if (*it->begin() - *itm->begin() == -60 && *(it->begin() + 2) == 1 &&
                           *(it->begin() + 1) == 460) {
                    *(itm->begin() + 3) = 1;
                    return;
                }
            }
            for (QVector < QVector < int >> ::iterator it = pipe->long_m.begin()->begin(); it != pipe->long_m.begin()->end();
            it++)
            {
                if (*it->begin() - *itm->begin() == 30) {
                    *(itm->begin() + 3) = 0;
                    return;
                } else if (*it->begin() - *itm->begin() == -70) {
                    *(itm->begin() + 3) = 1;
                    return;
                }
            }
            for (QVector < QVector < int >> ::iterator it = pipe->short_m.begin()->begin(); it != pipe->short_m.begin()->end();
            it++)
            {
                if (*it->begin() - *itm->begin() == 30) {
                    *(itm->begin() + 3) = 0;
                    return;
                } else if (*it->begin() - *itm->begin() == -70) {
                    *(itm->begin() + 3) = 1;
                    return;
                }
            }
        }
    }


}
