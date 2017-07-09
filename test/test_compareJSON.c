#include "unity.h"
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "errorNode.h"
#include "Rotation.h"
#include "compareJSON.h"
#include "RedBlackTree.h"
#include "RestructureNode.h"
#include "CustomAssertions.h"
#include "CException.h"

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

void test_compareFilePath_should_compare_2_similar_files_byte_by_byte_and_return_0(void){
	int compare = 0;
	Node *fileNode1 = NULL, *fileNode2 = NULL;
	Error *e = NULL;
	char *pathName1 = "forTesting/sysmem.c";
	char *pathName2 = "forTesting/sysmem2.c";
	unsigned long long int size1 = 5555555555;
	unsigned long long int size2 = 3355555555;
	unsigned long int crc1 = 2331234567;
	unsigned long int crc2 = 2331234598;
	//Create node 1
	json_t *fileObjectName1 = json_string(pathName1);
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	fileNode1 = createNodeWithFileInfo(fileObjectName1,fileObjectSize1,fileObjectCRC1);
	//Create node 2
	json_t *fileObjectName2 = json_string(pathName2);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	fileNode2 = createNodeWithFileInfo(fileObjectName2,fileObjectSize2,fileObjectCRC2);
	//Add node 1 into err
	e = createErr(fileNode1);
	//Compare 
	compare = compareFileByte(e,fileNode2);
	TEST_ASSERT_EQUAL(compare,0);
}

void test_compareFilePath_should_compare_2_different_files_byte_by_byte_and_return_negative_1(void){
	int compare = 0;
	Node *fileNode1 = NULL, *fileNode2 = NULL;
	Error *e = NULL;
	char *pathName1 = "forTesting/Testing 1.mp3";
	char *pathName2 = "forTesting/Testing 10.jpg";
	unsigned long long int size1 = 5555555555;
	unsigned long long int size2 = 3355555555;
	unsigned long int crc1 = 2331234567;
	unsigned long int crc2 = 2331234598;
	//Create node 1
	json_t *fileObjectName1 = json_string(pathName1);
	json_t *fileObjectSize1 = json_integer(size1);
	json_t *fileObjectCRC1 = json_integer(crc1);
	fileNode1 = createNodeWithFileInfo(fileObjectName1,fileObjectSize1,fileObjectCRC1);
	//Create node 2
	json_t *fileObjectName2 = json_string(pathName2);
	json_t *fileObjectSize2 = json_integer(size2);
	json_t *fileObjectCRC2 = json_integer(crc2);
	fileNode2 = createNodeWithFileInfo(fileObjectName2,fileObjectSize2,fileObjectCRC2);
	//Add node 1 into err
	e = createErr(fileNode1);
	//Compare 
	compare = compareFileByte(e,fileNode2);
	TEST_ASSERT_EQUAL(compare,-1);
}
