# Comparison: 陣列Array vs. 鏈結串列Linked List

| 比較項目 | 陣列 (Array) | 鏈結串列 (LinkedList) |
|---|---|---|
| 記憶體分配 | 靜態分配：在記憶體中佔用連續的空間。 | 動態分配：節點可散佈在記憶體各處，透過指標連結。 |
| 讀取效率 | 極快 O(1)：可透過索引（Index）隨機存取。 | 較慢 O(n)：需從頭節點開始依序尋找。 |
| 新增/刪除 | 較慢 O(n)：需移動插入點後的所有元素。 | 較快 O(1)：僅需修改前後節點的指標指向。 |
| 空間利用率 | 可能浪費空間（預宣告太大）或溢位。 | 隨用隨開，但每個節點額外耗費空間儲存指標。 |
| 快取友善度 | 高：具備空間局部性（Locality），對 CPU 快取友好。 | 低：資料散落，快取命中率較低。 |

## 什麼時候會用到？

### 使用 Array 的情境
- 資料筆數大致固定或變動不大
- 需要頻繁「依索引快速讀取」
- 重視效能與快取效率（如：表格資料、影像像素）
- 題目出現：random access、index、cache-friendly

### 使用 Linked List 的情境
- 資料大小高度動態
- 頻繁插入 / 刪除（尤其在中間或開頭）
- 不在意查找速度
- 題目出現：dynamic size、frequent insert/delete

## 總結
- 要不要快速用 index 讀資料？
- 插入 / 刪除是不是很頻繁？
- 記憶體是否需要連續？

- 快速查 → Array
- 動態改 → Linked List

## Reference
- 黃鈺峰教授，《CS203A 資料結構》課程簡報，作為本筆記相關內容之參考來源。
- 黃鈺峰教授，[**CS203A Github資料**](https://github.com/yfhuang/11401_CS203A/blob/main/StudyNote/05_Comparison_Array_LinkedList.md)，作為本筆記相關內容之參考來源。
- 部分內容與語句排版參考 AI Copilot 的建議，經整理與修正以符合教學筆記風格。