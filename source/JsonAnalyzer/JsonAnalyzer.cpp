#include "JsonAnalyzer.h"
#include "JsonNode.h"
#include <assert.h>
#include <iostream>

using namespace std;

void JsonAnalyzer::jsonParseWhitespace(JsonContent &jsonContent)
{
    
    const char *p = jsonContent.content;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
    {
        p++;
    }
    jsonContent.content = p;
    return;
}

int JsonAnalyzer::jsonParseNull(JsonContent &jsonContent, JsonNode *pJsonNode)
{
    EXPECT(jsonContent.content, 'n');
    if('u' != jsonContent.content[0] || 'l' != jsonContent.content[1] || 'l' != jsonContent.content[2])
    {
        return JSON_PARSE_INVALID_VALUE;
    }
    jsonContent.content += 3;
    pJsonNode->jsonType = JSON_NULL;
    return JSON_PARSE_OK;
}

int JsonAnalyzer::jsonParseValue(JsonContent &jsonContent, JsonNode *pJsonNode)
{
    switch(*jsonContent.content)
    {
        case 'n': return jsonParseNull(jsonContent, pJsonNode);
        case '\0': return JSON_PARSE_EXPECT_VALUE;
        default: return JSON_PARSE_INVALID_VALUE;
    }
}

int JsonAnalyzer::jsonParse(JsonNode *pJsonNode, const char *json)
{
    assert(nullptr != json);
    pJsonNode->jsonType = JSON_NULL;
    JsonContent jsonContent;
    jsonContent.content = json;
    jsonParseWhitespace(jsonContent);
    return jsonParseValue(jsonContent, pJsonNode);
}