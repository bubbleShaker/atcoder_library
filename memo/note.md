# これは何?
競プロの日記にしようと思う。<br>
思ったことをそのまま打ち込むだけなので、見やすくはならないと思う。<br>

# 10/27 ABC377のバチャ
終わったら、解けなかった問題を一門、すぬけさんの解説見た後にupsolveする。<br>
## 結果
ABCの3完だった。<br>
<img src="../photo/241027/01.png" width="500"><br>
パフォーマンスは816。<br>
Cまではよくある問題という印象。<br>
Dについて解けなかったので考えてみる。<br>

## D-Many Segments 2
<img src="../photo/241027/02.png" width="700"><br>
### 考えた解法
五月雨式に説明する。<br>
#### 配列Aを生成し、$imos法$を行う
配列$A$を作成し、その上で$[li,ri)$について$imos法$を行う。<br>
$A_i>0$なる点$A_i$から数直線上に右に長さ1の区間が塗りつぶされていると考える。<br>
#### 集合$set_L$の定義
塗りつぶした区間の左端となる点$L$を集合$set_L$に挿入する。<br>
#### $1\le l \le M$の点$l$とペアになる点$r$の個数を計算する

##### 1. $A_l=0$の場合
点$l$以上の最小の点$min_L$を二分探索で見つける。<br>
- $l$以上の点が存在しないならば$M-l$個
- そうでないならば$min_L-l$個

の点$r$が点$l$のペアとなりうる。<br>
また、点$l$が$Li=Ri$なる点$p$の集合$set_{p}$に含まれていないならば、$r=l$なる点$r$も点$l$のペアにできる。<br>

##### 2. $A_l>0$の場合
点$l$が
- 集合$set_{ng}$に含まれていない$\land$集合$set_L$に含まれている

ならば、$r=l$なる点$r$を点$l$のペアにできる。<br>

### サンプル3が合わない
上記のアルゴリズムを実装すると、サンプル3の出力が合わない。<br>
サンプル3の入力を数直線上に図示しようとしたらコンテストが終了してしまった。<br>

### 勘違い
- 「$l,r$が$[L_i,R_i]$に含まれるなら駄目」

ではなく、
- 「$l,r$が$[L_i,R_i]$を含むなら駄目」

だった

### すぬけさんの解説を見る
考え直したが、結局難しいので解説を見る。<br>

## 日記感想
アルゴリズムの説明を書かなければならないのが難しく、卒論の時とは異なり理解の補助になっている感じはないと思った。<br>
今後書くかは微妙。<br>

## 11/6
### RMQのSegmentTreeをソラで書けるようにしたい
スニペットを入れないで手打ちでプログラムを作成した方が、脳が活性化されて働く気がする、という経験則を手に入れた。<br>
それと同じような理屈で、主要なアルゴリズムやライブラリは全部ソラで書ける方が、頭が働いていいのでは？と思った。<br>
まずは全緑コーダー憧れのSegmentTreeをいつでもソラで書けるようになりたいと思ったので、2回ほど写経して覚えようとした。<br>
どうにかしてRMQのセグ木だけでも暗記に成功した、という経験が欲しい。<br>

## 11/7 セグ木(RMQ)暗記+ADT
写経1回+テスト2回を紙で。<br>
家に帰ってからテスト1回。<br>
家に帰ったときは、lの配列サイズを間違えてWAが出た。<br>
ADTは2完で悲しくなった。<br>
寝る前に写経を通して暗記して、翌日復習して定着を図るの、かなり効果がある。<br>
今日は風呂に入ったらRSQの暗記をしようと思う。<br>

## 11/8 セグ木(RSQ)テスト+グラフ探索アルゴリズムDFS写経
前日の夜にRSQのセグ木を写経して暗記した。<br>
今日の夜テストしてみたら暗記できていた。<br>
気が向いたらテストしてみて忘れてないか確認することにして、次の暗記するものを探す。<br>
グラフ探索アルゴリズムのdfsを暗記してみる。<br>
参考サイト:[深さ優先探索(Depth First Search)の基本](https://algo-logic.info/dfs/)<br>
stackを使ったdfsプログラムを始めて書いた。面白い。<br>
一つずつテストして、クリア出来たら次に進むことにする。<br>
→写経2回、テスト1回でクリア。<br>
再帰の方も写経しようと思う。<br>
→写経2回、テスト1回でクリア。<br>
では、スタックと再帰をそれぞれテストしてみる。<br>
→スタック…pop()を忘れるミス<br>
→再帰…クリア<br>
という感じになった。<br>
やりすぎると復習が大変なので今日はここで終わろうと思う。それか暇なので適当にセグ木(RMQ,RSQ)が書けるかテストしてみる。<br>
→両方ともクリア。寝る<br>