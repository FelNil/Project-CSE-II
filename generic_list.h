#ifndef _GENERIC_LIST_H_
#define _GENERIC_LIST_H_
#include "kernel.h" 

list * create_list();;
listobj * create_llistobj(int num);
void insert_first(list * mylist, listobj * pObj);
void insert_WRT_nTCnt(list * theList, listobj * pObj, uint _nTCnt);
void insert_WRT_Deadline(list * theList, listobj * pObj);
listobj * extract(listobj *pObj);
listobj * extract_first(list * theList);
void move_WRT_nTCnt(list * fromList, list * toList, uint _nTCnt);
void move_WRT_Deadline(list * fromList, list * toList);


#endif