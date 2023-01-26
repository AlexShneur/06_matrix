#pragma once
#include "Iterator.h"

#include <memory>

template <typename T, T default_value, size_t dim_count = 2>
class Matrix
{
public:

    using my_array = std::array<size_t, dim_count>;
    using my_iterator = Iterator<T, dim_count>;

    Matrix()
    {
        proxy = std::make_shared<ArrayProxy>(*this);
    }

    size_t size() 
    {
        return matrix.size();
    }

    my_iterator begin()
    {
        return my_iterator(matrix.begin());
    }

    my_iterator end()
    {
        return my_iterator(matrix.end());
    }

    class ArrayProxy
    {
    public:
        ArrayProxy(Matrix& _matrix)
            : matrix(_matrix)
        {
            current_dim = 0;
        }

        ArrayProxy& operator [](size_t new_index)
        {
            ++current_dim;
            set_array_index(new_index);
            return *this;
        }

        void reset_current_dimension()
        {
            current_dim = 0;
        }

        void set_array_index(size_t new_index)
        {
            array[current_dim] = new_index;
        }

        bool operator==(const T& val) const
        {
            return val == matrix.get_value_from_array(array);
        }

        void operator=(const T& val)
        {
            matrix.set_value_to_array(array, val);
        }

        operator T()
        {
            return matrix.get_value_from_array(array);
        }

    private:
        Matrix& matrix;
        my_array array{};
        size_t current_dim;
    };

    ArrayProxy& operator [](size_t index_num)
    {
        auto& pr = static_cast<ArrayProxy&>(*proxy);
        pr.reset_current_dimension();
        pr.set_array_index(index_num);

        return *proxy;
    }

private:
    const T& get_value_from_array(my_array array) const
    {
        auto it = matrix.find(array);
        if (it != matrix.end())
        {
            return it->second;
        }
        else
        {
            return default_value;
        }
    }

    void set_value_to_array(my_array array, const T& val)
    {
        if (val != default_value)
        {
            matrix[array] = val;
        }
    }

    std::map<my_array, T> matrix;
    std::shared_ptr<ArrayProxy> proxy;
};
