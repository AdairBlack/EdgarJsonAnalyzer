#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <memory>

#include "../JsonAnalyzer/JsonAnalyzer.h"
#include "../JsonAnalyzer/JsonNode.h"
#include "../JsonAnalyzer/JsonContent.h"

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
    JsonAnalyzer jsonAnalyzer;
    JsonNode jsonNode;

    jsonNode.jsonType = JSON_FALSE;
    EXPECT_EQ_INT(JSON_PARSE_EXPECT_VALUE, jsonAnalyzer.jsonParse(&jsonNode, ""));
    EXPECT_EQ_INT(JSON_NULL, jsonNode.jsonType);

    jsonNode.jsonType = JSON_FALSE;
    EXPECT_EQ_INT(JSON_PARSE_EXPECT_VALUE, jsonAnalyzer.jsonParse(&jsonNode, " "));
    EXPECT_EQ_INT(JSON_NULL, jsonNode.jsonType);
    return;
}

static void testParseInvalidValue()
{
    JsonAnalyzer jsonAnalyzer;
    JsonNode jsonNode;

    jsonNode.jsonType = JSON_FALSE;
    EXPECT_EQ_INT(JSON_PARSE_INVALID_VALUE, jsonAnalyzer.jsonParse(&jsonNode, "nul"));
    EXPECT_EQ_INT(JSON_NULL, jsonNode.jsonType);

    jsonNode.jsonType = JSON_FALSE;
    EXPECT_EQ_INT(JSON_PARSE_INVALID_VALUE, jsonAnalyzer.jsonParse(&jsonNode, "?"));
    EXPECT_EQ_INT(JSON_NULL, jsonNode.jsonType);

    return;
}

static void testParseRootNotSingular()
{
    JsonAnalyzer jsonAnalyzer;
    JsonNode jsonNode;

    jsonNode.jsonType = JSON_FALSE;
    EXPECT_EQ_INT(JSON_PARSE_ROOT_NOT_SINGULAR, jsonAnalyzer.jsonParse(&jsonNode, "null x"));
    EXPECT_EQ_INT(JSON_NULL, jsonNode.jsonType);

    return;
}

static void testParse()
{
    testParseNull();
    testParseExpectValue();
    testParseInvalidValue();
    testParseRootNotSingular();
    return;
}

int main()
{
    cout << "*****************Edgar's JsonAnalyzer Test*****************" << endl;
    testParse();

    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
    

    return 0;
}
