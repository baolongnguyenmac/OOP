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

        RectangleShape getPaddle() {
            return _paddle;
        }

        void setPlayerServe(bool b) {
            _playerServe = b;
        }
        bool getPlayerServe() {
            return _playerServe;
        }

        int getPoint() {
            return _point;
        }
        void setPoint(int point) {
            _point = point;
        }

        void setSpeed(float speed) {
            _speed = speed;
        }
        float getSpeed() {
            return _speed;
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