#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#include "Unit1.h"

class Signature {
public:
	UnicodeString Signature_(BYTE *dataBuffer, bool Pdf, bool Office, bool Z7, bool Vmdk, bool Png);
private:
	bool Poisk(BYTE sign[],int length,BYTE *dataBuffer);
};

#endif
