#include "IRefCnt.h"

class RefCountedObject :
	public IRefCnt
{
public:
	RefCountedObject();
	virtual ~RefCountedObject() throw();

	void SayHi(void) throw();
	void SayBye(void) throw();

	// IRefCnt interface implementation.
	unsigned int AddRef(void) throw();
	unsigned int Release(void) throw() ;

private:
	unsigned int _refCount;

}; // RefCountedObject