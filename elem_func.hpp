#ifndef ELEM_FUNC_HPP_
#define ELEM_FUNC_HPP_

#include "unary_expr.hpp"

#include <cstdlib>
#include <cmath>

namespace hc
{

using namespace std;

/* ABSOLUTE VALUE */

class abs_op
{
public:
    template <typename T>
    static auto op(T x)
    -> decltype(abs(x))
    {
        return abs(x);
    }
};

template <typename Iterable>
unary_expr<abs_op, const Iterable&>
abs(const Iterable& data)
{
    return unary_expr<abs_op, const Iterable&>(data);
}

/* SQUARE ROOT */

class sqrt_op
{
public:
    template <typename T>
    static auto op(T x)
    -> decltype(sqrt(x))
    {
        return sqrt(x);
    }
};

template <typename Iterable>
unary_expr<sqrt_op, const Iterable&>
sqrt(const Iterable& data)
{
    return unary_expr<sqrt_op, const Iterable&>(data);
}

/* CUBE ROOT */

class cbrt_op
{
public:
    template <typename T>
    static auto op(T x)
    -> decltype(cbrt(x))
    {
        return cbrt(x);
    }
};

template <typename Iterable>
unary_expr<cbrt_op, const Iterable&>
cbrt(const Iterable& data)
{
    return unary_expr<cbrt_op, const Iterable&>(data);
}

/* EXPONENTIAL */

class exp_op
{
public:
    template <typename T>
    static auto op(T x)
    -> decltype(exp(x))
    {
        return exp(x);
    }
};

template <typename Iterable>
unary_expr<exp_op, const Iterable&>
exp(const Iterable& data)
{
    return unary_expr<exp_op, const Iterable&>(data);
}

/* EXPONENTIAL (BASE 2) */

class exp2_op
{
public:
    template <typename T>
    static auto op(T x)
    -> decltype(exp2(x))
    {
        return exp2(x);
    }
};

template <typename Iterable>
unary_expr<exp2_op, const Iterable&>
exp2(const Iterable& data)
{
    return unary_expr<exp2_op, const Iterable&>(data);
}

/* LOGARITHM */

class log_op
{
public:
    template <typename T>
    static auto op(T x)
    -> decltype(log(x))
    {
        return log(x);
    }
};

template <typename Iterable>
unary_expr<log_op, const Iterable&>
log(const Iterable& data)
{
    return unary_expr<log_op, const Iterable&>(data);
}

/* LOGARITHM (BASE 10) */

class log10_op
{
public:
    template <typename T>
    static auto op(T x)
    -> decltype(log10(x))
    {
        return log10(x);
    }
};

template <typename Iterable>
unary_expr<log10_op, const Iterable&>
log10(const Iterable& data)
{
    return unary_expr<log10_op, const Iterable&>(data);
}

/* LOGARITHM (BASE 2) */

class log2_op
{
public:
    template <typename T>
    static auto op(T x)
    -> decltype(log2(x))
    {
        return log2(x);
    }
};

template <typename Iterable>
unary_expr<log2_op, const Iterable&>
log2(const Iterable& data)
{
    return unary_expr<log2_op, const Iterable&>(data);
}

}

#endif /* ELEM_FUNC_HPP_ */
