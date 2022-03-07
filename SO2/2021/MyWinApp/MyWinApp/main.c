#include <windows.h>
#include <tchar.h>
#include <windowsx.h>

typedef struct {
	int xi;
	int yi;

	int xf;
	int yf;
} myRect;

#define MAX_RECTS 250
myRect mat[MAX_RECTS];

int numrect;
int drawing;

int x1, y1, x2, y2;
POINT p;

LRESULT CALLBACK TrataEventos(HWND, UINT, WPARAM, LPARAM);
ATOM myRegisterClass(HINSTANCE myInst, TCHAR * winName);
HWND myCreateWindow(HINSTANCE myInst, TCHAR* winName);

TCHAR szProgName[] = TEXT("Base");

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	TCHAR winName[] = TEXT("Nova App");
	HWND hWnd;
	HWND hWnd2;
	MSG msg;

	if (!myRegisterClass(hInst, winName))
		return 0;

	hWnd = myCreateWindow(hInst, winName);
	hWnd2 = myCreateWindow(hInst, winName);

	SetWindowText(hWnd, TEXT("Janela 1"));
	SetWindowText(hWnd2, TEXT("Janela 2"));

	ShowWindow(hWnd, nCmdShow);
	ShowWindow(hWnd2, nCmdShow);
	UpdateWindow(hWnd);
	UpdateWindow(hWnd2);

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

ATOM myRegisterClass(HINSTANCE myInst, TCHAR* winName)
{
	WNDCLASSEX myWin;

	myWin.cbSize = sizeof(WNDCLASSEX);
	myWin.hInstance = myInst;
	myWin.lpszClassName = winName;
	myWin.lpfnWndProc = TrataEventos;
	myWin.style = CS_HREDRAW | CS_VREDRAW;
	myWin.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	myWin.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
	myWin.hCursor = LoadCursor(NULL, IDC_ARROW);
	myWin.lpszMenuName = NULL;
	myWin.cbClsExtra = 0;
	myWin.cbWndExtra = 0;
	myWin.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);

	return RegisterClassEx(&myWin);
}

HWND myCreateWindow(HINSTANCE myInst, TCHAR* winName)
{
	return CreateWindow(winName, TEXT("Estudo Especial SO2"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, HWND_DESKTOP, NULL, myInst, NULL);
}

LRESULT CALLBACK TrataEventos(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static TCHAR* myMsg = TEXT("Desenho de Rectangulos");
	PAINTSTRUCT ps;
	HDC hdc;
	int i;

	switch (msg)
	{
		case WM_CREATE:
		{
			drawing = 0;
			numrect = 0;
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		case WM_LBUTTONDOWN:
		{
			x1 = LOWORD(lParam);
			y1 = HIWORD(lParam);
			drawing = 1;
			break;
		}
		case WM_MOUSEMOVE:
		{
			if (drawing == 1)
			{
				x2 = LOWORD(lParam);
				y2 = HIWORD(lParam);
				InvalidateRect(hWnd, NULL, TRUE);
				break;
			}
		}
		case WM_LBUTTONUP:
		{
			if (drawing == 1)
			{
				x2 = LOWORD(lParam);
				y2 = HIWORD(lParam);
				mat[numrect].xi = x1;
				mat[numrect].yi = y1;
				mat[numrect].xf = x2;
				mat[numrect].yf = y2;

				if (numrect < MAX_RECTS - 1)
					numrect++;
				drawing = 0;
				InvalidateRect(hWnd, NULL, TRUE);
			}
		}
		case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);

			TextOut(hdc, 50, 50, myMsg, _tcslen(myMsg));

			for (i = 0; i < numrect; i++)
			{
				Rectangle(hdc, mat[i].xi, mat[i].yi, mat[i].xf, mat[i].yf);
			}

			if (drawing == 1)
			{
				Rectangle(hdc, x1, y1, x2, y2);
			}

			EndPaint(hWnd, &ps);
			break;
		}
		case WM_CLOSE:
		{
			int msgBoxId = MessageBox(hWnd, L"Really want to quit?", L"Quit", MB_ICONEXCLAMATION | MB_YESNO);

			if (msgBoxId == IDYES)
				PostQuitMessage(0);
			break;
		}
		default:
			return(DefWindowProc(hWnd, msg, wParam, lParam));
			break;
	}

	return(0);
}