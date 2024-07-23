# まとめ

## [Boot camp for Beginners Hard 100](https://kenkoooo.com/atcoder/#/training/Boot%20camp%20for%20Beginners/3)

---

## 1 D. Gathering Children

### 解き方

- 解説 AC した。
- DP で解く。
- 下記の dp[0][i]の中に最初に移動した位置が入る。

```c++
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            dp[0][i] = i + 1;
        } else if (S[i] == 'L') {
            dp[0][i] = i - 1;
        }
    }
```

- 下記で遷移できる。

```c++
    for (int i = 0; i < DP_MAX - 1; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }
```

- 下記で答えを取得できる。

```c++
    for (int i = 0; i < N; i++) {
        ans[dp[DP_MAX - 1][i]]++;
    }
```

---

## 2

### 解き方

---

## 3 A - Range Flip Find Route

### 解き方

- 解説 AC した。
- DP で 白色'.' ⇒ 黒色'#'になった箇所をカウントすれば OK

- 下記のように一番上の行と一番左の列を先に計算してから DP を実装すると楽

```c++
    for (int i = 1; i < H; i++) {
        if (A[i + 1][1] == '#' && A[i][1] == '.') {
            dp[i + 1][1] = dp[i][1] + 1;
        } else {
            dp[i + 1][1] = dp[i][1];
        }
    }
    for (int i = 1; i < W; i++) {
        if (A[1][i + 1] == '#' && A[1][i] == '.') {
            dp[1][i + 1] = dp[1][i] + 1;
        } else {
            dp[1][i + 1] = dp[1][i];
        }
    }
```

---

## 4 B. Between a and b ...

### 解き方

- a と b を x で割って値をカウントする。
- a を割り切れた場合+1 できることに注意する。

---

## 5 D. Powerful Discount Tickets

- 解説 AC した。
- priority_queue 型を使って値が最大の商品を割っていく

---

## 6 C. Dubious Document 2

- 解説 AC した。
- 後方から貪欲的に一致する文字列を探していく
- 置き換える部分に T の文字を含んでいる必要は無い
- 後ろから数えて T の文字数分だけ?の場合はそこが T に置き換わる
  - 下記のインプットの場合は答えは aaazz になることに注意
    > input:  
    > ?????  
    > zz  
    > output:  
    > aaazz

---

## 7 D. Integer Cards

- 解説 AC した。
- なるべく大きい値で数字を置き換えたいので
  - A は昇順ソート
  - B,C は C の値で降順ソートする

---

## 8 E. Double Factorial

- 解説 AC した。
- 最初に 10 で割れる数がいくつあるか数える
- そのあとは 5 \* 2 で一桁増えるので、
- 5 で割れる数、5 * 5 で割れる数 5 *5 \*5 で割れる数...をカウントしていけば OK

---

## 9 B. Template Matching

- 制約 1≦M≦N≦50 なので貪欲法で OK
- 下記のように B の左上と A の各座標が一致していれば、全ての値が一致するか判定する処理を走らせる

```c++
            if (A[i][a_n] == B[0][0])
```

---

## 10 D. Enough Array

- 解説 AC した。
- 先頭から for を回していく
  - 各連続部分列に対して、どのタイミングで K の値以上になったかがわかれば
    - ans += N - cnt - i; のようにして、その A[i]に対して K の値 以上になる個数がわかる

---

## 12 B. Counting of Trees

- 解説 AC した。
  - https://img.atcoder.jp/nikkei2019-2-qual/editorial.pdf
  - https://kawakeee.hatenablog.com/entry/2019/11/10/135302
- A[0]が 0 か、0 の数が二つある場合は答えは 0 になる
- 数字の個数をカウントして 1 から順番に下記の処理を回す

```c++
        ans = ans * mod_pow(cnt[i - 1], cnt[i], MOD);
```

---

## 13 D. Lucky PIN

- 解説 AC した。
- パスワードは 000 ~ 999 までの 1000 通り
- 上記 000 ~ 999 を渡された S で作れるかを判定すれば OK
- 4≤N≤30000 なので 30000 \* 1000 は十分に間に合う

---

## 14 C. Digits in Multiplication

- 解説 AC した。
- N の約数の vector を取得する。
- 後は先頭から貪欲法で OK
- N の約数の vector の取得方法は最適化されている必要がある

---

## 15 D. Flipping Signs

- 解説 AC した。
- エスパー力が試される問題
- 負の数が偶数個の場合、全ての数字を正にできる
- 負の数が奇数個の場合、一つだけ、負になる
  - 絶対値の合計から絶対値が一番小さい数字を良い感じに引けば OK

---

## 16 D. Line++

- 解説とソースコードを見て AC した
- N を二十ループで回して、
  - 1 重ループからの 2 重ループ目までの距離をカウントする
- 対象の距離の配列 cnt[k]をインクリメントする
- 頂点 X と頂点 Y の間の辺を通らない場合の最小の距離は下記になる

```c++
            k = min(k, j - i);
```

- 頂点 X と頂点 Y の間の辺を通った場合の最小の距離は下記になる

```c++
   abs(X - i) + abs(Y - j) + 1
```

---

## 17 C. AB Substrings

- 解説 AC した。
- 文字の中の"AB"の数は貪欲法でカウントする
- 下記のパターンを考える
  - 1. 先頭が B、末尾が A
  - 2. 先頭が B、末尾が A でない
  - 3. 先頭が B でなく、末尾が A
  - 4. 先頭が B でなく、末尾が A でない
- パターン 4 は無視して OK
- パターン 1 が 0 かどうかで結果が変わる
  - パターン 1 が 0 の場合、min(パターン 2,パターン 3)を足す
  - パターン 1 が 0 以外の場合
    - パターン 2,パターン 3 がともに 0 の場合、パターン 1 - 1 を足す
    - パターン 2,パターン 3 のどちらかが 0 以外の場合、パターン 1 + min(パターン 2,パターン 3)を足す

---

## 18 C. Back and Forth

- 解説 AC した。
- 一回目は(sx,sy)から(tx,ty)までは ↑→ の順の最短距離で良く
- 二回目は(tx,ty)から(sx,sy)までは ↓← の順の最短距離で良く
- 三回目は(sx,sy)から一つ下におりて一回目と二回目のルートを 1 マス分遠回りする
- 四回目は(tx,ty)から一つ上に移動して一回目と二回目のルートを 3 回目とは違うルートで 1 マス分遠回りする

---

## 19 D. Grid Coloring

- a1,a2...an を画像のように蛇行して設定できれば OK
  ![Alt text](%E7%94%BB%E5%83%8F/%E9%85%8D%E5%88%97%E3%81%AE%E4%BB%A3%E5%85%A5.png)

- 蛇行して設定する方法は下記

```c++
    int cnt_h = 0;
    int cnt_w = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < A[i]; j++) {
            mass[cnt_h][cnt_w] = i;

            if (cnt_h % 2 == 0) {
                cnt_w++;
            } else {
                cnt_w--;
            }

            if (cnt_w == W) {
                cnt_h++;
                cnt_w--; // ここで--する必要があるのに注意
            }
            if (cnt_w == -1) {
                cnt_h++;
                cnt_w++; // ここで++する必要があるのに注意
            }
        }
    }
```

---

## 20	C. ID

- そのまま対象の配列に下記のように設定すればOK
```c++
    int P[M + 1];
    int Y[M + 1];
    vector<int> city[N + 1];

    for (int i = 0; i < M; i++) {
        cin >> P[i];
        cin >> Y[i];
        city[P[i]].push_back(Y[i]);
    }
```
- 二分探索を使うためにソートする
```c++
    for (int i = 0; i < N + 1; i++) {
        sort(city[i].begin(), city[i].end());
    }
```
- 対象のY[i]が何番目にあるかは下記のように取得できる
```c++
        auto it = lower_bound(city[P[i]].begin(), city[P[i]].end(), Y[i]);
        int cnt = distance(city[P[i]].begin(), it) + 1;
```
- 文字の余白を詰める書き方は下記
```c++
    for (int i = 0; i < M; i++) {
        cout << setfill('0') << right << setw(6) << to_string(pre[i]);
        cout << setfill('0') << right << setw(6) << to_string(post[i]) << endl;
    }
```

---
## 21	D. Binomial Coefficients

- 解説 AC した。
- エスパー力が試される問題
- 参考記事: [パスカルの三角形](https://ja.wikipedia.org/wiki/%E3%83%91%E3%82%B9%E3%82%AB%E3%83%AB%E3%81%AE%E4%B8%89%E8%A7%92%E5%BD%A2)
- comb(n,r) の n は最大値 r は最大値の半分にもっとも近い数字が答えになる

---

## 22 C. String Transformation
- 解説 AC した。
- 各文字 S に対して T でどの文字に変換されるかの配列に変換できるかの配列を見つければ良い

```c++
    for (int i = 0; i < N; i++) {
        int S_moji = S[i] - 'a';
        int T_moji = T[i] - 'a';
        hikaku[S_moji][T_moji] = true;
    }
```

---
## 24	B. Robot Arms

- 解説 AC した。
- ロボットの腕が最長で右にどれくらい伸びているのかを求めてソートする
```c++
    pair<int, int> range[N + 1];
    for (int i = 0; i < N; i++) {
        range[i].first = robo[i].first + robo[i].second;
        range[i].second = robo[i].first - robo[i].second;
    }
    sort(range, range + N);
```
- 貪欲法で求める
  - 一番左から腕の範囲が被らなければカウントして、そのロボットが選ばれたロボット
```c++
    int cnt = 1;
    pair<int, int> prev = range[0];
    for (int i = 1; i < N; i++) {
        if (prev.first <= range[i].second) {
            prev = range[i];
            cnt++;
        }
    }
```

---
## 25	C. Special Trains

- 下記の制約から各地点からNまでかかる時間を二重ループで求めればOK
```
制約
1≦N≦500
1≦Ci≦100
1≦Si≦10^5
1≦Fi≦100
Si％Fi=0
```

--- 

## 26	B. K Cakes

- エスパー力が試される問題
- 一番大きい数値数値を -1 して、他の数値分マイナスしていく

---

## 27	D. Ki

- 深さ優先探索 DFS で解く
  - [DFSのアルゴリズム](https://algo-logic.info/dfs/)
- 下記でツリーを作成
```c++
    for (int i = 0; i < N - 1; i++) {
        pos[A[i]].push_back(B[i]);
        pos[B[i]].push_back(A[i]);
    }
```
- 下記で探索して次のノードに値を加算していく
```c++
    stack<int> st;
    st.emplace(1);
    flag[1] = true;
    while (st.size() != 0) {
        int state = st.top();  // 現在の状態
        st.pop();
        for (auto next : pos[state]) {
            if (!flag[next]) {  // 未探索の時のみ行う
                flag[next] = true;
                st.emplace(next);  // 次の状態をqueueへ格納
                ans[next] += ans[state];
            }
        }
    }
```

---

## 28	C. Candles
- 解説 AC した。
- 手前から貪欲法するのと、後ろから貪欲法するので、二回貪欲法をする。
- 下記で距離を計算できる
```c++
        int temp_left = A[i - K];
        int temp_right = A[i - K + K - 1];
        int temp_dis = abs(temp_left) + abs(temp_right - temp_left);
```
---

## 29 B. Colorful Creatures
- 下記の制約だと N ^ 2 だと TLE するので注意
```制約
2≤N≤100000
```
- 昇順ソートする
- 次のスライムを取り込めるかどうかを下記で判定する
  - 取り込めない場合、次のスライムに取り込まれてしまうので、カウントをリセットする
```c++
        if (size * 2 < A[i]) {
            cnt = 0;
        }
```

---

## 31 D. Preparing Boxes
- 後ろからいくつボールを入れる必要があるか決めていく
  - 倍数の個数分ボールをカウントする必要があるので、
- 出力の内容に注意
  - ボールを何番目の箱に入れるかを出力する


---

## 32 C. Factors of Factorial
- 解説 AC した。
- 素因数分解する
  - 各素数で割り切れる個数 + 1をかけていけばOK
  - (2で割り切れる個数 + 1) * (3で割り切れる個数 + 1) * (5で割り切れる個数 + 1) * (7で割り切れる個数 + 1)


---

## 34 C. Lining Up
- エスパー力が求められる問題
- pow(2,N - 2)が基本的に答えになる
- N = 1のケースの考慮漏れに注意
- Aiの数字は一つずつ出てくる
  - mapで数字を数えて 2 でない場合は、0 が答えになる
- 10 ^ 9 + 7 は下記
```c++
    const long long MOD = 1e+09 + 7;
```
---

## 35 D. Katana Thrower
- 投げた場合の攻撃力の合計を計算してから
- 切った場合の攻撃力を計算すればOK

---

## 38 D. Maze Master
- 解説 AC した。
- 幅優先探索をする
  - queで実装する方
- 制約から問題なし
```
1≤H,W≤20
```
---

## 39 C. Stones
- 解説 AC した。
- 左から黒石と白石の数を数える
  - 0(全て黒石にする場合)からN個目までループさせて各個数で、何個石を変えれば良いかをカウントする
```c++
    long long ans = 1LL << 60;
    for (int i = 0; i <= N; i++) {
        long long temp = 0;
        // 黒石にする数
        temp += cntShiro[N] - cntShiro[i];
        // 白石にする数
        temp += cntKuro[i] - cntKuro[0];

        ans = min(ans, temp);
    }
```

---

## 40 C. Inserting 'x'
- 解説 AC した。
- whileでループする
  - 先頭の文字と後ろの文字が同じ場合
    - 先頭と後ろの文字を削除
  - 先頭の文字が'x'で後ろがx'以外
    - 後ろに'x'を付与
    - カウントを++
  - 先頭の文字が'x'以外で後ろがx'
    - 先頭に'x'を付与
    - カウントを++
  - 上記の処理を繰り返して文字列の長さが 1 以下になると終了
  - 上記以外は -1 を出力する

---

## 41	C. Triangular Relationship
- 解説 AC した。
- 下記のため
```
(b + c) % K = 0
(a + b) % K = 0
(c + a) % K = 0
```
- 下記が成り立つ
```
a % K = 0
b % K = 0
c % K = 0
```
- K が奇数の場合は上記の数を count して
  - count * count * count が答えになる
- K が偶数の場合は下記が成り立つ
```
a % K + b % K = 0
```
- a + b が K の倍数
- つまりaとbはKの倍数の半分の値になる
- i % K == K / 2 となる数を数える
  - 答えにcount * count * count を足す



---

## 42 D. Insertion
- ~~解説 AC した。~~ 解説見たけど解けてない
- '(' と ')' は S の先頭か末尾に付ける
- '(' の個数をカウントして')'の分だけカウントをマイナスする
  - カウント分だけ末尾に ')' を末尾に付ける
- 上と同様にカウントして先頭に ')' を付ける
- S = S + ')' と S = ')' + S の + を入れる順序に注意する


---

## 43	D. Wall
- 解説ACした。
- [ワーシャル・フロイド法](https://algo-logic.info/warshall-floyd/)で最短距離を求めておく
- 下記で 1 になる場合の合計を求める
```c++
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] >= 0) {
                ans += C[A[i][j]][1];
            } else {
            }
        }
    }
```

---

## 45	D. 2017-like Number
- 久しぶりに自力で解けた
- エラトステネスのふるいで事前に 100000 までの素数の数を求めておく
- 累積和で結果を出力すればOK
```c++
        ans = sosuu_cnt[r[i]] - sosuu_cnt[(l[i] - 1)];
```

---




## chips

## 注意事項

**あとできれいにまとめる**

- priority_queue
  - 降順に値を入れる

```c++
  // データを追加する
  que.push(3);
  que.push(1);
  que.push(4);

  // 処理順に出力する
  while (!que.empty()) {
    cout << que.top() << endl;
    que.pop();
  }
  // 4 3 1
```

- 昇順に値を入れる [priority_queue](https://cpprefjp.github.io/reference/queue/priority_queue.html)

```c++
  // 昇順に処理する
  {
    priority_queue<
      int,                // 要素の型はint
      vector<int>,   // 内部コンテナはstd::vector (デフォルトのまま)
      greater<int>   // 昇順 (デフォルトはstd::less<T>)
    > que;

    que.push(3);
    que.push(1);
    que.push(4);

    while (!que.empty()) {
      cout << que.top() << endl;
      que.pop();
    }
```

- pair 型のソート [C++ vector<pair>のソートいろいろ 競プロ覚書](https://hiroms-blog.com/entries/vetor-pair-sort-varieties)

- first 昇順 first が同値の場合 second 昇順

```c++
int main() {
    vector<pair<int, int>> pairs = {{2, 3}, {1, 3}, {1, 2}, {5, 4}};
    sort(pairs.begin(), pairs.end());
    for(int i = 0; i < 4; i++) {
      cout << "first: " << pairs[i].first << ", second:" << pairs[i].second << endl;
    }
    return 0;
}
```

- first 降順 first が同値の場合 second 降順

```c++
int main() {
    vector<pair<int, int>> pairs = {{2, 3}, {1, 3}, {1, 2}, {5, 4}};
    sort(pairs.rbegin(), pairs.rend());
    for(int i = 0; i < 4; i++) {
      cout << "first: " << pairs[i].first << ", second:" << pairs[i].second << endl;
    }
    return 0;
}
```

- first 昇順 first が同値の場合 second 降順
- first 降順 first が同値の場合 second 昇順

  - 上に張ったリンク先参照

- [10 進数の桁数を求める](https://qiita.com/EqualL2/items/168e083caa5f07a1105b)
  - num の 10 進数の桁数を返す

```c++
unsigned GetDigit(unsigned num) {
    unsigned digit = 0;
    while (num != 0) {
        num /= 10;
        digit++;
    }
    return digit;
}
```

- [N の約数を全列挙するアルゴリズム](https://algo-logic.info/divisor/)
  - n の約数の配列を返す

```c++
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());  // 昇順に並べる
    return ret;
}
```

- 対象のY[i]が何番目にあるかは下記のように取得できる 集合のset型でも同様に取得可能
```c++
        auto it = lower_bound(city[P[i]].begin(), city[P[i]].end(), Y[i]);
        int cnt = distance(city[P[i]].begin(), it) + 1;
```

- 文字の余白を詰める書き方は下記
```c++
    for (int i = 0; i < M; i++) {
        cout << setfill('0') << right << setw(6) << to_string(pre[i]);
        cout << setfill('0') << right << setw(6) << to_string(post[i]) << endl;
    }
```

- 累積和のような総和を用いる問題は long long 型で宣言すること


