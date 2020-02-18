#ifndef PADDLE_H_
#define PADDLE_H_

#include "pre.h"

class CPaddle {
    public:
        CPaddle(Vector2f beginPos, Vector2f scorePos) {
            _text.setPosition(scorePos);
            setupText();
            _paddle.setPosition(beginPos);
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
            if (_paddle.getPosition().y >= 0) {
                _paddle.setPosition(_paddle.getPosition().x, _paddle.getPosition().y - _speed);
            }
        }

        void moveDown() {
            if (_paddle.getPosition().y + SIZE_PADDLE.y <= HEIGHT_SCREEN) {
                _paddle.setPosition(_paddle.getPosition().x, _paddle.getPosition().y + _speed);
            }
        }

        void drawPaddle(RenderWindow &window) {
            window.draw(_paddle);
        }

        void setupText() {
            if (!_font.loadFromFile("Rainbow Colors - TTF.ttf")) {
                cout << "Can't load font Rainbow Colors - TTF.ttf\n";
            }

            _text.setFont(_font);
            _text.setString(to_string(_point));
            _text.setColor(Color::Green);
            _text.setCharacterSize(150);
        }

    private:
        RectangleShape _paddle;
        float _speed;
        int _point;
        bool _playerServe;
        Font _font;
        Text _text;
};

#endif