#pragma once
#include <iterator>
#include <iostream>

namespace algorithms {
    template<typename Iterator>
    void BubbleSort(Iterator begin, Iterator end) {
        bool needToSort = true;
        while (needToSort) {
            needToSort = false;
            Iterator slow = begin;
            Iterator fast = slow;
            ++fast;
            while (fast != end) {
                if (*fast < *slow) {
                    std::swap(*fast, *slow);
                    needToSort = true;
                }
                ++fast;
                ++slow;
            }
        }
    }

    template<typename Iterator>
    void ShakeSort(Iterator begin, Iterator end) {
        if (!begin || begin == end) return;
        bool needToSort = true;
        Iterator start = begin;
        Iterator finish = end - 1;
        while (needToSort) {
            needToSort = false;
            for (Iterator it = start; it != end; ++it) {
                if (*it > *(it + 1)) {
                    std::swap(*it, *(it + 1));
                    needToSort = true;
                }
            }
            ++start;
            if (!needToSort) return;
            for (Iterator it = finish; it != begin; --it) {
                if (*it < *(it - 1)) {
                    std::swap(*it, *(it - 1));
                }
            }
            --finish;
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

    template<typename Iterator>
    void QuickSort(Iterator begin, Iterator end) {
        if (!begin || begin == end) return;
        auto value = *(begin + std::distance(begin, end) / 2);
        Iterator l = begin, r = std::prev(end);
        while (l <= r) {
            while (*l < value) l = std::next(l);
            while (*r > value) r = std::prev(r);
            if (l <= r) {
                std::swap(*l, *r);
                l = std::next(l);
                r = std::prev(r);
            }
        }
        if (begin < r) QuickSort(begin, std::next(r));
        if (l < end) QuickSort(l, end);
    }

    template<typename Iterator>
    void SelectionSort(Iterator begin, Iterator end) {
        if (std::distance(begin, end) <= 1) return;
        Iterator it1, it2, minIt;
        for (it1 = begin; it1 < std::prev(end); it1 = std::next(it1)) {
            minIt = it1;
            for (it2 = std::next(it1); it2 < end; it2 = std::next(it2)) {
                if (*it2 < *minIt) minIt = it2;
            }
            std::swap(*it1, *minIt);
        }
    }
}
