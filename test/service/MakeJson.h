#ifndef MAKEJSON_H
#define MAKEJSON_H

#include <iostream>

#include "jsoncpp/json/json.h"

using namespace std;

class MakeJson
{
    public:
    MakeJson(string fpath);
    string generate_token();


};

#endif // MAKEJSON_H