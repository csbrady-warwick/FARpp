#ifndef COMPARE_H
#define COMPARE_H

#include <cmath>
#include <complex>

template<typename T1, typename T2>
bool softCompare(const T1& p1, const T2& p2, const T1 thresh=1.0e-8){
	return !(std::abs(p1-p2)<=thresh);
}

template<typename T1, typename T2>
bool softCompare(const std::complex<T1>& p1, const std::complex<T2>& p2, const T1 thresh=1.0e-8){
	return !(std::abs(p1.real()-p2.real())<=thresh && std::abs(p1.imag()-p2.imag())<=thresh);
}

#endif
