#ifndef __UTIL_DEFER_FUNCTION_HEADER__
#define __UTIL_DEFER_FUNCTION_HEADER__

#include <functional>

namespace ccc {

	class DeferFunc {
	public:
		explicit DeferFunc(std::function<void(void)>& fn);
		virtual ~DeferFunc();
	
	
	private:
		std::function<void(void)> m_DeferFn;
	};

};

#endif
