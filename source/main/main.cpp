#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <memory>

#include "../JsonAnalyzer/JsonAnalyzer.h"
#include "../JsonAnalyzer/JsonNode.h"

using namespace std;

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do {\
        test_count++;\
        if (equality)\
            test_pass++;\
        else {\
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
            main_ret = 1;\
        }\
    } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

static void testParseNull()
{
    JsonAnalyzer jsonAnalyzer;
    JsonNode jsonNode;
    jsonNode.jsonType = JSON_NULL;
    EXPECT_EQ_INT(JSON_PARSE_OK, jsonAnalyzer.jsonParse(&jsonNode, "null"));
    EXPECT_EQ_INT(JSON_NULL, jsonNode.jsonType);
    return;
}

static void testParseExpectValue()
{
    JsonNode jsonNode;
}

int main()
{
    printf("*****************Edgar's JsonAnalyzer*****************\n");

    

    return 0;
}
