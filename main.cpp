
#include <iostream>
#include <set>

using namespace std;

struct Interval {
    int l, r;
    bool operator<(const Interval& other) const {
        if (r != other.r) return r < other.r;
        return l < other.l;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    set<Interval> intervals;
    while (n--) {
        char op;
        cin >> op;
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            int removed = 0;
            // Find the first interval whose r >= l
            auto it = intervals.lower_bound({0, l});
            while (it != intervals.end() && it->l <= r) {
                it = intervals.erase(it);
                removed++;
            }
            intervals.insert({l, r});
            cout << removed << "\n";
        } else if (op == 'B') {
            cout << intervals.size() << "\n";
        }
    }
    return 0;
}
