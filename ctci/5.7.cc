#include <bitset>
#include <cassert>
#include <vector>

template<size_t N>
int findMissing(const std::vector<std::bitset<N>>& array, size_t bit = 0)
{
    if (bit == N - 1) {
        return 0;
    }

    std::vector<std::bitset<N>> zeros;
    std::vector<std::bitset<N>> ones;

    for (auto& elem : array) {
        (elem[bit] ? ones : zeros).push_back(elem);
    }

    if (zeros.size() > ones.size()) {
        return (findMissing(ones, bit + 1) << 1) | 1;
    } else {
        return (findMissing(zeros, bit + 1) << 1) | 0;
    }
}

int main()
{
    std::vector<std::bitset<32>> array;

    assert(findMissing(array) == 0);

    for (unsigned i = 0; i < 1000; ++i) {
        if (i != 666) {
            array.push_back({i});
        }
    }

    assert(findMissing(array) == 666);
}
