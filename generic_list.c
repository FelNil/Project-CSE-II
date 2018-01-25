    //generic_list.c
#include "generic_list.h"


list * create_list()
{
  list * newList = (list*)calloc(1, sizeof(list));
  if(newList == NULL){
    return NULL;
  }
  
  newList->pHead = (listobj *)calloc(1, sizeof(listobj));
  if(newList->pHead == NULL){
    free(newList);
    return NULL;
  }
  
  newList->pTail = (listobj *)calloc(1, sizeof(listobj));
  if(newList->pTail == NULL){
    free(newList->pHead);
    free(newList);
    return NULL;
  }
  newList->pHead->pPrevious = newList->pHead;
  newList->pHead->pNext = newList->pTail;
  newList->pTail->pPrevious = newList->pHead;
  newList->pTail->pNext = newList->pTail;
  return newList;
}
listobj * create_listobj(int num)
{
  listobj * newObj = (listobj *)calloc(1, sizeof(listobj));
  
  if(newObj == NULL) return NULL;
  
  newObj->nTCnt = num;
  return(newObj);
}
void insert_first(list * theList, listobj * pObj)
{
  //insert first in list
  listobj * pMarker;
  pMarker = theList->pHead;
  
  //insert element 
  pObj->pNext = pMarker->pNext;
  pObj->pPrevious = pMarker;
  pMarker->pNext = pObj;
  pObj->pNext->pPrevious = pObj;
}
void insert_WRT_nTCnt(list * theList, listobj * pObj, uint _nTCnt)
{
  pObj->nTCnt = _nTCnt;
  if(theList->pHead == theList->pTail->pPrevious){
    //if list is empty
    insert_first(theList,pObj);
  }else{
    
    listobj * pMarker;
    pMarker = theList->pHead;
    
    //find place
    while(pMarker->pNext != theList->pTail)
    {
      if(pObj->nTCnt >= pMarker->pNext->nTCnt)
      {
        pMarker = pMarker->pNext;  
      }else break;
            
    }
      //insert pObj after marker
      pObj->pNext = pMarker->pNext;
      pObj->pPrevious = pMarker;
      pMarker->pNext = pObj;
      pObj->pNext->pPrevious = pObj;

  }  
}
void insert_WRT_Deadline(list * theList, listobj * pObj)
{  
  if(theList->pHead == theList->pTail->pPrevious)
  {
    //if list is empty
    insert_first(theList,pObj);
  }else{
    listobj * pMarker;
    pMarker = theList->pHead;
    
    //find place
    while(pMarker->pNext != theList->pTail)
    {
      if(pObj->pTask->DeadLine >= pMarker->pNext->pTask->DeadLine)
      {
        pMarker = pMarker->pNext;  
      }else break;
            
    }
      //insert pObj after marker
      pObj->pNext = pMarker->pNext;
      pObj->pPrevious = pMarker;
      pMarker->pNext = pObj;
      pObj->pNext->pPrevious = pObj;
  }  
}
void move_WRT_nTCnt(list * fromList, list * toList, uint _nTCnt)
{
  if(fromList->pHead != fromList->pTail->pPrevious){
  
    //extract the first object from the first list
    listobj * pObj;
    pObj = extract_first(fromList);
    pObj->nTCnt = _nTCnt;

    if(toList->pHead == toList->pTail->pPrevious){
      //if list is empty
      insert_first(toList,pObj);
    }else{
    
      listobj * pMarker;
      pMarker = toList->pHead;
            
    
      //find place
      while(pMarker->pNext != toList->pTail)
      {
        if(pObj->nTCnt >= pMarker->pNext->nTCnt)
        {
          pMarker = pMarker->pNext;  
        }else break;
            
      }
        //insert pObj after marker in to the second list.
        pObj->pNext = pMarker->pNext;
        pObj->pPrevious = pMarker;
        pMarker->pNext = pObj;
        pObj->pNext->pPrevious = pObj;
    }
  }else{
    //do nothing. No object to move.
  }
}
void move_WRT_Deadline(list * fromList, list * toList)
{

  if(fromList->pHead != fromList->pTail->pPrevious){
    
    //extract the first object from the first list
    listobj * pObj;
    pObj = extract_first(fromList);
    
    if(toList->pHead == toList->pTail->pPrevious){
      //if list is empty
      insert_first(toList,pObj);
    }else{
    
      listobj * pObj;
      pObj = extract_first(fromList);
      listobj * pMarker;
      pMarker = toList->pHead;
            
    
      //find place
      while(pMarker->pNext != toList->pTail)
      {
        if(pObj->pTask->DeadLine >= pMarker->pNext->pTask->DeadLine)
        {
          pMarker = pMarker->pNext;  
        }else break;
            
      }
        //insert pObj after marker in to the second list. 
        pObj->pNext = pMarker->pNext;
        pObj->pPrevious = pMarker;
        pMarker->pNext = pObj;
        pObj->pNext->pPrevious = pObj;
    }
  }else{
    //do nothing. No object to move.
  }

}
listobj * extract(listobj *pObj)
{
  pObj->pPrevious->pNext = pObj->pNext;
  pObj->pNext->pPrevious = pObj->pPrevious;
  pObj->pNext = pObj->pPrevious = NULL;
  return (pObj);
}
listobj * extract_first(list * theList)
{
  return( extract(theList->pHead->pNext) );
}





  