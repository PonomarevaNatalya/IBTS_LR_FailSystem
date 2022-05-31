#include <tchar.h>
#include <windows.h>

#include "Decorator.h"

class Pusto_Decorator : public Decorator
{
public:
	Pusto_Decorator(Iterator iterator);
	bool GetCurrent(byte *dataBuffer) override;
    Iterator Diterator;
};
