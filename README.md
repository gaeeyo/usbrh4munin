 usbrh4munin
 ===========

■概要

Strawberry Linuxから発売されている「USB温度・湿度測定モジュール」から取得した情報を出力するコンソールアプリケーションです。


■コンソールアプリケーションとして使う

usbrh4munin.exe と USBMeter.dll を同じフォルダに配置して、usbrh4munin.exe を実行します。
正常に動作すると以下のように温度と湿度が出力されます。

```
usb0temp.value 17.800000
usb0humid.value 55.737201
.
```
デバイスに何らかの問題が発生している場合に、正常に取得できないことがあります。
```
usb0temp.value ERROR
usb0humid.value ERROR
.
```

■munin で使う

1. usbrh4munin.exe と USBMeter.dll を同じフォルダに配置します

  usbrh4munin.exe
  USBMeter.dll

2. munin-node.ini の [Plugins] で External=1 を設定します。

  [Plugins]
    :
  External=1

3. munin-node.ini の [ExternalPlugin] を設定します。

  [ExternalPlugin]
  Plugin01=c:\usbrh\usbrh4munin.exe

4. サービスを再起動します

  sc stop munin-node
  sc start munin-node

■Zabbix Agent(3.4以降) で使う

1. zabbix_agentd.conf で UserParameter を設定します。
```
UserParameter=usbrh,c:\usbrh4\usbrh4munin.exe
```
2. Zabbixのアイテムに usbhrh をテキスト型で追加します
3. 2で追加したアイテムの依存アイテムを作成し、保存前処理で
`正規表現` で `usb0temp.value +([0-9.]+)` を設定し、出力に `\1` を指定します。


■連絡先

配布元の確認などはこのリンクから確認してください。

http://d.hatena.ne.jp/gae/searchdiary?word=%2a%5b%c6%fc%b5%ad%5d

