
#include "windows.h"

#include "conio.h"

#include <iostream>

using namespace std;

void MemoryStatus()

{

	MEMORYSTATUS memStatus;

	GlobalMemoryStatus(&memStatus);

	cout << "内存初始状态：" << endl;

	cout << "内存繁忙程度=" << memStatus.dwMemoryLoad << endl;

	cout << "总物理内存=" << memStatus.dwTotalPhys << endl;

	cout << "可用物理内存=" << memStatus.dwAvailPhys << endl;

	cout << "总页文件=" << memStatus.dwTotalPageFile << endl;

	cout << "可用页文件=" << memStatus.dwAvailPageFile << endl;

	cout << "总进程空间=" << memStatus.dwTotalVirtual << endl;

	cout << "可用进程空间=" << memStatus.dwAvailVirtual << endl;

}



int main()

{

	cout << "初始状态：" << endl;

	MemoryStatus();

	//申请内存

	char* lpv = (char*)VirtualAlloc(NULL, 1024 * 1024 * 1024, MEM_RESERVE,

		PAGE_READWRITE);

	cout << "申请内存后：" << endl;

	MemoryStatus();

	//提交内存

	lpv = (char*)VirtualAlloc(lpv, 1024 * 1024 * 1024, MEM_COMMIT,

		PAGE_READWRITE);

	cout << "提交内存后：" << endl;

	MemoryStatus();

	//使用内存

	strcpy(lpv, "abc");

	cout << "使用内存后：" << endl;

	MemoryStatus();

	//释放内存

	VirtualFree(lpv, 1024 * 1024 * 1024, MEM_RELEASE);



	system("pause");

	return 0;

}