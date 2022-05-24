#include <iostream>
#include "NoFS.h"

class NoFS : public AbsFSys
{
public:
	NoFS()
	{
	razmerClast=0;
	kolvoClast=0;
	razmer=0;
	name="Unknown FS";
	}


};
