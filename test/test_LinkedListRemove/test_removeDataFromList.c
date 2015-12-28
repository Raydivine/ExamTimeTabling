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

void test_removeDataFromList_given_head_is_NULL_should_throw_LL_ERR_DATA_IS_NOT_EXIST(void){
  CEXCEPTION_T err;
  int one=1, two=2, three=3, five=5;
  
  LinkedList *head = NULL;

   Try{
    removeDataFromList( &head, &three);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  clearLinkList(&head); 
}

void test_removeDataFromList_given_list_1_2_3_but_remove_5_should_throw_LL_ERR_DATA_IS_NOT_EXIST(void){
  CEXCEPTION_T err;
  int one=1, two=2, three=3, five=5;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &three);
  
  Try{
    removeDataFromList( &head, &five);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  clearLinkList(&head);   
}

void test_removeDataFromList_given_list_1_2_3_but_remove_NULL_should_throw_LL_ERR_DATA_IS_NOT_EXIST(void){
  CEXCEPTION_T err;
  int one=1, two=2, three=3, five=5;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &three);
  
  Try{
    removeDataFromList( &head, NULL);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  clearLinkList(&head);   
}

void test_removeDataFromList_given_list_1_and_remove_1_should_form_NULL(void){
  int one=1;
  
  LinkedList *head = linkListNew(&one);
 
  removeDataFromList( &head, &one);
  TEST_ASSERT_NULL(head);
  
  clearLinkList(&head);  
}

void test_removeDataFromList_given_list_1_2_and_remove_1_should_form_2(void){
  int one=1, two=2;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  
  removeDataFromList( &head, &one);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(2, *(int*)head->data);
  TEST_ASSERT_NULL(head->next);
  
  clearLinkList(&head);    
}

void test_removeDataFromList_given_list_1_2_3_and_but_remove_2_should_form_1_3(void){

  int one=1, two=2, three=3, five=5;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &three);
  
  removeDataFromList( &head, &two);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(1, *(int*)head->data);
  TEST_ASSERT_EQUAL(3, *(int*)HEAD_TWO->data);
  TEST_ASSERT_NULL(HEAD_THREE);
  
  clearLinkList(&head);   
}

void test_removeDataFromList_given_list_1_2_and_remove_2_should_form_1(void){
  int one=1, two=2;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  
  removeDataFromList( &head, &two);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(1, *(int*)head->data);
  TEST_ASSERT_NULL(head->next);
  
  clearLinkList(&head);    
}

