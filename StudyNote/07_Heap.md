# Heap (堆積)

## 核心概念
- Heap 是一種「特殊的完全二元樹 (Complete Binary Tree)」。  
- 它必須同時滿足兩個嚴格條件：
    - **結構性質 (Shape Property)**：必須是 Complete Binary Tree。除了最後一層外全滿，且最後一層節點由左至右填入。  
    這保證了它可以用 Array 緊密儲存，不需要指標。
    - **排序性質 (Heap-Order Property)**：父子節點之間有大小關係。  
        - **Max Heap**：父節點 ≥ 子節點（Root 是最大值）  
        - **Min Heap**：父節點 ≤ 子節點（Root 是最小值）  

## Heap 能解決什麼問題？
- **優先權佇列 (Priority Queue)**：Heap 最重要的應用。  
  就像急診室檢傷分類，不是先到先看診，而是「最嚴重的先看」。  
  Heap 讓我們可以 O(1) 拿到最大/最小值，O(log n) 處理新進資料。

**應用**：  
- 作業系統排程：最短作業優先 (SJF)，用 Min-Heap 挑選剩餘時間最短的工作執行。
- 網路封包處理 (QoS)：高優先級封包先送出。
- Heap Sort：利用 Heap 特性進行 O(n log n) 排序。

## 核心特性
- **陣列表示法 (Array Representation)**：完全二元樹可以用 Array Index 計算位置，省空間又快。
- **半排序 (Semi-ordered)**：Heap 只保證垂直方向（父子）有大小關係，兄弟之間無序。
- 與 Binary Search Tree (BST) 的「左小右大」不同。

## 關鍵考點

### 陣列索引計算 (必背公式)
- 假設 Root 放在 Index 0 的位置：  
    - 左小孩 (Left Child)：2i + 1  
    - 右小孩 (Right Child)：2i + 2  
    - 父節點 (Parent)：floor (i-1) / 2floor 

### Max Heap vs. Min Heap
- **Max Heap**：Root 是老大 (Max)，適合找最大值或處理最緊急事件。
- **Min Heap**：Root 是老么 (Min)，適合處理最短時間任務。

## 運作方式與操作邏輯
- Heap 操作核心在於「維持 Heap 的結構與排序性質」。只要動了資料，就要把它漂到正確位置。

1. **插入 (Insert) - Sift Up**  
   - 新資料先放在 Array 的最後一個位置 (Last Leaf)。
   - **Sift Up (上浮)**：與父節點比大小，若比爸爸大 (Max Heap)，交換。一路上浮，直到比爸爸小或成為 Root。

2. **取出極值 (Extract Max/Min) - Sift Down**  
   - 拿走 Root（極值），用 Array 最後一個元素補到 Root。
   - **Sift Down (下沉)**：與小孩比大小，選較大的小孩交換（Max Heap），一路下沉直到比小孩都大或成為 Leaf。

3. **Build Heap (建立堆積)**  
   - Bottom-up 方法：從最後一個非葉子節點開始，依序做 Sift Down。
   - 時間複雜度 O(n)，比逐個 Insert O(n log n) 快。

## 複雜度與實作
| 操作 | 時間複雜度 | 直覺 |
|---|---|---|
| Peek (看最大/小值) | O(1) | 就在 Root (Index 0)，直接拿 |
| Insert (插入) | O(log n) | 最差情況從 Leaf 浮到 Root，路徑長等於樹高 |
| Extract (取出) | O(log n) | 最差情況從 Root 沉到 Leaf，路徑長等於樹高 |
| Build Heap | O(n) | 使用 Floyd's algorithm (Bottom-up)，反直覺但重要 |
| Heap Sort | O(n log n) | 做 n 次 Extract Max |

## 容易搞混的地方與記憶重點

### Heap vs. Binary Search Tree (BST)
- **BST**：左小右大，用於搜尋 (O(log n))，In-order 走訪會排序。
- **Heap**：父大子小 (Max Heap)，用於找極值 (O(1))，兄弟無序，In-order 走訪是亂的。
- 重點：Heap 為「優先權」而生，不是搜尋任意值；找特定數字仍需 O(n)。

### Sift Down 選哪個小孩？
- 做 Max Heap 的 Sift Down 時，交換要跟「較大」的小孩換。
- 原因：若跟較小的小孩換，會違反 Max Heap 規則 (Parent ≥ 兩個小孩)。

## Reference
- 黃鈺峰教授，《CS203A 資料結構》課程簡報，作為本筆記 Heap 相關內容之主要參考來源  
- 部分內容與語句排版參考 AI Copilot 的建議，經整理與修正以符合教學筆記風格
