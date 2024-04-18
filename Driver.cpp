#include <iostream>
#include "Window.hpp"

int main()
{
    std::cout << "Booting up...\n";

    Window* pWindow = new Window();

    bool running = true;

    while (running)
    {
        if ( !pWindow->ProcessMessages() )
        {
            std::cout << "Closing the program!\n";
            running = false;
        }

        // Do things.

        Sleep(10);
    }

    delete pWindow;

    return 0;
}