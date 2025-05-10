ESP32とws1850sモジュール( https://www.switch-science.com/products/8301?srsltid=AfmBOorMixVNIWm1sMiKO3c1PTqjwFZWl9X0G_-vU2aMKctOxQ9IA6PN ) によってNFCタグを読み取るプログラムです。


MFRCオブジェクトのコンストラクタの第1引数には0x28を与えます。

第2引数は本来不要ですが、コンパイルエラーになる場合には255などの存在しないピンの番号であったり、使わないピンの番号を与えてやったりする必要があります。





参考
https://sample.msr-r.net/m5stack-rfid2unit/
