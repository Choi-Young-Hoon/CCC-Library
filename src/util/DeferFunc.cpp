#include "ccc/util/DeferFunc.hpp"
using namespace ccc;


DeferFunc::DeferFunc(std::function<void(void)>& fn)
:m_DeferFn(fn)
{}

DeferFunc::~DeferFunc() { 
	m_DeferFn();
}
