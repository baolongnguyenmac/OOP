#ifndef MENU_H_
#define MENU_H_

#include "pre.h"
#include "Ball.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu {
    public:
        Menu(float width, float height) {
            if (!font.loadFromFile("Rainbow Colors - TTF.ttf")) {
                cout << "Loi load font\n";
            }

            menu[0].setFont(font);
            menu[0].setColor(sf::Color::Red);
            menu[0].setString("1 player");
            menu[0].setPosition(Vector2f(width / 2 - 120, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
            menu[0].setCharacterSize(100);

            menu[1].setFont(font);
            menu[1].setColor(sf::Color::White);
            menu[1].setString("2 players");
            menu[1].setPosition(Vector2f(width / 2 - 120, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
            menu[1].setCharacterSize(100);

            menu[2].setFont(font);
            menu[2].setColor(Color::White);
            menu[2].setString("Exit");
            menu[2].setPosition(Vector2f(width / 2 - 120, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
            menu[2].setCharacterSize(100);

            selectedItemIndex = 0;
        }

        void draw(sf::RenderWindow &window) {
            for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
                window.draw(menu[i]);
            }
        }

        void MoveUp() {
            if (selectedItemIndex - 1 >= 0) {
                menu[selectedItemIndex].setColor(Color::White);
                selectedItemIndex--;
                menu[selectedItemIndex].setColor(Color::Red);
            }
        }

        void MoveDown() {
            if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
                menu[selectedItemIndex].setColor(Color::White);
                selectedItemIndex++;
                menu[selectedItemIndex].setColor(Color::Red);
            }
        }
        
        int GetPressedItem() { 
            return selectedItemIndex; 
        }

        int runMenu(RenderWindow &window) {
            Clock clock;
            const float FPS = 60.0f; // The desired FPS. (The number of updates each second).
            bool redraw = true;      // Do I redraw everything on the screen?

            // khoiwr taoj ddoois tuowngj 
            CPaddle *player1 = new CPaddle(POS_PADDLE_1, POS_SCORE_1);
            player1->setSpeed(5.0);
            CPaddle *player2 = new CPaddle(POS_PADDLE_2, POS_SCORE_2);
            player2->setSpeed(5.0);
            CBall *ball = new CBall;
            ball->setSpeed(5.0);
            CControl *control = new CControl;

            while (window.isOpen()) {
                Event e;

                ball->logicDemo(player1, player2);

                while (window.pollEvent(e)) {
                    switch (e.type) {
                        case Event::Closed: {
                            window.close();
                        } break;

                        case Event::KeyReleased: {
                            switch (e.key.code) {
                                case Keyboard::Up: {
                                    MoveUp();
                                } break;

                                case Keyboard::Down: {
                                    MoveDown();
                                } break;

                                case Keyboard::Enter: {
                                    return selectedItemIndex;
                                } break;
                            }
                        } break;
                    }
                }

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
                    draw(window);
                    player1->drawPaddle(window);
                    player2->drawPaddle(window);
                    ball->drawBall(window);
                    window.display();
                }
            }
        }

    private:
        int selectedItemIndex;
        Font font;
        Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif // !MENU_H_