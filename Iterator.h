#pragma once
#include <map>
#include <array>

template <typename T, size_t dim_count>
class Iterator
{
	using my_array = std::array<size_t, dim_count>;
	using my_matrix = std::map<my_array, T>;

public:
	Iterator(my_matrix& _matrix, size_t _current_index)
		: matrix(_matrix), current_index(_current_index)
	{

	}

	bool operator!=(const Iterator& _it) const
	{
		return current_index != _it.current_index;
	}

	Iterator& operator++()
	{
		++current_index;
		return *this;
	}

	Iterator& operator--()
	{
		--current_index;
		return *this;
	}

	Iterator& operator=(Iterator& _it)
	{
		current_index = _it.current_index;
		return *this;
	}

	const my_array& operator*()
	{
		auto it = matrix.begin();
		std::advance(it, current_index);
		return it->first;
	}

private:
	my_matrix& matrix;
	size_t current_index;
};