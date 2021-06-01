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

static WORD atox(TCHAR c)
{
	if (c >= 'a' && c <= 'f') c -= ('a' - 'A');
	if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
	if (c >= '0' && c <= '9') return (c - '0');
	return -1;
}

int AppMain(void)
{
	PCTSTR p = get_pszArgv0();
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD a = atox(p[0]);
	if (a == -1) return 87;
	if (p[1]) {
		WORD b = atox(p[1]);
		if (b == -1) return 87;
		a = (a << 4) | b;
	}
	return SetConsoleTextAttribute(hStdOut, a) ? 0 : 1;
}

void RawMain(void)
{
	ExitProcess(AppMain());
}
