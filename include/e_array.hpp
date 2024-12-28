#pragma once

#include <cstddef>
#include <iterator>

namespace evqovv {
namespace e_stl {
template <typename T, ::std::size_t N>
struct e_array {
    using value_type = T;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = value_type const &;
    using pointer = value_type *;
    using const_pointer = value_type const *;
    using iterator = value_type *;
    using const_iterator = value_type const *;
    using reverse_iterator = ::std::reverse_iterator<iterator>;
    using const_reverse_iterator = ::std::reverse_iterator<iterator const>;

    T elements[N];

    reference at(size_type pos) {
        if (pos >= N) [[unlikely]] {
            ::std::abort();
        }

        return elements[pos];
    }

    const_reference at(size_type pos) const {
        if (pos >= N) [[unlikely]] {
            ::std::abort();
        }

        return elements[pos];
    }

    reference operator[](size_type pos) {
        if (pos >= N) [[unlikely]] {
            ::std::abort();
        }

        return elements[pos];
    }

    const_reference operator[](size_type pos) const {
        if (pos >= N) [[unlikely]] {
            ::std::abort();
        }

        return elements[pos];
    }

    reference front() {
        return elements[0];
    }

    const_reference front() const {
        return elements[0];
    }

    reference back() {
        return elements[N - 1];
    }

    const_reference back() const {
        return elements[N - 1];
    }

    pointer data() noexcept {
        return elements;
    }

    const_pointer data() const noexcept {
        return elements;
    }

    iterator begin() noexcept {
        return elements;
    }

    const_iterator begin() const noexcept {
        return elements;
    }

    const_iterator cbegin() const noexcept {
        return elements;
    }

    iterator end() noexcept {
        return elements + N;
    }

    const_iterator end() const noexcept {
        return elements + N;
    }

    const_iterator cend() const noexcept {
        return elements + N;
    }

    reverse_iterator rbegin() noexcept {
        return { end() };
    }

    const_reverse_iterator rbegin() const noexcept {
        return { end() };
    }

    const_reverse_iterator crbegin() const noexcept {
        return { end() };
    }

    reverse_iterator rend() noexcept {
        return { begin() };
    }

    const_reverse_iterator rend() const noexcept {
        return { begin() };
    }

    const_reverse_iterator crend() const noexcept {
        return { begin() };
    }

    constexpr bool empty() const noexcept {
        return false;
    }

    constexpr size_type size() const noexcept {
        return N;
    }

    constexpr size_type max_size() const noexcept {
        return N;
    }

    void fill(T const &value) noexcept(::std::is_nothrow_copy_assignable_v<T>) {
        for (size_type i = 0; i != N; ++i) {
            elements[i] = value;
        }
    }

    void swap(e_array &other) noexcept(::std::is_nothrow_swappable_v<T>) {
        for (size_t i = 0; i != N; ++i) {
            ::std::swap(elements[i], other.elements[i]);
        }
    }
};

template <typename T>
struct e_array<T, 0> {
    using value_type = T;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = value_type const &;
    using pointer = value_type *;
    using const_pointer = value_type const *;
    using iterator = value_type *;
    using const_iterator = value_type const *;
    using reverse_iterator = ::std::reverse_iterator<iterator>;
    using const_reverse_iterator = ::std::reverse_iterator<iterator const>;

    constexpr reference at(size_type pos) {
        static_assert(false, "The length of this array is 0.");
    }

    constexpr const_reference at(size_type pos) const {
        static_assert(false, "The length of this array is 0.");
    }

    constexpr reference operator[](size_type pos) {
        static_assert(false, "The length of this array is 0.");
    }

    constexpr const_reference operator[](size_type pos) const {
        static_assert(false, "The length of this array is 0.");
    }

    constexpr reference front() {
        static_assert(false, "The length of this array is 0.");
    }

    constexpr const_reference front() const {
        static_assert(false, "The length of this array is 0.");
    }

    constexpr reference back() {
        static_assert(false, "The length of this array is 0.");
    }

    constexpr const_reference back() const {
        static_assert(false, "The length of this array is 0.");
    }

    constexpr pointer data() noexcept {
        return nullptr;
    }

    constexpr const_pointer data() const noexcept {
        return nullptr;
    }

    constexpr iterator begin() noexcept {
        return nullptr;
    }

    constexpr const_iterator begin() const noexcept {
        return nullptr;
    }

    constexpr const_iterator cbegin() const noexcept {
        return nullptr;
    }

    constexpr iterator end() noexcept {
        return nullptr;
    }

    constexpr const_iterator end() const noexcept {
        return nullptr;
    }

    constexpr const_iterator cend() const noexcept {
        return nullptr;
    }

    constexpr reverse_iterator rbegin() noexcept {
        return nullptr;
    }

    constexpr const_reverse_iterator rbegin() const noexcept {
        return nullptr;
    }

    constexpr const_reverse_iterator crbegin() const noexcept {
        return nullptr;
    }

    constexpr reverse_iterator rend() noexcept {
        return nullptr;
    }

    constexpr const_reverse_iterator rend() const noexcept {
        return nullptr;
    }

    constexpr const_reverse_iterator crend() const noexcept {
        return nullptr;
    }

    constexpr bool empty() const noexcept {
        return true;
    }

    constexpr size_type size() const noexcept {
        return 0;
    }

    constexpr size_type max_size() const noexcept {
        return 0;
    }

    constexpr void fill(T const &value) noexcept(::std::is_nothrow_copy_assignable_v<T>) {}

    constexpr void swap(e_array &other) noexcept(::std::is_nothrow_swappable_v<T>) {}
};

template <typename T, ::std::size_t N>
bool operator==(e_array<T, N> const &lhs, e_array<T, N> const &rhs) {
    for (::std::size_t i = 0; i != N; ++i) {
        if (lhs.elements[i] != rhs.elements[i]) {
            return false;
        }
    }

    return true;
}

template <typename T, ::std::size_t N>
bool operator!=(e_array<T, N> const &lhs, e_array<T, N> const &rhs) {
    return !(lhs == rhs);
}

template <typename T, ::std::size_t N>
bool operator<(e_array<T, N> const &lhs, e_array<T, N> const &rhs) {
    for (::std::size_t i = 0; i != N; ++i) {
        if (lhs.data[i] != rhs.data[i]) {
            return lhs.data[i] < rhs.data[i];
        }
    }

    return false;
}

template <typename T, ::std::size_t N>
bool operator>(e_array<T, N> const &lhs, e_array<T, N> const &rhs) {
    return rhs < lhs;
}

template <typename T, ::std::size_t N>
bool operator<=(e_array<T, N> const &lhs, e_array<T, N> const &rhs) {
    return !(lhs > rhs);
}

template <typename T, ::std::size_t N>
bool operator>=(e_array<T, N> const &lhs, e_array<T, N> const &rhs) {
    return !(lhs < rhs);
}

template <::std::size_t I, typename T, ::std::size_t N>
T &get(e_array<T, N> &a) noexcept {
    static_assert(I < N, "Index out of range.");
    return a[I];
}

template <::std::size_t I, typename T, ::std::size_t N>
T const &get(e_array<T, N> const &a) noexcept {
    static_assert(I < N, "Index out of range.");
}

template <::std::size_t I, typename T, ::std::size_t N>
T &&get(e_array<T, N> &&a) noexcept {
    static_assert(I < N, "Index out of range.");
    return ::std::move(a[I]);
}

template <::std::size_t I, typename T, ::std::size_t N>
T const &&get(e_array<T, N> const &&a) noexcept {
    static_assert(I < N, "Index out of range.");
    return ::std::move(a[I]);
}

template <typename T, ::std::size_t N>
void swap(e_array<T, N> &lhs, e_array<T, N> &rhs) noexcept(::std::is_nothrow_swappable_v<T>) {
    lhs.swap(rhs);
}

template <typename T, typename... Args>
e_array(T, Args...) -> e_array<T, 1 + sizeof...(Args)>;
}
}