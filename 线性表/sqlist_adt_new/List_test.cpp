#include<iostream>
using namespace std;

const int MAXLISTSIZE = 100;

template<class ElemType>
class SqList
{
   private:
      ElemType *elem;   // 存储空间基址
      int length;               // 当前长度
      int listsize;        // 允许的最大存储容量(以sizeof(ElemType)为单位
   public:
      //初始化顺序表
      SqList(int ms = 20);
      //删除顺序表
      ~SqList(){delete [] elem;}
      //将顺序表置为空表
      void ListClear( ){length = 0;}
      //返回顺序表的长度
      int ListLength() const {return length;}
      //设置顺序表的长度
      bool SetListLength(int len);
      //判断顺序表是否为空表
      bool ListEmpty() const;
      //判断顺序表是否为满表 
      bool ListFull() const;
      //用e返回顺序表的第i个元素
      ElemType GetElem(int i) const;
      //用e设置顺序表的第i个元素
      bool SetElem(int i, ElemType e);
      //在顺序表的第pos个位置之前插入e元素
      bool ListInsert(int pos,ElemType e);
      //删除顺序表的第pos个位置的元素
      bool ListDelete(int pos, ElemType &e);
      //compare函数，用来判断a和b是否相等
      bool compare(ElemType a, ElemType *b);
      //按指定条件查找
      int LocateElem(ElemType e);
      //逆置顺序表
      void Invert(int, int); 
      //返回线性表给定数据元素的前驱数据元素的值
      bool PriorElem(ElemType cur_e, ElemType &pri_e); 
      //返回线性表给定数据元素的后继数据元素的值
      bool NextElem(ElemType cur_e, ElemType &nex_e); 
      //销毁线性表
      void ListDestroy(); 
      //遍历顺序表
      int ListTraverse() const;
};

template<class ElemType>
SqList<ElemType>::SqList(int maxsize){
      // 构造一个空的线性表L
      if( maxsize == 0 ) maxsize = MAXLISTSIZE;
      elem = new ElemType[maxsize];

      //if( !elem )   exit(0);             // 存储分配失败
      length = 0;                         // 顺序表的初始长度为0
      listsize = maxsize;            // 该顺序表可以存储元素的最大容量
}

template<class ElemType>
bool SqList<ElemType>::ListEmpty() const{
     //判断线性表是否为空     
     if(length == 0) return true;//如果当前元素个数为0说明为空表         
     return false; 
}

template<class ElemType>
bool SqList<ElemType>::ListFull() const{
     //判断线性表是否为满     
     if(length == MAXLISTSIZE) return true;//如果当前元素个数为最大值说明为满表         
     return false; 
}

template<class ElemType>
bool SqList<ElemType>::SetListLength(int len){
     //判断设置的长度的合法性     
     if(len < 1 || len > MAXLISTSIZE) return false;
     length = len;         
     return true; 
}

template<class ElemType>
ElemType SqList<ElemType>::GetElem(int i) const{
     //if( i < 1 || i > listsize + 1 ) exit(0); // 位置不合法
     //用e返回线性表L的第i个元素     
     return *(elem + i - 1);     
}

template<class ElemType>
bool SqList<ElemType>::SetElem(int i, ElemType e){
     if( i < 1 || i > listsize + 1 ) return false; // 位置不合法
     //用e设置线性表L的第i个元素     
     *(elem + i - 1) = e;
     return true;     
}

template<class ElemType>
void SqList<ElemType>::Invert( int s, int t ){
     // 本算法将顺序表 中下标自 s 到 t 的元素逆置，即将
     // （Rs,Rs+1,…,Rt-1,Rt）改变为（Rt,Rt-1,…,Rs+1,Rs）
     ElemType w; 
     for ( int k=s; k<=(s+t)/2; k++ ){
         w = elem[k];
         elem[k] = elem[t-k+s];
         elem[t-k+s] = w;
     } // for
} // invert 

template<class ElemType>
bool SqList<ElemType>::ListInsert(int pos,ElemType e){
     // 若存储空间不满且1≤pos ≤LengthList(L)+1，则在顺序表L的
     // 第pos个元素之前插入新的元素e且返回TRUE，否则返回FALSE。
     if( pos < 1 || pos > listsize + 1 ) return false; // 插入位置不合法
     if( length >= MAXLISTSIZE ) return false; // 当前存储空间已满，无法插入
     for( int j = length - 1; j >= pos - 1; --j)  
         elem[j+1] = elem[j];       // 插入位置及之后的元素后移
     elem[pos-1] = e;              // 插入e
     ++ length;                         // 表长增1
     return true;
} // ListInsert

template<class ElemType>
bool SqList<ElemType>::ListDelete(int pos, ElemType &e){
      // 若1≤pos ≤LengthList(L) ，则以e带回从顺序表L中删除的
      // 第pos个元素且返回TRUE，否则返回FALSE。
      if( pos < 1 || pos > length ) return false;         // 删除位置不合法
      e = elem[pos-1];
      for( int j = pos; j <= length; ++j)  
          elem[j-1] = elem[j];       // 被删除元素之后的元素左移
      -- length;                         // 表长减1
      return true;
} // ListDelete

template<class ElemType>
bool SqList<ElemType>::compare(ElemType a, ElemType *b){
      //compare函数，用来判断a和b是否相等     
      if(a == *b) return true;
      //如果相等则返回-1     
      else return false; 
}

template<class ElemType>
//int SqList<ElemType>::LocateElem(ElemType e,bool (* compare)(ElemType, ElemType *)){
int SqList<ElemType>::LocateElem(ElemType e){
    //按指定条件查找
    int i;      
    for(i = 0; i < length; i++){          
       if ((compare(e, elem + i)) == false) continue;
       //如果e不等于第i个元素就继续查找         
       else break;     
     }      
     if(i == length) return -1; //如果搜索完毕都没有找到e这个元素，说明e不是L中的元素返回0
     else return i;//如果找到了的话就返回下标 
}  

template<class ElemType>
bool SqList<ElemType>::PriorElem(ElemType cur_e, ElemType &pre_e){
    //查找e的前趋
    if(elem){
       if(LocateElem(cur_e) && LocateElem(cur_e) !=0){
       //如果e是L中的元素，并且e对应的下标不为0
          pre_e =*(elem + LocateElem(cur_e) - 1);
          return true;
        }
        else return false;
     }
     return false;
}

template<class ElemType>
bool SqList<ElemType>::NextElem(ElemType cur_e, ElemType &nex_e){
    //查找e的后继 
    if(elem){
       if(LocateElem(cur_e) && LocateElem(cur_e) !=length-1){
       //如果e是L中的元素，并且e对应的下标不为最后元素 
          nex_e =*(elem + LocateElem(cur_e) + 1);
          return true;
        }
        else return false;
     }
     return false;
}

template<class ElemType>
int SqList<ElemType>::ListTraverse() const{
     //打印顺序表     
     for(int i = 0; i < length; i++){         
        cout<<*(elem + i)<<" ";
     }      
     cout<<endl; 
     return 1;
}

template<class ElemType>
void SqList<ElemType>::ListDestroy() {
     //销毁顺序表     
      delete elem;
      listsize = 0;
      length = 0;   
}

template<class ElemType>
void ListCreate( SqList<ElemType> &sqlist,int n, ElemType A[] ){
     // 本算法生成顺序表
    for(int i = 0; i < n; i++){         
         sqlist.ListInsert(i+1,A[i]);
    }      
} // exchange 

//按中点优先的顺序遍历线性表（外壳） 
template<class ElemType>
void List_Order( const SqList<ElemType> &A  ){
   int mid,len;
   int left, right;
   
   len = A.ListLength();
   left = 1;
   right = len;
   
   if(len > 0) List_Order_Recursive( A, left, right );
}

//按中点优先的顺序遍历线性表（递归） 
template<class ElemType>
void List_Order_Recursive( const SqList<ElemType> &A, int left, int right ){
    int mid;
    
    if(left <= right){
        mid = (left + right) / 2;
        cout<<A.GetElem(mid)<<" ";
        List_Order_Recursive(A, left, mid - 1 );    
        List_Order_Recursive(A, mid + 1, right );    
    }
}     

int main()
{
    SqList <int> A;
    
    int n;
    cin>>n;
    int Input[n];
    for( int i = 0; i < n; i++)
       cin>>Input[i];
       
    
    //建立顺序表 
    ListCreate(A, n, Input);

    //输出顺序表A 
    A.ListTraverse();
    //按规则输出顺序表A 
    List_Order(A);
 
    return 0;
}
