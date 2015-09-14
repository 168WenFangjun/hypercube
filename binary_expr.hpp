#ifndef BINARY_EXPR_HPP_
#define BINARY_EXPR_HPP_

namespace hc
{

using namespace std;

template <typename Op, typename Iterator1, typename Iterator2>
class binary_iter
{
public:
    using type = binary_iter<Op, Iterator1, Iterator2>;
    using value_type = const decltype(Op::op(*declval<Iterator1>(), *declval<Iterator2>()));

private:
    Iterator1 m_left;
    Iterator2 m_right;

public:
    binary_iter(Iterator1 left, Iterator2 right) :
        m_left (left),
        m_right (right)
    {

    }

    value_type operator*() const
    {
        return Op::op(*m_left, *m_right);
    }

    type& operator++()
    {
        ++m_left;
        ++m_right;
        return *this;
    }

    type& operator--() 
    {
        --m_left;
        --m_right;
        return *this;
    }

    type operator++(int) 
    {
        type temp_expr(m_left, m_right);
        ++(*this);
        return temp_expr;
    }

    type operator--(int) 
    {
        type temp_expr(m_left, m_right);
        --(*this);
        return temp_expr;
    }

    bool operator==(const type& rhs)
    {
        return m_left == rhs.m_left || m_right == rhs.m_right;
    }

};

template <typename Op, typename Iterable1, typename Iterable2, typename Guard1 = decltype(declval<Iterable1>().begin()), typename Guard2 = decltype(declval<Iterable2>().begin())>
class binary_expr
{
public:
    using type = binary_expr<Op, Iterable1, Iterable2>;
    using value_type = decltype(Op::op(*declval<Iterable1>().begin(), *declval<Iterable2>().begin()));
    using iterator = binary_iter<Op, decltype(declval<Iterable1>().begin()), decltype(declval<Iterable2>().begin())>;

private:
    Iterable1 m_left;
    Iterable2 m_right;

public:
    binary_expr(Iterable1 left, Iterable2 right) :
        m_left (left),
        m_right (right)
    {

    }

    iterator begin() const
    {
        return iterator(m_left.begin(), m_right.begin());
    }

    iterator end() const
    {
        return iterator(m_left.end(), m_right.end());
    }
};

}

#endif /* BINARY_EXPR_HPP_ */
