#include "unity.h"
#include "LinkedList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_linkListNew_given_number_one_should_create_link_with_data_of_one(void){
  int one = 1;

	LinkedList *link = linkListNew(&one);
  TEST_ASSERT_NOT_NULL(link);
  TEST_ASSERT_EQUAL( 1, *(int*)link->data);
  TEST_ASSERT_NULL(link->next);
  clearLinkList(link);
}

void test_linkListNew_given_char_ABC_should_create_link_with_data_of_ABC(void){
  char *font = "ABC";

	LinkedList *link = linkListNew(font);
  TEST_ASSERT_NOT_NULL(link);
  TEST_ASSERT_EQUAL( *font, *(char*)link->data);
  TEST_ASSERT_EQUAL_STRING( "ABC", (char*)link->data);
  TEST_ASSERT_NULL(link->next);
  clearLinkList(link);
}

void test_linkListNew_given_NULL_should_create_link_with_data_of_NULL(void){

	LinkedList *link = linkListNew(NULL);
  TEST_ASSERT_NOT_NULL(link);
  TEST_ASSERT_NULL(link->data);
  TEST_ASSERT_NULL(link->next);
  clearLinkList(link);
}

void test_addDataToTail_given_head_carry_one_and_add_number2_to_tail_should_from_list_of_data_one_two(void){
  int one = 1, two = 2;
  LinkedList *link = linkListNew(&one);

  addDataToTail( link, &two);
  TEST_ASSERT_NOT_NULL(link);
  TEST_ASSERT_EQUAL(1, *(int*)link->data);
  TEST_ASSERT_NOT_NULL(link->next);
  TEST_ASSERT_EQUAL(2, *(int*)link->next->data);
  TEST_ASSERT_NULL(link->next->next);
  clearLinkList(link);
}

void test_addDataToTail_given_head_carry_NULL_add_number2_to_tail_should_from_list_of_data_NULL_two(void){
  int two = 2;
  LinkedList *link = linkListNew(NULL);

  addDataToTail( link, &two);
  TEST_ASSERT_NOT_NULL(link);
  TEST_ASSERT_NULL(link->data);
  TEST_ASSERT_NOT_NULL(link->next);
  TEST_ASSERT_EQUAL(2, *(int*)link->next->data);
  clearLinkList(link);
}

void test_addDataToTail_given_head_carry_one_and_add_NULL_to_tail_should_from_list_of_data_one_NULL(void){
  int one = 1;
  LinkedList *link = linkListNew(&one);

  addDataToTail( link, NULL);
  TEST_ASSERT_NOT_NULL(link);
  TEST_ASSERT_EQUAL(1, *(int*)link->data);
  TEST_ASSERT_NOT_NULL(link->next);
  TEST_ASSERT_NULL(link->next->data);
  TEST_ASSERT_NULL(link->next->next);
  clearLinkList(link);
}