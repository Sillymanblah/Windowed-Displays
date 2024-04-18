#include "Window.hpp"

LRESULT CALLBACK myProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc( hWnd, uMsg, wParam, lParam );
}

Window::Window() : _hInstance( GetModuleHandle(nullptr) )
{
    WNDCLASSW wndClass = {NULL};
    wndClass.lpszClassName = CLASS_NAME;
    wndClass.hInstance = _hInstance;
    wndClass.hIcon = LoadIcon( NULL, IDC_ICON );
    wndClass.hCursor = LoadCursor( NULL, IDC_ARROW );
    wndClass.lpfnWndProc = myProcedure;
    
    ATOM myAtom = RegisterClassW( &wndClass );
    
    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

    int width = 900, height = 700; 

    RECT rect;
    rect.left = 50;
    rect.top = 50;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;

    AdjustWindowRect( &rect, style, false );

    _hWnd = CreateWindowW(
        CLASS_NAME,
        L"Window Test",
        style,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        _hInstance,
        NULL
    );

    ShowWindow( _hWnd, SW_SHOW );
}

Window::~Window()
{
    UnregisterClassW( CLASS_NAME, _hInstance );
}

bool Window::ProcessMessages()
{
    MSG msg = {};

    while ( PeekMessage( &msg, nullptr, 0u, 0u, PM_REMOVE ) )
    {
        if ( msg.message == WM_QUIT ) return false;

        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

    return true;
}
