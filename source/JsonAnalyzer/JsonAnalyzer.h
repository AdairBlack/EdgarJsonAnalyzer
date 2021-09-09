#ifndef JSON_ANALYZER_H__
#define JSON_ANALYZER_H__

#define EXPECT(json, ch) do{assert(*json == (ch)); json++;} while(0);

typedef enum
{
    JSON_NULL,
    JSON_FALSE,
    JSON_TRUE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

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