# Comparison: 堆疊 Stack vs. 佇列 Queue

| 比較項目 | 堆疊 (Stack) | 佇列 (Queue) |
|---|---|---|
| 存取原則 | LIFO (後進先出) | FIFO (先進先出) |
| 操作術語 | Push (推入)、Pop (彈出)、Peek (查看頂端) | Enqueue (入隊)、Dequeue (出隊)、Front/Rear |
| 存取限制 | 只能在頂端 (Top) 進行操作。 | 在末端加入，在前端移除。 |
| 常見應用 | 函式呼叫堆疊 (Recursion)、撤銷操作 (Undo)、括號匹配。 | 任務排程、列印緩衝區、寬度優先搜尋 (BFS)。 |
| 實作方式 | 可使用 Array 或 LinkedList 實作。 | 可使用 Array (通常為環形) 或 LinkedList 實作。 |

## 什麼時候會用到？

### 使用 Stack 的情境
- 有「回到上一個狀態」的需求
- 程式執行順序需要回溯
- 題目出現：recursion、undo、call stack

### 使用 Queue 的情境
- 任務依到達順序處理
- 多筆資料等待被處理
- 題目出現：waiting line、scheduling、BFS

## 總結
- 最後進來的要先處理 → Stack
- 最早進來的要先處理 → Queue
- DFS → Stack（或 recursion）
- BFS → Queue

## Reference
- 黃鈺峰教授，《CS203A 資料結構》課程簡報，作為本筆記相關內容之參考來源。
- 部分內容與語句排版參考 AI Copilot 的建議，經整理與修正以符合教學筆記風格。