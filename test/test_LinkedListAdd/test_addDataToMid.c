#include "unity.h"
#include "LinkedList.h"
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

void test_addDataToMid_given_head_is_NULL_should_throw_LL_ERR_DATA_IS_NOT_EXIST(void){
  CEXCEPTION_T err;
  int one=1, two=2, three=3, five=5;
  
  LinkedList *head = NULL;

   Try{
    addDataToMid( &head, &three, &five);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  clearLinkList(&head); 
}

void test_addDataToMid_given_list_1_2_3_and_add_data_after_5_should_throw_LL_ERR_DATA_IS_NOT_EXIST(void){
  CEXCEPTION_T err;
  int one=1, two=2, three=3, five=5;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &three);
  
  Try{
    addDataToMid( &head, &three, &five);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  clearLinkList(&head);   
}

void test_addDataToMid_given_list_1_and_add_5_after_1_should_form_1_5(void){
  int one=1, five=5;
  
  LinkedList *head = linkListNew(&one);
 
  addDataToMid( &head, &five, &one);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(1, *(int*)head->data);
  TEST_ASSERT_EQUAL(5, *(int*)HEAD_TWO->data);
  TEST_ASSERT_NULL(HEAD_THREE);

  clearLinkList(&head);  
}

void test_addDataToMid_given_list_1_2_3_and_add_5_after_2_should_form_1_2_5_3(void){
  int one=1, two=2, three=3, five=5;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail( &head, &two);
  addDataToTail( &head, &three);
  
  addDataToMid( &head, &five, &two);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(1, *(int*)head->data);
  TEST_ASSERT_EQUAL(2, *(int*)HEAD_TWO->data);
  TEST_ASSERT_EQUAL(5, *(int*)HEAD_THREE->data);
  TEST_ASSERT_EQUAL(3, *(int*)HEAD_FOUR->data);
  TEST_ASSERT_NULL(HEAD_FIVE);

  clearLinkList(&head);  
}

void test_addDataToMid_given_list_1_2_3_and_add_NULL_after_2_should_form_1_2_NULL_3(void){
  int one=1, two=2, three=3;
  
  LinkedList *head = linkListNew(&one);
  addDataToTail(&head,&two);
  addDataToTail(&head,&three);
  
  addDataToMid(&head, NULL, &two);
  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_EQUAL(1, *(int*)head->data);
  TEST_ASSERT_EQUAL(2, *(int*)HEAD_TWO->data);
  TEST_ASSERT_NOT_NULL (HEAD_THREE);
  TEST_ASSERT_NULL (HEAD_THREE->data);
  TEST_ASSERT_EQUAL(3, *(int*)HEAD_FOUR->data);
  TEST_ASSERT_NULL(HEAD_FIVE);

  clearLinkList(&head);  
}



