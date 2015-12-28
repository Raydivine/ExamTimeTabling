#include "unity.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include "LinkedListAdd.h"
#include "CException.h"

#define HEAD    head
#define HEAD1   head->next
#define HEAD2   head->next->next
#define HEAD3   head->next->next->next
#define HEAD4   head->next->next->next->next
#define HEAD5   head->next->next->next->next->next
#define HEAD6   head->next->next->next->next->next->next

int a,b,c,d,e,f;
int x,y,z,p,w;

LinkedList *head;

void setUp(void){
  // Test element , share to all test
  head = linkListNew(&f);  
  addDataToHead( &head, &e);
  addDataToHead( &head, &d);
  addDataToHead( &head, &c);
  addDataToHead( &head, &b);
  addDataToHead( &head, &a);
  
  // head = a,b,c,d,e,f  
}
void tearDown(void){
 clearLinkList(&head);
}

void test_removeDatasFromList_given_removelist_is_NULL_wILL_mantain_the_head(void){
  CEXCEPTION_T err;

  LinkedList *removeList = NULL;

  removeDatasFromList( &head, removeList);
  TEST_ASSERT_EQUAL_PTR( &a, HEAD->data );
  TEST_ASSERT_EQUAL_PTR( &b, HEAD1->data );
  TEST_ASSERT_EQUAL_PTR( &c, HEAD2->data );
  TEST_ASSERT_EQUAL_PTR( &d, HEAD3->data );
  TEST_ASSERT_EQUAL_PTR( &e, HEAD4->data );
  TEST_ASSERT_EQUAL_PTR( &f, HEAD5->data );
  TEST_ASSERT_NULL(HEAD6);

  clearLinkList(&removeList);   
}


void test_removeDatasFromList_given_list_is_NULL_should_throw_LL_ERR_DATA_IS_NOT_EXIST(void){
  CEXCEPTION_T err;
 
  head = NULL;
  LinkedList *removeList = linkListNew(&f); 

   Try{
    removeDatasFromList( &head, removeList);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)
 
  clearLinkList(&removeList); 
}

void test_removeDatasFromList_given_removelist_is_x_y_z_which_not_in_exist_in_list_should_throw_LL_ERR_DATA_IS_NOT_EXIST(void){
  CEXCEPTION_T err;

  LinkedList *removeList = linkListNew(&z); 
  addDataToHead( &removeList, &y);
  addDataToHead( &removeList, &x);
  
  Try{
    removeDatasFromList( &head, removeList);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)
  
  TEST_ASSERT_EQUAL_PTR( &a, HEAD->data );
  TEST_ASSERT_EQUAL_PTR( &b, HEAD1->data );
  TEST_ASSERT_EQUAL_PTR( &c, HEAD2->data );
  TEST_ASSERT_EQUAL_PTR( &d, HEAD3->data );
  TEST_ASSERT_EQUAL_PTR( &e, HEAD4->data );
  TEST_ASSERT_EQUAL_PTR( &f, HEAD5->data );
  TEST_ASSERT_NULL(HEAD6);

  clearLinkList(&removeList);   
}


void test_removeDatasFromList_given_removelist_is_a_b_c_should_form_head_d_e_f(void){

  LinkedList *removeList = linkListNew(&c); 
  addDataToHead( &removeList, &b);
  addDataToHead( &removeList, &a);
   
  removeDatasFromList( &head, removeList);
  TEST_ASSERT_EQUAL_PTR( &d, HEAD->data );
  TEST_ASSERT_EQUAL_PTR( &e, HEAD1->data );
  TEST_ASSERT_EQUAL_PTR( &f, HEAD2->data );
  TEST_ASSERT_NULL(HEAD3);
  
  clearLinkList(&removeList);   
}

void test_removeDatasFromList_given_removelist_is_a_b_x_because_x_at_last_so_will_remove_a_b_then_throw_err(void){
  CEXCEPTION_T err;

  LinkedList *removeList = linkListNew(&x); 
  addDataToHead( &removeList, &b);
  addDataToHead( &removeList, &a);
  
  Try{
    removeDatasFromList( &head, removeList);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  TEST_ASSERT_EQUAL_PTR( &c, HEAD->data );
  TEST_ASSERT_EQUAL_PTR( &d, HEAD1->data );
  TEST_ASSERT_EQUAL_PTR( &e, HEAD2->data );
  TEST_ASSERT_EQUAL_PTR( &f, HEAD3->data );
  TEST_ASSERT_NULL(HEAD4);
  
  clearLinkList(&removeList);   
}

void test_removeDatasFromList_given_removelist_is_x_a_b_because_x_is_infront_so_wont_remove_a_b_and_direct_throw_err(void){
  CEXCEPTION_T err;

  LinkedList *removeList = linkListNew(&a); 
  addDataToHead( &removeList, &b);
  addDataToHead( &removeList, &x);
  
  Try{
    removeDatasFromList( &head, removeList);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  TEST_ASSERT_EQUAL_PTR( &a, HEAD->data );
  TEST_ASSERT_EQUAL_PTR( &b, HEAD1->data );
  TEST_ASSERT_EQUAL_PTR( &c, HEAD2->data );
  TEST_ASSERT_EQUAL_PTR( &d, HEAD3->data );
  TEST_ASSERT_EQUAL_PTR( &e, HEAD4->data );
  TEST_ASSERT_EQUAL_PTR( &f, HEAD5->data );
  TEST_ASSERT_NULL(HEAD6);
  
  clearLinkList(&removeList);   
}

void test_removeDatasFromList_given_removelist_is_a_x_b_because_x_is_middle_a_b_so_will_remove_a_only_and_throw_err(void){
  CEXCEPTION_T err;

  LinkedList *removeList = linkListNew(&b); 
  addDataToHead( &removeList, &x);
  addDataToHead( &removeList, &a);
  
  Try{
    removeDatasFromList( &head, removeList);
    TEST_FAIL_MESSAGE("Expected LL_ERR_DATA_IS_NOT_EXIST to be thrown. But receive none");
  }Catch(err)

  TEST_ASSERT_EQUAL_PTR( &b, HEAD->data );
  TEST_ASSERT_EQUAL_PTR( &c, HEAD1->data );
  TEST_ASSERT_EQUAL_PTR( &d, HEAD2->data );
  TEST_ASSERT_EQUAL_PTR( &e, HEAD3->data );
  TEST_ASSERT_EQUAL_PTR( &f, HEAD4->data );
  TEST_ASSERT_NULL(HEAD5);
  
  clearLinkList(&removeList);   
}

