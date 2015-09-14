#ifndef POW_EXPR_HPP_
#define POW_EXPR_HPP_

#include "binary_expr.hpp"
#include "scalar_expr.hpp"

#include <cmath>

namespace hc
{

class pow_op
{
public:
    template <typename T1, typename T2>
    static auto op(T1 x1, T2 x2) -> decltype(pow(x1, x2))
    {
        return pow(x1, x2);
    }

};

template <typename Iterable1, typename Iterable2> using pow_expr = binary_expr<pow_op, Iterable1, Iterable2>;

template <typename Iterable>
pow_expr<scalar_t<Iterable>, const Iterable&>
pow(value_t<Iterable> left, const Iterable& right)
{
    return pow_expr<scalar_t<Iterable>, const Iterable&>(scalar_t<Iterable>(left), right);
}

template <typename Iterable>
pow_expr<const Iterable&, scalar_t<Iterable>>
pow(const Iterable& left, value_t<Iterable> right)
{
    return pow_expr<const Iterable&, scalar_t<Iterable>>(left, scalar_t<Iterable>(right));
}

template <typename Iterable1, typename Iterable2>
pow_expr<const Iterable1&, const Iterable2&>
pow(const Iterable1& left, const Iterable2& right)
{
    return pow_expr<const Iterable1&, const Iterable2&>(left, right);
}

}

#endif /* POW_EXPR_HPP_ */
