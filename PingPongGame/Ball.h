#ifndef BALL_H_
#define BALL_H_

#include "pre.h"
#include "Paddle.h"

class CBall {
    public:
        CBall() {
            _speed = SPEED_BALL;
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
                _ball.setPosition(_ball.getPosition().x, _ball.getPosition().y - _speed);
            }
        }

        void moveDown() {
            if (_ball.getPosition().y + SIZE_BALL.x <= HEIGHT_SCREEN) {
                _ball.setPosition(_ball.getPosition().x, _ball.getPosition().y + _speed);
            }
        }

        void moveLeft() {
            if (_ball.getPosition().x >= 0) {
                _ball.setPosition(_ball.getPosition().x - _speed, _ball.getPosition().y);
            }
        }

        void moveRight() {
            if (_ball.getPosition().x + SIZE_BALL.x <= WIDTH_SCREEN) {
                _ball.setPosition(_ball.getPosition().x + _speed, _ball.getPosition().y);
            }
        }

        void logic(CPaddle &player1, CPaddle &player2) {
            if (_ball.getGlobalBounds().intersects(player1.getPaddle().getGlobalBounds())) {
                if (_dir == LEFT_UP) {
                    _dir = RIGHT_UP;
                } else if (_dir == LEFT_DOWN) {
                    _dir = RIGHT_DOWN;
                } else if (_dir == LEFT) {
                    if (player1.getPlayerServe()) {
                        _dir = RIGHT_UP;
                    } else {
                        _dir = RIGHT_DOWN;
                    }
                }
            }

            if (_ball.getGlobalBounds().intersects(player2.getPaddle().getGlobalBounds())) {
                if (_dir == RIGHT_UP) {
                    _dir = LEFT_UP;
                } else if (_dir == RIGHT_DOWN) {
                    _dir = LEFT_DOWN;
                } else if (_dir == RIGHT) {
                    if (player2.getPlayerServe()) {
                        _dir = LEFT_UP;
                    } else {
                        _dir = LEFT_DOWN;
                    }
                }
            }

            if (_ball.getPosition().x <= 0) {
                player2.setPoint(player2.getPoint() + 1);
                player1.setPlayerServe(true);
                player2.setPlayerServe(false);
            }

            if (_ball.getPosition().x + SIZE_BALL.x >= WIDTH_SCREEN) {
                player1.setPoint(player1.getPoint() + 1);
                player2.setPlayerServe(true);
                player1.setPlayerServe(false);
            }

            switch (_dir) {
                case LEFT_UP: {
                    moveLeft();
                    moveUp();
                } break;

                case LEFT_DOWN: {
                    moveLeft();
                    moveDown();
                } break;

                case LEFT: {
                    moveLeft();
                } break;

                case RIGHT: {
                    moveRight();
                } break;

                case RIGHT_DOWN: {
                    moveRight();
                    moveDown();
                } break;

                case RIGHT_UP: {
                    moveRight();
                    moveUp();
                } break;
            }
        }

    private:
        RectangleShape _ball;
        float _speed;
        int _dir;   // huong di chuyen cua bong
};

#endif