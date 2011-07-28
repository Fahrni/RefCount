// IRefCnt - Base interface for a ref counted object.
//
// Note, most ref counted systems I've used don't actaully
// return a count from their methods. I've done it here
// for illustration purposes.
//
class IRefCnt
{
public:
	// Pure virtual interface.
	virtual unsigned int AddRef(void) throw()	= 0;
	virtual unsigned int Release(void) throw()	= 0;
};