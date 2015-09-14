#ifndef SCALAR_EXPR_HPP_
#define SCALAR_EXPR_HPP_

namespace hc
{

using namespace std;

template <typename T>
class scalar_expr
{
private:
    const T m_value;

public:
    using value_type = T;
    using type = scalar_expr<T>;
    using const_iterator = type;

    scalar_expr(value_type value) :
        m_value (value)
    {
    }
    
    const value_type& operator*() const
    {
        return m_value;
    }

    const_iterator begin() const
    {
        return *this;
    }

    const_iterator end() const
    {
        return *this;
    }

    bool operator==(const type& rhs)
    {
        return this == &rhs;
    }

    type& operator++() 
    {
        return *this;
    }

    type& operator--() 
    {
        return *this;
    }

    type& operator++(int) 
    {
        return *this;
    }

    type& operator--(int) 
    {
        return *this;
    }
};

template <typename T> using value_t = typename T::value_type;
template <typename T> using scalar_t = scalar_expr<typename T::value_type>;

}

#endif /* SCALAR_EXPR_HPP_ */
