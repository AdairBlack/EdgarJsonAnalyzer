#include "JsonAnalyzer.h"

#ifndef JSON_NODE_H__
#define JSON_NODE_H__

class JsonNode
{
private:
public:
    JsonNode() = default;
    ~JsonNode() = default;

    JsonType jsonType;
};

#endif