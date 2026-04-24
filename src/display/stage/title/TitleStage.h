#ifndef TITLESTAGE_H
#define TITLESTAGE_H

#include "display/stage/Stage.h"
#include "../../displayable/ui/button/UiButton.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include <string>
class TitleStage : public Stage {
public:
    TitleStage();
    virtual ~TitleStage() = default;
    void update() override;
private:
    UiButton startButton;
    UiButton exitButton;
    std::string m_playerName;
    sf::RectangleShape m_nameBox;
    std::unique_ptr<sf::Text> m_nameText;
    std::unique_ptr<sf::Text> m_nameLabel;
    bool m_nameBoxActive;
};

#endif
