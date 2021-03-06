#ifndef PRE_H_
#define PRE_H_

#include "iostream"
using namespace std;

#include "SFML/Graphics.hpp"
using namespace sf;

#include "string"

#include "stdlib.h"

#define HEIGHT_SCREEN 1000
#define WIDTH_SCREEN 1500

#define POS_BALL Vector2f(WIDTH_SCREEN / 2, HEIGHT_SCREEN / 2)
#define SPEED_BALL 2.5f
#define SIZE_BALL Vector2f(25, 25)
#define LEFT_UP 1
#define RIGHT_UP 2
#define RIGHT 3
#define RIGHT_DOWN 4
#define LEFT_DOWN 5
#define LEFT 6

#define SIZE_PADDLE Vector2f(25, 200)
#define SPEED_PADDLE 3.5f
#define POS_PADDLE_1 Vector2f(0, HEIGHT_SCREEN / 2 - SIZE_PADDLE.y / 2)
#define POS_SCORE_1 Vector2f(WIDTH_SCREEN / 2 - 120, HEIGHT_SCREEN / 2 - 75)
#define POS_PADDLE_2 Vector2f(WIDTH_SCREEN - SIZE_PADDLE.x, HEIGHT_SCREEN / 2 - SIZE_PADDLE.y / 2)
#define POS_SCORE_2 Vector2f(WIDTH_SCREEN / 2 + 60, HEIGHT_SCREEN / 2 - 75)

#endif