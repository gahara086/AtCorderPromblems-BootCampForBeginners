# まとめ

## [Boot camp for Beginners Medium 100](https://kenkoooo.com/atcoder/#/training/Boot%20camp%20for%20Beginners/3)

**※苦手な問題を赤字で記す**

---

## 1 B. Trained?

### 解き方

- そのまま代入する 無限ループするかは cnt>100000 で強引に判定する

```c++
        lihgt = A[lihgt];
        if (cnt > 100000) {
            cnt = -1;
            break;
        }
```

---

## 2 A. Irreversible operation

### 解き方

- 黒を 1 白を 0 に置き換えて２進数に変換する
  - BBW -> 110 BWBWBW -> 101010
- 処理を行うと黒が一つ右にビットシフトする
- 黒の位置に応じて回数をプラスする

---

## 3 A. ><

### 解き方

- 小なり「<」大なり「>」を別々に分けて実装する
- 小なり「<」を満たすように変換

```c++
    for (int n = 0; n < S.length(); n++) {
        if (S[n] == '<') {
            N[n + 1] = max(N[n + 1], N[n] + 1);
        }
    }
```

- 大なり「>」を満たすように変換

```c++
    for (int n = S.length(); n > 0; n--) {
        if (S[n - 1] == '>') {
            N[n - 1] = max(N[n - 1], N[n] + 1);
        }
    }
```

---

## 4 B. ss

### 解き方

- そのままごり押し

```c++
   while (true) {
        cnt++;
        temp.pop_back();
        int temp_size = temp.size();
        if (temp_size % 2 != 0) {
            continue;
        }
        string before_str = temp.substr(0, temp_size / 2);
        string aftere_str = temp.substr(temp_size / 2, temp_size - 1);
        if (before_str == aftere_str) {
            break;
        }
    }
```

---

## 5 D. ModSum

### 解き方

- 制約「N は 1≤N≤10^9 を満たす整数である。」のため、for を使うと実行時間オーバーする
- 上記制約から long long を使うこと
- あまりが最大になる組は((N) % (N - 1)) + ((N - 1) % (N - 2))+ ((N - 2) % (N - 3))...となる

  等差数列の和の公式を用いて解く

```c++
    long long sum = 0;
    long long temp = N - 1;
    sum = (1 + temp) * temp / 2;
```

---

## 6 B. Minesweeper

### 解き方

- string S とは別に long long map[H + 1][w + 1]を用意する
- 配列外アクセスに注意してそのまま解く

---

## 7 B. Cut and Count

### 解き方

- 制約 2≤N≤100 なので計算量は N^logN でも OK
- 文字列は重複してカウントしないので、分割後にソートして重複は削除する

```c++
    for (int i = 1; i < N; i++) {
        string before = S.substr(0, i);
        string after = S.substr(i, N - 1);
        sort(before.begin(), before.end());
        sort(after.begin(), after.end());
        before.erase(unique(before.begin(), before.end()), before.end());
        after.erase(unique(after.begin(), after.end()), after.end());
        /* 以下略 */
```

---

## 8 C. Colorful Leaderboard

### 解き方

> また、レートが 3200 以上になると色を自由に変えることができます。

- 問題文の上記の文言は 8 種類の色「灰色」「茶色」「緑色」「水色」「青色」「黄色」「橙色」「赤色」以外になることに注意
- 最小値のパターン N = 1 A1 = 9999 を入力した場合の結果のロジックの考慮漏れで WA が続いてしまった

---

## 9 B. Choose Integers

### 解き方

- A B C の各値を偶数か奇数かで判定するロジックでは解けないので要注意
- A の n 倍を B で割った余りが C になるかを for で強引に判定する

---

## 10 C. Together

### 解き方

- a1,a2...aN の最大値分の配列を作って、その配列の添え字の a[n]の+-1 までの範囲の数を数える

---

## 11 B. Checkpoints

### 解き方

- 制約 1≦N,M≦50 だと計算量 N\*M でも問題無いみたい
- そのまま二重ループで解く

---

## 12 B. Grid Compression

### 解き方

- なんかうまく行かなかったからあとで考える
- 配列外アクセスを考慮するのが苦手

---

## 13 C. Traveling

### 解き方

- 残り時間と距離の差が奇数かどうか

---

## <font color="Red">14 C. Grid Repainting 2</font>

### 解き方

- 周りを'#'にしてあげると、配列外アクセスの判定がスムーズになる

```c++
    // input
    char S[H + 2][W + 2];
    for (int i = 0; i <= H + 1; i++) {
        for (int j = 0; j <= W + 1; j++) {
            S[i][j] = '#';
        }
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> S[i][j];
        }
    }
    // calc
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (S[i][j] == '#') {
                if (S[i - 1][j] != '#' && S[i][j - 1] != '#' &&
                    S[i + 1][j] != '#' && S[i][j + 1] != '#') {
                    ans = false;
                }
            }
        }
    }
```

---

## 15 B. KEYENCE String

### 解き方

- 制約 S の長さは 7 以上 100 以下から連続した文字列を削除したパターン全てを比較する N^2 の計算量でも OK

---

## 16 C. Bugged

### 解き方

- 動的計画法で解く
- 前回のループ時の値を代入する箇所が漏れて wa になった

---

## 17 C. Sentou

### 解き方

- 超過するかどうかは if で判定してそのまま解く
- t[0]t[1]には 0 が入るのでループして足し算する時に処理に注意する

---

## 18 C. Takahashi's Information

### 解き方

- メモ帳に ↓ を書き出したのが良かった
- (c[0][0] + c[1][1] + c[2][2]) == a1 + b1 + a2 + b2 + a3 + b3 で
- 3 \* (c[0][0] + c[1][1] + c[2][2]) == 3(a1​ + a2 + a3 + b1 + b2 + b3) が成り立つかどうかで判定できるのに気づけた

```
a1 + b1, a1 + b2, a1 + b3
a2 + b1, a2 + b2, a2 + b3
a3 + b1, a3 + b2, a3 + b3

c1,1, c1,2, c1,3
c2,1, c2,2, c2,3
c3,1, c3,2, c3,3

3(a1​ + a2 + a3 + b1 + b2 + b3) = sum
```

---

## 19 B. RGB Boxes

### 解き方

- こういう問題は全てのパターンを計算しなくても最後のパターンの余りが 0 になるかで、値が存在するか判定できる

---

## 21 D. Banned K

### 解き方

- 制約 3≤N≤2×10 ^5,1≤Ai≤N にきをつけて全ての計算用の変数を long long で宣言する
- 全ての通りの合計を計算してから解く
- そこから値を引いて計算後の値を足せば OK

---

## 22 C. Dice and Coin

### 解き方

- for と while を使ってそのまま解く
- long long でインプットした N は計算時は(double)でキャストすることに注意

---

## 23 C. Guess The Number

### 解き方

- 数値を 0-999 まで回して文字列に変換して条件を満たしているか判定する
- 上記のループは 0 から始めないといけないことに注意する。
- 上記のループは桁数を満たしているかは変換した文字列の長さで判定できる。

---

## 24 A. A+...+B Problem

### 解き方

- 数字の例を実際に書き出せたのが良かった
- 組み合わせだと整数の総和が重複してしまうので、最大値と最小値がいくつになるのかに着眼する

---

## 25 C. Not so Diverse

### 解き方

- ボールの種類の数をカウントして、少ない順にボールの数をソートする
- 消すボールの数分だけ、加算していく

---

## 27 A. Prefix and Suffix

### 解き方

- 文字をどうやって比較するのかを考える
- s の先頭の文字と t の先頭の文字から比較し始めて、
  - 一致していれば s と t の添え字をインクリメント
  - 一致していなければ t の添え字をインクリメント

---

## 28 D. Dice in Line

### 解き方

- 期待値を入力時に計算しておいて、期待値が最大になる区間を for で回して探索する

---

## 30 C. Flip,Flip, and Flip......

### 解き方

- 絵を書けば計算式がわかるタイプの問題
- abs を使えば変に if 分を使わなくて良くなる

---

## 31 C. 4-adjacent

### 解き方

- 4 の倍数があれば数字二つをカバーできて、2 の倍数が 2 繋がれば 4 の倍数になるので、数字をカウントして下記のように計算する

```c++
        calc_ans = cnt_4 _ 2 + (cnt_2 / 2) _ 2 + 1;
```

- 下記のように 4 で割り切れる場合は 2 の倍数のカウントを一つ減らす

```c++
        if (A[n] % 2 == 0) {
            cnt_2++;
        }
        if (A[n] % 4 == 0) {
            cnt_2--;
            cnt_4++;
        }

```

---

## 32 C. Otoshidama

### 解き方

- 組み合わせをループで総当たりしていく
- 三つ目のループは下記のように答えが合っているかは引き算で判定できるので不要になる

```c++
            if (Y - (N - i - j) * 1000 == sum) {
                ans_10000 = i;
                ans_5000 = j;
                ans_1000 = (N - i - j);
            }

```

---

## 33 B. Unhappy Hacking (ABC Edit)

### 解き方

- ↓S で B からひとつ前と B の二文字削除

```c++
    S.erase(i - 1, 2);
```

- 削除した後 i = 0 にして先頭から再度削除するようにする
  - 最後までループすると i++でインクリメントされてしまうのでそのまま先頭の文字が B の場合は削除するようにする

---

## 34 C. Minimization

### 解き方

- 処理の過程を絵で表した。
- 最初に K の範囲を同じ数値にした後、次に同じ範囲を拡大させるためには、K の範囲をかぶらせないといけないので K-1 の範囲しか同じ値にできない。
  - while で同じ範囲にした数が N 以下になるのを計算する。

---

## 35 C. Anti-Division

### 解き方

- A と B の範囲で下記をカウントして解く
  - C で割れるものの個数
  - D で割れるものの個数
  - C と D で割れるものの個数、**C と D の最小公倍数で割れるものの個数であることに注意**

---

## 36 C. Skip

### 解き方

- ユークリッドの互除法で X と各座標の最大公約数が答えになる。
- 三つの場合下記のようなユークリッドの互除法で解ける。for で全ての距離の最大公約数を取っていく。
  - 三つの内の二つの数字の最大公約数をユークリッドの互除法で求めて，得られた最大公約数と残っている一つの数字の最大公約数をユークリッドの互除法で求めれば良い。

---

## 37 C. Grand Garden

### 解き方

- 最大値分ループさせて値を書く hN をデクリメントさせていく。
- prev_H のように前の hN の値が 0 になった場合に答えのカウントを増やす。
- for のループ開始を i = 2 のようにして実装すると、サンプルでは答えが合うが、別の解で AC にならず WA になってしまうので注意。

---

## 38 B. Problem Set

### 注意事項

- 制約 1≤N≤200,000 1≤M≤200,000 のため、計算量が N^2 だと TLE になる

### 解き方

- Dn をソートする
  - 各 Tn が D にあるかを二分探索で存在するか判定して、
    - 存在しない場合、NO
    - 存在する場合、対応する Dn を-1 に置き換えて値を取得済であることを表す

---

## 42 B. Evilator

### 解き方

- U と D の場合で場合分けする。
  - U の場合、上の階数分 +1 下の階数分 +2
  - D の場合、上の階数分 +2 下の階数分 +1

---

## 43 C. Go Home

### 解き方

- 時間 t でいける距離の最大値を等差数列の和の公式で求める
  - X < 求めた等差数列の和となる t が答え

---

## 45 C. pushpush

### 解き方

- scc の文字を作るのに M - N \* 2 が 0 以上になる場合とそれ以外で場合分けする

---

## 46 B. Palindrome-phobia

### 解き方

- メモ帳に実際の a,b,c それぞれの文字数を書き出したのが良かった。
- a,b,c それぞれの文字数の差が 2 以上になっている場合 NO になる。

---

## 47 A. Biscuits

### 解き方

- 解説の動画と pdf 通り

---

## 48 C. Rectangle Cutting

### 解き方

- ある一点を通れば常に面積は二等分できる。
  - 点が真ん中にあれば答えが二通り以上存在する。

---

## 51 <font color="Red">C. Many Medians</font>

わからなくて解説 AC した。

### 解き方

- ソートした X の配列から対象の Xi をを削除して真ん中にある数字が答えになる
  - 配列削除を毎回行うと、TLE になるため、連想配列 map を使って Xi が何番目の位置にあるかを決めておく必要がある
  - map<'値' 'ソート後の位置'>
- 解説がわかりやすい。
  - [解説](https://img.atcoder.jp/arc095/editorial.pdf)
  - [解説ソース](https://blog.hamayanhamayan.com/entry/2018/04/15/163238)

---

## 52 D. Megalomania

### 解き方

- 仕事終わりの時間までに仕事が完了するかを判定すれば OK。
  - pair の配列を仕事終わりの時間でソートする。

```c++
    vector<pair<int, int>> work;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cin >> B[i];
        work.push_back({B[i], A[i]});
    }
    sort(work.begin(), work.end());
```

---

## 53 C. Traveling Plan

### 解き方

- 解説 AC した
- 合計値から経路分を引く典型的な問題
  - 引く分の経路は図示して考える

---

## 55 C. Cat Snuke and a Voyage

### 解き方

- pair で値を入れてソートする

```c++
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        cin >> B[i];
        ship_create[i].first = A[i];
        ship_create[i].second = B[i];
    }
    sort(A, A + M);
    sort(ship_create, ship_create + M);
```

- 最初のインプット値 A もソートされていたおかげで、A の値の位置のイテレータを二分探索で取得できる

```c++
    for (int i = 0; i < M; i++) {
        if (ship_create[i].first == 1) {
            point = ship_create[i].second;
            auto itr = lower_bound(A, A + M, point);
            for (int j = itr - A; j < M; j++) {

```

---

## 56 C. Subarray Sum

### 解き方

- K の数分 S を表示させて、それ以外は S+1 を表示させる
- オーバーフローを考慮して S が 10 の 9 乗の場合は、S+1 ではなく 1 を表示させる

- 10 の 9 乗は下記のように書くこと
  - 1e+09

```c++
    if (S == 1e+09) {
```

---

## 57 C. Green Bin

### 解き方

- s1.s2...sN の文字列をソートする
- ソートした文字列を下記のように map でカウントする

```c++
    map<string, long long> calc;
    for (int i = 0; i < N; i++) {
        calc[A[i]] = 0;
    }
    for (int i = 0; i < N; i++) {
        calc[A[i]]++;
    }
```

- chips に記載した map のアクセスの方法で全てアクセスし、アナグラムを作れる個数を計算する

---

## 59 D. Derangement

### 解き方

- 制約 2≤N≤10^5 なので、計算量は N で OK
- 先頭から値が違えば swap していく
- swap する都合上、for を最後まで回さないため、最後の値が N になっているか判定する必要があるため注意

---

## 60 C. March

### 解き方

- 下記のような配列に'M''A''R''C''H'の文字列をカウントしていく

```c++
    long long cnt[5];
```

- cnt[5]を 3 重ループで組み合わせの数を掛け算してカウントしていく

---

## 61 D. String Formation

### 解き方

- そのまま処理を実装すると TLE になる
- 下記を for に組み込むと TLE になりがちなので注意

```c++
reverse(S.begin(), S.end());
```

- 下記のようなキューの配列を作成して que.size()分の処理を for で回す
  - rev_flag の値と Fi の値に応じて、for_push.second の bool 値を調整する

```c++
    bool rev_flag = false;
    pair<string, bool> for_push;
    vector<pair<string, bool>> que;
```

---

## 62 C. Monsters Battle Royale

### 解き方

- A1 A2 ... An の最大公約数を求めれば OK
- 下記のような制約で long long A[N]のように動的に配列を確保すると wa にはまる
  > 制約 入力は全て整数である。  
  > 2≤N≤10^5  
  > 1≤Ai≤10^9

---

## 63 B. Snuke's Coloring 2 (ABC Edit)

### 解き方

- そのまま範囲を下記のように設定して計算する

```c++
    int W_max = W;
    int W_min = 0;
    int H_max = H;
    int H_min = 0;
```

- インプットした X,Y をそのまま W_max,W_min,H_max,H_min に代入すると wa になるので下記のように値を代入する

```c++
        switch (A) {
            case 1:
                W_min = max(X, W_min);
                break;
            case 2:
                if (X <= W) {
                    W_max = min(X, W_max);
                }
                break;
            case 3:
                H_min = max(Y, H_min);
                break;
            case 4:
                if (Y <= H) {
                    H_max = min(Y, H_max);
                }
                break;
            default:
                break;
        }

```

---

## 64 C. Good Sequence

### 解き方

- 下記のような制約で から計算量は N ぐらいなのは明らか
  > 制約 入力は全て整数である。  
  > 2≤N≤10^5
  > ai は整数である。
  > 1≤Ai≤10^9
- 下記のような配列で input する

```c++
    map<long long, long long> cnt;
    for (int i = 0; i < 1e+05; i++) {
        cnt[i] = 0;
    }

    long long input;
    for (int i = 1; i <= N; i++) {
        cin >> input;
        cnt[input]++;
    }
```

- cnt の map から条件に超過する分と条件に足りない分を計算して足していく

---

## 66 A. Multiple Array

### 解き方

- 後ろから計算していく
- カウントした数を A[i]に加算すればよい
- A[i] > B[i] と A[i] < B[i] の場合で分けて考える
  - A[i] > B[i]の場合、カウントした数を A[i]にいくら足せば B[i]の倍数になるか計算すればいい
  - A[i] < B[i]の場合、B[i] - A[i]を足す

---

## 67 A. Multiple Array

### 解き方

- 下記の制約からそのまま実装すれば OK

> 1≤∣SA∣≤100  
> 1≤∣SB∣≤100  
> 1≤∣SC∣≤100

---

## 68 A. Shik and Stone

### 解き方

- "Possible"と"Impossible"の場合で'#'の数を数えれば OK

H = 4, W = 5 で "Possible" の場合、'#'は 8 個

> 例 1  
> ##...  
> .##..  
> ..##.  
> ...##  
> 例 2  
> ##...  
> .#...  
> .#...  
> .####

H = 4, W = 5 で "Impossible" の場合、'#'は 8 個以上

> 例 1  
> ###..  
> .###.  
> ..##.  
> ...##  
> 例 2  
> ####.  
> .###.  
> ..##.  
> ...##

---

## 69 C - Five Transportations

### 解き方

- 解説 AC した
- 一番移動に時間がかかる箇所、A,B,C,D,E で一番小さい数字に着眼する

---

## 70 A. Simple Calculator

### 解き方

- X < Y X > Y と正か負かと Y が 0 かどうかで細かく分けて計算した
- テストパターン漏れで wa になりがちなので注意

---

## 71 C. Splitting Pile

### 解き方

- そのまま計算すれば OK
- 合計をもとめて、そこから計算していく
- long long 型の最大値を仮でで入力する時は下記のように代入すること

```c++
    long long ans = 1000000000000000000LL;
    long long temp_ans = 1000000000000000000LL;
```

---

## 72 C. Multiple Clocks

### 解き方

- 各 Ai の最小公倍数を求めれば OK
- N = 1 の場合の処理を入れないといけないのに注意

---

## 73 C. Sqrt Inequality

### 解き方

- 解説 AC した
- 計算に小数点が出る問題は整数で計算できるように式を展開する
- 2 乗の処理で pow 関数を使うとなぜかうまく行かなかったのでそのまま 2 乗する

---

## 74 C. Dubious Document

### 解き方

- 下記のような連想配列を使って、そのまま解く

```c++
    map<char, int> cnt[N + 1];  // 各文字列の文字数のカウント用
    map<char, int> cnt_moji;    // 全ての文字の最小数の計算用
```

---

## 75 D. Prediction and Restriction

### 解き方

- そのまま解く
- 勝てない場合は K 回後と同じ手を出して、K 回後は勝てるようにする

---

## 76 C. Attention

### 解き方

- 'E'と'W'の数を計算して、そこからロジックで解く
- 制約から計算量は N まで、N^N だと TLE になる
  > 制約  
  > 2≤N≤3×10^5

---

## 77 C. HSI

### 解き方

- 解説 AC した
- 期待値を計算できるように式を展開するタイプの問題

---

## 78 A. Connection and Disconnection

### 解き方

- 文字が全て同じの場合は答えは下記になる

```c++
S.length() * K / 2
```

- 文字が違う場合は N が一つ増えた場合、どれくらいカウント数が増えるかに着眼して、N=1 は N=2 からどれくらいカウントが増えたかを計算する

---

## 79 C. Reconciled?

### 解き方

- 組み合わせは計算で求める
- MOD の使い方は下記参照
- [「1000000007 で割ったあまり」の求め方を総特集！ 〜 逆元から離散対数まで 〜 - Qiita](https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a)

- 掛け算しか使わない場合は、乗算してすぐに余りをとって OK

```c++
const long long MOD = 1e+09 + 7;
int facctorialMethod(int k) {
    int sum = 1;
    for (int i = 1; i <= k; ++i) {
        sum = sum % MOD * i % MOD;
    }
    return sum;
}
```

---

## 81 C. 1D Reversi

### 解き方

- 色が変わった階数をカウントすれば OK
- S.length() == 1 の場合は全て同じ色なので考えなくて OK

---

## 82 C. Be Together

### 解き方

- 平均値は四捨五入して計算数する
- 平均値に対して、各入力 Ai を計算して和を求める

---

## 83 A. Limited Insertion

### 解き方

- vector 型の insert 関数を使って実装する

---

## 84 D. Triangles

### 解き方

- ソートしてから貪欲法で解く

---

## 88 C. X: Yet Another Die Game

### 解き方

- そのまま解く

---

## 89 B. Box and Ball

### 解き方

- そのまま解く
- 移動後にボールが 0 個になった時の赤色の玉があるかの判定するフラグを忘れないようにする

---

## 90 C. GeT AC

### 解き方

- 各番目の文字で'AC'の文字列がいくつあるかを事前に求めておく

```C++
    long long sum[N];
    for (int i = 0; i < N; i++) {
        sum[i] = 0;
    }
    char prev = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] == 'C' && prev == 'A') {
            sum[i] = sum[i - 1] + 1;
        } else {
            sum[i] = sum[i - 1];
        }
        prev = S[i];
    }
```

---

## 91 B. Sum of Three Integers

### 解き方

- 全探索でそのまま解く
- 下記のような条件にすれば 3 重ループにする必要はない
  > X + Y >= S - Z && X + Y <= S

---

## 94 C. Buy an Integer

### 解き方

- 解説 AC した
- A×N+B×d(N)の N を二分探索で求める

---

## 95 C. Buy an Integer

### 解き方

- 制約 1 <= N <= 10^5 なので下記のような連想配列に数整数の数を入れていく
- 下記の連想配列を 1 からループして数字の数の合計が K 以上になったタイミングが答え

```c++
map<long long, long long> cnt; // first: 1 ~ 10^5のカウント, second: 数字の数
```

---

## 96 C. Typical Stairs

### 解き方

- dp で解く
- 配列外アクセスに注意
- 下記のように渡れない箇所 a1,a2...am は設定する

---

## 97 B. Exactly N points

### 解き方

- 1 から N までの合計を計算する
- 合計から N,N-1,N-2 と順に引いていき、合計よりも多い場合は表示しない数、合計より小さくなった場合は表示する数になる

---

```c++
    bool ng[100009];
    for (int i = 0; i <= 100005; i++) {
        ng[i] = false;
    }
    for (int i = 1; i <= M; i++) {
        long long temp;
        cin >> temp;
        ng[temp] = true;
    }
```

---

## 99 B. fLIP

### 解き方

- 解説 AC した
- 行と列を塗った時に何マス塗られるかの法則性を見つける
  - 上記の法則は下記のようになる

```
            long long calc = i * (M - k) + (N - i) * k;
```

---

## 100 C. /\/\/\/

### 解き方

- 偶数番目と奇数番目に同じ数字がいくつあるかカウントする
- 同じ数字の数が違う場合

```c++
        ans += (N / 2) - max_even_cnt;
        ans += (N / 2) - max_odd_cnt;
```

- 同じ数字の数が同じ場合、下記の二つを試して小さい方が答え
  - 奇数番目は二番目に多い数字で置き換える
  - 偶数番目は二番目に多い数字で置き換える

```c++
        long long temp_ans = 0;
        temp_ans += (N / 2) - second_even_cnt;
        temp_ans += (N / 2) - max_odd_cnt;
        long long temp_ans_2 = 0;
        temp_ans_2 += (N / 2) - max_even_cnt;
        temp_ans_2 += (N / 2) - second_odd_cnt;
        ans = min(temp_ans, temp_ans_2);
```

---

## chips

## 注意事項

**あとできれいにまとめる**

- 二分探索してイテレータを取得できる

```c++
  auto itr = lower_bound(A, A + M, point);
  // itr - A がイテレータになる
  // A[itr - A] または *itrで値を取得できる
```

- pair をソートすると first の値でソートされる

```c++
    vector<int> A_v;
    vector<int> B_v;
    pair<int, int> ship_create[M];

    for (int i = 0; i < M; i++) {
        cin >> A[i];
        cin >> B[i];
        ship_create[i].first = A[i];
        ship_create[i].second = B[i];
    }
    sort(ship_create, ship_create + M);
```

- 10 の 9 乗は下記のように書ける
  - 1e+09

```c++
    if (S == 1e+09) {
```

- でかい数字の和が発生する場合考慮が必要

  - 56 C. Subarray Sum

- map の全要素アクセスは下記でできる

```c++
    auto begin = map.begin();
    auto end = map.end();
    for (auto iter = begin; iter != end; iter++) {
        cout << iter->first << endl;
        cout << iter->second << endl;
    }
```

- 下記を for に組み込むと TLE になりがちなので注意

```c++
reverse(S.begin(), S.end());
```

- 下記のような制約で long long A[N]のように動的に配列を確保すると wa にはまる場合がある
- 問題によっては AC するときもある

  - 62 C. Monsters Battle Royale
    > 制約 入力は全て整数である。  
    > 2≤N≤10^5  
    > 1≤Ai≤10^9

- 制約が二桁以下の数字の場合は実行時間を考えないで、そのまま実装すればだいたい解ける
- ↓ のコンテストの B を工夫しようとして死んだ

  - ユニークビジョンプログラミングコンテスト 2023 春 (AtCoder Beginner Contest 300)

- long long 型の最大値を仮でで入力する時は下記のように代入する

```c++
    long long ans = 1000000000000000000LL;
    long long temp_ans = 1000000000000000000LL;
```

- [「1000000007 で割ったあまり」の求め方を総特集！ 〜 逆元から離散対数まで 〜 - Qiita](https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a)

- 掛け算しか使わない場合は、乗算してすぐに余りをとって OK

```c++
const long long MOD = 1e+09 + 7;
int facctorialMethod(int k) {
    int sum = 1;
    for (int i = 1; i <= k; ++i) {
        sum = sum % MOD * i % MOD;
    }
    return sum;
}
```

- 二番目に大きい数字を求める方法

  - [配列の最大値と二番目に大きい数を求めたい。](https://teratail.com/questions/68835)

- ↓ この input 値の入れ方は覚える

  - https://atcoder.jp/contests/keyence2019/submissions/41150033

- 配列を並べ替えてくれる関数 next_permutation
- 計算量が N! と膨大になる可能性があるため、注意
- sort されている必要があるため注意
  - [C - Almost Equal 解説](https://atcoder.jp/contests/abc302/editorial/6408)
  - [next_permutation](https://cpprefjp.github.io/reference/algorithm/next_permutation.html)

```c++
int main() {
  int n,m;
  cin>>n>>m;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s[i];
  sort(s.begin(),s.end());
  do{
    bool ok=true;
    for(int i=0;i<n-1;i++){
      int cnt=0;
      for(int j=0;j<m;j++) if(s[i][j]!=s[i+1][j]) cnt++;
      if(cnt!=1) ok=false;
    }
    if(ok){
      cout<<"Yes"<<endl;
      return 0;
    }
  }while(next_permutation(s.begin(),s.end()));
  cout<<"No"<<endl;
}
```


- multiset(多重集合)
  - set(集合)に重複して同じ値を入れられるようになったクラス
  - [ABC306 E](https://atcoder.jp/contests/abc306/editorial/6607)








