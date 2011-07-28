#include "plat.h"
#include "RefCountedObject.h"

////////////////////////////////////////////////////////////////////////////////////////////
// Some caveats to note.
//
// This code is not thread safe. It does not assume a platform and is for
// illustration purposes only. If you were to implement this for real you
// should definitely consider synchronizing access to _refCount. 
//
// E.G. On Windows you might choose to use:
//	::InterlockedIncrement and ::InterlockedDecrement
//
// On other platforms, do what's right for the platform.
////////////////////////////////////////////////////////////////////////////////////////////

RefCountedObject::RefCountedObject() :
	_refCount(1)
{
	// Some argue about starting an object at one. Some prefer
	// starting at zero and using alternate construction methods,
	// say registering a construction function that "knows" how
	// to create an object. For this example we'll just use
	// "new" then move forward with an object that has a ref
	// count of one.
	printf("RefCountedObject constructed, count is %d\n", _refCount);
}

// virtual
RefCountedObject::~RefCountedObject() throw()
{
	printf("RefCountedObject has reached zero, it's going away\n");
}

void RefCountedObject::SayHi(void) throw()
{
	printf("\n-> Hi there! I'm a RefCountedObject, I am cool.\n");
}

void RefCountedObject:: SayBye(void) throw()
{
	printf("\n-> I'm saying 'Bye', but only because you said to.\n");
}

// IRefCnt interface implementation.
unsigned int RefCountedObject::AddRef(void) throw()
{
	int currentCount = ++_refCount;

	printf("\tRefCountedObject::AddRef(), ref count is now %d\n", currentCount);

	return currentCount;
}

unsigned int RefCountedObject::Release(void) throw()
{
	int currentCount = --_refCount;

	// When the reference count reaches zero in a ref counted system
	// the object deletes itself.
	if (0 == currentCount)
	{
		delete this;
	}

	printf("\tRefCountedObject::Release(), ref count is now %d\n", currentCount);
	return currentCount;
}
