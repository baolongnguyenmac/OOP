#include "pre.h"
#include "Paddle.h"
#include "Ball.h"
#include "Control.h"

int main(int argc, char const *argv[]) {
    RenderWindow window(VideoMode(WIDTH_SCREEN, HEIGHT_SCREEN), "SFML");

    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(WIDTH_SCREEN / 2, 0)),
        sf::Vertex(sf::Vector2f(WIDTH_SCREEN / 2, HEIGHT_SCREEN))
    };

    CPaddle *paddle1 = new CPaddle(POS_PADDLE_1, POS_SCORE_1);
    CPaddle *paddle2 = new CPaddle(POS_PADDLE_2, POS_SCORE_2);
    CBall *ball = new CBall;
    // CControl *control = CControl::getInstance();
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
        window.draw(line, 2, Lines);
        window.display();
    }

    return 0;
}
