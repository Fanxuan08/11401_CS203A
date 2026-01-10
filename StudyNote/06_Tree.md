# Trees (樹)

## 核心概念
- 樹 (Tree) 是一種「非線性、階層式 (Hierarchical)」的資料結構。  
- 之前學的 Array 和 Linked List 都是「一條線」排下去 (Linear)，但在真實世界很多關係是「一對多」的，例如：  
    - **檔案系統**：資料夾裡面有資料夾。  
    - **族譜**：祖先往下開枝散葉。  
    - **組織架構**：總經理 -> 經理 -> 員工。  

## Tree 能解決什麼問題？
- **反映真實結構**：自然地表示階層關係。  
- **高效搜尋**：透過特定的規則（如 Binary Search Tree），讓搜尋速度從 O(n) 加快到 O(log n)。  

## 核心特性
- **只有一個 Root (根)**：所有東西的起源。  
- **沒有 Cycle (迴圈)**：不能繞一圈回到原點，不然就是 Graph 了。  
- **遞迴定義**：樹的每一個分支 (Subtree) 本身也是一棵樹。  

## 關鍵考點

### 必考名詞解釋（不要背定義，要看圖會認）
- **Root**：最上面、源頭的根。  
- **Leaf (葉子)**：最下面沒有小孩的節點。  
- **Degree (分枝度)**：一個節點有幾個小孩 (Fan-out)。  
- **Siblings (兄弟)**：同一個爸媽的小孩。  
- **Path**：從 A 走到 B 的路徑。  
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/Tree1.jpg" alt="Tree1" width="800">

### Height vs. Depth (超級容易搞混)
- **Depth (深度)**：從 Root 往下數。Root 的 depth 是 0 (或 1，看定義，通常是 0)。  
- **Height (高度)**：從 Leaf 往上數。該節點到最遠 Leaf 的距離。Leaf 的 height 是 0。  
- **Tree Height** = Root 的 Height = 整棵樹最深有多深。 
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/Tree2.jpg" alt="Tree2" width="800"> 

### Binary Tree (二元樹) 的種類
- 二元樹是考試重點，每個節點最多 2 個小孩：  
- **Full**：每個節點要嘛 0 個小孩，要嘛 2 個 (沒有獨生子)。  
- **Complete (完全)**：  
  - 定義：除了最後一層，上面全滿；最後一層的葉子都靠左。  
  - 用途：可以用 Array 實作 (Heap 就是用這個)。  
- **Perfect (完美)**：每一層都滿，像三角形一樣完美。  
- **Degenerate/Skewed (歪斜)**：全部都只有左小孩或右小孩，退化成 Linked List，效能最差。  

### Binary Search Tree (BST)
- 樹最核心的應用。  
- **黃金規則**：左 < 中 < 右。  
- 對任意節點：左子樹所有值都要比它小，右子樹所有值都要比它大。  
- **In-order Traversal (中序走訪)**：BST 會得到 Sorted Sequence (排序好的數列)。  

## 運作方式與操作邏輯

### Tree Traversal (走訪：怎麼把樹逛一遍)
- **DFS (深度優先)** - 用 Stack 或 Recursion。
  - **Pre-order (前序)**：中 -> 左 -> 右 (複製樹時用)。
  - **In-order (中序)**：左 -> 中 -> 右 (BST 輸出排序時用)。
  - **Post-order (後序)**：左 -> 右 -> 中 (刪除樹時用，先刪小孩再刪父母)。
- **BFS (廣度優先)** - 用 Queue。
  - **Level-order**：一層一層從左到右印。

### BST 的操作邏輯
- **Search**: 比我小往左走，比我大往右走。。
- **Insert**: 先 Search，找到 NULL 的位置就插進去。。
- **Delete (大魔王)**：分三種情況。
  - **Leaf**: 直接刪除。
  - **One Child**: 獨生子直接繼承父位。
  - **Two Children**: 需要找「替死鬼」來補位 (Predecessor 或 Successor)。

### General Tree 轉 Binary Tree
- **Left Child-Right Sibling**：  
  - 第一個孩子變成 Binary Tree 的左子節點。
  - 下一個兄弟變成 Binary Tree 的右子節點。
- 這樣可以把任意形狀的樹都統一變成二元樹來處理。
<img src="https://github.com/Fanxuan08/11401_CS203A/blob/main/StudyNote/參考圖片/Tree3.jpg" alt="Tree3" width="800"> 

## 複雜度與實作
| 結構/狀態 | Search / Insert / Delete | 實作 |
|---|---|---|
| Average BST | O(log n) | 每次切一半，跟 Binary Search 一樣快。 |
| Skewed BST (最差) | O(n) | 資料剛好已排序，樹退化成 Linked List。 |
| Balanced BST (AVL/Red-Black) | O(log n) | 透過旋轉 (Rotation) 保持平衡，最差也是 O(\log n)。 |

**實作建議**：  
- 如果你要頻繁搜尋資料，BST 很棒。  
- 但是如果 Insert 的資料已經排好序，用普通 BST 會變 O(n)，需要使用 AVL Tree 或 Red-Black Tree (Self-balancing trees)。  

## 容易搞混的地方與記憶重點

### Complete Binary Tree 的 Array Representation
- 假設 Array 從 index 1 開始放：  
  - 自己是 i  
  - 左小孩：2*i  
  - 右小孩：2*i + 1  
  - 爸媽：floor(i/2)  
- 如果 Array 從 0 開始，左小孩是 2*i + 1  

### Pre/In/Post Order 記憶法
- Pre (前)：中左右  
- In (中)：左中右  
- Post (後)：左右中  
- 畫圖技巧：拿一支筆沿著樹的外圍跑一圈  
  - 第一次經過節點是 Pre  
  - 第二次是 In  
  - 第三次是 Post  

### 為什麼要學 AVL/Red-Black Tree？
- BST 最壞情況下太慢 (O(n))。
- **AVL**：高度差不能超過 1，讀取快，但插入刪除要旋轉。
- **Red-Black**：規則寬鬆，實務上最常用 (如 C++ std::map)。

## Reference
- 黃鈺峰教授，《CS203A 資料結構》課程簡報，作為本筆記 Tree 相關內容之主要參考來源。  
- 部分內容與語句排版參考 AI Copilot 的建議，經整理與修正以符合教學筆記風格。
