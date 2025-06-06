## 🧠 **作品名稱**
**《無聲的殺人告白》**

---

## 🧾 **創作構想說明**
作品以 1980 年李師科搶案中使用的點三八左輪手槍為原型，透過 3D 列印與 Arduino 技術，重建此歷史物件並轉化為互動載體。  
故事由 AI 靈媒的視角出發，敘述兩個靈魂：李師科與王迎先——一個是加害者、一個是受害者。  
在科技不斷滲透人類生活的今日，作品試圖引導觀眾反思：當 AI 參與詮釋歷史，甚至擁有「道德判斷力」，人類的價值是否仍具主導性？

---

## 🎯 **創作核心概念**
- 探討科技如何重塑記憶與道德敘事。  
- 引發對人類面臨的道德抉擇是否會被 AI 的存在所改變，AI 是否具備道德批判意識的深思。  
- 反思社會對罪與正義的標準是否會因 AI 介入而動搖。

---

## 🧩 **作品互動方式**
觀眾手持重製的點三八左輪手槍裝置（內建陀螺儀與 WiFi 模組），對準螢幕觸發不同影像內容，  
就如同觀落陰的流程，觀者可以選擇你要觀的靈魂片段。  

- 系統透過 Arduino 搭配 ESP8266 模組即時偵測角度變化，  
  並直接透過 WiFi 將方向資訊傳送至 TouchDesigner。  
- TouchDesigner 根據角度資訊即時控制影像播放與切換，  
  使觀眾每個動作都成為敘事的一部分。

---
## **🔁 理念與互動設計的連結說明**

互動：觀眾拿起這把「重製的手槍」時，不再只是觀看者，而是變成這個AI靈媒的具身化身，透過「指向」來選擇觀看哪段靈魂記憶，這種選擇本身即是一種價值判斷與倫理介入。

連結：這種操作方式讓觀眾進入角色，使他們從第三人稱轉化為第一人稱視角，在「觀察歷史」的同時也「介入歷史」，體現AI參與詮釋的倫理困境。

科技成為介入記憶與真相的橋樑，觀眾不再是被動的旁觀者，而是主動參與、甚至左右敘事發展的詮釋者。透過這樣的設計體現AI參與詮釋的倫理困境

---

## 🧱 **材料**
- 3D 列印手槍外殼  
- Arduino Nano 33 IoT  
- MPU6050 陀螺儀模組  
- ESP8266 WiFi 模組  
- 小型鋰電池、電線、開關  

---

## 🔌 **接線說明**
- **MPU6050（陀螺儀模組）**：連接至 Arduino I2C 腳位（SCL → A5、SDA → A4）  
- **ESP8266 模組（WiFi）**：透過 UART 與 Arduino 通訊（TX/RX）  
- **電源**：使用可充電鋰電池模組，供電至 Arduino 與感測模組  
- **開關**：控制供電時間  

---

## 🤖 **AI 在創作中的角色**
- 虛構 AI 靈媒視角的角色設定與敘事引導  
- 使用 AI 影像生成工具（Stable Diffusion、Runway）重建歷史人物表情  
- 命名發想與概念延伸中提供批判性對話素材  

---

## 🧪 **使用技術與工具**
- Arduino Nano 33 IoT  
- MPU6050 陀螺儀模組  
- ESP8266 WiFi 模組  
- TouchDesigner  
- WiFi 傳輸資料整合

---
