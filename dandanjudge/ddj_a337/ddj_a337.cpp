#include <iostream>
#include <queue>
using namespace std;
#define f first
#define s second
#define fr front()
#define h(x, y) n-1-x + m-1-y

// test of oneline command

/* test of multiple lines command
 * 1
 * 2
 * for(int i = 0; i < n; ++i)
 * 4
 */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	while(cin >> n >> m) {
		int arr[n][m];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				cin >> arr[i][j];
		queue<vector<int> > lst;
		if(arr[0][0] == 1 || arr[n-1][m-1] == 1) {
			cout << "Am I a joke to you?" << '\n';
			continue;
		}
		lst.push(make_pair(0, 0));
		while(!lst.empty() && arr[n-1][m-1] == 0) {
			if(lst.fr.f > 0 && arr[lst.fr.f - 1][lst.fr.s] == 0) {
				arr[lst.fr.f - 1][lst.fr.s] = arr[lst.fr.f][lst.fr.s] - 1;
				lst.push(make_pair(lst.fr.f - 1, lst.fr.s));
			}
			if(lst.fr.f < n - 1 && arr[lst.fr.f + 1][lst.fr.s] == 0) {					
				arr[lst.fr.f + 1][lst.fr.s] = arr[lst.fr.f][lst.fr.s] - 1;
				lst.push(make_pair(lst.fr.f + 1, lst.fr.s));
			}
			if(lst.fr.s > 0 && arr[lst.fr.f][lst.fr.s - 1] == 0) {
				arr[lst.fr.f][lst.fr.s - 1] = arr[lst.fr.f][lst.fr.s] - 1;
				lst.push(make_pair(lst.fr.f, lst.fr.s - 1));
			}
			if(lst.fr.s < m - 1 && arr[lst.fr.f][lst.fr.s + 1] == 0) {
				arr[lst.fr.f][lst.fr.s + 1] = arr[lst.fr.f][lst.fr.s] - 1;
				lst.push(make_pair(lst.fr.f, lst.fr.s + 1));
			}
			lst.pop();
		}
		if(arr[n-1][m-1] < 0)
			cout << -arr[n-1][m-1] << '\n';
		else
			cout << "Am I a joke to you?" << '\n';
	}
}
