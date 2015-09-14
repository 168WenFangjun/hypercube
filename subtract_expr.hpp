#ifndef SUBTRACT_EXPR_HPP_
#define SUBTRACT_EXPR_HPP_

#include "binary_expr.hpp"
#include "scalar_expr.hpp"

namespace hc
{

class subtract_op
{
public:
    template <typename T1, typename T2>
    static auto op(T1 x1, T2 x2) -> decltype(x1 - x2)
    {
        return x1 - x2;
    }

};

template <typename Iterable1, typename Iterable2> using subtract_expr = binary_expr<subtract_op, Iterable1, Iterable2>;

template <typename Iterable>
subtract_expr<scalar_t<Iterable>, const Iterable&>
operator-(value_t<Iterable> left, const Iterable& right)
{
    return subtract_expr<scalar_t<Iterable>, const Iterable&>(scalar_t<Iterable>(left), right);
}

template <typename Iterable>
subtract_expr<const Iterable&, scalar_t<Iterable>>
operator-(const Iterable& left, value_t<Iterable> right)
{
    return subtract_expr<const Iterable&, scalar_t<Iterable>>(left, scalar_t<Iterable>(right));
}

template <typename Iterable1, typename Iterable2>
subtract_expr<const Iterable1&, const Iterable2&>
operator-(const Iterable1& left, const Iterable2& right)
{
    return subtract_expr<const Iterable1&, const Iterable2&>(left, right);
}

}

#endif /* SUBTRACT_EXPR_HPP_ */
