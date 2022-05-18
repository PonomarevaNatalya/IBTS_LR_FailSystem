#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#include<AbsFSys.h>
#pragma pack(push,1)

typedef struct
{
	byte Text[11];
	byte null[81];
	byte Kolvoclast[4];
	byte null2[12];
	byte razm2Sec[1];
	byte clastMnoz[1];

} exFAT_MBR;

#pragma pack(pop)

#endif
