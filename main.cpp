#include "windows.h"

static LRESULT CALLBACK WindowProcedure(HWND hWnd,
                                        UINT Msg,
                                        WPARAM wParam,
                                        LPARAM lParam) {
    switch (Msg) {
    case WM_CLOSE :
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, Msg, wParam, lParam);
}

void RegistrarClaseVentana(const TCHAR *NombreClaseVentana,
                           WNDPROC WndProc) {
    WNDCLASSEX WinClass;
    WinClass.cbSize = sizeof(WNDCLASSEX);
    WinClass.style = 0;
    WinClass.lpfnWndProc = WndProc;
    WinClass.cbClsExtra = 0;
    WinClass.cbWndExtra = 0;
    WinClass.hInstance = GetModuleHandle(NULL);
    WinClass.hIcon = NULL;
    WinClass.hIconSm = NULL;
    WinClass.hCursor = LoadCursor(0, IDC_ARROW);
    WinClass.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    WinClass.lpszMenuName = 0;
    WinClass.lpszClassName = NombreClaseVentana;
    ATOM A = RegisterClassEx(&WinClass);
}

int APIENTRY WinMain(HINSTANCE hInstance,
           HINSTANCE hPrevInstance,
           LPSTR lpCmdLine,
           int nCmdShow) {
    TCHAR NombreClase[] = TEXT("Mi Ventana");
    RegistrarClaseVentana(NombreClase, WindowProcedure);
    HWND hWnd = CreateWindowEx(NULL, NombreClase,
                               TEXT("Ejemplo"),
                               WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                               100, 100, 300, 300,
                               NULL, NULL, hInstance, NULL);
    MSG Mensaje;
    while(TRUE == GetMessage(&Mensaje, NULL, 0, 0)) {
        TranslateMessage(&Mensaje);
        DispatchMessage(&Mensaje);
    }
    return 0;
}
