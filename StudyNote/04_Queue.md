# Queue (佇列)

## 核心概念
- 是另一種受限的線性資料結構，但它的規則與 Stack 相反，遵循 **FIFO (First-In, First-Out，先進先出)** 原則。
- 就像在櫃檯「排隊」，先排的人先買到票離開，後來的人只能排在隊伍最後面。

## Queue 能解決什麼問題？
- **排隊與排程**：處理需要「公平競爭」或「依序處理」的場景。
    -  **印表機工作順序**：先傳送的文件先列印。
    -  **網路封包傳輸**：依序處理接收到的數據。
    -  **作業系統 CPU 排程**：處理待執行的行程 (Processes)。

## 核心特性
- **雙端操作**：插入在末端（Rear），刪除在前端（Front）。這與 Stack 只有一端開口完全不同。

## 關鍵考點
- **FIFO (先進先出)**：Queue 的靈魂準則。
- **Front & Rear 指標**：
    - **Front**：指向隊伍的頭（負責出隊 Dequeue）。
    - **Rear**：指向隊伍的尾（負責入隊 Enqueue）。
- **實作選擇**：同樣可以用 Array 或 Linked List 實作。但用 Array 實作時會有「空間浪費」的問題，通常需要引進 **Circular Queue (環狀佇列)** 的概念。


## 運作方式與操作邏輯

### 基本操作 (皆為 $O(1)$)
- **Enqueue / AddQ (入隊)**：將新元素加到 Rear 端。
- **Dequeue / DeleteQ (出隊)**：將 Front 端的元素移除並回傳。
- **Front / Peek (查看)**：讀取 Front 端的元素值，但不移除它。
- **IsEmpty / IsFull**：檢查目前隊伍狀態。

> **設計理由**：為了保證「先來後到」的邏輯。在實作上，如果用普通的 Array 做，Dequeue 後前面的空間就空下來了，資料卻無法遞補（除非全部往前搬 $O(n)$），這就是為什麼要發展出 **Circular Queue** 的原因。

## 複雜度與實作

| 操作 | 時間複雜度 | 備註 |
| :--- | :--- | :--- |
| **Enqueue** | $O(1)$ | 直接在 Rear 加入資料 |
| **Dequeue** | $O(1)$ | 直接從 Front 移出資料 |
| **Search** | $O(n)$ | 需從 Front 依序找起，不適合搜尋 |

### 實作建議：環狀佇列 (Circular Queue)
- 為了重複利用 Array 空間，我們把陣列想成一個「圓環」。
-  **關鍵運算子**：`%` (取餘數)。
-  **指標移動**：
    * `rear = (rear + 1) % MAX_SIZE`
    * `front = (front + 1) % MAX_SIZE`

## 容易搞混的地方與記憶重點

### 「假已滿」(False Overflow) 與環狀緩衝
-  **問題**：在普通的 Array Queue 中，當 `rear` 碰到陣列結尾時，就算 `front` 前面有空位，也無法再 enqueue。
-  **解決**：用 **Circular Queue** 讓 `rear` 繞回索引 0。

### 空與滿的判斷 (Circular Queue 的難點)
- 在環狀佇列中，`front == rear` 通常代表「空」。但如果塞滿了，`rear` 也會繞一圈追上 `front`。
-  **解法 1：浪費一個空間**。讓 `rear` 永遠在 `front` 前一格就停下。
    * **空 (Empty)**：`front == rear`
    * **滿 (Full)**：`(rear + 1) % MAX_SIZE == front`
-  **解法 2：使用變數**。用一個 `count` 紀錄目前資料數量。

### Array vs Linked List 實作

#### **Array (Circular)**
- **優點**：存取速度快，記憶體效率高（不用存指標）。
- **缺點**：必須預先宣告大小。

#### **Linked List**
- **優點**：不需要擔心 IsFull，可無限增長。
- **關鍵**：需要兩個指標 `front` 和 `rear` 分別指向 Head 和 Tail。

## Reference
* 黃鈺峰教授，《CS203A 資料結構》課程簡報。
* 部分語句參考 AI Copilot 建議，並進行排版與語意修正。
* 圖片來源：Stack 與 Queue 示意圖 — 來源於 [Better Programming (Medium)](https://medium.com/better-programming/stack-vs-queue-55d6ea7b2f4f?utm_source=chatgpt.com)