#ifndef PADDLE_H_
#define PADDLE_H_

#include "pre.h"

class CPaddle {
    public:
        CPaddle() {
            _speed = SPEED_PADDLE;
            _paddle.setFillColor(Color::White);
            _paddle.setSize(SIZE_PADDLE);
            _point = 0;
            _playerServe = false;
        }

        

        void setPoint(int point) {
            _point = point;
        }

        void moveUp() {
            if (_paddle.getPosition().x >= 0) {
                _paddle.setPosition(_paddle.getPosition().x, _paddle.getPosition().y - _speed);
            }
        }

        void moveDown() {
            if (_paddle.getPosition().x + SIZE_PADDLE.y <= HEIGHT_SCREEN) {
                _paddle.setPosition(_paddle.getPosition().x, _paddle.getPosition().y + _speed);
            }
        }

    private:
        RectangleShape _paddle;
        float _speed;
        int _point;
        bool _playerServe;
};

#endif