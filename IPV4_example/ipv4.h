#include <array>
#include <iostream>
#include <string>
#include <sstream>

class ipv4 {
private:
	std::array<unsigned char, 4> data;
public:
	// constexpr constructors means that static initialization can be performed

	constexpr ipv4() : data{ {0} } {} // default constuctor
	constexpr ipv4(unsigned char const a, unsigned char const b,
		unsigned char const c, unsigned char const d) // constuctor from 4 separate bytes
		: data{ a,b,c,d } {}
	explicit constexpr ipv4(unsigned long a) // constructor from 4 byte data
		: data{ {static_cast<unsigned char>(( a >> 24) & 0xFF),
				 static_cast<unsigned char>((a >> 16) & 0xFF),
			     static_cast<unsigned char>((a>>8) & 0xFF),
				 static_cast<unsigned char>(a & 0xFF)} } {}
	ipv4(ipv4& other) noexcept : data{ other.data } {} // copy constructor
	ipv4& operator=(const ipv4& other) noexcept // copy assignment
	{
		data = other.data;
		return *this;
	}

	constexpr unsigned long to_ulong() const noexcept
	{
		return data[0] << 24 | data[1] << 16 | data[2] << 8 | data[3];
	}
	std::string to_string() const
	{
		std::stringstream sstr;
		sstr << *this;
		return sstr.str();
	}

	ipv4& operator++()
	{
		*this = ipv4(1 + to_ulong());
		return *this;
	}

	ipv4& operator++(int)
	{
		ipv4 result(*this);
		++(*this);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const ipv4& a)
	{
		// casting to int to see the ip adress in numeric representation
		os << static_cast<int>(a.data[0]) << '.'
			<< static_cast<int>(a.data[1]) << '.'
			<< static_cast<int>(a.data[2]) << '.'
			<< static_cast<int>(a.data[3]);
		return os;
	}
	friend std::istream& operator>>(std::istream& is, ipv4& a)
	{
		char d1, d2, d3; // dots of the ip adress
		int b1, b2, b3, b4; // bytes of the ip adress
		is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4; // read ip adress
		if (d1 == '.' && d2 == '.' && d3 == '.')
			a = ipv4(b1, b2, b3, b4); // constuct the ip adress from 4 bytes
		else
			is.setstate(std::ios_base::failbit);
		return is;
	}

	friend bool operator==(const ipv4& a, const ipv4& b) noexcept
	{
		return a.data == b.data;
	}

	friend bool operator!=(const ipv4& a, const ipv4& b) noexcept
	{
		return !(a == b);
	}

	friend bool operator<(const ipv4& a, const ipv4& b) noexcept
	{
		return a.to_ulong() < b.to_ulong();
	}

	friend bool operator>(const ipv4& a, const ipv4& b) noexcept
	{
		return b < a;
	}

	friend bool operator<=(const ipv4& a, const ipv4& b) noexcept
	{
		return !(a > b);
	}

	friend bool operator>=(const ipv4& a, const ipv4& b) noexcept
	{
		return !(a < b);
	}
};