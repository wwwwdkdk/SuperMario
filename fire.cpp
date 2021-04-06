#include "fire.h"
#include<QDebug>

Fire::Fire() {
    Fire_Init();
}

void Fire::Fire_Init() {
    x = x1 = x2 = y = y2 = y2 = 0;
    direction = direction1 = direction2 = 1;
    is_have = is_have1 = is_have2 = false;
}

void Fire::Fire_Move(Mary *m, Pipe *p, Brick *r, Master *ms) {
    mary = m;
    pipe = p;
    brick = r;
    master = ms;
}

void Fire::Fire_xy() {
    if (!is_have) {
        if (mary->direction == "right") {
            x = mary->x + 350;
            direction = 1;
        } else {
            direction = 0;
            x = mary->x + 290;
        }
        is_have = true;
        y = mary->y + 15;
        if (mary->x <= 300) {
            x -= 300 - mary->x;
        }
    } else if (is_have && !is_have1) {
        if (mary->direction == "right") {
            x1 = mary->x + 350;
            direction1 = 1;
        } else {
            direction1 = 0;
            x1 = mary->x + 290;
        }
        is_have1 = true;
        y1 = mary->y + 15;
        if (mary->x <= 300) {
            x1 -= 300 - mary->x;
        }
    } else if (is_have && is_have1 && !is_have2) {
        if (mary->direction == "right") {
            x2 = mary->x + 350;
            direction2 = 1;
        } else {
            direction2 = 0;
            x2 = mary->x + 290;
        }
        is_have2 = true;
        y2 = mary->y + 15;
        if (mary->x <= 300) {
            x2 -= 300 - mary->x;
        }
    } else if (is_have && is_have1 && is_have2) {
        if (x > x1 && x > x2) {
            if (mary->direction == "right") {
                x = mary->x + 350;
                direction = 1;
            } else {
                direction = 0;
                x = mary->x + 290;
            }
            is_have = true;
            y = mary->y + 15;
            if (mary->x <= 300) {
                x -= 300 - mary->x;
            }
        } else if (x1 > x && x1 > x2) {
            if (mary->direction == "right") {
                x1 = mary->x + 350;
                direction1 = 1;
            } else {
                direction1 = 0;
                x1 = mary->x + 290;
            }
            is_have1 = true;
            y1 = mary->y + 15;
            if (mary->x <= 300) {
                x1 -= 300 - mary->x;
            }
        } else if (x2 > x && x2 > x1) {
            if (mary->direction == "right") {
                x2 = mary->x + 350;
                direction2 = 1;
            } else {
                direction2 = 0;
                x2 = mary->x + 290;
            }
            is_have2 = true;
            y2 = mary->y + 15;
            if (mary->x <= 300) {
                x2 -= 300 - mary->x;
            }
        }
    }
}

void Fire::Fire_state() {
    if (is_have && direction) {
        x += 10;
    } else if (is_have && !direction) {
        x -= 10;
    }
    if (is_have1 && direction1) {
        x1 += 10;
    } else if (is_have1 && !direction1) {
        x1 -= 10;
    }
    if (is_have2 && direction2) {
        x2 += 10;
    } else if (is_have2 && !direction2) {
        x2 -= 10;
    }
    for (QVector < QVector < int >> ::iterator it = master->m.begin()->begin(); it != master->m.begin()->end();
    it++)
    {
        if (x > *it->begin() && x <= *it->begin() + 30 && *(it->begin() + 2) == 1 && y >= *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 40) {
            is_have = false;
            *(it->begin() + 2) = 0;
            x = 0;
            return;
        }
        if (x1 > *it->begin() && x1 <= *it->begin() + 30 && *(it->begin() + 2) == 1 && y >= *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 40) {
            is_have1 = false;
            *(it->begin() + 2) = 0;
            x1 = 0;
            return;
        }
        if (x2 > *it->begin() && x2 <= *it->begin() + 30 && *(it->begin() + 2) == 1 && y >= *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 40) {
            is_have2 = false;
            *(it->begin() + 2) = 0;
            x2 = 0;
            return;
        }
    }
    for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();
    it++)
    {
        if (x > *it->begin() + 10 && x <= *it->begin() + 30 && y > *(it->begin() + 1) && y < *(it->begin() + 1) + 40) {
            is_have = false;
            x = 0;
            return;
        }
        if (x1 > *it->begin() + 10 && x1 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y < *(it->begin() + 1) + 40) {
            is_have1 = false;
            x1 = 0;
            return;
        }
        if (x2 > *it->begin() + 10 && x2 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y < *(it->begin() + 1) + 40) {
            is_have2 = false;
            x2 = 0;
            return;
        }
    }

    for (QVector < QVector < int >> ::iterator it = pipe->long_m.begin()->begin(); it != pipe->long_m.begin()->end();
    it++)
    {
        if (x > *it->begin() + 10 && x <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 100) {
            is_have = false;
            x = 0;
            return;
        }
        if (x1 > *it->begin() + 10 && x1 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 100) {
            is_have1 = false;
            x1 = 0;
            return;
        }
        if (x2 > *it->begin() + 10 && x2 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 100) {
            is_have2 = false;
            x2 = 0;
            return;
        }
    }
    for (QVector < QVector < int >> ::iterator it = pipe->short_m.begin()->begin(); it != pipe->short_m.begin()->end();
    it++)
    {
        if (x > *it->begin() + 10 && x <= *it->begin() + 30 && y > *(it->begin() + 1) && y <= *(it->begin() + 1) + 50) {
            is_have = false;
            x = 0;
            return;
        }
        if (x1 > *it->begin() + 10 && x1 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 50) {
            is_have1 = false;
            x1 = 0;
            return;
        }
        if (x2 > *it->begin() + 10 && x2 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 50) {
            is_have2 = false;
            x2 = 0;
            return;
        }
    }
}
