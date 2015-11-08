#include "unity.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
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

void test_addDataToTail_given_head_is_NULL_and_add_RMB1_should_form_head_is_RMB1(void){

  LinkedList *head = NULL;

  addDataToTail( &head, &programmeList[0]);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL_PTR(&programmeList[0], head->data);
  TEST_ASSERT_NULL(head->next);
  clearLinkList(head);
}

void test_addDataToTail_given_head_is_RMB1_and_add_RMB2_should_add(void){

  LinkedList *head = linkListNew(&programmeList[0]);

  addDataToTail( &head, &programmeList[1]);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL_PTR(&programmeList[0], head->data);
  TEST_ASSERT_EQUAL_PTR(&programmeList[1], HEAD_TWO->data);
  TEST_ASSERT_NULL(HEAD_TWO->next);
  clearLinkList(head);
}

void test_addDataToTail_given_list_is_RMB1_RMB2_and_add_RMB3_should_add(void){

  LinkedList *head = linkListNew(&programmeList[0]);
  addDataToTail( &head, &programmeList[1]);
  
  addDataToTail( &head, &programmeList[2]);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL_PTR(&programmeList[0], head->data);
  TEST_ASSERT_EQUAL_PTR(&programmeList[1], HEAD_TWO->data);
  TEST_ASSERT_EQUAL_PTR(&programmeList[2], HEAD_THREE->data);
  TEST_ASSERT_NULL(HEAD_THREE->next);
  clearLinkList(head);
}