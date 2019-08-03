#include<iostream>
#include<windows.h>
#include<string.h>
#include<conio.h >
using namespace std;
void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
// ==================== DUA CON TRO DEN VI TRI =============================
void gotoxy(int x, int y) // Di chuyen toa do con tro trong he toa do De-cat
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
//=====================TRA VE VI TRI X CUA CON TRO==============================
int wherex()
{
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
return screen_buffer_info.dwCursorPosition.X;
}
//=========================TRA VE VI TRI Y CUA CON TRO============================
int wherey( void )
{
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
return screen_buffer_info.dwCursorPosition.Y;
}
// ============= DOI MAU CHU ================
void ChangeColor(int k)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, k);
}
//==============================AN CO TRO MAN HINH CONSOLE=======================
void AnConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//==============================HIEN CON TRO MAN HINH CONSOLE================
void HienConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void KhungNgoai()
{
	char tren = 223;
	char duoi = 220;
	char doc = 219;
	for (int i = 1; i <= 55; i++)
	{
		for (int j = 1; j <= 196; j++)
		{
			if (i == 1 || i == 55)
			{
				if (i == 1)
				{
					if ( j != 1 && j != 196 && j != 40)
					{
						cout << tren;
					}
					else
					{
						cout << doc;
					}
				}
				else
				{
					if (i == 55)
					{
						if (j != 1 && j != 196 && j != 40)
						{
							cout << duoi;
						}
						else
						{
							cout << doc;
						}
					}
				}
			}
			else
			{
				if (j == 1 || j == 196)
				{
					cout << doc;
				}
				else
				{
					if (j == 40)
					{
						cout << doc;
					}
					else
					{
						cout << " ";
					}
				}
			}
		}
		gotoxy(0,wherey()+1);
//		cout << endl;
	}
}
int Menu()
{
	AnConTro();
	string Menu[12];
	Menu[0] = "             THEM MAY BAY             ";
	Menu[1] = "              XOA MAY BAY             ";
	Menu[2] = "           CHINH SUA MAY BAY          ";
	Menu[3] = "           THEM CHUYEN BAY            ";
	Menu[4] = "             XOA CHUYEN BAY           ";
	Menu[5] = "         CHINH SUA CHUYEN BAY         ";
	Menu[6] = "                DAT VE                ";
	Menu[7] = "               HUY VE                 ";
	Menu[8] = "DANH SACH HANH KHACH THUOC CHUYEN BAY ";
	Menu[9] = "   CHUYEN BAY KHOI HANH TRONG NGAY    ";
	Menu[10]= "   CAC VE CON TRONG CUA CHUYEN BAY    ";
	Menu[11]= "       THONG KE LUOT THUC HIEN        ";
	for (int i = 0; i < 12; i++)
	{
		gotoxy(1,15+2*i);
		cout << Menu[i];
	}
	int dem = 0;
	gotoxy(1,15+2*dem);
	ChangeColor(224);
	cout << Menu[dem];
	char c = getch();
	bool kytu;
	if (c == -32 || c == 0)
	{
		kytu = 0;
		c = getch();
	}
	else
	{
		kytu = 1;
	}
	while (c != 13 && c != 27)
	{
		if (c == 72 && !kytu) // phim up 
		{
			if (dem > 0)
			{
				ChangeColor(15);
				gotoxy(1,15+2*dem);
				cout << Menu[dem];
				dem--;
				ChangeColor(224);
				gotoxy(1,15+2*dem);
				cout << Menu[dem];
			}
		}
		if (c == 80 && !kytu)
		{
			if (dem < 11)
			{
				ChangeColor(15);
				gotoxy(1,15+2*dem);
				cout << Menu[dem];
				dem++;
				ChangeColor(224);
				gotoxy(1,15+2*dem);
				cout << Menu[dem];
			}
		}
		c = getch();
		if (c == -32 || c == 0)
		{
			c = getch();
			kytu = 0;
		}
		else
		{
			kytu = 1;
		}
	}
	HienConTro();
	if (c == 27)
	{
		return 0; // Exit
	}
	return dem+1;
}

