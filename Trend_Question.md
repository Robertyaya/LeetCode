# OS
## 1. OS解釋
OS是管理計算機硬體和軟體資源的程序, 並通過kernel mode and user mode去保護硬體
如果要操作底層的硬體資源, 須透過high level的system call來操作

## 2. System call
- 1. User mode: User mode運行的process或可以直接讀取user program的數據
- 2. Kernal mode: Kernal mode運行的process可以訪問底層硬體的資源不受限制
我們運行的program都是在user mode運行, 因此如果要調用作業系統提供的系統級別的功能就要利用system call,
在運行我們用戶的程序中, 凡與kernal mode級別的資源有關的操作 
ex:
Process control
File Management
Device Management
Information Maintenance
Communication
都可以通做system call向作業系統提出服務請求, 並由作業系統代為完成

## 3. Process間通信, IPC
- 1. Pipes
- 2. Names Pipes
- 3. Signal
- 4. Message Queuing
- 5. Semaphores
信號量是一個計數器, 用於多進程對共享數據的訪問, 信號量的意圖在於進程間同步. 可避免race condition

- 6. Shared memory
使得多個process可以訪問同一塊內存空間, 不同process可以即時看到對方process中對共享數據的更新. 這種方式
需要依靠某種同步操作, 如mutex and semaphores等. 這是最有用的process間通信方式

- 7. Sockets
此方法主要用於在客戶端和伺服器之間通過網路進行通信, 不同主機之間的process進行雙向通信

## 5. Thread 同步
- 1. mutex
只有擁有互斥對象的thread才有訪問公共資源的權限. 而因為互斥對象只有一個, 因此可以確保公共資源不會被多個thead"同時"訪問
- 2. Semphares
允許同一時刻多個thread訪問同一資源, (停車場的概念, 會有一個計數器紀錄現在已經進入幾台車, 當滿了之後要等其他車走了才能再有車進去), 需要控制同一時刻訪問此資源的最大thread數量

## 6. Virtual Memory
軟體佔用的內存可能已經遠遠超出電腦本身具有的物理內存, 通過virtual memory可以讓程序可以擁有超過系統物理內存大小的可用內存空間. 虛擬內存是計算機系統內存管理的一種技術, 虛擬哪存的重要意義是他定義了一個連續的虛擬地址空間, 並且把內存擴展到硬碟空間
虛擬內存使得應用程式認為他擁有連續的可用內存(一個連續完整的地址空間). 實際上, 通常是被分割成多個物理內存碎片還有部分暫時存在外部硬碟空間上, 在需要時才進行數據交換

## 7. Program & Thread & Process
Program:
尚未被load到記憶體的一堆code

Process: 
當program load進記憶體之後, 隨時可執行的程式就叫做process
每個process會有自己獨立一個momory空間不會互相干擾
而process之間溝通相較於thread之間比較麻煩, 可以利用shared momory的方式讓兩個process之間做溝通

Thread:
Process為thread的container概念, 一個process裡面可以有數個thread在run, 而thread之間的溝通相較於process來講就簡單很多,因為不同的thread在是配 可以利用global variable
優點: 
- Much quicker to create a thread than a process
- Much quicker to switch between threads than to switch between processes
- Thread share data easily
缺點:
- No security between threads
- If one thread blocks, all thread will block
何時該使用thread
- Doing I/O work: Thread allow you to ensure that I/O latency does not delay unrelated pats of your application

## 8. Memory Hierarchy
Rigister - Cache - Main Memory - Disk - Tape
愈快 <- 速度 -> 愈慢
愈昂貴 <- 價格 -> 愈便宜
愈小 <- 容量 -> 愈大

# DB related
SQL vs NoSQL:
https://www.kshuang.xyz/doku.php/database:sql_vs_nosql
https://ithelp.ithome.com.tw/articles/10187443
https://read01.com/GPnEx.html#.X1xNIZMzZTY

SQL是一個拿來查詢資料庫的語言, SQL並不是一個資料庫系統, MySQL才是
常見MySQL, PostgreSQL...
任何一種以SQL為基礎的資料庫系統, 都有差不多的特性, 必須事先定義好Schema, 資料庫的規格書
就是資料庫裡面要有哪些欄位, 每一個欄位的資料型態是什麼. 會先把每一個欄位的名稱跟型態都先固定住


SQL: relational database

NoSQL: non-relational database

- SQL database: 
table建立了比較嚴格的資料模板, 資料格式上比較不容易出錯
ex: 這表示在data table中你無法使用同一張資料表紀錄欄位不同的資料, 或是在欄位值應該是數字的地方填入字串
- NoSQL database: 
是以類似JSON去儲存資料, 為巢狀格式, 在document中我們可以儲存任何資料, 不像data tables那樣嚴格

## CI/CD
https://medium.com/@Bear_/%E4%BB%80%E9%BA%BC%E6%98%AF-ci-cd-72bd5ae571f1






