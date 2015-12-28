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
  clearLinkList(&link);
}

void test_linkListNew_given_char_ABC_should_create_link_with_data_of_ABC(void){
  char *font = "ABC";

	LinkedList *link = linkListNew(font);
  TEST_ASSERT_NOT_NULL(link);
  TEST_ASSERT_EQUAL( *font, *(char*)link->data);
  TEST_ASSERT_EQUAL_STRING( "ABC", (char*)link->data);
  TEST_ASSERT_NULL(link->next);
  clearLinkList(&link);
}

void test_linkListNew_given_NULL_should_create_link_with_data_of_NULL(void){

	LinkedList *link = linkListNew(NULL);
  TEST_ASSERT_NOT_NULL(link);
  TEST_ASSERT_NULL(link->data);
  TEST_ASSERT_NULL(link->next);
  clearLinkList(&link);
}

