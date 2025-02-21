BigInt クラス

1. 概要

BigInt クラスは、標準の整数型では扱いきれない任意の大きさの整数を文字列で表現し、基本的な四則演算（加算、減算、乗算、除算、剰余）を可能にする。


2. 要素

std::string value : 数値を文字列として保持。

bool isNegative : 負数を示すフラグ。

normalize() : 余分なゼロを削除し、適切な符号を保持する。


3. 各操作のアルゴリズム


3.1. 加算

アルゴリズム

1. 符号が異なる場合、A + (-B) = A - B となるため、減算に委譲。
2. 数値を反転し、桁ごとに足し合わせる。
3. 繰り上がりが発生する場合、次の桁へ伝播させる。
4. 計算結果を反転し、正しい順序で格納する。

3.2. 減算

アルゴリズム

1. 符号が異なる場合、A - (-B) = A + B となるため、加算に委譲。
2. 大小を比較し、結果が負になるかを判定。
3. 数値を反転し、桁ごとに引き算を行う。
4. 借りが発生する場合、次の桁から 1 を借りる。
5. 計算結果を反転し、正しい順序で格納する。

3.3. 乗算

アルゴリズム

1. 各桁ごとに掛け算を行い、対応する位置に加算する。
2. 繰り上がりを次の桁に伝播させる。
3. 計算結果を文字列として格納する。

例

   123
×  45 ->
   615  (123 × 5) +
  4920  (123 × 40) =
  5535

3.4. 除算

アルゴリズム

1. 被除数の左から順に桁を増やしながら、割れるか判定。
2. 商を求め、余りを更新。
3. 各ステップで除算結果を記録し、最終的な商を取得する。

例

 1234 ÷ 5

  12 (÷5 = 2 余り 2)
  
  23 (÷5 = 4 余り 3)
  
  34 (÷5 = 6 余り 4)
  
  商: 246 余り: 4

3.5. 剰余

アルゴリズム

1. 割り算と同様の処理を行う。
2. 商を求めず、余りのみを記録する。

例

 1234 % 5 = 4
 

4. 比較演算

operator== : value と isNegative が一致するか判定。

operator< : 符号が異なれば符号で判定、桁数が異なれば桁数で判定、同じなら辞書順で判定。

5. 出力

符号を出力し、value をそのまま表示する。
