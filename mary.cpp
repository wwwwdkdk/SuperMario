#include "mary.h"
#include<QDebug>

Mary::Mary() {
    Mary_Init();
}

void Mary::Mary_Init() {
    x = 0;
    y = 455;
    map_x = 0;
    life = 5;
    colour = 1;
    height = 20;
    distance = 0;
    walk_state = 0;
    ground_state = 0;
    die_state = 0;
    die_pix_state = -50;
    can_move = true;
    is_die = false;
    is_jump = false;
    is_jump_end = true;
    is_space_release = true;
    is_invincible = false;
    direction = "right";
    invincible_state = 0;
}

void Mary::Move_state() {
    if (walk_state == 1140) {
        walk_state = 0;
    }
    if (ground_state == 805) {
        ground_state = 5;
    } else if (ground_state == -5) {
        ground_state = 795;
    }
    if (!is_jump_end) {
        walk_state = 0;
    }
}

void Mary::Mary_Move(const QString &direction) {

    if (direction == "right" && x < 300 && can_move) {
        x += 5;
        map_x += 5;
        walk_state += 57;
    } else if (direction == "left" && x <= 300 && x >= 0 && can_move) {
        x -= 5;
        map_x -= 5;
        walk_state += 57;
    } else if (direction == "right" && x >= 300 && can_move) {
        x += 5;
        walk_state += 57;
        ground_state += 5;
    } else if (direction == "left" && x > 300 && can_move) {
        x -= 5;
        walk_state += 57;
        ground_state -= 5;
    } else if ((direction == "left" && x < 0) || (!can_move && direction != "null")) {
        walk_state += 57;
    }
    Move_state();
}


void Mary::Jump_And_Down() {
    if (is_jump && is_jump_end && is_space_release) {
        is_space_release = false;//每按一次空格键只能触发一次跳跃
        is_jump_end = false;//跳跃状态开始
        distance = 1;
    }
    if (distance > 0) {
        y -= height - distance;
        distance++;
    }
}

void Mary::Mary_die() {
    if (is_die && die_state < 20) {
        y -= 5;
        die_state++;
        die_pix_state += 50;
    } else if (is_die && die_state >= 20) {
        y += 5;
        die_state++;
    }

}

