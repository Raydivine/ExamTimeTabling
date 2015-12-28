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

void test_returnHead_given_list_1_should_form_NULL_and_return_1(void){
  int one=1;
  
  LinkedList *remove, *head = linkListNew(&one);
 
  remove = returnHead(&head);
  TEST_ASSERT_NOT_NULL(remove);
  TEST_ASSERT_EQUAL(1, *(int*)remove->data);
  TEST_ASSERT_NULL(remove->next);

  TEST_ASSERT_NULL(head);
  
  clearLinkList(&head); 
}

void test_returnHead_given_list_1_2_should_form_2and_return_1(void){
  int one=1, two=2;
  
  LinkedList *remove, *head = linkListNew(&one);
  addDataToTail( &head, &two);
  
  remove = returnHead(&head);
  TEST_ASSERT_NOT_NULL(remove);
  TEST_ASSERT_EQUAL(1, *(int*)remove->data);
  TEST_ASSERT_NULL(remove->next);
  
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(2, *(int*)head->data);
  TEST_ASSERT_NULL(HEAD_TWO);
  
  clearLinkList(&head);  
}

void test_returnHead_given_list_1_2_4_should_form_2_4_and_return_1(void){
  int one=1, two=2, four=4;
  
  LinkedList *remove, *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &four);
  
  remove = returnHead(&head);
  TEST_ASSERT_NOT_NULL(remove);
  TEST_ASSERT_EQUAL(1, *(int*)remove->data);
  TEST_ASSERT_NULL(remove->next);
  
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(2, *(int*)head->data);
  TEST_ASSERT_EQUAL(4, *(int*)HEAD_TWO->data);
  TEST_ASSERT_NULL(HEAD_THREE);
  
  clearLinkList(&head);  
}

void test_returnHead_given_list_NULL_should_return_NULL(void){

  
  LinkedList *remove, *head = NULL;
  
  remove = returnHead(&head);
  TEST_ASSERT_NULL(remove);
  TEST_ASSERT_NULL(head);
  
  clearLinkList(&head);  
}