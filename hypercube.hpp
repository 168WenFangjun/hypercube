#ifndef HYPERCUBE_HPP_
#define HYPERCUBE_HPP_

#include <array>
#include <vector>
#include <type_traits>
#include <utility>
#include <initializer_list>

#include "add_expr.hpp"
#include "subtract_expr.hpp"
#include "mult_expr.hpp"
#include "div_expr.hpp"
#include "pow_expr.hpp"
#include "elem_func.hpp"
#include "util.hpp"

namespace hc
{

using namespace std;

template <int Dim, typename T = double>
class hypercube
{
private:
    template <int, typename> friend class hypercube;

    array<int, Dim> m_size;
    array<int, Dim> m_offset;
    vector<T> m_store;

public:
    using type = hypercube<Dim, T>;
    using value_type = T;

    template <typename... Int>
    hypercube(Int... N) :
        m_size { { N... } },
        m_store (util::product(N...))
    {
        m_offset[0] = 1;
        for (int i = 1; i < Dim; ++i)
        {
            m_offset[i] = m_offset[i - 1] * m_size[i - 1];
        }
    }

    int size() const
    {
        return m_store.size();
    }

    template <typename... Int>
    value_type& operator() (Int... N)
    {
        static_assert(sizeof...(Int) == Dim, "Expecting Dim parameters");
        return m_store[util::flatten_index(m_offset, N...)];
    }

    template <typename... Int>
    const value_type& operator() (Int... N) const
    {
        return const_cast<decltype(*this)>(*this)(N...);
    }

    /* ASSIGNMENT */

    type& operator=(const type& rhs)
    {
        if (this != (void *) &rhs)
        {
            if (m_store.size() == rhs.size())
            {
                m_store = rhs.m_store;
            }
            else
            {
                throw range_error("Unequal number of elements");
            }
        }
        return *this;
    }

    template <typename Rhs>
    typename enable_if<is_convertible<Rhs, value_type>::value, type>::type&
    operator=(const Rhs& value) noexcept
    {
        m_store.assign(m_store.size(), value);
        return *this;
    }

    template <typename Rhs>
    typename enable_if<is_convertible<decltype(*declval<Rhs>().begin()), value_type>::value, type>::type&
    operator=(const Rhs& rhs)
    {
        auto rhs_it = rhs.begin();
        for (auto& lhs : m_store)
        {
            lhs = *(rhs_it++);
        }
        return *this;
    }

    template <typename TT>
    type& operator=(initializer_list<TT> rhs)
    {
        auto rhs_it = rhs.begin();
        for (auto& lhs : m_store)
        {
            lhs = *(rhs_it++);
        }
        return *this;
    }

    /* ADDITION */

    template <typename Rhs>
    typename enable_if<is_convertible<Rhs, value_type>::value, type>::type&
    operator+=(const Rhs& value) noexcept
    {
        for (auto& lhs : m_store)
        {
            lhs += value;
        }
        return *this;
    }

    template <typename Rhs>
    typename enable_if<is_convertible<decltype(declval<value_type>() + *declval<Rhs>().begin()), value_type>::value, type>::type&
    operator+=(const Rhs& rhs)
    {
        auto rhs_it = rhs.begin();
        for (auto& lhs : m_store)
        {
            lhs += *(rhs_it++);
        }
        return *this;
    }

    /* SUBTRACTION */

    template <typename Rhs>
    typename enable_if<is_convertible<Rhs, value_type>::value, type>::type&
    operator-=(const Rhs& value) noexcept
    {
        for (auto& lhs : m_store)
        {
            lhs -= value;
        }
        return *this;
    }

    template <typename Rhs>
    typename enable_if<is_convertible<decltype(declval<value_type>() + *declval<Rhs>().begin()), value_type>::value, type>::type&
    operator-=(const Rhs& rhs)
    {
        auto rhs_it = rhs.begin();
        for (auto& lhs : m_store)
        {
            lhs -= *(rhs_it++);
        }
        return *this;
    }

    /* MULTIPLICATION */

    template <typename Rhs>
    typename enable_if<is_convertible<Rhs, value_type>::value, type>::type&
    operator*=(const Rhs& value) noexcept
    {
        for (auto& lhs : m_store)
        {
            lhs *= value;
        }
        return *this;
    }

    template <typename Rhs>
    typename enable_if<is_convertible<decltype(declval<value_type>() + *declval<Rhs>().begin()), value_type>::value, type>::type&
    operator*=(const Rhs& rhs)
    {
        auto rhs_it = rhs.begin();
        for (auto& lhs : m_store)
        {
            lhs *= *(rhs_it++);
        }
        return *this;
    }

    /* DIVISION */

    template <typename Rhs>
    typename enable_if<is_convertible<Rhs, value_type>::value, type>::type&
    operator/=(const Rhs& value) noexcept
    {
        for (auto& lhs : m_store)
        {
            lhs /= value;
        }
        return *this;
    }

    template <typename Rhs>
    typename enable_if<is_convertible<decltype(declval<value_type>() + *declval<Rhs>().begin()), value_type>::value, type>::type&
    operator/=(const Rhs& rhs)
    {
        auto rhs_it = rhs.begin();
        for (auto& lhs : m_store)
        {
            lhs /= *(rhs_it++);
        }
        return *this;
    }

    /* STANDARD ITERATORS */

    auto begin() noexcept
    -> decltype(m_store.begin())
    {
        return m_store.begin();
    }

    auto begin() const noexcept
    -> decltype(m_store.begin())
    {
        return m_store.begin();
    }

    auto cbegin() const noexcept
    -> decltype(m_store.cbegin())
    {
        return m_store.cbegin();
    }

    auto end() noexcept
    -> decltype(m_store.end())
    {
        return m_store.end();
    }

    auto end() const noexcept
    -> decltype(m_store.end())
    {
        return m_store.end();
    }

    auto cend() const noexcept
    -> decltype(m_store.cend())
    {
        return m_store.cend();
    }

};

template <int Dim> using hyperfloat = hypercube<Dim, float>;
template <int Dim> using hypershort = hypercube<Dim, short>;
template <int Dim> using hyperint   = hypercube<Dim, int>;
template <int Dim> using hyperlong  = hypercube<Dim, long>;

}

#endif /* HYPERCUBE_HPP_ */
