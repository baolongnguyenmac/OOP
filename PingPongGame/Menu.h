#ifndef MENU_H_
#define MENU_H_

#include "pre.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu {
    public:
        Menu(float width, float height) {
            if (!font.loadFromFile("Rainbow Colors - TTF.ttf")) {
                // handle error
            }

            menu[0].setFont(font);
            menu[0].setColor(sf::Color::Red);
            menu[0].setString("Play");
            menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
            menu[0].setCharacterSize(100);

            menu[1].setFont(font);
            menu[1].setColor(sf::Color::White);
            menu[1].setString("Hall cc");
            menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
            menu[1].setCharacterSize(100);

            menu[2].setFont(font);
            menu[2].setColor(sf::Color::White);
            menu[2].setString("Exit");
            menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
            menu[2].setCharacterSize(100);

            selectedItemIndex = 0;
        }

        void draw(sf::RenderWindow &window) {
            for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
                window.draw(menu[i]);
            }
        }

        void Menu::MoveUp() {
            if (selectedItemIndex - 1 >= 0) {
                menu[selectedItemIndex].setColor(sf::Color::White);
                selectedItemIndex--;
                menu[selectedItemIndex].setColor(sf::Color::Red);
            }
        }

        void Menu::MoveDown() {
            if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
                menu[selectedItemIndex].setColor(sf::Color::White);
                selectedItemIndex++;
                menu[selectedItemIndex].setColor(sf::Color::Red);
            }
        }
        
        int GetPressedItem() { 
            return selectedItemIndex; 
        }

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif // !MENU_H_