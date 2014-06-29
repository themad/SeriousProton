#include "input.h"
#include "engine.h"

P<WindowManager> InputHandler::windowManager;

sf::Vector2f InputHandler::mousePos;
int InputHandler::mouse_wheel_delta;
bool InputHandler::mouse_button_down[sf::Mouse::ButtonCount];
bool InputHandler::keyboard_button_down[sf::Keyboard::KeyCount];

bool InputHandler::mouseButtonDown[sf::Mouse::ButtonCount];
bool InputHandler::mouseButtonPressed[sf::Mouse::ButtonCount];
bool InputHandler::keyboardButtonDown[sf::Keyboard::KeyCount];
bool InputHandler::keyboardButtonPressed[sf::Keyboard::KeyCount];
string InputHandler::keyboard_text_entry;

void InputHandler::initialize()
{
    memset(mouse_button_down, 0, sizeof(mouse_button_down));
    memset(keyboard_button_down, 0, sizeof(keyboard_button_down));
}

void InputHandler::update()
{
    if (!windowManager)
        windowManager = engine->getObject("windowManager");

    mousePos = sf::Vector2f(sf::Mouse::getPosition() - windowManager->window.getPosition());
    mousePos.x *= float(windowManager->virtualSize.x) / float(windowManager->window.getSize().x);
    mousePos.y *= float(windowManager->virtualSize.y) / float(windowManager->window.getSize().y);
    for(unsigned int n=0; n<sf::Mouse::ButtonCount; n++)
    {
        //bool down = sf::Mouse::isButtonPressed(sf::Mouse::Button(n)) && windowManager->hasFocus();    //
        bool down = mouse_button_down[n];
        mouseButtonPressed[n] = (!mouseButtonDown[n] && down);
        mouseButtonDown[n] = down;
    }
    
    for(unsigned int n=0; n<sf::Keyboard::KeyCount; n++)
    {
        bool down = keyboard_button_down[n];
        keyboardButtonPressed[n] = (!keyboardButtonDown[n] && down);
        keyboardButtonDown[n] = down;
    }
}
