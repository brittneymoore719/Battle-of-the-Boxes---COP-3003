#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <string>
#include "UiElement.h"

class UiButton : UiElement {
    public:
        UiButton(std::string label);
        virtual void update() override;
        bool hasBeenClicked();
    private:
        bool m_clicked;
        std::string m_label;
};

#endif
