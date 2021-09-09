#ifndef JSON_NODE_H__
#define JSON_NODE_H__

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

class JsonNode
{
private:
public:
    JsonNode() = default;
    ~JsonNode() = default;

    JsonType jsonType;
};

#endif