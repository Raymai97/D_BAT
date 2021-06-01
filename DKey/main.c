#include <Windows.h>

int AppMain(void)
{
	int ret = 0;
	INPUT_RECORD rec = { 0 };
	DWORD dwRead = 0;
	for (;;)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwRead);
		if (dwRead != 1) continue;
		if (rec.EventType != KEY_EVENT) continue;
		if (!rec.Event.KeyEvent.bKeyDown) continue;
		ret = rec.Event.KeyEvent.wVirtualKeyCode;
		break;
	}
	return ret;
}

void RawMain(void)
{
	ExitProcess(AppMain());
}
