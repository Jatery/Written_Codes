# Linked List出題與應用(a572)

## 主旨
	
利用Linked List（鏈結串列）解決自己的程式問題，並藉此熟悉Class與Pointer等相關工具的用法，並加以活用。

## 動機

此題的構思約是一年前（高二上）時候的想法，當時想出一題新穎又不失趣味度的題目，但以當時的程式能力，想到的解法最優也只有$O(n^2)$。直到這學期認識到Linked List才完成較為滿意的程式碼與複雜度。

## 解題過程

先上題敘。

[a572(dandanjudge)](https://dandanjudge.fdhs.tyc.edu.tw/ShowProblem?problemid=a572)

:::info
**a572: Uncle Lanjen Trying to Hit the Sack**

內容：
Uncle Lanjen是個上大夜班的血汗勞工
每天下班回到家都已經非常早了
只想早早睡個覺
但非常不幸的是
Lanjen的鄰居養了一群神奇的藍色胖鳥俗稱BFB
這些BFB會在天亮時啼叫，就像一般的公雞一樣
不過他們在被殺了之後
會把要自己該叫的叫完才會死（不過隔天又活了就是
脾氣不是很好的Lanjen
只要在睡夢中被吵醒
就會立刻衝去隔壁把吵醒他的那隻BFB給殺了
而每次被吵完之後還要躺在床上花個五分鐘才能入睡
試問Lanjen從0分鐘上床開始
哪些BFB會因此壯烈成仁


輸入說明：
第一行有一個數字$n$代表有$n$隻BFB
接下來有$n$行，每行有兩個數字$a_i$, $b_i$
代表每隻BFB開始與結束啼叫的時間點

輸出說明：
依照時間順序輸出"Poor BFB No.$i$ died at time $a_i$..."
若沒有BFB壯烈成仁則輸出"Every BFB is alive, it's another peaceful day."

範例輸入：
7
19 20
6 8
15 18
13 13
14 19
27 29
7 8

範例輸出：
Poor BFB No.2 died at time 6...
Poor BFB No.5 died at time 14...
Poor BFB No.6 died at time 27...

> *提示：
  每隻BFB會從 $a_i$ 時間點開始啼叫至 $b_i$ 結束
  換句話說牠會從 $a_i$ 叫至 $b_i% - %1$
  而在沒有其他BFB啼叫的情況下Uncle Lanjen會於 $b_i$ + $5$ 入睡
  被吵醒的定義為開始啼叫的前一刻是睡著的狀態
  即開始入睡的時間點啼叫不算被吵醒
  保證沒有BFB會跟其他隻同時叫
  $0$ ≤ $a_i$ ≤ $b_i$ ≤ $10^9$
  $n$ ≤ $10^6$*
:::

題目大意是要記錄下每隻BFB開始啼叫的時間點與Lanjen睡著的時段，於每次被吵醒時輸出該時刻與吵醒Lanjen的BFB。困難點在於每隻BFB並不會照編號順序啼叫，有些類似線段樹的多次區間修後遍歷。

剛開始最初的構想是用陣列去實現，搭配當時剛學會的線段樹，理論上可以把複雜度壓到$O(nlog(n))$。不過線段樹的部分最後卡在如何判讀輸出的問題，最後遂捨棄此想法。

下面是陣列的程式碼，時間複雜度$O(n^2)$。

```cpp=
int main() {
	int n, arr[maxn + 1] = {0}, a, b;
	//0代表睡著，-1代表醒著，1~n代表該時間點被n號BFB吵醒
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a >> b;
		if(a == b)
			continue;
		if(arr[i] <= 0)
			arr[i] = i;
		for(int j=a+1;j<b+5;++j)
			if(arr[j] == 0) 
				arr[j] = -1;
	}
	bool f = 1;
	for(int i=0;i<=maxn;i++) {
		//尋找前一刻睡著的啼叫時間點
		if(arr[i]>0 && !arr[i-1]) {
			f = 0;
			cout << "Poor BFB No." << arr[i] << " died at time " << i << "...\n";
		}
	}
	if(f)
		cout << "Every BFB is alive, it's another peaceful day.\n";
}
```

由於題目的性質，陣列需要多次插入與修改，因此Linked List是再適合不過，馬上開始著手解題。同時間也藉此回去重溫當初瀏覽過去但未曾實踐的Pointer與Class。這裡的思路改成儲存Lanjen睡覺的區間與吵醒的BFB編號，每次修改時從頭遍歷，如果正好處於睡覺的期間就將該節點一分為二，若是切到頭或尾修改即可，若是橫跨多個節點則直接刪除。因為每次修改都是從頭遍歷，時間複雜度約為$O(nlog(n))$。

首先是宣告與建構的部分。`sta`與`end`代表睡著的開始與結束（左閉右開），`num`代表吵醒的那隻BFB編號。
```cpp=
class lst {
public:
	int sta, end, num;
	class lst *next;
};

void input(lst *ptr, int a, int b, int c, lst *nt) {
	ptr->sta = a;
	ptr->end = b;
	ptr->num = c;
	ptr->next = nt;
}
```
不清楚Class裡面的建構元是否可以建構指摽型態的資料，故選擇了在外頭另開一個函式。

接下來的問題在於如何修改每一次輸入的`f`與`s`。這裡因為是單向串列，我選擇使用了雙指標，方便節點的刪除與修改。
```cpp=
int n, f, s;
cin >> n;
lst *newlst, *ptrf, *ptrs, *delptr;
delptr = new lst;
input(delptr, 0, maxn, 0, nullptr);
s += 5;
ptrf = delptr;
ptrs = delptr;
```
這裡直接將`s`加了$5$，形成醒著的區間`{f,s)`，左閉右開。

接下來將兩個指標定位，一個使`f`小於該節點的起床時間，另一個則在這個節點的前面。記得判別當`ptrf`位於第一個獲最後一個的情況。
```cpp=
//將ptrf移動到f的位置（之間或之後）
while(f > ptrf->end && ptrf->next)
	ptrf = ptrf->next;
//將ptrs移動到ptrf前一格（或同一格，當ptrf為第一格
while(ptrs->next != ptrf && ptrs != ptrf)
	ptrs = ptrs->next;
```

定位完後再分情況判斷。總共有三種情況：
1. `f`與`s`都在同一個節點裡，將節點一分為二即可。
2. `f`在節點裡而`s`未知，將該節點做修飾後再找到可能包含`s`的節點，判斷是否需要修飾。
3. `f`在兩個節點中間，找到可能包含`s`的節點並判斷是否需要修飾。

可以發現情況一與情況二，包含`f`的節點都需要修飾，因為遍歷過程為單向，故先做處理。
```cpp=
if(f > ptrf->sta) {
	if(s < ptrf->end) {
		//情況一
		newlst = new lst;
		input(newlst, s, ptrf->end, ptrf->num, ptrf->next);
		input(ptrf, ptrf->sta, f, i, newlst);
		continue;
	}
	else {
		//情況二
		ptrf->end = f;
		ptrf->num = i;
		ptrs = ptrf;
	}
}
```
處理完`f`後，其中一個指標定位`s`，一個指標固定，定位完後，在後頭的指標指到前面指標的過程中順道將無用的節點刪除。這裡借用了`newlst`來協助刪除的動作。
```cpp=
//將ptrf移動至s的位置（之前或之後）
while(ptrf->end < s && ptrf->next)
	ptrf = ptrf->next;
//不論前面是否執行，ptrs該格皆不會被刪除
while(ptrs->next != ptrf) {
	//將ptrs至ptrf之間的格子全數刪除
	newlst = ptrs->next;
	ptrs->next = newlst->next;
	delete newlst;
}
//判斷ptrf是否需要修飾
if(s > ptrf->sta)
	ptrf->sta = s;
```
最後再從頭遍歷，邊輸出邊刪除就大功告成了。
```cpp=
ptrf = delptr;
if(!ptrf->num) {
	cout << "Every BFB is alive, it's another peaceful day.'\n";
}
while(ptrf->num) {
	cout << "At time " << ptrf->end << ", BFB No." << ptrf->num << " is killed.\n";
	delptr = ptrf;
	ptrf = ptrf->next;
	delete delptr;
}
delete ptrf;
```
另外別忘了在前面加上空包彈的判別。
```cpp=
if(f == s)
	continue;
```
以下是全部的程式碼。

```cpp=
#include <iostream>
using namespace std;
const int maxn = 1e9;

class lst {
public
	int sta, end, num;
	class lst *next;
};

void input(lst *ptr, int a, int b, int c, lst *nt) {
	ptr->sta = a;
	ptr->end = b;
	ptr->num = c;
	ptr->next = nt;
}

int main() {
	int n, f, s;
	cin >> n;
	lst *newlst, *ptrf, *ptrs, *delptr;
	delptr = new lst;
	input(delptr, 0, maxn, 0, nullptr);
	for(int i=1;i<=n;i++) {
		cin >> f >> s;
		if(f == s)
			continue;
		s += 5;
		ptrf = delptr;
		ptrs = delptr;
		//將ptrf移動到f的位置（之間或之後）
		while(f > ptrf->end && ptrf->next)
			ptrf = ptrf->next;
		//將ptrs移動到ptrf前一格（或同一格，當ptrf為第一格
		while(ptrs->next != ptrf && ptrs != ptrf)
			ptrs = ptrs->next;
		//判斷f與ptrf的關係
		if(f > ptrf->sta) {
			if(s < ptrf->end) {
				//f與s皆在ptrf內，建新格將ptrf一分為二
				newlst = new lst;
				input(newlst, s, ptrf->end, ptrf->num, ptrf->next);
				input(ptrf, ptrf->sta, f, i, newlst);
				continue;
			}
			else {
				//因已知ptrf內有f，修飾ptrf且將ptrs移至ptrf
				ptrf->end = f;
				ptrf->num = i;
				ptrs = ptrf;
			}
		}
		//將ptrf移動至s的位置（之前或之後）
		while(ptrf->end < s && ptrf->next)
			ptrf = ptrf->next;
		//不論前面是否執行，ptrs該格皆不會被刪除
		while(ptrs->next != ptrf) {
			//將ptrs至ptrf之間的格子全數刪除
			newlst = ptrs->next;
			ptrs->next = newlst->next;
			delete newlst;
		}
		//判斷ptrf是否需要修飾
		if(s > ptrf->sta)
			ptrf->sta = s;
	}
	//輸出
	ptrf = delptr;
	if(!ptrf->num) {
		cout << "Every BFB is alive, it's another peaceful day.'\n";
	}
	while(ptrf->num) {
		cout << "At time " << ptrf->end << ", BFB No." << ptrf->num << " is killed.\n";
		delptr = ptrf;
		ptrf = ptrf->next;
		delete delptr;
	}
	delete ptrf;
}
```

## 心得
由於整個題目頗具原創性，從一開始我就在多次插入與修改苦惱了許久。因為不熟於指標的運用，在工具上就直接少了一項。直至這次課程才發現鏈結串列與本題的契合度，雖然之前也有相似想法，但未曾實踐過。過程不難想像，但難點在於什麼要先做什麼要擺後面，逐次判斷狀況才能順利在一次遍歷就完成修改。概念理解後，剩下的就是單純的指標操作了，看似繁瑣，但分解看來也就沒那麼複雜了。從上完Linked List到完成程式碼只花了大概一週，比起想解法的半年短多了。以及就是測資的生成，使用了同學的模板，但那又是另一回事了。

另外也有同學提供了其他解法，是使用vector儲存後sort過去再進行判讀，捨棄了陣列的概念，不失為一種解法。並且題目可以再多問說總共的睡眠時間，測資數量也能再增加以抵制容量使用量大的vector。不論如何，見證了自己的題目從構思到完成，且又具有些許挑戰性，讓自己充滿成就感。
> [name=jaterychen]

## 參考資料
[Class - @konchin](https://hackmd.io/@konchin/rJy7uNO5U)
[Basic fstream - @revcoding](https://hackmd.io/q4WFzFFQQG-Wj0Qpht9Zrw)

最後留個出測資用的程式碼，模板為[@revcoding](https://hackmd.io/@revcoding)所有。
```cpp=
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>
using namespace std;
const int maxn = 1e9;

const string id = "a572"; // problem id
vector<int> num{1, 1}; // number of test data
vector<pii> range_n{{10000, 100000}, {100000, 1000000}}; // range: [l, r]
vector<pii> range_ab{{1, 10000000}, {1, 1000000000}}; // range: [l, r]
fstream fin, fout;

string fn(int x) {
	return string{char('0' + x / 10), char('0' + x % 10)};
}

class lst {
	public:
		int sta, end, num;
		class lst *next;
};

void input(lst *ptr, int a, int b, int c, lst *nt) {
    ptr->sta = a;
    ptr->end = b;
    ptr->num = c;
    ptr->next = nt;
}

int solve(vector<int> inp) {
	/* code here to solve */
	/* return solution */
	/* or just use "fout << ans" */
	int n = inp[0];
	int f, s;
	lst *newlst, *ptrf, *ptrs, *delptr;
    delptr = new lst;
    input(delptr, 0, maxn, 0, nullptr);
    for(int i=1;i<=n;i++) {
        f = inp[2*i-1];
        s = inp[2*i];
        if(f == s)
            continue;
        s += 5;
        ptrf = delptr;
        ptrs = delptr;
        while(f > ptrf->end && ptrf->next)          //將ptrf移動到f的位置（之間或之後）
            ptrf = ptrf->next;
        while(ptrs->next != ptrf && ptrs != ptrf)   //將ptrs移動到ptrf前一格（或同一格，當ptrf為第一格
            ptrs = ptrs->next;
        if(f > ptrf->sta) {                         //判斷f與ptrf的關係
            if(s < ptrf->end) {                     //f與s皆在ptrf內，建新格將ptrf一分為二
                newlst = new lst;
                input(newlst, s, ptrf->end, ptrf->num, ptrf->next);
                input(ptrf, ptrf->sta, f, i, newlst);
                continue;
            }
            else {                                  //因已知ptrf內有f，修飾ptrf且將ptrs移至ptrf
                ptrf->end = f;
                ptrf->num = i;
                ptrs = ptrf;
            }
        }
        while(ptrf->end < s && ptrf->next)          //將ptrf移動至s的位置（之前或之後），該格不會被刪除
            ptrf = ptrf->next;
        while(ptrs->next != ptrf) {                 //不論前面是否執行，ptrs該格皆不會被刪除
            newlst = ptrs->next;                    //將ptrs至ptrf之間的格子全數刪除
            ptrs->next = newlst->next;
            delete newlst;
        }
        if(s > ptrf->sta)                           //判斷ptrf是否需要修飾
            ptrf->sta = s;
    }
    ptrf = delptr;
    if(!ptrf->num) {
        fout << "Every BFB is alive, it's another peaceful day.'\n";
    }
    else {
        while(ptrf->num) {
            fout << "Poor BFB No." << ptrf->num << " died at time " << ptrf->end << "...\n";
            delptr = ptrf;
            ptrf = ptrf->next;
            delete delptr;
        }
    }
    delete ptrf;
}

int main() {
	srand(time(0));
	mt19937 gen(rand());
	
	for (int i = 0; i < num.size(); i++) {
		uniform_int_distribution<int> a(range_ab[i].f, range_ab[i].s), b(range_ab[i].f, range_ab[i].s);
		uniform_int_distribution<int> inn(range_n[i].f, range_n[i].s);
		fin.open(id + "_" + fn(i + 4) + ".in", ios::out);
		fout.open(id + "_" + fn(i + 4) + ".out", ios::out);
		
		/* ---------- data ----------*/
		for (int j = 0; j < num[i]; j++) {
			vector<int> inp;
			
			/* input, output data
			e.g.
			
			auto rd = dis(gen);
			fin << rd << '\n';
			fout << solve(rd) << '\n';
			
			*/
			
			auto rn = inn(gen);
			fin << rn << '\n';
			inp.push_back(rn);
			
			for(int k = 0; k < rn; k++) {
				auto ra = a(gen), rb = b(gen);
				if(ra > rb) swap(a, b);
				fin << ra << ' ' << rb << '\n';
				inp.push_back(ra);
				inp.push_back(rb);
			}
			
			
			fout << solve(inp) << '\n';
		}
		fin.close();
		fout.close();
	}
	return 0;
}
```

