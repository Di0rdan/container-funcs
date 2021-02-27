template <typename It, typename Pred>
bool AnyOf(It first, It last, Pred f) {
    for (; first != last; ++first) {
        if (f(*first)) {
            return true;
        }
    }
    return false;
}

template <typename InIter, typename OutIter, typename Predicate>
OutIter RemoveCopyIf(InIter first, InIter last, OutIter out, Predicate f) {
    for (auto it = first; it != last; ++it) {
        if (!f(*it)) {
            *out = *it;
            ++out;
        }
    }
    return out;
}

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return first;
    Iter cur = next(first);
    for (Iter it = next(first); it != last; ++it) {
        if (*prev(it) != *it) {
            *cur = *it;
            ++cur;
        }
    }
    return cur;
}

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out) {
    while (first1 != last1) {
        if (first2 == last2) return copy(first1, last1, out);
        if (*first1 < *first2) {
            *out++ = *first1++;
        } else {
            if (*first2 == *first1) {
                ++first1;
            }
            ++first2;
        }
    }
    return out;
}

template <typename InIter, typename OutIter>
OutIter ReverseCopy(InIter first, InIter last, OutIter out) {
    while (first != last) {
        *out++ = *(--last);
    }
    return out;
}

template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter TransformIf(InIter first, InIter last, OutIter out,
                    Predicate condition, Action f) {
    for (; first != last; ++first) {
        if (condition(*first)) {
            *out++ = f(*first);
        }
    }
    return out;
}

template <typename It, typename OutputIt>
OutputIt SidewaysMerge(It first1, It last1, It first2, It last2, OutputIt out) {
    while (first1 != last1 || first2 != last2) {
        if (first1 == last1) {
            *out++ = *(--last2);
        } else if (first2 == last2) {
            *out++ = *first1++;
        } else if (*first1 < *prev(last2)) {
            *out++ = *first1++;
        } else {
            *out++ = *(--last2);
        }
    }
    return out;
}