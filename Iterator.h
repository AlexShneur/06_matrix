#pragma once
#include <map>
#include <array>

template <typename T, size_t dim_count>
class Iterator
{
	using my_array = std::array<size_t, dim_count>;
	using my_matrix = std::map<my_array, T>;

public:
	Iterator(typename my_matrix::iterator _mit)
		: mit(_mit)
	{

	}

	bool operator!=(const Iterator& _it) const
	{
		return mit != _it.mit;
	}

	Iterator& operator++()
	{
		++mit;
		return *this;
	}

	Iterator& operator--()
	{
		--mit;
		return *this;
	}

	Iterator& operator=(Iterator& _it)
	{
		mit = _it.mit;
		return *this;
	}

	typename my_matrix::value_type& operator*()
	{
		return *mit;
	}
private:
	typename my_matrix::iterator mit;
};