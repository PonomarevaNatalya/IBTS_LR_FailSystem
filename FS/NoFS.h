#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#include<AbsFSys.h>
class NoFS : public AbsFSys
{
public:
	NoFS();
};
#endif
