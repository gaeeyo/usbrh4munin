
 usbrh4munin
 ===========

■概要

 Strawberry Linuxから発売されている「USB温度・湿度測定モジュール」を
munin-nodewin32 から利用するための外部プラグインです。

■使い方


1. アーカイブの Release 以下にある2つのファイルを、適当な場所に配置します。

  usbrh4munin.exe
  USBMeter.dll

2. munin-node.ini の [Plugins] で External=1 を設定します。

  [Plugins]
    :
  External=1

3. munin-node.ini の [ExternalPlugin] を設定します。

  [ExternalPlugin]
  Plugin01=W:\share\usbrh4munin.exe

  usbrh4munin.exeを配置した場所をプルパスで記述します。

4. サービスを再起動します

  sc stop munin-node
  sc start munin-node

■連絡先

配布元の確認などはこのリンクから確認してください。

http://d.hatena.ne.jp/gae/searchdiary?word=%2a%5b%c6%fc%b5%ad%5d


