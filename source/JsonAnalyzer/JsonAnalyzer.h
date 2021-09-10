#ifndef JSON_ANALYZER_H__
#define JSON_ANALYZER_H__

#include "JsonNode.h"
#include "JsonContent.h"

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
    void jsonParseWhitespace(JsonContent &jsonContent);
    int jsonParseNull(JsonContent &jsonContent, JsonNode &jsonNode);
    int jsonParseValue(JsonContent &jsonContent, JsonNode &jsonNode);

public:
    int jsonParse(JsonNode &jsonNode, const char *json);
    JsonAnalyzer() = default;
    ~JsonAnalyzer() = default;
};

#endif