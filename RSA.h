#include<boost/multiprecision/cpp_int.hpp>
#include<iostream>
#include<vector>
#include<cmath>

using boost::multiprecision::cpp_int;

using namespace std;

template<typename T>

T gcd(T a, T b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}


class RSA
{
public:
	unsigned p;
	unsigned q;
	unsigned n;
	unsigned phi_n;
	unsigned e;
	unsigned d;
	unsigned m;


	boost::multiprecision::cpp_int m_0;
	boost::multiprecision::cpp_int c;


	~RSA();

	
	void SetKey(const int&);
	unsigned calculate_n();
	unsigned calculate_phi();
	unsigned calculate_e();
	unsigned calculate_d();

	boost::multiprecision::cpp_int encrypt(const std::string&);
	boost::multiprecision::cpp_int decrypt();
};