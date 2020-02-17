#ifndef BALL_H_
#define BALL_H_

#include "pre.h"
#include "Paddle.h"

class CBall {
    public:
        CBall() {
            _speedX = _speedY = SPEED_BALL;
            _ball.setSize(SIZE_BALL);
            _ball.setFillColor(Color::Cyan);
        }

        RectangleShape getBall() {
            return _ball;
        }

        void setSize(int size) {
            _ball.setSize(Vector2f(size, size));
        }

        void moveUp() {
            if (_ball.getPosition().y >= 0) {
                _ball.setPosition(_ball.getPosition().x, _ball.getPosition().y - _speedY);
            }
        }

        void moveDown() {
            if (_ball.getPosition().y + SIZE_BALL.x <= HEIGHT_SCREEN) {
                _ball.setPosition(_ball.getPosition().x, _ball.getPosition().y + _speedY);
            }
        }

        void moveLeft() {
            if (_ball.getPosition().x >= 0) {
                _ball.setPosition(_ball.getPosition().x - _speedX, _ball.getPosition().y);
            }
        }

        void moveRight() {
            if (_ball.getPosition().x + SIZE_BALL.x <= WIDTH_SCREEN) {
                _ball.setPosition(_ball.getPosition().x + _speedX, _ball.getPosition().y);
            }
        }

        void logic(CPaddle &player1, CPaddle &player2) {
            // if (_ball.getGlobalBounds().intersects(player1.getP))
        }

    private:
        RectangleShape _ball;
        float _speedX;
        float _speedY;
        int _dir;   // huong di chuyen cua bong
};

#endif