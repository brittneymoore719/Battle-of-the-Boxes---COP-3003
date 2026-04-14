#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include "display/Updatable.h"

class UiButton : Updatable {
    public:
        UiButton(std::string label, sf::Vector2f position, sf::Vector2f size);
        void update() override;
        bool hasBeenClicked();
        bool isHovered();
    private:
        bool m_clicked;
        bool m_wasMousePressed;
        std::string m_label;

        sf::RectangleShape m_rect;
};

#endif
