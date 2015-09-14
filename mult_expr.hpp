#ifndef MULT_EXPR_HPP_
#define MULT_EXPR_HPP_

#include "binary_expr.hpp"
#include "scalar_expr.hpp"

namespace hc
{

class mult_op
{
public:
    template <typename T1, typename T2>
    static auto op(T1 x1, T2 x2) -> decltype(x1 * x2)
    {
        return x1 * x2;
    }

};

template <typename Iterable1, typename Iterable2> using mult_expr = binary_expr<mult_op, Iterable1, Iterable2>;

template <typename Iterable>
mult_expr<scalar_t<Iterable>, const Iterable&>
operator*(value_t<Iterable> left, const Iterable& right)
{
    return mult_expr<scalar_t<Iterable>, const Iterable&>(scalar_t<Iterable>(left), right);
}

template <typename Iterable>
mult_expr<const Iterable&, scalar_t<Iterable>>
operator*(const Iterable& left, value_t<Iterable> right)
{
    return mult_expr<const Iterable&, scalar_t<Iterable>>(left, scalar_t<Iterable>(right));
}

template <typename Iterable1, typename Iterable2>
mult_expr<const Iterable1&, const Iterable2&>
operator*(const Iterable1& left, const Iterable2& right)
{
    return mult_expr<const Iterable1&, const Iterable2&>(left, right);
}

}

#endif /* MULT_EXPR_HPP_ */
