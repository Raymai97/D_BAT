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

static BOOL tryParseToShort(PCTSTR *pp, SHORT *pVal)
{
	PCTSTR p = *pp;
	if (*p >= '0' && *p <= '9') {
		*pVal = 0;
		for (; *p >= '0' && *p <= '9'; ++p) {
			*pVal *= 10;
			*pVal += *p - '0';
		}
		*pp = p;
		return TRUE;
	}
	return FALSE;
}

int AppMain(void)
{
	int ret = 0;
	PCTSTR p = get_pszArgv0();
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi = { 0 };
	SHORT *pXY = &csbi.dwCursorPosition.Y;
	if (*p == 'x') {
		pXY = &csbi.dwCursorPosition.X; ++p;
	}
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	if (tryParseToShort(&p, pXY)) {
		SetConsoleCursorPosition(hStdOut, csbi.dwCursorPosition);
	}
	if (*p == 'e') {
		SHORT i, nNeeded = csbi.dwSize.X - csbi.dwCursorPosition.X;
		for (i = 0; i < nNeeded; ++i) {
			DWORD cbWri = 0;
			WriteFile(hStdOut, " ", 1, &cbWri, NULL);
		}
		SetConsoleCursorPosition(hStdOut, csbi.dwCursorPosition);
	}
	return ret;
}

void RawMain(void)
{
	ExitProcess(AppMain());
}
