#include "pre.h"
#include "Paddle.h"
#include "Ball.h"
#include "Control.h"
#include "Menu.h"

void twoPlayersMode(RenderWindow &window) {
    window.clear();

    Clock clock;
    const float FPS = 60.0f; //The desired FPS. (The number of updates each second).
    bool redraw = true;      //Do I redraw everything on the screen?

    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(WIDTH_SCREEN / 2, 0)),
        sf::Vertex(sf::Vector2f(WIDTH_SCREEN / 2, HEIGHT_SCREEN))
    };

    CPaddle *paddle1 = new CPaddle(POS_PADDLE_1, POS_SCORE_1);
    CPaddle *paddle2 = new CPaddle(POS_PADDLE_2, POS_SCORE_2);
    CBall *ball = new CBall;
    CControl *control = new CControl;

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }
        }

        // nhận điều khiển, các kiểu các kiểu 
        control->control(*paddle1, *paddle2, *ball);
        ball->logic(*paddle1, *paddle2);

        // xử lý thắng thua


        //Wait until 1/120th of a second has passed, then update everything.
        if (clock.getElapsedTime().asSeconds() >= 1.0f / (FPS)) {
            redraw = true; //We're ready to redraw everything
            clock.restart();
        }
        else {
            Time sleepTime = seconds((1.0f / FPS) - clock.getElapsedTime().asSeconds());
            sleep(sleepTime);
        }

        if (redraw) {
            window.clear();
            paddle1->drawPaddle(window);
            paddle2->drawPaddle(window);
            ball->drawBall(window);
            window.draw(line, 2, Lines);
            window.display();
        }
    }
}

void onePlayer(RenderWindow &window) {

}

int main(int argc, char const *argv[]) {
    RenderWindow window(VideoMode(WIDTH_SCREEN, HEIGHT_SCREEN), "PingPongGame");
    Menu m(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            switch (e.type) {
                case sf::Event::Closed: {
                    window.close();
                } break;

                case sf::Event::KeyReleased: {
                    switch (e.key.code) {
                        case sf::Keyboard::Up: {
                            m.MoveUp();
                        } break;

                        case sf::Keyboard::Down: {
                            m.MoveDown();
                        } break;

                        case sf::Keyboard::Enter: {
                            switch (m.GetPressedItem()) {
                                case 0: {   // 1ng choiw
                                    onePlayer(window);
                                } break;

                                case 1: {   // 2ng choiw
                                    twoPlayersMode(window);
                                } break;

                                case 2: {   // thoat
                                    window.close();
                                } break;
                            }
                        }
                    }
                } break;
            }
        }

        

        // window.clear();
        m.draw(window);
        window.display();
    }

    return 0;
}
