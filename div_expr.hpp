#ifndef DIV_EXPR_HPP_
#define DIV_EXPR_HPP_

#include "binary_expr.hpp"
#include "scalar_expr.hpp"

namespace hc
{

class div_op
{
public:
    template <typename T1, typename T2>
    static auto op(T1 x1, T2 x2) -> decltype(x1 / x2)
    {
        return x1 / x2;
    }

};

template <typename Iterable1, typename Iterable2> using div_expr = binary_expr<div_op, Iterable1, Iterable2>;

template <typename Iterable>
div_expr<scalar_t<Iterable>, const Iterable&>
operator/(value_t<Iterable> left, const Iterable& right)
{
    return div_expr<scalar_t<Iterable>, const Iterable&>(scalar_t<Iterable>(left), right);
}

template <typename Iterable>
div_expr<const Iterable&, scalar_t<Iterable>>
operator/(const Iterable& left, value_t<Iterable> right)
{
    return div_expr<const Iterable&, scalar_t<Iterable>>(left, scalar_t<Iterable>(right));
}

template <typename Iterable1, typename Iterable2>
div_expr<const Iterable1&, const Iterable2&>
operator/(const Iterable1& left, const Iterable2& right)
{
    return div_expr<const Iterable1&, const Iterable2&>(left, right);
}

}

#endif /* DIV_EXPR_HPP_ */
