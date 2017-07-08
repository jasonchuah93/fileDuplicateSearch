#include "unity.h"
#include "compareJSON.h"
#include "Node.h"
#include "errorNode.h"

void setUp(void){}
void tearDown(void){}

void test_compareFileSize_should_compare_2_files_size_and_return_1(void){
	Node *rootNodePtr = NULL,*targetNodePtr = NULL;
	int compare = 0;
	unsigned long long int size1 = 5555555555;
	unsigned long long int size2 = 3333333333;
	unsigned long int crc1 = 1231234567;
	unsigned long int crc2 = 2331234567;
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	
	rootNodePtr = createNode(fileObjectSize1,fileObjectCRC1);
	targetNodePtr = createNode(fileObjectSize2,fileObjectCRC2);
	
	compare = compareFileSize(&rootNodePtr,targetNodePtr);
	TEST_ASSERT_EQUAL(1,compare);
	
	free(rootNodePtr);
	free(targetNodePtr);
}

void test_compareFileSize_should_compare_2_files_size_and_return_negative_1(void){
	Node *rootNodePtr = NULL,*targetNodePtr = NULL;
	int compare = 0;
	unsigned long long int size1 = 2345678945;
	unsigned long long int size2 = 3333333333;
	unsigned long int crc1 = 1231234567;
	unsigned long int crc2 = 2331234567;
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	
	rootNodePtr = createNode(fileObjectSize1,fileObjectCRC1);
	targetNodePtr = createNode(fileObjectSize2,fileObjectCRC2);
	
	compare = compareFileSize(&rootNodePtr,targetNodePtr);
	TEST_ASSERT_EQUAL(-1,compare);
	
	free(rootNodePtr);
	free(targetNodePtr);
}

void test_compareFileSize_should_compare_2_files_size_and_call_compareFileCRC_to_return_1(void){
	Node *rootNodePtr = NULL,*targetNodePtr = NULL;
	int compare = 0;
	unsigned long long int size1 = 2345678945;
	unsigned long long int size2 = 2345678945;
	unsigned long int crc1 = 4294967291;
	unsigned long int crc2 = 2331234567;
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	
	rootNodePtr = createNode(fileObjectSize1,fileObjectCRC1);
	targetNodePtr = createNode(fileObjectSize2,fileObjectCRC2);
	
	compare = compareFileSize(&rootNodePtr,targetNodePtr);
	TEST_ASSERT_EQUAL(1,compare);
	
	free(rootNodePtr);
	free(targetNodePtr);
}

void test_compareFileSize_should_compare_2_files_size_and_call_compareFileCRC_to_return_negative_1(void){
	Node *rootNodePtr = NULL,*targetNodePtr = NULL;
	int compare = 0;
	unsigned long long int size1 = 2345678945;
	unsigned long long int size2 = 2345678945;
	unsigned long int crc1 = 1231234567;
	unsigned long int crc2 = 2331234567;
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	
	rootNodePtr = createNode(fileObjectSize1,fileObjectCRC1);
	targetNodePtr = createNode(fileObjectSize2,fileObjectCRC2);
	
	compare = compareFileSize(&rootNodePtr,targetNodePtr);
	TEST_ASSERT_EQUAL(-1,compare);
	
	free(rootNodePtr);
	free(targetNodePtr);
}

void test_compareFileSize_should_compare_2_files_size_and_call_compareFileCRC_to_return_0(void){
	Node *rootNodePtr = NULL,*targetNodePtr = NULL;
	int compare = 0;
	unsigned long long int size1 = 2345678945;
	unsigned long long int size2 = 2345678945;
	unsigned long int crc1 = 2331234567;
	unsigned long int crc2 = 2331234567;
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	
	rootNodePtr = createNode(fileObjectSize1,fileObjectCRC1);
	targetNodePtr = createNode(fileObjectSize2,fileObjectCRC2);
	
	compare = compareFileSize(&rootNodePtr,targetNodePtr);
	TEST_ASSERT_EQUAL(0,compare);
	
	free(rootNodePtr);
	free(targetNodePtr);
}

void test_compareFileCRC_should_compare_2_files_size_and_return_1(void){
	Node *rootNodePtr = NULL,*targetNodePtr = NULL;
	int compare = 0;
	unsigned long long int size1 = 5555555555;
	unsigned long long int size2 = 3333333333;
	unsigned long int crc1 = 2331234567;
	unsigned long int crc2 = 1231234567;
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	
	rootNodePtr = createNode(fileObjectSize1,fileObjectCRC1);
	targetNodePtr = createNode(fileObjectSize2,fileObjectCRC2);
	
	compare = compareFileCRC(&rootNodePtr,targetNodePtr);
	TEST_ASSERT_EQUAL(1,compare);
	
	free(rootNodePtr);
	free(targetNodePtr);
}

void test_compareFileCRC_should_compare_2_files_size_and_return_negative_1(void){
	Node *rootNodePtr = NULL,*targetNodePtr = NULL;
	int compare = 0;
	unsigned long long int size1 = 5555555555;
	unsigned long long int size2 = 3333333333;
	unsigned long int crc1 = 1231234567;
	unsigned long int crc2 = 2331234567;
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	
	rootNodePtr = createNode(fileObjectSize1,fileObjectCRC1);
	targetNodePtr = createNode(fileObjectSize2,fileObjectCRC2);
	
	compare = compareFileCRC(&rootNodePtr,targetNodePtr);
	TEST_ASSERT_EQUAL(-1,compare);
	
	free(rootNodePtr);
	free(targetNodePtr);
}

void test_compareFileCRC_should_compare_2_files_size_and_return_0(void){
	Node *rootNodePtr = NULL,*targetNodePtr = NULL;
	int compare = 0;
	unsigned long long int size1 = 5555555555;
	unsigned long long int size2 = 3333333333;
	unsigned long int crc1 = 2331234567;
	unsigned long int crc2 = 2331234567;
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	
	rootNodePtr = createNode(fileObjectSize1,fileObjectCRC1);
	targetNodePtr = createNode(fileObjectSize2,fileObjectCRC2);
	
	compare = compareFileCRC(&rootNodePtr,targetNodePtr);
	TEST_ASSERT_EQUAL(0,compare);
	
	free(rootNodePtr);
	free(targetNodePtr);
}

void test_compareFilePath_should_compare_2_files_byte_by_byte(void){
	int compare = 0;
	Node *rootNodePtr = NULL,*targetNodePtr = NULL;
	Error *rootErrPtr = NULL,*targetErrPtr = NULL;
	char *pathName1 = "forTesting/Testing 1.mp3";
	char *pathName2 = "forTesting/Testing 10.jpg";
	unsigned long long int size1 = 5555555555;
	unsigned long long int size2 = 3333333333;
	unsigned long int crc1 = 2331234567;
	unsigned long int crc2 = 2331234567;
	//Create node 1
	json_t *fileObjectName1 = json_string(pathName1);
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	rootNodePtr = createNodeWithFileInfo(fileObjectName1,fileObjectSize1,fileObjectCRC1);
	//Create node 2
	json_t *fileObjectName2 = json_string(pathName2);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	targetNodePtr = createNodeWithFileInfo(fileObjectName2,fileObjectSize2,fileObjectCRC2);
	
	
}