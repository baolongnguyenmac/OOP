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

        void logic(CPaddle &player1, CPaddle &player2) {
            // bong cham player1
            if (isCollision(player1)) {
                _speed += 0.25f;
                player1.setSpeed(player1.getSpeed() + 0.25);
                player2.setSpeed(player1.getSpeed());
                switch (_dir) {
                    case LEFT: {
                        int a = rand() % 3;
                        switch (a) {
                            case 2:
                                _dir = RIGHT;
                                break;

                            case 0:
                                _dir = RIGHT_DOWN;
                                break;

                            case 1: 
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

            // bong cham player2
            if (isCollision(player2)) {
                player1.setSpeed(player1.getSpeed() + 0.25);
                player2.setSpeed(player1.getSpeed());
                _speed += 0.25f;
                switch (_dir) {
                    case RIGHT: {
                        int a = rand() % 3;
                        switch (a) {
                            case 1: 
                                _dir = LEFT;
                                break;

                            case 2: 
                                _dir = LEFT_UP;
                                break;

                            case 0:
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
                player2.setPlayerServe(true);
                player1.setPoint(player1.getPoint() + 1);

                // set speed lai nhu cu
                _speed = SPEED_BALL;
                player1.setSpeed(SPEED_PADDLE);
                player2.setSpeed(SPEED_PADDLE);

                // cout << "p1 | p2: " << player1.getPoint() << " | " << player2.getPoint() << endl;
            }

            // p2 wins 1point
            if (_ball.getPosition().x <= 0) {
                player1.setPlayerServe(true);
                player2.setPoint(player2.getPoint() + 1);

                // set speed lai nhu cu
                _speed = SPEED_BALL;
                player1.setSpeed(SPEED_PADDLE);
                player2.setSpeed(SPEED_PADDLE);

                // cout << "p1 | p2: " << player1.getPoint() << " | " << player2.getPoint() << endl;
            }

            // set lai vi tri ball khi co luot choi
            if (player1.getPlayerServe()) {
                _ball.setPosition(player1.getPaddle().getPosition().x + SIZE_PADDLE.x, player1.getPaddle().getPosition().y + SIZE_PADDLE.y/2);
            }
            else if (player2.getPlayerServe()) {
                _ball.setPosition(player2.getPaddle().getPosition().x - SIZE_BALL.x, player2.getPaddle().getPosition().y + SIZE_PADDLE.y/2);
            }

            // direction
            // chi xet _dir khi bong dang chay
            if (!player1.getPlayerServe() || !player2.getPlayerServe())
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

        // use as a video in order to demo game at the beginning 
        void logicDemo(CPaddle *player1, CPaddle *player2) {
            logic(*player1, *player2);
            player1->setPoint(-9999);
            player2->setPoint(-9999);

            // xử lý trường hợp bấm phím space để phát bóng
            if(player1->getPlayerServe()) {
                player1->setPlayerServe(false);
                setDir(RIGHT);
            }
            else if(player2->getPlayerServe()) {
                player2->setPlayerServe(false);
                setDir(LEFT);
            }

            // xử lý autorun
            switch (getDir()) {
                case RIGHT:
                case RIGHT_UP:
                case RIGHT_DOWN: {
                    if (_ball.getPosition().x >= WIDTH_SCREEN/2) {
                        if (_ball.getPosition().y > player2->getPaddle().getPosition().y + SIZE_PADDLE.y /2) {
                            player2->moveDown();
                        }
                        else {
                            player2->moveUp();
                        }
                    }
                } break;

                case LEFT:
                case LEFT_DOWN:
                case LEFT_UP: {
                    if (_ball.getPosition().x < WIDTH_SCREEN/2) {
                        if (_ball.getPosition().y > player1->getPaddle().getPosition().y + SIZE_PADDLE.y /2) {
                            player1->moveDown();
                        }
                        else {
                            player1->moveUp();
                        }
                    }
                } break;
            }
        }

        void setSpeed(float speed) {
            _speed = speed;
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