template<class ElemType>
class list
{
   public:
      virtual void ListClear() = 0; //�����Ա���Ϊ�ձ�
      virtual bool ListEmpty() const = 0; //�ж����Ա��Ƿ�Ϊ�ձ�
      virtual int ListLength() const = 0; //�õ����Ա�ĳ���
      virtual bool SetListLength(int length) = 0; //�������Ա�ĳ���
      virtual ElemType GetElem(int i) const = 0; //��e�������Ա�ĵ�i��Ԫ��
      virtual bool SetElem(int i,ElemType e) = 0; //�������Ա�ĵ�i��Ԫ��
      virtual bool ListInsert(int pos,ElemType e) = 0; //�����Ա�ĵ�pos��λ��֮ǰ����eԪ��
      virtual bool ListDelete(int pos, ElemType &e) = 0; //ɾ�����Ա�ĵ�pos��λ�õ�Ԫ��
      virtual int LocateElem(ElemType e) = 0; //��ָ����������
      virtual void Invert(int, int) = 0; //�������Ա� 
      virtual bool PriorElem(ElemType cur_e, ElemType &pri_e) = 0; //�������Ա��������Ԫ�ص�ǰ������Ԫ�ص�ֵ
      virtual bool NextElem(ElemType cur_e, ElemType &nex_e) = 0; //�������Ա��������Ԫ�صĺ������Ԫ�ص�ֵ
      virtual int ListTraverse() const = 0; //�������Ա�
      virtual void ListDestroy() = 0; //�������Ա� 
      virtual ~list(){}; 
};
 
