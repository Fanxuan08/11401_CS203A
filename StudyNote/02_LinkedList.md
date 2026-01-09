# Linked List (鏈結串列)

## 核心概念
- Linked List 的出現是為了 **「解決陣列的限制」**。  
- 陣列最大的問題：固定大小、記憶體必須連續、插入中間元素效率低。  
  如果要在陣列中間插一個元素，後面所有人都要往後移 (Shift)，效率很低。  
- Linked List 的每個節點（Node）包含兩部分：自己的資料（Data）以及指向下一個節點的指標（Next Pointer）。

## Linked List 能解決什麼問題？
- **動態擴充資料**：資料不必連續，只要指標連得上，記憶體位置可以分散。

## 核心特性
- **動態大小（Dynamic size）**  
- **插入與刪除效率高**：只需更新指標即可完成操作，不需要搬移大量資料。

## 關鍵考點
- **頭節點 (Head)**：整條串列的起點，若丟失 Head 位址，整個串列將無法訪問，造成 Memory Leak。  
- **指標 (Pointer)**：串列連結的核心，插入或刪除操作都在調整指標。  
- **無法隨機存取**：必須從 Head 開始依序遍歷到目標元素 (O(n))。

## 運作方式與操作邏輯

### 插入 (Insertion)
- **頭部插入**：最快 (O(1))，將新節點的 `next` 指向目前的 Head，再更新 Head。  
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/Insert1.jpg" alt="Insert1" width="600">

- **中間/尾部插入**：需先走訪找到目標位置，將新節點連接後續，再更新前一個節點的指標。
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/Insert2.jpg" alt="Insert2" width="600">

### 刪除 (Deletion)
- 找到前一個節點 (Prev)，將 Prev 的 `next` 指向目標節點的下一個節點。  
- 刪除後需釋放記憶體 `free(Target)`，否則記憶體會被佔用。
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/Delete.jpg" alt="Delete" width="600">

### 搜尋 (Search)
- 從 Head 開始，依序更新 `current = current->next`，直到找到目標或到達 `NULL`。

## 複雜度與實作
| 操作 | 時間複雜度 | 備註 |
|---|---|---|
| Access (索引取值) | O(n) | 尋找第 k 個元素效率低。 |
| Insert/Delete (已知位置) | O(1) | 已知位置可快速操作指標。 |
| Insert/Delete (未知位置) | O(n) | 需先遍歷找到位置，耗時 O(n)。 |
| Memory Usage | 較高 | 每個資料都要額外存一個指標空間。 |

**實作建議**：  
- 資料量**常變動且需要中間增減** → Linked List  
- 資料量**大小固定且需要快速隨機存取** → [**Array**](https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/01_Array.md)


## 容易搞混的地方與記憶重點

### 斷路與懸掛節點 (Dangling Node)
- 錯誤範例：先斷掉前一節節點的指標，再接後續，導致後面的節點丟失。  
- 解決方法：先將新節點連接到後續，再更新前一節節點的指標。

### Linked List 的進階變體
- **Singly (單向)**：只能向後遍歷。
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/LinkedList.jpg" alt="LinkedList" width="500">

- **Doubly (雙向)**：增加 `prev` 指標，可向前遍歷，刪除節點時不必尋找 Prev，但記憶體消耗更大。
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/DoublyLinkedList.jpg" alt="DoublyLinkedList" width="400">

- **Circular (環狀)**：尾節點指向頭節點，適合輪流機制（如遊戲回合、OS 排程）。
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/CircularLinkedList.jpg" alt="CircularLinkedList" width="500">

### Selection Sort (交換值 vs 交換指標)
- **交換值 (Swap Value)**：直接修改節點資料，簡單但資料量大時效率低。  
- **交換指標 (Swap Pointer)**：操作指標即可完成節點移動，不需要搬動大量資料。

## Reference
- 黃鈺峰教授，《CS203A 資料結構》課程簡報，作為本筆記 Linked List 相關內容之主要參考來源。  
- 部分內容與語句排版參考 AI Copilot 的建議，經整理與修正以符合教學筆記風格。