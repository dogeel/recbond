--- recbond Ver1.0.0 ---

これは、recpt1(http://hg.honeyplanet.jp/pt1/)をベースにしたLinux用BonDriver録画
コマンドです。

BonDriverProxy_Linux(https://github.com/u-n-k-n-o-w-n/BonDriverProxy_Linux)の
ヘッダーファイルをインクルードしていますのでBonDriverProxy_Linuxのソースディレクトリ上に
recbondのディレクトリを残したまま展開してビルドしてください。


[オプション]
recpt1のものをそのまま受け継いでいますが"--LNB"と"--device"を廃止、BonDriver指定
"--driver"とスペース指定"--space"を追加しています。
あと「字幕が出ない」と言われてしまうので無効化してありますが"--sid"のストリーム指定子に
"epg1seg"(1セグ用EPG)・"caption"(字幕)・"esdata"(データ放送等)が追加されています。
有効化する場合は、"EXTRA_SID=1 make"てな感じでビルド時に環境変数を渡してやってください。


[チャンネル指定]
BonDriverチャンネル指定に加えrecpt1で使われている従来のものをそのまま使用できます。
またBS/CSについてはDVB対応のためにTSIDによる指定(16進数か10進数)を新たに加えました。
なおBonDriverチャンネル指定方法は、"Bn"(nは0から始まる数字)となります。

全てのチャンネル指定方法を有効にするにはBonDriverのチャンネル定義とrecbond/pt1_dev.h
のチャンネル定義を並びも含めて同期させる必要があります。

LinuxのBonDriverの場合は、同梱のパッチをあててconfファイルを差し替えることにより
全てのチャンネル指定方法が利用可能です。

WindowsのBonDriverをBonDriverProxy経由で使用する場合は、BonDriverのiniファイルの
チャンネル定義をrecbond/pt1_dev.hのそれと同期させる必要があります。同梱のconfファイル
を参考にして変更してください。
sidとTSIDでのチャンネル指定はBonDriverの改造が必要なので使えないものと考えてください。
いろいろ面倒な場合は、BonDriverチャンネル指定方法でお願いします。


[スペース指定]
省略時は、0が設定されます。


[BonDriver指定]
フルパス指定の他に短縮指定が行なえます。
またBonDriverチャンネル指定以外で省略された場合は、自動選択されます。

短縮指定と自動選択を利用する場合は、ビルド時にrecbond/pt1_dev.hを編集して各BonDriver
のファイルパスを登録してください。

短縮指定の指定方法は、地デジが"Tn"・BS/CSは"Sn"(nは0から始まる数字)です。

BonDriver_Proxyを利用する場合は、短縮指定時に"P"を頭に付加してください。
自動選択時は、"P"を単独で指定してください。


[備考]
・チャンネル定義をいじらない
  「BonDriverチャンネル指定しか使わないぜ！」という場合を除き一切変更してはいけません。
  もちろんチャンネルスキャンは考慮しませんしBonDriver_LinuxPTやBonDriver_DVBのサービス
  絞込み(#USESERVICEID=1)は以ての外です。
  BSで局編成の変更があった場合は、がんばって変更してください。
・実録画時間が変動する
  ストリームを録画コマンドで受け取る前に加工していると実録画時間が変動します。
  BonDriver直接利用で-1秒ぐらい、BonDriverProxy経由で±1秒ぐらい変動します。
・BonDriverProxy使用時のチャンネル選択は、BonDriver指定時は強制・省略時は空き

**** 更新中 ****
