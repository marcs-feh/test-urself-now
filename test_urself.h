#ifndef _test_urself_h_include_
#define _test_urself_h_include_

#include <stdio.h>
#include <stdbool.h>
typedef unsigned int uint;

#ifndef TEST_URSELF_COLORLESS
#define TEST_COL_FAIL  "\e[0;31m"
#define TEST_COL_PASS  "\e[0;32m"
#define TEST_COL_TITLE "\e[1;37m"
#define TEST_COL_RESET "\e[0m"
#else
#define TEST_COL_FAIL  ""
#define TEST_COL_PASS  ""
#define TEST_COL_TITLE ""
#define TEST_COL_RESET ""
#endif

struct Test {
	const char* title;
	uint tests_count;
	uint error_count;
};

static
void testUrselfDisplayHeader(struct Test* t){
	printf("[" TEST_COL_TITLE "%s" TEST_COL_RESET "]\n", t->title);
}

static
void testUrselfAssert(struct Test* t, bool expr, const char* msg){
	t->tests_count += 1;
	if(!expr){
		t->error_count += 1;
		printf("  Failed: %s\n", msg);
	}
}

static
void testUrselfDisplayResults(struct Test* t){
	if(t->error_count > 0){
		printf(TEST_COL_FAIL "FAIL" TEST_COL_RESET);
	} else {
		printf(TEST_COL_PASS "PASS" TEST_COL_RESET);
	}
	printf(" ok in %u/%u\n", t->tests_count - t->error_count, t->tests_count);
}

#define Test_Begin(title_) struct Test _test_ = { .title = title_, .tests_count = 0, .error_count = 0}; \
	testUrselfDisplayHeader(&_test_);
#define Test_End() testUrselfDisplayResults(&_test_); return _test_.error_count;
#define Test_Log(fmt, ...) printf("  >> " fmt "\n", __VA_ARGS__);
#define Test_Proc static uint
// Test predicate.
#define Tp(expr) { testUrselfAssert(&_test_, (expr), #expr); }

#endif /* Include guard */
