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
            _ball.setPosition(POS_BALL);
            _dir = LEFT;
        }

        void setDir(int dir) {
            _dir = dir;
        }
        int getDir() {
            return _dir;
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

        void logic(CPaddle &paddle1, CPaddle &paddle2) {
            // bong cham paddle1
            if (isCollision(paddle1)) {
                _speed += 0.5f;
                switch (_dir) {
                    case LEFT: {
                        int a = rand() % 3;
                        switch (a) {
                            case 0:
                                _dir = RIGHT;
                                break;

                            case 1:
                                _dir = RIGHT_DOWN;
                                break;

                            case 2: 
                                _dir = RIGHT_UP;
                                break;
                        }
                    } break;

                    case LEFT_DOWN: {
                        _dir = RIGHT_DOWN;
                    } break;

                    case LEFT_UP: {
                        _dir = RIGHT_UP;
                    } break;
                }
            }

            // bong cham paddle2
            if (isCollision(paddle2)) {
                _speed += 0.5f;
                switch (_dir) {
                    case RIGHT: {
                        int a = rand() % 3;
                        switch (a) {
                            case 0: 
                                _dir = LEFT;
                                break;

                            case 1: 
                                _dir = LEFT_UP;
                                break;

                            case 2:
                                _dir = LEFT_DOWN;
                                break;
                        }
                    } break;

                    case RIGHT_DOWN: {
                        _dir = LEFT_DOWN;
                    } break;

                    case RIGHT_UP: {
                        _dir = LEFT_UP;
                    } break;
                }
            }

            // bong cham bien tren
            if (_ball.getPosition().y <= 0) {
                if (_dir == LEFT_UP) {
                    _dir = LEFT_DOWN;
                } else if (_dir == RIGHT_UP) {
                    _dir = RIGHT_DOWN;
                }
            }

            // bong cham bien duoi
            if (_ball.getPosition().y + SIZE_BALL.y >= HEIGHT_SCREEN) {
                if (_dir == RIGHT_DOWN) {
                    _dir = RIGHT_UP;
                } else if (_dir == LEFT_DOWN) {
                    _dir = LEFT_UP;
                }
            }

            // p1 wins 1point
            if (_ball.getPosition().x + SIZE_BALL.x >= WIDTH_SCREEN) {
                paddle1.setPoint(paddle1.getPoint() + 1);
                _speed = SPEED_BALL;
                _ball.setPosition(paddle2.getPaddle().getPosition().x - SIZE_BALL.x - SIZE_PADDLE.x, paddle2.getPaddle().getPosition().y + SIZE_PADDLE.y/2);
            }

            // p2 wins 1point
            if (_ball.getPosition().x <= 0) {
                paddle2.setPoint(paddle2.getPoint() + 1);
                _speed = SPEED_BALL;
                _ball.setPosition(paddle1.getPaddle().getPosition().x + SIZE_PADDLE.x, paddle1.getPaddle().getPosition().y + SIZE_PADDLE.y/2);
            }

            // direction
            switch (_dir) {
                case LEFT: {
                    moveLeft();
                } break;

                case RIGHT: {
                    moveRight();
                } break;

                case LEFT_UP: {
                    moveLeft();
                    moveUp();
                } break;

                case LEFT_DOWN: {
                    moveLeft();
                    moveDown();
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

        void drawBall(RenderWindow &window) {
            window.draw(_ball);
        }

    private:
        RectangleShape _ball;
        float _speed;
        int _dir;   // huong di chuyen cua bong

        bool isCollision(CPaddle paddle) {
            return _ball.getGlobalBounds().intersects(paddle.getPaddle().getGlobalBounds());
        }
};

#endif