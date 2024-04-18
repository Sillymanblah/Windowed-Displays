#pragma once
#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <Windows.h>

LRESULT CALLBACK myProcedure( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

class Window
{
private:
    HINSTANCE _hInstance;
    HWND _hWnd;
    const wchar_t* CLASS_NAME = L"Testing";

public:
    Window();
    Window( const Window& other ) = delete;
    Window& operator =( Window& other ) = delete;
    ~Window();

    bool ProcessMessages();

};

#endif // __WINDOW_HPP__