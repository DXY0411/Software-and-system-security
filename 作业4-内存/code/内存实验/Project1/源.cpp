#include <windows.h>

void main()
{
	SYSTEM_INFO sf;
	GetSystemInfo(&sf);

	//�����ڴ棬���Ϊ�ύ���ɶ���д
	LPVOID lpvBase = VirtualAlloc(
		NULL,                 // system selects address
		4096,     // size of allocation
		MEM_COMMIT,   // allocate reserved pages
		PAGE_READWRITE);       // protection = no access
	if (lpvBase == NULL)
		return;
	//����ڴ�����дЩ����
	unsigned char *ip = (unsigned char *)lpvBase;
	ip[0] = 0x89;
	//�޸�Ϊ��ֻ�������ԣ���֤�Ƿ���д��
	DWORD dw;
	VirtualProtect(lpvBase, 4096, PAGE_READONLY, &dw);
	ip[0]=0x44; 
}