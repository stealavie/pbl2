#include"RSA.h"

unsigned ConvertToInt(const std::string& word)
{
	unsigned k=0;
	for(char c: word)
	{
		k+=word[c];
	}
	return k;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i ++) {
        if (n % i == 0) return false;
    }
    return true;
}

pair<int, int> closest_primes(int n) {
    int half = n / 2;
    for (int i = 0; i <= half; ++i) {
        if (is_prime(half - i) && is_prime(half + i)) {
            return make_pair(half - i, half + i);
        }
    }
    return make_pair(-1, -1);  
} bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i ++) {
        if (n % i == 0) return false;
    }
    return true;
}

pair<int, int> closest_primes(int n) {
    int half = n / 2;
    for (int i = 0; i <= half; ++i) {
        if (is_prime(half - i) && is_prime(half + i)) {
            return make_pair(half - i, half + i);
        }
    }
    return make_pair(-1, -1);  
}

void RSA::SetKey(const int& n)
{
	pair<int, int> primes = closest_primes(n);
    p=primes.first;
	q=primes.second; 
}


unsigned RSA::calculate_n()
{
	n = p * q;
	return n;
}

unsigned RSA::calculate_phi()
{
	phi_n = (p - 1) * (q - 1);
	return phi_n;
}

unsigned RSA::calculate_e()
{
	unsigned i = 2;
	while (gcd(i, phi_n) != 1)
		i++;
	e = i;
	if (e >= phi_n)
		exit(0);
	return e;
}

unsigned RSA::calculate_d()
{
	unsigned i = 1;
	while (((phi_n * i) + 1) % e != 0)
		i++;
	d = ((i * phi_n) + 1) / e;
	return d;
}


boost::multiprecision::cpp_int RSA::encrypt(const std::string& word)
{
	RSA* obj=new RSA();
	m=ConvertToInt(word);
	obj->SetKey(m);
	obj->calculate_e();
	obj->calculate_n();
	c = (boost::multiprecision::cpp_int(boost::multiprecision::pow(boost::multiprecision::cpp_int(m), e))) % n;
	delete obj;
	return c;
}


boost::multiprecision::cpp_int RSA::decrypt()
{
	m_0 = (boost::multiprecision::cpp_int(boost::multiprecision::pow(boost::multiprecision::cpp_int(c), d))) % n;
	return m_0;
}

