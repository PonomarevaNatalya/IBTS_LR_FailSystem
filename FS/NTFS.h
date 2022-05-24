#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#include<AbsFSys.h>
#pragma pack(push,1)

typedef struct
{
	byte Text[11];
	byte BaitSect[2];
	byte SectKlast[1];
    byte Skip[26];
	byte KolvoSect[8];

} NTFS_MBR;

#pragma pack(pop)

#endif
