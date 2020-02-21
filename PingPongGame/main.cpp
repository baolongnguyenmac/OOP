#include "pre.h"
#include "Paddle.h"
#include "Ball.h"
#include "Control.h"
#include "Menu.h"

void twoPlayersMode(RenderWindow &window) {
    window.clear();

    Clock clock;
    const float FPS = 60.0f; // The desired FPS. (The number of updates each second).
    bool redraw = true;      // Do I redraw everything on the screen?

    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(WIDTH_SCREEN / 2, 0)),
        sf::Vertex(sf::Vector2f(WIDTH_SCREEN / 2, HEIGHT_SCREEN))
    };

    CPaddle *player1 = new CPaddle(POS_PADDLE_1, POS_SCORE_1);
    CPaddle *player2 = new CPaddle(POS_PADDLE_2, POS_SCORE_2);
    CBall *ball = new CBall;
    CControl *control = new CControl;

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }
            if (e.type == Event::KeyReleased) {
                if (e.key.code == Keyboard::Q) {
                    return;
                }
            }
        }

        // nhận điều khiển, các kiểu các kiểu 
        control->control(*player1, *player2, *ball);
        ball->logic(*player1, *player2);

        // // xử lý thắng thua
        // if (player1->getPoint() == 1 || player2->getPoint() == 1) {
        //     window.clear();
        //     if (player1->getPoint() == 1) {
        //         player1->drawWinner(window, "1");
        //     }
        //     else {
        //         player1->drawWinner(window, "2");
        //     }
        // }

        // Wait until 1/60th of a second has passed, then update everything.
        if (clock.getElapsedTime().asSeconds() >= 1.0f / (FPS)) {
            redraw = true; // We're ready to redraw everything
            clock.restart();
        }
        else {
            Time sleepTime = seconds((1.0f / FPS) - clock.getElapsedTime().asSeconds());
            sleep(sleepTime);
        }

        if (redraw) {
            window.clear();
            player1->drawPaddle(window);
            player2->drawPaddle(window);
            ball->drawBall(window);
            window.draw(line, 2, Lines);
            window.display();
        }
    }
}

void onePlayerMode(RenderWindow &window) {
    window.clear();
}

int main(int argc, char const *argv[]) {
    RenderWindow window(VideoMode(WIDTH_SCREEN, HEIGHT_SCREEN), "PingPongGame");
    Menu m(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        int choice = m.runMenu(window);
        switch (choice) {
            case 0: {
                onePlayerMode(window);
            } break;

            case 1: {
                twoPlayersMode(window);
            } break;

            case 2: {
                window.close();
            }
        }
    }

    return 0;
}
