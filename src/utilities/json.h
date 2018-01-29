

#ifndef JSON_H
#define JSON_H

namespace ARK
{
namespace Utilities
{

  struct JSONChar
  {
    private:
      char *jsonChars;

    public:
      JSONChar(const char *_jsonChars);

      const char *subvalueIn(const char *_key, const char *_subkey);
      const char *subarrayValueIn(const char *_key, int _pos, const char *_subkey);
  };

  /*  ARK::Utilities::JSONString jString(_jsonStr); */
  /*  jString.valueFor(_keyName); */
  struct JSONString
  {

    private:
      String jsonStr;

    public:
      JSONString(String _jsonStr);
      String valueFor(String _key);
      String subvalueFor(String _key, int _pos);
      String valueIn(String _key, String _subkey);
      String subvalueIn(String _key, String _subkey);
      String subarrayValueIn(String _key, int _pos, String _subkey);
  };

};
};




ARK::Utilities::JSONString::JSONString(String _jsonStr)
{
  this->jsonStr = _jsonStr;
};

/*    { "key1": value1, "key2": value2 }    */
String ARK::Utilities::JSONString::valueFor(String _key)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  return root[_key];
}

/*    { "key": { subValue1, subvalue2 } }    */
String ARK::Utilities::JSONString::subvalueFor(String _key, int _pos)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  return root[_key][_pos];
}

String ARK::Utilities::JSONString::valueIn(String _key, String _subkey)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  return root[_key][_subkey];
}

String ARK::Utilities::JSONString::subvalueIn(String _key, String _subkey)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  JsonObject &newRoot = root[_key];
  return newRoot[_subkey];
}

String ARK::Utilities::JSONString::subarrayValueIn(String _key, int _pos, String _subkey)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  // JsonArray& root = jsonBuffer.parseArray(this->jsonStr);
  return root[_key][_pos][_subkey];
}

ARK::Utilities::JSONChar::JSONChar(const char *_jsonChars)
{
  strcpy(this->jsonChars, _jsonChars);
};

const char *ARK::Utilities::JSONChar::subvalueIn(const char *key, const char *subkey)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonChars);
  jsonBuffer.clear();
  JsonObject &newRoot = root[key];
  return newRoot[subkey];
}
const char *ARK::Utilities::JSONChar::subarrayValueIn(const char *_key, int _pos, const char *_subkey)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  jsonBuffer.clear();
  JsonObject &root = jsonBuffer.parseObject(this->jsonChars);
  // JsonArray& root = jsonBuffer.parseArray(this->jsonChars);
  return root[_key][_pos][_subkey];
}

#endif
