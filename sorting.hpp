#pragma once
#include <iterator>

namespace algorithms {
    template<typename Iterator>
    void BubbleSort(Iterator begin, Iterator end) {
        bool needToSort = true;
        while (needToSort) {
            needToSort = false;
            Iterator slow = begin;
            Iterator fast = std::next(slow);
            while (fast != end) {
                if (*fast < *slow) {
                    auto value = *slow;
                    *slow = *fast;
                    *fast = value;
                    needToSort = true;
                }
                fast = std::next(fast);
                slow = std::next(slow);
            }
        }
    }
}
