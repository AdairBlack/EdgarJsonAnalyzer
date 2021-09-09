#include "JsonAnalyzer.h"
#include "JsonNode.h"
#include <assert.h>

void JsonAnalyzer::jsonParseWhitespace(const char *json)
{
    const char *p = json;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
    {
        p++;
    }
    json = p;
    return;
}

int JsonAnalyzer::jsonParseNull(const char *json, JsonNode *pJsonNode)
{
    EXPECT(json, 'n');
    if('u' != json[0] || 'l' != json[1] || 'l' != json[2])
    {
        return JSON_PARSE_INVALID_VALUE;
    }
    json += 3;
    pJsonNode->jsonType = JSON_NULL;
    return JSON_PARSE_OK;
}

int JsonAnalyzer::jsonParseValue(const char *json, JsonNode *pJsonNode)
{
    switch(*json)
    {
        case 'n': return jsonParseNull(json, pJsonNode);
        case '\0': return JSON_PARSE_EXPECT_VALUE;
        default: return JSON_PARSE_INVALID_VALUE;
    }
}

int JsonAnalyzer::jsonParse(JsonNode *pJsonNode, const char *json)
{
    assert(nullptr != json);
    pJsonNode->jsonType = JSON_NULL;
    jsonParseWhitespace(json);
    return jsonParseValue(json, pJsonNode);
}