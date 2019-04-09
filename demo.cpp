#include <GLUT/GLUT.h>
#include <cmath>
#include <iostream>
using namespace std;

enum State { STANDING, JUMPING, SQUATING, DOWNHILL, NORMAL_ATTACK, UPWARD_ATTACK, DOWNWARD_ATTACK, CHASSIS_ATTACK };
enum Input { UP, DOWN, RUP, RDOWN, ATK, RATK };

class Hero {
  private:
    State state;
    string what;

  public:
    void handleInput(Input input);
    void say() {
        cout << "BBO使用了:" << what << endl;
    }
    Hero() {
        state = STANDING;
        what = "站立";
    }
};

void Hero::handleInput(Input input) {
    switch (state) {
        case STANDING:
            if (input == ATK) {
                state = NORMAL_ATTACK;
                what = "进行攻击";
                say();
            } else if (input == DOWN) {
                state = SQUATING;
                what = "蹲下";
                say();
            } else if (input == UP) {
                state = JUMPING;
                what = "跳起来";
                say();
            }
            break;
        case JUMPING:
            if (input == RUP) {
                state = STANDING;
                what = "站立";
                say();
            } else if (input == ATK) {
                state = UPWARD_ATTACK;
                what = "向上攻击";
                say();
            } else if (input == DOWN) {
                state = DOWNHILL;
                what = "迅速下降";
                say();
            }
            break;
        case SQUATING:
            if (input == RDOWN) {
                state = STANDING;
                what = "站立";
                say();
            } else if (input == ATK) {
                state = CHASSIS_ATTACK;
                what = "下段攻击";
                say();
            }
            break;
        case DOWNHILL:
            if (input == ATK) {
                state = DOWNWARD_ATTACK;
                what = "向下攻击";
                say();
            } else if (input == RDOWN) {
                state = STANDING;
                what = "站立";
                say();
            }
            break;
        case NORMAL_ATTACK:
            if (input == RATK) {
                state = STANDING;
                what = "站立";
                say();
            }
            break;
        case UPWARD_ATTACK:
            if (input == RATK) {
                state = STANDING;
                what = "站立";
                say();
            }
            break;
        case DOWNWARD_ATTACK:
            if (input == RATK) {
                state = STANDING;
                what = "站立";
                say();
            }
            break;
        case CHASSIS_ATTACK:
            if (input == RATK) {
                state = SQUATING;
                what = "蹲下";
                say();
            }else if (input == RDOWN){
                state = STANDING;
                what = "站立";
                say();
            }
            break;
    }
}

// class HeroState {
//   public:
//     virtual ~HeroState() {}
//     virtual void handleInput(Hero &hero, Input input) {}
//     virtual void update(Hero &hero) {}
// };
// class StandingState : public HeroState {};
// class JumpingState : public HeroState {};
// class SquatingState : public HeroState {};
// class DownhillState : public HeroState {};
// class NormalAttackState : public HeroState {};
// class UpwardAttackState : public HeroState {};
// class DownwardAttackState : public HeroState {};
// class ChassisAttackState : public HeroState {};

Hero BBO;
void inputKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            BBO.handleInput(UP);
            break;
        case GLUT_KEY_DOWN:
            BBO.handleInput(DOWN);
            break;
        case GLUT_KEY_RIGHT:
        case GLUT_KEY_LEFT:
            BBO.handleInput(ATK);
            break;
    }
}
void inputKey2(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            BBO.handleInput(RUP);
            break;
        case GLUT_KEY_DOWN:
            BBO.handleInput(RDOWN);
            break;
        case GLUT_KEY_RIGHT:
        case GLUT_KEY_LEFT:
            BBO.handleInput(RATK);
            break;
    }
}
void Draw() {}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("drawClock");
    glutSpecialFunc(inputKey);
    glutSpecialUpFunc(inputKey2);
    glutDisplayFunc(&Draw);
    glutMainLoop();
    return (0);
}