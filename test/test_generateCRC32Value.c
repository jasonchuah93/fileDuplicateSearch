#include "unity.h"
#include "generateCRC32Value.h"

void setUp(void){}
void tearDown(void){}

//Test for checking CRC32 Value

void test_hashCRC_should_return_0_if_input_is_not_a_file_type(void){
	int checksum1=0;
	checksum1=hashCRC("forTesting");
	TEST_ASSERT_EQUAL(checksum1,0);
}
void test_hashCRC_should_be_equal_for_two_file_with_same_content_but_different_name(void){
	int checksum1=0,checksum2=0;
	checksum1=hashCRC("forTesting/Testing 5.txt");
	checksum2=hashCRC("forTesting/Testing 6.txt");
	TEST_ASSERT_EQUAL(checksum1,checksum2);
}

void test_hashCRC_should_not_be_equal_if_file_content_is_different(void){
	int checksum1=0,checksum2=0;
	checksum1=hashCRC("forTesting/Testing 1.mp3");
	checksum2=hashCRC("forTesting/Testing 10.jpg");
	TEST_ASSERT_NOT_EQUAL(checksum1,checksum2);
}

void test_hashCRC_should_not_be_equal_if_type_of_files_is_different(void){
	int checksum1=0,checksum2=0;
	checksum1=hashCRC("forTesting/Testing 7.pdf");
	checksum2=hashCRC("forTesting/Testing 4.docx");
	TEST_ASSERT_NOT_EQUAL(checksum1,checksum2);
}

void test_hashCRC_should_be_equal_for_two_file_with_same_content_but_different_name_in_excel_format(void){
	int checksum1=0,checksum2=0;
	checksum1=hashCRC("forTesting/Testing 2.xlsx");
	checksum2=hashCRC("forTesting/Testing 3.xlsx");
	TEST_ASSERT_EQUAL(checksum1,checksum2);
}
