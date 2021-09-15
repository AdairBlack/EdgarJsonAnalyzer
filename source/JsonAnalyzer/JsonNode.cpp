#include <assert.h>
#include "JsonNode.h"

double JsonNode::getNumber()
{
    assert(JSON_NUMBER == jsonType);
    return number;
}