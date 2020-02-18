#include "pre.h"
#include "Paddle.h"
#include "Ball.h"
#include "Control.h"

int main(int argc, char const *argv[]) {
    RenderWindow window(VideoMode(WIDTH_SCREEN, HEIGHT_SCREEN), "SFML");
    
    CPaddle *paddle1 = new CPaddle(POS_PADDLE_1);
    CPaddle *paddle2 = new CPaddle(POS_PADDLE_2);
    CBall *ball = new CBall;
    CControl *control = new CControl;

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }
        }

        control->control(*paddle1, *paddle2, *ball);
        ball->logic(*paddle1, *paddle2);

        window.clear();
        paddle1->drawPaddle(window);
        paddle2->drawPaddle(window);
        ball->drawBall(window);
        window.display();
    }

    return 0;
}
