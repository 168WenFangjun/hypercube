#ifndef UNARY_EXPR_HPP_
#define UNARY_EXPR_HPP_

namespace hc
{

using namespace std;

template <typename Op, typename Iterator>
class unary_iter
{
public:
    using type = unary_iter<Op, Iterator>;
    using value_type = const decltype(Op::op(*declval<Iterator>()));

private:
    Iterator m_it;

public:
    unary_iter(Iterator it) :
        m_it (it)
    {

    }

    value_type operator*() const
    {
        return Op::op(*m_it);
    }

    type& operator++()
    {
        ++m_it;
        return *this;
    }

    type& operator--() 
    {
        --m_it;
        return *this;
    }

    type operator++(int) 
    {
        type temp_expr(m_it);
        ++(*this);
        return temp_expr;
    }

    type operator--(int) 
    {
        type temp_expr(m_it);
        --(*this);
        return temp_expr;
    }

    bool operator==(const type& rhs)
    {
        return m_it == rhs.m_it;
    }

};

template <typename Op, typename Iterable, typename Guard = decltype(declval<Iterable>().begin())>
class unary_expr
{
public:
    using type = unary_expr<Op, Iterable>;
    using value_type = decltype(Op::op(*declval<Iterable>().begin()));
    using iterator = unary_iter<Op, decltype(declval<Iterable>().begin())>;

private:
    Iterable m_data;

public:
    unary_expr(Iterable data) :
        m_data (data)
    {

    }

    iterator begin() const
    {
        return iterator(m_data.begin());
    }

    iterator end() const
    {
        return iterator(m_data.end());
    }
};

}

#endif /* UNARY_EXPR_HPP_ */
