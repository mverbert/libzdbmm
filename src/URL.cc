#include "zdbmm.h"

ZDB::URL::URL(const char * url) {
  internal = URL_new(url);
};

ZDB::URL::~URL() {
  URL_free(&internal);	
}

void * ZDB::URL::value() {
  return internal;
}
