#include "zdbmm.h"
#include "SQLExceptionmm.h"

ZDB::URL::URL(const char * url) {
  TRY {
    internal = URL_new(url);
  } CATCH_RETHROW_SQL;
};

ZDB::URL::~URL() {
  TRY {
    URL_free(&internal);	
  } CATCH_RETHROW_SQL;
}

void * ZDB::URL::value() {
  return internal;
}
