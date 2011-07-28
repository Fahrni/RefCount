// RefCount.cpp : Defines the entry point for the console application.
//
#include "plat.h"
#include "RefCountedObject.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// Create a ref counted object, initial value is ONE.
	RefCountedObject* rco = new RefCountedObject();
	if (rco)
	{
		// The object is completely valid at this point, that is if the
		// pointer is NOT null.
		rco->SayHi();

		// Bump the Reference Count, should now be TWO.
		//	1) Was one at ctor time.
		//	2) Doing and AddRef() bumps to two.
		rco->AddRef();

		// Yep, we're still good.
		rco->SayBye();

		// Decrement the count, should still be ONE.
		rco->Release();

		// Ah, yes, our object is still good!
		rco->SayHi();

		// Do final release, this will cause the object to go away.
		rco->Release();

		// DO NOT REFERENCE THE OBJECT NOW! It's gone.
	}

	return 0;
}

