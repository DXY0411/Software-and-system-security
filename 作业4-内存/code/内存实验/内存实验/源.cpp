
#include "windows.h"

#include "conio.h"

#include <iostream>

using namespace std;

void MemoryStatus()

{

	MEMORYSTATUS memStatus;

	GlobalMemoryStatus(&memStatus);

	cout << "�ڴ��ʼ״̬��" << endl;

	cout << "�ڴ深æ�̶�=" << memStatus.dwMemoryLoad << endl;

	cout << "�������ڴ�=" << memStatus.dwTotalPhys << endl;

	cout << "���������ڴ�=" << memStatus.dwAvailPhys << endl;

	cout << "��ҳ�ļ�=" << memStatus.dwTotalPageFile << endl;

	cout << "����ҳ�ļ�=" << memStatus.dwAvailPageFile << endl;

	cout << "�ܽ��̿ռ�=" << memStatus.dwTotalVirtual << endl;

	cout << "���ý��̿ռ�=" << memStatus.dwAvailVirtual << endl;

}



int main()

{

	cout << "��ʼ״̬��" << endl;

	MemoryStatus();

	//�����ڴ�

	char* lpv = (char*)VirtualAlloc(NULL, 1024 * 1024 * 1024, MEM_RESERVE,

		PAGE_READWRITE);

	cout << "�����ڴ��" << endl;

	MemoryStatus();

	//�ύ�ڴ�

	lpv = (char*)VirtualAlloc(lpv, 1024 * 1024 * 1024, MEM_COMMIT,

		PAGE_READWRITE);

	cout << "�ύ�ڴ��" << endl;

	MemoryStatus();

	//ʹ���ڴ�

	strcpy(lpv, "abc");

	cout << "ʹ���ڴ��" << endl;

	MemoryStatus();

	//�ͷ��ڴ�

	VirtualFree(lpv, 1024 * 1024 * 1024, MEM_RELEASE);



	system("pause");

	return 0;

}