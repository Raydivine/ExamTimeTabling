#include "unity.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include "LinkedListAdd.h"
#include "CException.h"

#include "ExamStruct.h"

#define HEAD_TWO      head->next
#define HEAD_THREE    head->next->next
#define HEAD_FOUR     head->next->next->next
#define HEAD_FIVE     head->next->next->next->next

Programme programmeList[]
 = {
     {.name = "RMB1", .studentNum = 10},
     {.name = "RMB2", .studentNum = 20},
     {.name = "RMB3", .studentNum = 30},
   } ;


void setUp(void){}

void tearDown(void){}

void test_removeDataFromList_given_head_is_NULL_should_throw_LL_ERR_DATA_IS_NOT_EXIST(void){
  CEXCEPTION_T err;

  LinkedList *head = NULL;

   Try{
    removeDataFromList( &head, &programmeList[0]);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  clearLinkList(head); 
}


void test_removeDataFromList_given_list_is_RMB1_RMB2_but_remove_RMB3_should_throw_LL_ERR_DATA_IS_NOT_EXIST(void){
  CEXCEPTION_T err;
  
  LinkedList *head = linkListNew(&programmeList[0]);
  addDataToTail( &head, &programmeList[1]);

  Try{
    removeDataFromList( &head, &programmeList[2]);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  clearLinkList(head);   
}

void test_removeDataFromList_given_list_RMB1_RMB2_RMB3_and_remove_RMB1_should_remove(void){

  LinkedList *head = linkListNew(&programmeList[0]);
  addDataToTail( &head, &programmeList[1]);
  addDataToTail( &head, &programmeList[2]);
  
  removeDataFromList( &head, &programmeList[0]);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL_PTR(&programmeList[1], head->data);
  TEST_ASSERT_EQUAL_PTR(&programmeList[2], HEAD_TWO->data);
  TEST_ASSERT_NULL(HEAD_TWO->next);
  clearLinkList(head);   
}

void test_removeDataFromList_given_list_RMB1_RMB2_RMB3_and_remove_RMB2_should_remove(void){

  LinkedList *head = linkListNew(&programmeList[0]);
  addDataToTail( &head, &programmeList[1]);
  addDataToTail( &head, &programmeList[2]);
  
  removeDataFromList( &head, &programmeList[1]);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL_PTR(&programmeList[0], head->data);
  TEST_ASSERT_EQUAL_PTR(&programmeList[2], HEAD_TWO->data);
  TEST_ASSERT_NULL(HEAD_TWO->next);
  clearLinkList(head);   
}

void test_removeDataFromList_given_list_RMB1_RMB2_RMB3_and_remove_RMB3_should_remove(void){

  LinkedList *head = linkListNew(&programmeList[0]);
  addDataToTail( &head, &programmeList[1]);
  addDataToTail( &head, &programmeList[2]);
  
  removeDataFromList( &head, &programmeList[2]);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL_PTR(&programmeList[0], head->data);
  TEST_ASSERT_EQUAL_PTR(&programmeList[1], HEAD_TWO->data);
  TEST_ASSERT_NULL(HEAD_TWO->next);
  clearLinkList(head);   
}


