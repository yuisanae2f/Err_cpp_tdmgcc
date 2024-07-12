// DataStructure.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include <iostream>
#include <vector>

namespace ae2f {
	struct iAllocator {
		virtual void* ptr() = 0;
	};

	template<typename t>
	struct cAllocator : public iAllocator {
		t&& raw;
		virtual void* ptr() override { return ((void*)&raw); }
		cAllocator(t& val) : raw((t&&)val) {
			const size_t _amp = sizeof(val);
			const size_t _div = sizeof(val[0]);
			for (size_t i = 0; i < (_amp / _div); i++) {
				raw[i] = val[i];
			} 
		}
		cAllocator(t&& val) : raw((t&&)val) {
			const size_t _amp = sizeof(val);
			const size_t _div = sizeof(val[0]);

			for (size_t i = 0; i < (_amp / _div); i++) {
				raw[i] = val[i];
			}
		}
	};
}

int main()
{
	ae2f::cAllocator<int[3]> a({ 3, 65, 5 });
	std::cout << a.raw[1];
	return 0;
}
