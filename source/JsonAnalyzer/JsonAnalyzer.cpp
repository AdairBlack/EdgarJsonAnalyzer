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

int JsonAnalyzer::jsonParseNull(JsonContent &jsonContent, JsonNode &jsonNode)
{
    EXPECT(jsonContent.content, 'n');
    if('u' != jsonContent.content[0] || 'l' != jsonContent.content[1] || 'l' != jsonContent.content[2])
    {
        return JSON_PARSE_INVALID_VALUE;
    }
    jsonContent.content += 3;
    jsonNode.jsonType = JSON_NULL;
    return JSON_PARSE_OK;
}

int JsonAnalyzer::jsonParseTrue(JsonContent &jsonContent, JsonNode &jsonNode)
{
    EXPECT(jsonContent.content, 't');
    if('r' != jsonContent.content[0] || 'u' != jsonContent.content[1] || 'e' != jsonContent.content[2])
    {
        return JSON_PARSE_INVALID_VALUE;
    }
    jsonContent.content += 3;
    jsonNode.jsonType = JSON_TRUE;
    return JSON_PARSE_OK;
}

int JsonAnalyzer::jsonParseFalse(JsonContent &jsonContent, JsonNode &jsonNode)
{
    EXPECT(jsonContent.content, 'f');
    if('a' != jsonContent.content[0] || 'l' != jsonContent.content[1] || 's' != jsonContent.content[2] || 'e' != jsonContent.content[3])
    {
        return JSON_PARSE_INVALID_VALUE;
    }
    jsonContent.content += 4;
    jsonNode.jsonType = JSON_FALSE;
    return JSON_PARSE_OK;
}

int JsonAnalyzer::jsonParseNumber(JsonContent &jsonContent, JsonNode &jsonNode)
{
    char *end = nullptr;
    //TODO validate number
    jsonNode.number = strtod(jsonContent.content, &end);
    if(jsonContent.content == end)
    {
        return JSON_PARSE_INVALID_VALUE;
    }

    jsonContent.content = end;
    jsonNode.jsonType = JSON_NUMBER;

    return JSON_PARSE_OK;
}

int JsonAnalyzer::jsonParseValue(JsonContent &jsonContent, JsonNode &jsonNode)
{
    switch(*jsonContent.content)
    {
        case 'n': return jsonParseNull(jsonContent, jsonNode);
        case 't': return jsonParseTrue(jsonContent, jsonNode);
        case 'f': return jsonParseFalse(jsonContent, jsonNode);
        case '\0': return JSON_PARSE_EXPECT_VALUE;
        default: return jsonParseNumber(jsonContent, jsonNode);
    }
}

int JsonAnalyzer::jsonParse(JsonNode &jsonNode, const char *json)
{
    assert(nullptr != json);
    int ret = JSON_PARSE_OK;
    jsonNode.jsonType = JSON_NULL;
    JsonContent jsonContent;
    jsonContent.content = json;
    jsonParseWhitespace(jsonContent);
    if(JSON_PARSE_OK == (ret = jsonParseValue(jsonContent, jsonNode)))
    {
        jsonParseWhitespace(jsonContent);
        if(*jsonContent.content != '\0')
        {
            ret = JSON_PARSE_ROOT_NOT_SINGULAR;
        }
    }
    return ret;
}