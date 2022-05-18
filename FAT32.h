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
	byte Rezerv[2];
	byte kolvoCopyFat[1];
	byte Skip[15];
	byte KolvoSect[4];
	byte razmerFat[4];

} FAT32_MBR;

#pragma pack(pop)

#endif
