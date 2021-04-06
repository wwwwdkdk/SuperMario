#ifndef MARY_H
#define MARY_H

#include<QString>

class Mary {
public:
    Mary();

    int x;//角色的理论x坐标
    int map_x;//角色在地图中的x坐标
    int y;//角色y坐标
    int colour;//角色颜色
    int life;//角色生命
    int walk_state;
    int ground_state;
    int height;
    int distance;
    int die_state;
    int die_pix_state;
    int invincible_state;
    bool can_move;
    bool is_invincible;
    bool is_die;//判断角色是否死亡
    bool is_jump;//判断角色是否跳跃
    bool is_jump_end;//判断角色单次跳跃是否结束
    bool is_space_release;
    QString direction;//角色移动的方向
    void Mary_Init();//角色初始化
    void Move_state();

    void Mary_Move(const QString &direction);//角色移动
    void Jump_And_Down();//上升和下降
    void Mary_die();//角色死亡
private:


};

#endif // MARY_H
