# Hashing (雜湊)

## 核心概念
- Hashing 是一種高效的資料存取方法。傳統的陣列查找需要遍歷整個陣列 (O(n))，或先排序再二分搜尋 (O(\log n))。  
- Hashing 的目標是將搜尋、插入與刪除操作的平均時間複雜度降至 O(1)。  
- 其原理是：透過 Hash Function 將資料的 Key 映射到陣列索引 (Index)，直接存取對應位置的資料。
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/HashTable.jpg" alt="HashTable" width="600">

## Hashing 能解決什麼問題？
- **快速查找**：就像查字典，你不會從第一頁翻到最後一頁找單字，而是根據字母索引直接跳到那一區。
- **實務應用**：DNS 快取 (查 Domain 對應 IP)、資料庫索引、編譯器查變數名稱。

## 核心特性
- **Key-Value Pair**：以鍵值對形式儲存資料，操作主要依 Key 進行，只關心 Key 對應的 Value。
- **無序性 (Unordered)**：資料在 Hash Table 中的存放順序不依輸入順序。
- **確定性 (Deterministic)**：相同 Key 輸入 Hash Function 時，應始終得到相同索引。

## 關鍵考點

### Hash Function (雜湊函數)
- 將 Key（字串或大數字）轉換為陣列範圍內的索引。  
- **優秀的 Hash Function 條件**：計算快速、分佈均勻 (Uniform Distribution)、降低衝突機率。

### Collision (碰撞)
- 因為 Array 大小有限，但可能的 Key 無限，一定會有兩個不同的 Key 算出同一個 Index 的情況。

### Load Factor (α) 負載因子
- 定義：\(α = n / m\) (資料個數 / 陣列大小)。  
- 含義：代表這張表「有多擠」。  
- **α** 越高，碰撞機率越大，操作速度越慢。

## 運作方式與操作邏輯

### Hash Function 設計 (怎麼算 Index？)
- **Division Method (除法)**：h(k) = k mod m  
- 重點：m (Table size) 最好選 **質數 (Prime)**，可以減少因為輸入資料規律而造成的衝突。

### Collision Resolution 碰撞解方
#### 解法一：Separate Chaining (鏈結法)
- 每個陣列格子 (Bucket) 為一個 Linked List 頭節點，碰撞資料依序加入鏈結。
- **優點**：資料量超過陣列大小時仍可存放。
- **缺點**：需要額外指標空間，Linked List 的快取效率較低。

#### 解法二：Open Addressing (開放定址法)
- 當發生碰撞時，依規則尋找下一個空位（Probing），所有資料皆存放於陣列內。
- **找空位的方法 (Probing Strategies)**：
  - **Linear Probing (線性探測)**：依序往後尋找空位。
    問題：Primary Clustering，連續空位容易形成衝突群。
  - **Quadratic Probing (平方探測)**：按照平方間隔尋找空位  
    問題：Secondary Clustering，相同初始索引的元素仍沿相同路徑尋找空位。
  - **Double Hashing (雙重雜湊)**：使用第二個 Hash Function 決定探測距離：Index + i·h₂(k)。
    優點：分布均勻，減少叢集現象。

### 複雜度與實作

| 操作 | 平均時間 | 最差時間 (Worst Case) | 直覺 |
|---|---|---|---|
| Search | O(1) | O(n) | 平均直接命中索引；最差所有元素集中到同一格子，需遍歷 Linked List。 |
| Insert | O(1) | O(n) | 同上。 |
| Delete | O(1) | O(n) | 同上。 |

**實戰建議**：

- **Hash Table vs. Array**  
  優勢：可透過 Key 直接以 O(1) 存取資料。  
  劣勢：無法支援範圍查詢 (Range Query)，需遍歷全表。

- **Rehashing**  
  當 Load Factor(α) 過高時，建立更大陣列並重算所有資料索引。  
  運算成本高 (O(n))，但可維持平均 O(1) 效率。

## 容易搞混的地方與記憶重點

### Primary vs. Secondary Clustering
- **Primary Clustering**：線性探測會導致衝突元素集中形成長鏈，像路邊停車，一台停了，下一台就停它旁邊，最後連成一長排。
- **Secondary Clustering**：平方探測避免連續衝突，但相同初始索引的元素仍沿同一路徑探測，像青蛙跳，雖然跳得開，但如果起始點一樣，跳的落點就完全一樣 (跳的軌跡重疊)。

### Open Addressing 的刪除陷阱 (Lazy Delete)
- 不能直接將元素設為 NULL  
- 原因：Probing 搜尋時遇到 NULL 會停止，可能導致後續資料找不到。
- 解法：標記為 “Deleted”（或 Tombstone），搜尋繼續，插入時可覆蓋。

### Table Size 為什麼要選質數？
- 避免輸入資料具有規律時造成衝突集中。
- 質數大小可均勻分散索引。

## Reference
- 黃鈺峰教授，《CS203A 資料結構》課程簡報，作為本筆記 Hashing 相關內容之主要參考來源。  
- 部分內容與語句排版參考 AI Copilot 的建議，經整理與修正以符合教學筆記風格。
