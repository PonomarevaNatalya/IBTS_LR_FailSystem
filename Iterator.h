#include <tchar.h>
#include <windows.h>
#include "AbsFSys.h"

class Iterator
{
protected:
	long Position;
	unsigned long long final;
	unsigned long long end_FS;
public:
	Iterator();
	Iterator(AbsFSys filesys);

	AbsFSys Filesys;

	void StartPosition(long position);
	unsigned int CurrentPosition();
	void FinalPosition(unsigned long position);
	void First();
	void End();
	void Next();
	void Back ();
	bool IsDone();
    bool IsStart ();
	virtual bool GetCurrent(byte *dataBuffer);
};
