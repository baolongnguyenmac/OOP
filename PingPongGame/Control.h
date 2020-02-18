#ifndef CONTROL_H_
#define CONTROL_H_

#include "pre.h"
#include "Ball.h"

class CControl {
    public:
        // static CControl* getInstance() {
        //     if (_instance == NULL) {
        //         _instance = new CControl();
        //     }
        //     return _instance;
        // }

        void control(CPaddle &player1, CPaddle &player2, CBall &ball) {
            if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
                player1.moveUp();
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
                player1.moveDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
                player2.moveUp();
            } 
            if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
                player2.moveDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
                if(player1.getPlayerServe()) {
                    player1.setPlayerServe(false);
                    ball.setDir(RIGHT);
                }
                else if(player2.getPlayerServe()) {
                    player2.setPlayerServe(false);
                    ball.setDir(LEFT);
                }
            }
        }

    // private:
    //     static CControl *_instance;
    //     CControl() {
    //         _instance = new CControl;
    //     }
};

// CControl* CControl::_instance = NULL;

#endif