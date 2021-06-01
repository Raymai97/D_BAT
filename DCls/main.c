#include <Windows.h>

static PCTSTR get_pszArgv0(void)
{
	PCTSTR p = GetCommandLine();
	if (*p == '\"') {
		for (++p; *p++ != '\"';);
	}
	else {
		for (++p; *p++ != ' ';);
	}
	while (*p == ' ') ++p;
	return p;
}

int AppMain(void)
{
	int ret = 0;
	PCTSTR p = get_pszArgv0();
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0 };
	if (*p >= '0' && *p <= '9') {
		for (; *p >= '0' && *p <= '9'; ++p) {
			coord.Y *= 10;
			coord.Y += *p - '0';
		}
		SetConsoleCursorPosition(hStdOut, coord);
	}
	if (*p == 'e') {
		CONSOLE_SCREEN_BUFFER_INFO csbi = { 0 };
		SHORT i, nNeeded;
		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		coord.Y = csbi.dwCursorPosition.Y;
		nNeeded = csbi.dwSize.X - csbi.dwCursorPosition.X;
		for (i = 0; i < nNeeded; ++i) {
			DWORD cbWri = 0;
			WriteFile(hStdOut, " ", 1, &cbWri, NULL);
		}
		SetConsoleCursorPosition(hStdOut, coord);
	}
	return ret;
}

void RawMain(void)
{
	ExitProcess(AppMain());
}
