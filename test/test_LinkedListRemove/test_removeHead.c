#include "unity.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include "LinkedListAdd.h"
#include "CException.h"

#define HEAD_TWO      head->next
#define HEAD_THREE    head->next->next
#define HEAD_FOUR     head->next->next->next
#define HEAD_FIVE     head->next->next->next->next

void setUp(void)
{
}

void tearDown(void)
{
}


void test_removeHead_given_list_1_should_form_NULL(void){
  int one=1;
  
  LinkedList *head = linkListNew(&one);
 
  removeHead(&head);
  TEST_ASSERT_NULL(head);
  
  clearLinkList(&head); 
}

void test_removeHead_given_list_1_2_should_form_2(void){
  int one=1, two=2;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  
  removeHead( &head);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(2, *(int*)head->data);
  TEST_ASSERT_NULL(head->next);
  
  clearLinkList(&head);  
}

void test_removeHead_given_list_1_2_4_should_form_2_4(void){
  int one=1, two=2, four=4;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &four);
  
  removeHead( &head);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(2, *(int*)head->data);
  TEST_ASSERT_EQUAL(4, *(int*)HEAD_TWO->data);
  TEST_ASSERT_NULL(HEAD_THREE);
  
  clearLinkList(&head);  
}

void test_removeHead_given_list_NULL_should_form_NULL(void){
  int one=1, two=2, four=4;
  
  LinkedList *head = NULL;
  
  removeHead( &head);
  TEST_ASSERT_NULL(head);
  
  clearLinkList(&head);  
}