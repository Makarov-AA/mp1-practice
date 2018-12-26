#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ListDirectoryContents(const wchar_t *sDir, ULONGLONG* size, wchar_t** file_name)
{
	int i;
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
			size[i] = fileSize;
			wchar_t[i] = 
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wprintf(L"File: %s Size: %d\n", sPath, fileSize);
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return 0;
}
void bubble(int* a, int n)
{
	int i = 0, j, tmp;
	for (; i < n; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}

}

void main()
{
	struct file_data
	{
		ULONGLONG* size;
		wchar_t** file_name;
	} data;
	int sort_num;
	setlocale(LC_ALL, "Russian");
	printf("Введите путь");
	ListDirectoryContents(L"E:\\stack\\", data.size, data.file_name);
	printf("Выберите метод сортировки:\n1: Пузырьком\n2:Выбором\n3:Вставками\n");
	scanf("%d", &sort_num);
	switch (sort_num)
	{
	case 1:

	} 
}