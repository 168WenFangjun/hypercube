#ifndef UTIL_HPP_
#define UTIL_HPP_

namespace hc
{
namespace util
{

    /* PRODUCT OF ARBITRARILY MANY INTS */

    template <typename... Int>
    inline int product(Int... N);

    template <typename... Remaining>
    inline int product(int n, Remaining... N)
    {
        return n * product(N...);
    }

    template <>
    inline int product()
    {
        return 1;
    }

    /* FLATTEN MULTIDIM ARRAY INDEX */

    template <typename Arr, typename... Int>
    inline int flatten_index(const Arr& offset, Int... N);

    template <typename Arr>
    inline int flatten_index(const Arr& offset)
    {
        return 0;
    }

    template <typename Arr, typename... Remaining>
    inline int flatten_index(const Arr& offset, int n, Remaining... N)
    {
        return n * offset[offset.size() - sizeof...(Remaining) - 1] + flatten_index(offset, N...);
    }

}
}

#endif /* UTIL_HPP_ */
