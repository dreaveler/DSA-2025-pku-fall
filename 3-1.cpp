#include <iostream>
#include <vector>
#include <deque>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    if (!(std::cin >> n >> k)) return 0;
    std::vector<int> a(n);
    for (auto& v : a) std::cin >> v;

    if (k <= 0 || k > n) {
        std::cout << '\n' << '\n';
        return 0;
    }

    std::deque<int> dqMin, dqMax; 
    std::vector<int> mins, maxs;
    mins.reserve(n - k + 1);
    maxs.reserve(n - k + 1);

    for (int i = 0; i < k; ++i) {
        while (!dqMin.empty() && a[dqMin.back()] >= a[i]) dqMin.pop_back();
        dqMin.push_back(i);
        while (!dqMax.empty() && a[dqMax.back()] <= a[i]) dqMax.pop_back();
        dqMax.push_back(i);
    }
    mins.push_back(a[dqMin.front()]);
    maxs.push_back(a[dqMax.front()]);

    for (int i = k; i < n; ++i) {
        while (!dqMin.empty() && dqMin.front() <= i - k) dqMin.pop_front();
        while (!dqMax.empty() && dqMax.front() <= i - k) dqMax.pop_front();
        while (!dqMin.empty() && a[dqMin.back()] >= a[i]) dqMin.pop_back();
        dqMin.push_back(i);
        while (!dqMax.empty() && a[dqMax.back()] <= a[i]) dqMax.pop_back();
        dqMax.push_back(i);

        mins.push_back(a[dqMin.front()]);
        maxs.push_back(a[dqMax.front()]);
    }

    for (size_t i = 0; i < mins.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << mins[i];
    }
    std::cout << '\n';
    for (size_t i = 0; i < maxs.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << maxs[i];
    }
    std::cout << '\n';
}