#include <windows.h>
// Window Procedure function that handles all window events
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);// Signal the application to terminate
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            // Fill window with white background
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            //Create and select a red brush for deawing
            HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH oldBrush = SelectObject(hdc, redBrush);

            //Get window dimensions
            RECT rect;
            GetClientRect(hwnd, &rect);
            int width = rect.right - rect.left;
            int height = rect.bottom - rect.top;

            //define Sphere size
            int sphereRadius = 100;

            //Draw a red circle in the centre of the window
            Ellipse(hdc,
                    (width / 2) - sphereRadius,  //Left positon
                    (height / 2) - sphereRadius, // top position
                    (width / 2) + sphereRadius,  //right position
                    (height / 2) + sphereRadius  //Botoom position
            );

            //clean up gdi resources
            SelectObject(hdc, oldBrush);
            DeleteObject(redBrush);
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

//Mian entry point for winows application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Configure the window class proterties
    const char CLASS_NAME[] = "RedSphereWindowClass";
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc; // set window procedure function
    wc.hInstance = hInstance;    // set application instance
    wc.lpszClassName = CLASS_NAME; // set class name 
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //set white background

    //Register the window class with weindows
    RegisterClass(&wc);
    
    //Create actual window
    HWND hwnd = CreateWindowEx(
        0,                            //window styles (optional)
        CLASS_NAME,               
        "Red Sphere Window",          //window title
        WS_OVERLAPPEDWINDOW,          // Standrd window style
        CW_USEDEFAULT, CW_USEDEFAULT, //Initial postion decided by windows
        800, 600,                     // window size
        NULL,                         //parent window handle
        NULL,                         // menu handle
        hInstance,                    // application insatce handle
        NULL                          // additonl application data (last parameter)
    );

    //check if window creation suceeded
    if (hwnd == NULL) {
        return 0;
    }

    //display
    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg); // Translate virtual-key messages
        DispatchMessage(&msg); // Dispatch message to WindowProc
    }
    return 0;
}
