#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 256
int ListDirectoryContents(const wchar_t *sDir)
{
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Path not found: [%s]\n", sDir);
		return 1;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;

			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wprintf(L"File: %s Size: %d\n", sPath, fileSize);
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return 0;
}

void main()
{
	char* a = (char*)malloc(MAX_LEN);
	wchar_t* ca = (wchar_t*)malloc(MAX_LEN);
	fgets(a, MAX_LEN, stdin);
	a[strlen(a) - 1] = '\0';
	swprintf(ca, MAX_LEN, L"%hs", a);
	ListDirectoryContents(ca);
}