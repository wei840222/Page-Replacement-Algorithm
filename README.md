# Page-Replacement-Algorithm
##OS Memory Page Replacement Algorithm Simulation

作業系統(OS, Operating System)對於記憶體(Memory)管理的方式有許多種，這篇文章將會說明當使用分頁(Paging)的方法管理記憶體時，若發生了分頁錯誤(Page fault)，作業系統要如何找到一個適當的分頁(Page)，並將其取代成新的內容，儘量讓未來發生分頁錯誤的機會降到最低。

分頁(Paging)
許多作業系統，如Linux、Windows、MAC OS X，都使用分頁的方式來管理記憶體。分頁技術應用在虛擬記憶體(Virtual Memory)上，將一塊實體記憶體(Physical Memory)切成數個固定大小的頁框(Frame)，再將一塊虛擬記憶體切成數個固定大小的分頁(Page)，頁框和分頁的大小必須一樣，接著再藉由分頁表(Page Table)將各個分頁去對應實體記憶體的頁框(Frame)。這樣的作法可以帶來多種好處，好比連續的虛擬記憶體空間在實體記憶體空間上也不一定需要連續，使得記憶體更容易配置(Allocate)，因為不需要在雜亂實體記憶體空間上尋找可用的連續空間。另外，虛擬記憶體空間可以大於等於實體記憶體空間，超出的空間可以使用輔助記憶體(Secondary Memory)，如硬碟、記憶卡等儲存裝置來儲存，等到有需要存取的時候，再替換(Replacement)至實體記憶體空間。

在Linux系統中，虛擬記憶體的大小等於實體記憶體空間的大小加上所有在輔助記憶體上可用的SWAP空間。Linux的SWAP空間可以直接用磁碟分割的方式來配置出SWAP分割區，分割區的大小就是SWAP空間的大小；也可以在現有的檔案系統下建立一個專門用來進行SWAP的檔案，檔案的大小就是SWAP空間的大小。

在Windows系統中，虛擬記憶體的大小等於實體記憶體空間的大小加上所有硬碟分割區下的分頁檔案大小和所有USB儲存裝置與記憶卡中ReadyBoost的檔案大小。

分頁錯誤(Page fault)
當作業系統要存取某個分頁時，會先去分頁表中搜尋該分頁的分頁項目(PTE, Page Table Entry)，這個分頁項目會儲存分頁對應的頁框，以及其他關於這個分頁一些資訊，例如這個分頁目前是不是正存在於實體記憶體中(是不是有頁框可以使用)。若要存取的分頁不存在於實體記憶體中，就會發生分頁錯誤(Page fault)，此時就需要替這個分頁尋找一個頁框來使用。這個在發生分頁錯誤後，尋找頁框並使用的動作就稱為分頁替換(Page Replacement)。

分頁替換(Page Replacement)
如果實體記憶體中還有沒使用到的頁框，可以直接將分頁的內容從輔助記憶體移進(swap in)這個實體記憶體的頁框中；如果實體記憶體中所有的頁框都已經被分頁使用，那麼只好想辦法找出一個未來可能要很久才會再被用到的頁框中其他分頁的內容，將其移出(swap out)至輔助記憶體中儲存，接著再將輔助記憶體中要使用的分頁內容移進(swap in)這個實體記憶體的頁框中。由於這個移出移入(swap in/out)的動作需要許多時間來完成，因此我們會希望分頁替換的次數愈少愈好。也就是說，我們要讓分頁被替換後，再次發生分頁錯誤的機會降低。分頁錯誤的次數愈少，作業系統的運作效能就能愈好，同時也能減少對輔助記憶體的讀寫次數，延長硬體壽命。

分頁替換演算法(Page Replacement Algorithm)
以下將分別使用不同演算法來實際模擬當要在三個頁框的實體記憶體情況下，連續存取「E F A B F C F D B C F C B A B」以字母代號表示的分頁時的流程。

First in First out Page Replacement(FIFO)
將存在於實體記憶體頁框中最久的分頁給取代掉，實作起來最為容易。流程如下表，表格填色的部份表示下一次分頁錯誤發生時要拿來進行替換的頁框。

分頁替換演算法(Page Replacement Algorithm)介紹與模擬

分頁錯誤的次數為12次。

Least Recently Used Page Replacement(LRU)
將存在於實體記憶體頁框中最久沒用到的分頁給取代掉，實作起來比起FIFO稍微困難，需使用計數變數(Counter)去儲存每個在頁框內的分頁使用後閒置的時間，或是如Linked List等額外的資料結構來儲存過去頁框中的分頁使用的順序，但實行起來成效顯著。流程如下表，分頁後數字的部份為最近使用的排序，數字愈小表示愈久之前使用過。

分頁替換演算法(Page Replacement Algorithm)介紹與模擬

分頁錯誤的次數為10次。

The Clock Page Replacement (Second Chance)
基於FIFO，但是會重新給予被使用到的分頁第二次機會，使其可以跳過一次頁框被別的分頁選擇取代的命運。概念上類似LRU，能保留最近使用過的頁框，但比LRU還要容易實作得多。流程如下表，分頁後數字的部份為剩餘可跳過被選擇取代的次數。

分頁替換演算法(Page Replacement Algorithm)介紹與模擬

分頁錯誤的次數為11次。

Random Page Replacement
基於FIFO，只是當沒有可用的頁框時，會隨機選取一個頁框來替換。流程如下表：

分頁替換演算法(Page Replacement Algorithm)介紹與模擬

分頁錯誤的次數為10次(隨機)。

Optimal Page Replacement
基於FIFO，將於實體記憶體頁框中，不會再次被使用或是最久才會再次被使用的分頁給取代掉，實作起來最非常困難，因為要預知未來可能會存取的分頁，但是這個將會是理想最佳解。流程如下表：

分頁替換演算法(Page Replacement Algorithm)介紹與模擬

分頁錯誤的次數僅為8次(最佳)。
