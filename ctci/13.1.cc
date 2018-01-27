#include <fstream>
#include <iostream>
#include <string>

template<class T>
class fifo {
  public:
    fifo(size_t n)
        : buffer{new T[n]}
        , capacity{n}
    {}

    ~fifo()
    {
        delete[] buffer;
    }

    void push_back(T&& elem)
    {
        buffer[tail] = elem;
        tail = (tail + 1) % capacity;
        if (head == tail) {
            head = (head + 1) % capacity;
        }
    }

    T&& pop_front()
    {
        T& ret = buffer[head];
        head = (head + 1) % capacity;
        return std::move(ret);
    }

    bool empty() const
    {
        return head == tail;
    }

  private:
    T *buffer{nullptr};
    size_t capacity{0};
    size_t head{0};
    size_t tail{0};
};

void
tail(size_t k, std::istream& is)
{
    fifo<std::string> q{k+1};

    for (std::string line; std::getline(is, line); ) {
        q.push_back(std::move(line));
    }

    while (!q.empty()) {
        std::cout << q.pop_front() << std::endl;
    }
}

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " LINES\n";
        return 1;
    }

    size_t k = std::stoi(argv[1]);
    tail(k, std::cin);
    return 0;
}
