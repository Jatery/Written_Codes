#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
		pair<int, int> lst[n];
        
        for (int j = 0; j < n; j++) {
			cin >> lst[j].second >> lst[j].first;
		}
        
        sort(lst, lst + n);
        
        int cnt = 0;
        int time = 0;
       	int f[lst[n - 1].first + 1];
		f[0] = 0;
        int k = 0;
        
        for (int j = 1; j <= lst[n - 1].first; j++) {            
            while (k < n && lst[k].first <= j) {
                f[j] = max(f[j], f[j - lst[k].second] + 1);
                k++;
            }
        }
        
        cout << f[lst[n - 1].first] << endl;
    }
    
    return 0;
}

