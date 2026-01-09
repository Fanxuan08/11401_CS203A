# Graphs (圖形)

## 核心概念
Graph 是比 Tree 更廣義的資料結構，用來描述「物件與物件之間的關係」。  
如果說 Tree 是有階級制度的組織圖（有 Root、有 Parent-Child），那 Graph 就是一張 **網狀地圖**。  

由兩個主要元素組成：  
- **Vertex (頂點 / Node)**：代表物件（如：城市、人、網頁）。
- **Edge (邊)**：代表關係（如：道路、朋友關係、連結）。
- 數學表示法：**G = (V, E)**  

## Graph 能解決什麼問題？
- **模擬複雜關係**：現實世界大多不是層級狀，而是網狀。
- **實務應用**：
  - 地圖導航 (Google Maps)：找兩點間最短路徑 (Weighted Graph)。
  - 社群網路：FB 好友是雙向 (Undirected)，IG 追蹤是單向 (Directed)。
  - 網路爬蟲：網頁之間的超連結跳轉。

## 核心特性
- **沒有 Root**：沒有起點也沒有終點，大家地位平等。
- **可以有 Cycle (環)**：可以繞一圈回到原點（Tree 最大不同）。 
- **多對多關係**：一個點可以連向任意多個點。

## 關鍵考點

### Graph 的分類 (必考名詞)
- **Directed vs. Undirected (有向 vs. 無向)**  
  - Undirected：邊沒有方向 (A-B = B-A)。
  - Directed (Digraph)：邊有箭頭 (A → B)。
- **Weighted vs. Unweighted (加權 vs. 無權)**  
  - Weighted：邊有數值 (Weight/Cost)，通常代表距離或花費。
- **Cyclic vs. Acyclic (有環 vs. 無環)**  
  - Cyclic：可以走出一條路繞回原點。
- **Connected**：任兩點都可連通 (沒有孤島)。

### Degree (分支度) 的計算
- **Undirected**：連幾條線出去就是 Degree。
  - 公式：所有 Degree 加起來 = 2 * Edge 數。
- **Directed**：
  - **In-degree**：有多少箭頭指進來。
  - **Out-degree**：有多少箭頭指出去。

## 運作方式與操作邏輯

### Graph Representation (怎麼把圖存進電腦？)
| 特性 | Adjacency Matrix (鄰接矩陣) | Adjacency List (鄰接串列) |
|---|---|---|
| 結構 | 2D Array M[i][j] | Array + Linked List |
| 儲存方式 | 有邊填 1 (或權重)，沒邊填 0 | 每個點掛一個 List，存它的鄰居 |
| 空間 | O(V²) (超浪費，適合 Dense Graph) | O(V+E) (省空間，適合 Sparse Graph) |
| 查邊 (A, B) | O(1) | O(Degree(A)) |
| 找鄰居 | O(V) | O(Degree(A)) |
| 適用場景 | 邊多的稠密圖 (Dense) | 邊少的稀疏圖 (Sparse，如地圖、社群) |

### Graph Traversal (怎麼把圖逛一遍？)
- 跟 Tree 一樣有兩種逛法，但因有 Cycle，一定要記「Visited」，否則會無窮迴圈。
- **DFS (深度優先搜尋)**  
  - 邏輯：一條路走到底，撞牆再回頭。
  - 實作：使用 Stack 或 Recursion。
  - 用途：走迷宮、判斷有無 Cycle。
- **BFS (廣度優先搜尋)**  
  - 邏輯：地毯式搜索，先把鄰居逛完再往外擴一層。
  - 實作：使用 Queue。
  - 用途：找無權重圖的最短路徑。

## 複雜度與實作
| 資料結構 | 空間複雜度 | DFS/BFS 遍歷時間 | 適用場景 | 優點 | 缺點 |
|---|---|---|---|---|---|
| **Adjacency Matrix** | O(V²) | O(V²) | 密集圖、需要快速判斷任意兩頂點是否相鄰 | 查找邊是否存在 O(1) | 空間消耗大，稀疏圖浪費；遍歷邊效率低 |
| **Adjacency List** | O(V + E) | O(V + E) | 稀疏圖、實務大規模圖（如社交網路、路網） | 節省空間，遍歷邊高效 | 判斷任意兩頂點是否相鄰需 O(degree) |

**實作建議**：  
- **資料結構選擇**：實務中圖通常為 Sparse Graph (邊數 << V²)，建議用 Adjacency List。
- **演算法選擇**：
  - 最短路徑 (無權重)：使用 BFS，保證最少邊數路徑。
  - 圖的連通性或是否有環：使用 DFS，遞迴直觀，便於追蹤訪問狀態。

## 容易搞混的地方與記憶重點

### Tree vs. Graph (比較表)
| 特性 | Tree | Graph |
|---|---|---|
| Cycle | No (有環就不是 Tree) | Yes (允許有環) |
| Root | 有 (唯一的頭) | 無 (大家平等) |
| 路徑 | 兩點間只有唯一一條路徑 | 兩點間可能有多條路徑 |
| 關係 | 階層式 (Parent-Child) | 網狀 (Neighbor) |
| 走訪 | 不用記 Visited | 必須記 Visited |

### DFS/BFS 用哪個資料結構？
- DFS = Stack (Deep -> Stack，一直壓下去)  
- BFS = Queue (排隊買票，一層一層來)  

## Reference
- 黃鈺峰教授，《CS203A 資料結構》課程簡報，作為本筆記 Graph 相關內容之主要參考來源  
- 部分內容與語句排版參考 AI Copilot 的建議，經整理與修正以符合教學筆記風格
