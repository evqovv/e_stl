#pragma once

#include <cstddef>
#include <utility>

namespace evqovv {
namespace e_stl {
template <typename T>
struct default_deleter {
    void operator()(T *p) {
        delete p;
    }
};

template <typename T>
struct default_deleter<T[]> {
    void operator()(T *p) {
        delete[] p;
    }
};

template <typename T, typename Deleter = default_deleter<T>>
struct unique_ptr {
    using pointer = T *;
    using element_type = T;
    using deleter_type = Deleter;

    pointer ptr;
    deleter_type deleter;

    unique_ptr(::std::nullptr_t = nullptr) noexcept : ptr(nullptr) {}

    explicit unique_ptr(T *p) noexcept : ptr(p) {}

    unique_ptr(unique_ptr const &) = delete;

    unique_ptr &operator=(unique_ptr const &) = delete;

    ~unique_ptr() noexcept {
        if (ptr) {
            deleter(ptr);
        }
    }

    pointer get() const noexcept {
        return ptr;
    }

    deleter_type get_deleter() const noexcept {
        return deleter;
    }

    pointer release() noexcept {
        auto temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(pointer new_ptr = nullptr) noexcept {
        if (ptr) {
            deleter(ptr);
        }
        ptr = new_ptr;
    }

    explicit operator bool() const noexcept {
        return ptr != nullptr;
    }

    void swap(unique_ptr &other) noexcept {
        ::std::swap(ptr, other.ptr);
    }

    unique_ptr &operator=(unique_ptr &&r) noexcept {
        if (this != &r) [[likely]] {
            if (ptr) {
                deleter(ptr);
            }
            ptr = ::std::exchange(r.ptr, nullptr);
        }

        return *this;
    }

    template <typename U, typenaem E>
    unique_ptr &operator=(unique_ptr<U, E> &&r) noexcept {

    }
};
}
}