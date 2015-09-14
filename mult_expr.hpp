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
mult_expr<scalar_expr<typename Iterable::value_type>, const Iterable&>
operator*(typename Iterable::value_type left, const Iterable& right)
{
    using ScalarType = scalar_expr<typename Iterable::value_type>;
    return mult_expr<ScalarType, const Iterable&>(ScalarType(left), right);
}

template <typename Iterable>
mult_expr<const Iterable&, scalar_expr<typename Iterable::value_type>>
operator*(const Iterable& left, typename Iterable::value_type right)
{
    using ScalarType = scalar_expr<typename Iterable::value_type>;
    return mult_expr<const Iterable&, ScalarType>(left, ScalarType(right));
}

template <typename Iterable1, typename Iterable2>
mult_expr<const Iterable1&, const Iterable2&>
operator*(const Iterable1& left, const Iterable2& right)
{
    return mult_expr<const Iterable1&, const Iterable2&>(left, right);
}

}

#endif /* MULT_EXPR_HPP_ */
