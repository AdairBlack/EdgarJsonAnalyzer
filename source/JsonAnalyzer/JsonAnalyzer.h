#ifndef EDGARJSON_H__
#define EDGARJSON_H__

typedef enum{JSON_NULL, JSON_FALSE, JSON_TRUE, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT} JsonType;

class JsonAnalyzer
{
private:
public:
    JsonType jsonType;
    int jsonParse();
    JsonAnalyzer(/* args */);
    ~JsonAnalyzer();
};

JsonAnalyzer::JsonAnalyzer(/* args */)
{
}

JsonAnalyzer::~JsonAnalyzer()
{
}

#endif