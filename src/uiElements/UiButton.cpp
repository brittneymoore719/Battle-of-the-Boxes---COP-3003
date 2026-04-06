#include "UiButton.h"
#include <format>
#include <iostream>

UiButton::UiButton(std::string label) {
    m_label = label;
}

void UiButton::update() {
    // handling of detecting when the mouse clicks the button would happen here
    // drawing would also happen here

    std::cout << std::format("click {} button (y/n)\n", m_label);
    char choice{0};
    std::cin >> choice;
    if (choice == 'y') m_clicked = true;
    else m_clicked = false;
}

bool UiButton::hasBeenClicked() {
    return m_clicked;
}
