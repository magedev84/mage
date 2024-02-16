#pragma once

#include "sqlite3.h"
#include "mage_string.h"

//----------------------------------------------------
// SQLite를 편하게 사용하기 위한 래핑 클래스
//----------------------------------------------------
class MSQLiteWrapper
{
public:
    int Open(const MString& inPath);

protected:
    sqlite3* DB = nullptr;
};



