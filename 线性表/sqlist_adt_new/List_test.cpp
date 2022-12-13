#include<iostream>
using namespace std;

const int MAXLISTSIZE = 100;

template<class ElemType>
class SqList
{
   private:
      ElemType *elem;   // �洢�ռ��ַ
      int length;               // ��ǰ����
      int listsize;        // ��������洢����(��sizeof(ElemType)Ϊ��λ
   public:
      //��ʼ��˳���
      SqList(int ms = 20);
      //ɾ��˳���
      ~SqList(){delete [] elem;}
      //��˳�����Ϊ�ձ�
      void ListClear( ){length = 0;}
      //����˳���ĳ���
      int ListLength() const {return length;}
      //����˳���ĳ���
      bool SetListLength(int len);
      //�ж�˳����Ƿ�Ϊ�ձ�
      bool ListEmpty() const;
      //�ж�˳����Ƿ�Ϊ���� 
      bool ListFull() const;
      //��e����˳���ĵ�i��Ԫ��
      ElemType GetElem(int i) const;
      //��e����˳���ĵ�i��Ԫ��
      bool SetElem(int i, ElemType e);
      //��˳���ĵ�pos��λ��֮ǰ����eԪ��
      bool ListInsert(int pos,ElemType e);
      //ɾ��˳���ĵ�pos��λ�õ�Ԫ��
      bool ListDelete(int pos, ElemType &e);
      //compare�����������ж�a��b�Ƿ����
      bool compare(ElemType a, ElemType *b);
      //��ָ����������
      int LocateElem(ElemType e);
      //����˳���
      void Invert(int, int); 
      //�������Ա��������Ԫ�ص�ǰ������Ԫ�ص�ֵ
      bool PriorElem(ElemType cur_e, ElemType &pri_e); 
      //�������Ա��������Ԫ�صĺ������Ԫ�ص�ֵ
      bool NextElem(ElemType cur_e, ElemType &nex_e); 
      //�������Ա�
      void ListDestroy(); 
      //����˳���
      int ListTraverse() const;
};

template<class ElemType>
SqList<ElemType>::SqList(int maxsize){
      // ����һ���յ����Ա�L
      if( maxsize == 0 ) maxsize = MAXLISTSIZE;
      elem = new ElemType[maxsize];

      //if( !elem )   exit(0);             // �洢����ʧ��
      length = 0;                         // ˳���ĳ�ʼ����Ϊ0
      listsize = maxsize;            // ��˳�����Դ洢Ԫ�ص��������
}

template<class ElemType>
bool SqList<ElemType>::ListEmpty() const{
     //�ж����Ա��Ƿ�Ϊ��     
     if(length == 0) return true;//�����ǰԪ�ظ���Ϊ0˵��Ϊ�ձ�         
     return false; 
}

template<class ElemType>
bool SqList<ElemType>::ListFull() const{
     //�ж����Ա��Ƿ�Ϊ��     
     if(length == MAXLISTSIZE) return true;//�����ǰԪ�ظ���Ϊ���ֵ˵��Ϊ����         
     return false; 
}

template<class ElemType>
bool SqList<ElemType>::SetListLength(int len){
     //�ж����õĳ��ȵĺϷ���     
     if(len < 1 || len > MAXLISTSIZE) return false;
     length = len;         
     return true; 
}

template<class ElemType>
ElemType SqList<ElemType>::GetElem(int i) const{
     //if( i < 1 || i > listsize + 1 ) exit(0); // λ�ò��Ϸ�
     //��e�������Ա�L�ĵ�i��Ԫ��     
     return *(elem + i - 1);     
}

template<class ElemType>
bool SqList<ElemType>::SetElem(int i, ElemType e){
     if( i < 1 || i > listsize + 1 ) return false; // λ�ò��Ϸ�
     //��e�������Ա�L�ĵ�i��Ԫ��     
     *(elem + i - 1) = e;
     return true;     
}

template<class ElemType>
void SqList<ElemType>::Invert( int s, int t ){
     // ���㷨��˳��� ���±��� s �� t ��Ԫ�����ã�����
     // ��Rs,Rs+1,��,Rt-1,Rt���ı�Ϊ��Rt,Rt-1,��,Rs+1,Rs��
     ElemType w; 
     for ( int k=s; k<=(s+t)/2; k++ ){
         w = elem[k];
         elem[k] = elem[t-k+s];
         elem[t-k+s] = w;
     } // for
} // invert 

template<class ElemType>
bool SqList<ElemType>::ListInsert(int pos,ElemType e){
     // ���洢�ռ䲻����1��pos ��LengthList(L)+1������˳���L��
     // ��pos��Ԫ��֮ǰ�����µ�Ԫ��e�ҷ���TRUE�����򷵻�FALSE��
     if( pos < 1 || pos > listsize + 1 ) return false; // ����λ�ò��Ϸ�
     if( length >= MAXLISTSIZE ) return false; // ��ǰ�洢�ռ��������޷�����
     for( int j = length - 1; j >= pos - 1; --j)  
         elem[j+1] = elem[j];       // ����λ�ü�֮���Ԫ�غ���
     elem[pos-1] = e;              // ����e
     ++ length;                         // ����1
     return true;
} // ListInsert

template<class ElemType>
bool SqList<ElemType>::ListDelete(int pos, ElemType &e){
      // ��1��pos ��LengthList(L) ������e���ش�˳���L��ɾ����
      // ��pos��Ԫ���ҷ���TRUE�����򷵻�FALSE��
      if( pos < 1 || pos > length ) return false;         // ɾ��λ�ò��Ϸ�
      e = elem[pos-1];
      for( int j = pos; j <= length; ++j)  
          elem[j-1] = elem[j];       // ��ɾ��Ԫ��֮���Ԫ������
      -- length;                         // ����1
      return true;
} // ListDelete

template<class ElemType>
bool SqList<ElemType>::compare(ElemType a, ElemType *b){
      //compare�����������ж�a��b�Ƿ����     
      if(a == *b) return true;
      //�������򷵻�-1     
      else return false; 
}

template<class ElemType>
//int SqList<ElemType>::LocateElem(ElemType e,bool (* compare)(ElemType, ElemType *)){
int SqList<ElemType>::LocateElem(ElemType e){
    //��ָ����������
    int i;      
    for(i = 0; i < length; i++){          
       if ((compare(e, elem + i)) == false) continue;
       //���e�����ڵ�i��Ԫ�ؾͼ�������         
       else break;     
     }      
     if(i == length) return -1; //���������϶�û���ҵ�e���Ԫ�أ�˵��e����L�е�Ԫ�ط���0
     else return i;//����ҵ��˵Ļ��ͷ����±� 
}  

template<class ElemType>
bool SqList<ElemType>::PriorElem(ElemType cur_e, ElemType &pre_e){
    //����e��ǰ��
    if(elem){
       if(LocateElem(cur_e) && LocateElem(cur_e) !=0){
       //���e��L�е�Ԫ�أ�����e��Ӧ���±겻Ϊ0
          pre_e =*(elem + LocateElem(cur_e) - 1);
          return true;
        }
        else return false;
     }
     return false;
}

template<class ElemType>
bool SqList<ElemType>::NextElem(ElemType cur_e, ElemType &nex_e){
    //����e�ĺ�� 
    if(elem){
       if(LocateElem(cur_e) && LocateElem(cur_e) !=length-1){
       //���e��L�е�Ԫ�أ�����e��Ӧ���±겻Ϊ���Ԫ�� 
          nex_e =*(elem + LocateElem(cur_e) + 1);
          return true;
        }
        else return false;
     }
     return false;
}

template<class ElemType>
int SqList<ElemType>::ListTraverse() const{
     //��ӡ˳���     
     for(int i = 0; i < length; i++){         
        cout<<*(elem + i)<<" ";
     }      
     cout<<endl; 
     return 1;
}

template<class ElemType>
void SqList<ElemType>::ListDestroy() {
     //����˳���     
      delete elem;
      listsize = 0;
      length = 0;   
}

template<class ElemType>
void ListCreate( SqList<ElemType> &sqlist,int n, ElemType A[] ){
     // ���㷨����˳���
    for(int i = 0; i < n; i++){         
         sqlist.ListInsert(i+1,A[i]);
    }      
} // exchange 

//���е����ȵ�˳��������Ա���ǣ� 
template<class ElemType>
void List_Order( const SqList<ElemType> &A  ){
   int mid,len;
   int left, right;
   
   len = A.ListLength();
   left = 1;
   right = len;
   
   if(len > 0) List_Order_Recursive( A, left, right );
}

//���е����ȵ�˳��������Ա��ݹ飩 
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
       
    
    //����˳��� 
    ListCreate(A, n, Input);

    //���˳���A 
    A.ListTraverse();
    //���������˳���A 
    List_Order(A);
 
    return 0;
}
