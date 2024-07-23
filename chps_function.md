
# chps_function

良く使用する関数をまとめる

---

## [std::iota](https://cpprefjp.github.io/reference/numeric/iota.html)

### 概要
指定された値から始まる整数列を生成する。

iota()関数は、値の範囲[value, value + (last - first))を前から順番に範囲[first, last)の各要素に代入する。

これは、連続した値のシーケンスが必要な場合に使用する。

input
```c++
int main()
{
  // 0から始まる10要素のシーケンスを作成する。
  // iota()関数に与えるシーケンスの要素数分だけ値が生成されるため、
  // 可変長のコンテナを与える場合には、事前に必要な要素数に
  // リサイズしておく必要がある
  std::array<int, 10> ar;
  std::iota(ar.begin(), ar.end(), 0);

  for (int x : ar) {
    std::cout << x << std::endl;
  }
}
```
output
```
0
1
2
3
4
5
6
7
8
9
```

---

## sortで比較するために使用する Compare comp について
### [std::sort等で指定する比較関数についてのメモ](https://qiita.com/threecups/items/aa1923a9922dc0a7abfe)
### 使われた問題
- [ABC308 C - Standings](https://atcoder.jp/contests/abc308/tasks/abc308_c)
- 解説: https://atcoder.jp/contests/abc308/editorial/6689

### 使用例

```c++
int main() {
    int p[10];
    iota(p, p + 10, 0);  //{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } の配列を作成
    // ソート対象の配列
    int sort_subject[10] = {10, 10, 3, 3, 5, 6, 7, 8, 9, 1};

    auto f = [&](int i, int j) {
        // XXX: 比較用の処理を実装したい場合はここに実装
        auto a = sort_subject[i];
        auto b = sort_subject[j];
        return a > b;  // 降順ソート
    };

    stable_sort(p, p + 10, f); // 同じ値の場合順番を変えない

    for (int i = 0; i < 10; i++) {
        // ソートした結果、上から何番目かを表示
        cout << "p[i] = " << p[i] << endl;
        // ソート結果を表示
        // p[i]で何番目にソートした値が入っている箇所を指定する
        cout << sort_subject[p[i]] << endl;
    }

    return 0;
}
```


---

## [std::stable_sort](https://cpprefjp.github.io/reference/algorithm/stable_sort.html)
### 使われた問題
- [ABC308 C - Standings](https://atcoder.jp/contests/abc308/tasks/abc308_c)
- 解説: https://atcoder.jp/contests/abc308/editorial/6689


### 概要
イテレータ範囲[first, last)を安定ソートで並べ替える

### 備考
同じ値が複数あった場合に、ソート前の位置関係が保たれる、「安定ソート」を行う。 一般的なマージソートで実装される。


### 使用例
```c++
int main() {
    int p[10];
    iota(p, p + 10, 0);  //{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } の配列を作成
    // ソート対象の配列
    int sort_subject[10] = {10, 10, 3, 3, 5, 6, 7, 8, 9, 1};

    auto f = [&](int i, int j) {
        // XXX: 比較用の処理を実装したい場合はここに実装
        auto a = sort_subject[i];
        auto b = sort_subject[j];
        return a > b;  // 降順ソート
    };

    stable_sort(p, p + 10, f); // 同じ値の場合順番を変えない

    for (int i = 0; i < 10; i++) {
        // ソートした結果、上から何番目かを表示
        cout << "p[i] = " << p[i] << endl;
        // ソート結果を表示
        // p[i]で何番目にソートした値が入っている箇所を指定する
        cout << sort_subject[p[i]] << endl;
    }

    return 0;
}
```



---





