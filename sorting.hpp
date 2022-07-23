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
                    std::swap(*fast, *slow);
                    needToSort = true;
                }
                fast = std::next(fast);
                slow = std::next(slow);
            }
        }
    }

    template<typename Iterator>
    void ShakeSort(Iterator begin, Iterator end) {
        int sz = end - begin;
        if (sz <= 1) return;
        bool needToSort = true;
        Iterator start = begin - 1;
        Iterator finish = end - 1;
        while (needToSort) {
            needToSort = false;
            ++start;
            for (Iterator it = start; it < finish; ++it) {
                if (*it > *(it + 1)) {
                    std::swap(*it, *(it + 1));
                    needToSort = true;
                }
            }
            if (!needToSort) return;
            --end;
            for (Iterator it = end; it > begin; --it) {
                if (*it < *(it - 1)) {
                    std::swap(*it, *(it - 1));
                }
            }
        }
    }
}
