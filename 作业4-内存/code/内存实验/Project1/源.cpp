#include <windows.h>

void main()
{
	SYSTEM_INFO sf;
	GetSystemInfo(&sf);

	//分配内存，标记为提交、可读可写
	LPVOID lpvBase = VirtualAlloc(
		NULL,                 // system selects address
		4096,     // size of allocation
		MEM_COMMIT,   // allocate reserved pages
		PAGE_READWRITE);       // protection = no access
	if (lpvBase == NULL)
		return;
	//向该内存里面写些东西
	unsigned char *ip = (unsigned char *)lpvBase;
	ip[0] = 0x89;
	//修改为“只读”属性，验证是否能写入
	DWORD dw;
	VirtualProtect(lpvBase, 4096, PAGE_READONLY, &dw);
	ip[0]=0x44; 
}