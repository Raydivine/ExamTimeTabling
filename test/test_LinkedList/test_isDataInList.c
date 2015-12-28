#include "unity.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"

#define HEAD_TWO      head->next
#define HEAD_THREE    head->next->next
#define HEAD_FOUR     head->next->next->next
#define HEAD_FIVE     head->next->next->next->next

int one=1, two=2, three=3, five=5;

void setUp(void){}

void tearDown(void){}

void test_isDataInList_given_head_is_NULL_should_return0(void){
  LinkedList *head = NULL;

  int ans = isDataInList( head, &three);
  TEST_ASSERT_EQUAL(0, ans);

  clearLinkList(&head); 
}

void test_isDataInList_given_list_1_2_3_and_search_5_should_return_0(void){

  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &three);
  
  int ans = isDataInList( head, &five);
  TEST_ASSERT_EQUAL(0, ans);

  clearLinkList(&head);   
}

void test_isDataInList_given_list_1_2_3_and_search_3_should_return_1(void){

  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &three);
  
  int ans = isDataInList( head, &three);
  TEST_ASSERT_EQUAL(1, ans);

  clearLinkList(&head);   
}

void test_isDataInList_given_list_1_2_3_and_search_1_should_return_1(void){

  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &three);
  
  int ans = isDataInList( head, &one);
  TEST_ASSERT_EQUAL(1, ans);

  clearLinkList(&head);   
}

void test_isDataInList_given_list_1_2_3_and_search_2_should_return_1(void){

  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &three);
  
  int ans = isDataInList( head, &two);
  TEST_ASSERT_EQUAL(1, ans);

  clearLinkList(&head);   
}


void test_isDataInList_given_list_a_b_c_d_s_and_search_s_should_return_1(void){
  char a,b,c,d,s;
  
  LinkedList *head = linkListNew(&a);
  addDataToTail( &head, &b);
  addDataToTail( &head, &c);
  addDataToTail( &head, &d);
  addDataToTail( &head, &s);
  
  int ans = isDataInList( head, &s);
  TEST_ASSERT_EQUAL(1, ans);

  clearLinkList(&head);   
}

void test_isDataInList_given_list_a_b_c_d_s_and_search_t_should_return_0(void){
  char a,b,c,d,s,t;
  
  LinkedList *head = linkListNew(&a);
  addDataToTail( &head, &b);
  addDataToTail( &head, &c);
  addDataToTail( &head, &d);
  addDataToTail( &head, &s);
  
  int ans = isDataInList( head, &t);
  TEST_ASSERT_EQUAL(0, ans);

  clearLinkList(&head);   
}