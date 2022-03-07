#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK TrataEventos(HWND, UINT, WPARAM, LPARAM);

TCHAR szProgName[] = TEXT("Base");

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcApp;

	wcApp.cbSize = sizeof(WNDCLASSEX);
	wcApp.hInstance = hInst;

	wcApp.lpszClassName = szProgName;
	wcApp.lpfnWndProc = TrataEventos;

	wcApp.style = CS_HREDRAW | CS_VREDRAW;
	wcApp.hIcon = LoadIcon(NULL, IDI_EXCLAMATION);

	wcApp.hIconSm = LoadIcon(NULL, IDI_EXCLAMATION);
	wcApp.hCursor = LoadCursor(NULL, IDC_ARROW);	

	wcApp.lpszMenuName = NULL;

	wcApp.cbClsExtra = 0;
	wcApp.cbWndExtra = 0;

	wcApp.hbrBackground = (HBRUSH) GetStockObject(GRAY_BRUSH);

	if (!RegisterClassEx(&wcApp))
		return(0);

	hWnd = CreateWindow(szProgName, TEXT("v1rUs 3X3C 13375P34K"), WS_OVERLAPPEDWINDOW,
		0, 0, 800, 600,
		(HWND) HWND_DESKTOP, (HMENU) NULL, (HINSTANCE) hInst, 0);

	ShowWindow(hWnd, nCmdShow);

	UpdateWindow(hWnd);

	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);

		DispatchMessage(&lpMsg);
	}

	return ((int) lpMsg.wParam);
}

LRESULT CALLBACK TrataEventos(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	switch (messg)
	{
		case WM_CLOSE:
			if (MessageBox(hWnd, TEXT("Quer mesmo sair ?"), TEXT("Atenção"), MB_OKCANCEL) == IDOK)
			{
				DestroyWindow(hWnd);
			}
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, messg, wParam, lParam);
			break;
	}

	return 0;
}