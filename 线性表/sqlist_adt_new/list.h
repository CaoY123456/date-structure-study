template<class ElemType>
class list
{
   public:
      virtual void ListClear() = 0; //将线性表置为空表
      virtual bool ListEmpty() const = 0; //判断线性表是否为空表
      virtual int ListLength() const = 0; //得到线性表的长度
      virtual bool SetListLength(int length) = 0; //设置线性表的长度
      virtual ElemType GetElem(int i) const = 0; //用e返回线性表的第i个元素
      virtual bool SetElem(int i,ElemType e) = 0; //设置线性表的第i个元素
      virtual bool ListInsert(int pos,ElemType e) = 0; //在线性表的第pos个位置之前插入e元素
      virtual bool ListDelete(int pos, ElemType &e) = 0; //删除线性表的第pos个位置的元素
      virtual int LocateElem(ElemType e) = 0; //按指定条件查找
      virtual void Invert(int, int) = 0; //逆置线性表 
      virtual bool PriorElem(ElemType cur_e, ElemType &pri_e) = 0; //返回线性表给定数据元素的前驱数据元素的值
      virtual bool NextElem(ElemType cur_e, ElemType &nex_e) = 0; //返回线性表给定数据元素的后继数据元素的值
      virtual int ListTraverse() const = 0; //遍历线性表
      virtual void ListDestroy() = 0; //销毁线性表 
      virtual ~list(){}; 
};
 
