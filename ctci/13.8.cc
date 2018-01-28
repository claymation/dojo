#include <algorithm>
#include <iostream>

template<typename T>
class smart_ptr {
  public:
    smart_ptr(T* ptr)
        : ptr{ptr}
        , refcount(new size_t{1})
    {}

    ~smart_ptr()
    {
        std::cerr << "~smart_ptr(): refcount=" << *refcount << std::endl;
        --(*refcount);
        if (!(*refcount)) {
            delete refcount;
            delete ptr;
        }
    }

    smart_ptr(const smart_ptr& other)
        : ptr{other.ptr}
        , refcount{other.refcount}
    {
        ++(*refcount);
    }

    smart_ptr&
    operator=(const smart_ptr& other)
    {
        smart_ptr that(other);
        swap(*this, that);
        return *this;
    }

    T&
    operator*()
    {
        return *ptr;
    }

    const T&
    operator*() const
    {
        return *ptr;
    }

  template<typename U>
  friend void swap(smart_ptr<U>&, smart_ptr<U>&);

  private:
    T* ptr;
    size_t* refcount;
};

template<typename T>
inline void
swap(smart_ptr<T>& p, smart_ptr<T>& q)
{
    using std::swap;
    swap(p.ptr, q.ptr);
    swap(p.refcount, q.refcount);
}

int main()
{
    smart_ptr<int> p{new int{42}};
    std::cout << *p << std::endl;

    {
        smart_ptr<int> q{p};
        std::cout << *q << std::endl;
    }

    p = smart_ptr<int>{new int{24}};
    std::cout << *p << std::endl;
}
