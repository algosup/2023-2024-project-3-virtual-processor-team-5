#include <windows.h>
#include <stdio.h> // Necessary for sprintf and sscanf

#define ID_EDIT_INPUT 101
#define ID_EDIT_OUTPUT 102
#define ID_BTN_RUN 103

// Prototypes
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
int evaluerExpression(char* input);

HWND hEditInput, hEditOutput; // Global declaration for the handles

// Function to evaluate the expression
int evaluerExpression(char* input) {
    int a, b;
    if (sscanf(input, "%d+%d", &a, &b) == 2) { // Simplification for this example
        return a + b;
    }
    return 0; // If the expression is not recognized
}

char const g_szClassName[] = "VirtualTerminal";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc = {0};
    HWND hwnd;
    MSG Msg;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProcedure;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Failed to register window class!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        0,
        g_szClassName,
        "Virtual Terminal",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, // Adjusted size
        NULL, NULL, hInstance, NULL);

    // Adjustments for hEditInput to accept multiline input
    hEditInput = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | ES_AUTOVSCROLL, 
                              10, 10, 775, 100, hwnd, (HMENU)ID_EDIT_INPUT, hInstance, NULL); // Adjusted input area

    hEditOutput = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY, 
                               10, 120, 775, 400, hwnd, (HMENU)ID_EDIT_OUTPUT, hInstance, NULL); // Adjusted output area

    CreateWindow("BUTTON", "Run", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
                 700, 530, 80, 30, hwnd, (HMENU)ID_BTN_RUN, hInstance, NULL); // Adjusted button

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return (int) Msg.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_COMMAND:
            if (LOWORD(wParam) == ID_BTN_RUN) {
                char inputText[1024] = {0};
                GetWindowText(hEditInput, inputText, sizeof(inputText)); // Retrieves user input

                int result = evaluerExpression(inputText); // Evaluates the user-entered expression
                char outputText[1024];
                sprintf(outputText, "Result: %d", result); // "Result: %d"

                SetWindowText(hEditOutput, outputText); // Updates the output area with the result
            }
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}