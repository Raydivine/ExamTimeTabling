#include "unity.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"

#define HEAD_TWO      head->next
#define HEAD_THREE    head->next->next
#define HEAD_FOUR     head->next->next->next
#define HEAD_FIVE     head->next->next->next->next

char a,b,c,d,e,f,g,h,i;

void setUp(void){}
void tearDown(void){}

void test_isListsHaveSameElement_given_list1_a_b_c_and_list2_d_e_f_should_return_0(void){
  
  LinkedList *list1 = linkListNew(&a);
  addDataToTail( &list1, &b);
  addDataToTail( &list1, &c);
  
  LinkedList *list2 = linkListNew(&d);
  addDataToTail( &list2, &e);
  addDataToTail( &list2, &f);
  
  int ans = isListsHaveSameElement(list1, list2);
  TEST_ASSERT_EQUAL(0, ans);

  clearLinkList(&list1);  
  clearLinkList(&list2);  
}

void test_isListsHaveSameElement_given_list1_a_b_c_and_list2_d_e_a_should_return_1(void){
  
  LinkedList *list1 = linkListNew(&a);
  addDataToTail( &list1, &b);
  addDataToTail( &list1, &c);
  
  LinkedList *list2 = linkListNew(&d);
  addDataToTail( &list2, &e);
  addDataToTail( &list2, &a);
  
  int ans = isListsHaveSameElement(list1, list2);
  TEST_ASSERT_EQUAL(1, ans);

  clearLinkList(&list1);  
  clearLinkList(&list2);  
}

void test_isListsHaveSameElement_given_list1_a_b_c_and_list2_d_e_b_should_return_1(void){
  
  LinkedList *list1 = linkListNew(&a);
  addDataToTail( &list1, &b);
  addDataToTail( &list1, &c);
  
  LinkedList *list2 = linkListNew(&d);
  addDataToTail( &list2, &e);
  addDataToTail( &list2, &b);
  
  int ans = isListsHaveSameElement(list1, list2);
  TEST_ASSERT_EQUAL(1, ans);

  clearLinkList(&list1);  
  clearLinkList(&list2);  
}

void test_isListsHaveSameElement_given_list1_a_b_c_and_list2_c_e_b_should_return_1(void){
  
  LinkedList *list1 = linkListNew(&a);
  addDataToTail( &list1, &b);
  addDataToTail( &list1, &c);
  
  LinkedList *list2 = linkListNew(&c);
  addDataToTail( &list2, &e);
  addDataToTail( &list2, &b);
  
  int ans = isListsHaveSameElement(list1, list2);
  TEST_ASSERT_EQUAL(1, ans);

  clearLinkList(&list1);  
  clearLinkList(&list2);  
}

void test_isListsHaveSameElement_given_list1_a_b_c_and_list2_NULL_should_return_0(void){
  
  LinkedList *list1 = linkListNew(&a);
  addDataToTail( &list1, &b);
  addDataToTail( &list1, &c);
  
  LinkedList *list2 = NULL;
  
  int ans = isListsHaveSameElement(list1, list2);
  TEST_ASSERT_EQUAL(0, ans);

  clearLinkList(&list1);  
  clearLinkList(&list2);  
}

void test_isListsHaveSameElement_given_list1_NULL_and_list2_c_e_b_should_return_1(void){
  
  LinkedList *list1 = NULL;
  
  LinkedList *list2 = linkListNew(&c);
  addDataToTail( &list2, &e);
  addDataToTail( &list2, &b);
  
  int ans = isListsHaveSameElement(list1, list2);
  TEST_ASSERT_EQUAL(0, ans);

  clearLinkList(&list1);  
  clearLinkList(&list2);  
}
