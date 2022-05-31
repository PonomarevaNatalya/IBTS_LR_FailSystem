#include <iostream>
#include "Pusto_Decorator.h"


	Pusto_Decorator::Pusto_Decorator(Iterator iterator){
		Diterator=iterator;
		Filesys=iterator.Filesys;
		end_FS=Filesys.kolvoClast;
	}


	bool Pusto_Decorator::GetCurrent(byte *dataBuffer){
    if(Diterator.GetCurrent(dataBuffer))
		{
			for(int i=0;i<1024;i++)
			{
			if(dataBuffer[i]!=0)
			   return true;
			}

			return false;
		}
	}
