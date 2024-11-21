#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 666;; i++) {
        int tmp = i;
        while (tmp >= 666) {
            if (tmp % 1000 == 666) {
                cnt++;
                break;
            }
            break;
        }
        if (n == cnt) {
            cout << i;
            return 0;
        }
    }
}

// 어렵지는 않은데 생각하는게 좀 힘들다 길게 생각해봐야 하나