#ifndef JSON_ANALYZER_H__
#define JSON_ANALYZER_H__

#include "JsonNode.h"

#define EXPECT(json, ch) do{assert(*json == (ch)); json++;} while(0);

enum {
    JSON_PARSE_OK = 0,
    JSON_PARSE_EXPECT_VALUE,
    JSON_PARSE_INVALID_VALUE,
    JSON_PARSE_ROOT_NOT_SINGULAR
};

class JsonAnalyzer
{
private:
    void jsonParseWhitespace(const char *json);
    int jsonParseNull(const char *json, JsonNode *pJsonNode);
    int jsonParseValue(const char *json, JsonNode *pJsonNode);

public:
    int jsonParse(JsonNode *pJsonNode, const char *json);
    JsonAnalyzer() = default;
    ~JsonAnalyzer() = default;
};

#endif