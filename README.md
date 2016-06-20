# smart-clotheshorse-system

"溫溼度感應自動晾衣系統"為一個能夠依據室外天氣,在下雨前將戶外晾曬衣物收進室內,待雨停後將衣物再次晾曬於戶外的系統。因為材料與能源有限,此處製作的為縮小版模型,架構示意圖與簡介如附檔"Term project_期末報告_104062606張沛文.docx"所示,程式碼位於transmitter.ino與receiver.ino。



Requirements----

1. Arduino Micro * 2

2. 溫濕度感應器DHT-22

3. HC08(BLE 4.0) * 2

4. 步進馬達

5. 步進馬達控制板

6. 滑輪 * 2

7. arduino編譯與燒錄環境



How to run this system?

1. 如Term project_期末報告_104062606張沛文.docx裡所敘述之架構完成系統模型

2. 將receiver.ino燒錄於馬達端Arduino Micro

3. 將transmitter.ino燒錄於濕度感應端Arduino Micro

4. run them

5. 對DHT-22所在環境做濕度變化與模型運作

Devices Wiring

Arduino Micro、馬達達控制板、HC08、步進馬達、DHT-22皆依據購買模組之documents說明以一般方式接線即可
