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
        if (std::distance(begin, end) <= 1) return;
        bool needToSort = true;
        Iterator start = std::prev(begin);
        Iterator finish = std::prev(end);
        while (needToSort) {
            needToSort = false;
            start = std::next(start);
            for (Iterator it = start; it < finish; it = std::next(it)) {
                if (*it > *std::next(it)) {
                    std::swap(*it, *std::next(it));
                    needToSort = true;
                }
            }
            if (!needToSort) return;
            end = std::prev(end);
            for (Iterator it = end; it > begin; it = std::prev(it)) {
                if (*it < *std::prev(it)) {
                    std::swap(*it, *std::prev(it));
                }
            }
        }
    }

    template<typename Iterator>
    void InsertionSort(Iterator begin, Iterator end) {
        for (Iterator it = std::next(begin); it < end; it = std::next(it)) {
            Iterator a = it;
            while (a > begin && *std::prev(a) > *a) {
                std::swap(*std::prev(a), *a);
                a = std::prev(a);
            }
        }
    }
}
