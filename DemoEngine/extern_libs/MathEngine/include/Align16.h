#ifndef ALIGN_16_H
#define ALIGN_16_H

#include <malloc.h>

namespace lge
{
	// Inherit from this class to enforce 16-byte alignment when dynamically allocating object
	// Child classes must obviously be the size of 16 bytes!
	class Align16
	{
	public:
		void *operator new(size_t size)
		{
			void *p = _aligned_malloc(size, 16);
			return p;
		}

			void *operator new[] (size_t size)
		{
			void *p = _aligned_malloc(size, 16);
			return p;
		}

			void operator delete(void *p)
		{
			_aligned_free(p);
		}

		void operator delete[] (void *p)
		{
			_aligned_free(p);
		}
	};
}

#endif