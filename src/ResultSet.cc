#include "zdbmm.h"
#include "SQLExceptionmm.h"

ZDB::ResultSet::ResultSet(ResultSet_T resultSet) {
    internal = resultSet;
}
int ZDB::ResultSet::getColumnCount() {
  TRY {
    RETURN ResultSet_getColumnCount(internal);
  } CATCH_RETHROW_SQL;
}
const char *ZDB::ResultSet::getColumnName(int columnIndex) {
  TRY {
    RETURN ResultSet_getColumnName(internal, columnIndex);
  } CATCH_RETHROW_SQL;
}
long ZDB::ResultSet::getColumnSize(int columnIndex) {
  TRY {
    RETURN ResultSet_getColumnSize(internal, columnIndex);
  } CATCH_RETHROW_SQL;
}
int ZDB::ResultSet::next() {
  TRY {
    RETURN ResultSet_next(internal);
  } CATCH_RETHROW_SQL;
}
const char *ZDB::ResultSet::getString(int columnIndex) {
  TRY {
    RETURN ResultSet_getString(internal, columnIndex);
  } CATCH_RETHROW_SQL;
}
const char *ZDB::ResultSet::getStringByName(const char *columnName) {
  TRY {
    RETURN ResultSet_getStringByName(internal, columnName);
  } CATCH_RETHROW_SQL;
}
int ZDB::ResultSet::getInt(int columnIndex) {
  TRY {
    RETURN ResultSet_getInt(internal, columnIndex);
  } CATCH_RETHROW_SQL;
}
int ZDB::ResultSet::getIntByName(const char *columnName) {
  TRY {
    RETURN ResultSet_getIntByName(internal, columnName);
  } CATCH_RETHROW_SQL;
}
long long int ZDB::ResultSet::getLLong(int columnIndex) {
  TRY {
    RETURN ResultSet_getLLong(internal, columnIndex);
  } CATCH_RETHROW_SQL;
}
long long int ZDB::ResultSet::getLLongByName(const char *columnName) {
  TRY {
    RETURN ResultSet_getLLongByName(internal, columnName);
  } CATCH_RETHROW_SQL;
}
double ZDB::ResultSet::getDouble(int columnIndex) {
  TRY {
    RETURN ResultSet_getDouble(internal, columnIndex);
  } CATCH_RETHROW_SQL;
}
double ZDB::ResultSet::getDoubleByName(const char *columnName) {
  TRY {
    RETURN ResultSet_getDoubleByName(internal, columnName);
  } CATCH_RETHROW_SQL;
}
const void *ZDB::ResultSet::getBlob(int columnIndex, int *size) {
  TRY {
    RETURN ResultSet_getBlob(internal, columnIndex, size);
  } CATCH_RETHROW_SQL;
}
const void *ZDB::ResultSet::getBlobByName(const char *columnName, int *size) {
  TRY {
    RETURN ResultSet_getBlobByName(internal, columnName, size);
  } CATCH_RETHROW_SQL;
}
time_t ZDB::ResultSet::getTimestamp(int columnIndex) {
  TRY {
    RETURN ResultSet_getTimestamp(internal, columnIndex);
  } CATCH_RETHROW_SQL;
}
time_t ZDB::ResultSet::getTimestampByName(const char *columnName) {
  TRY {
    RETURN ResultSet_getTimestampByName(internal, columnName);
  } CATCH_RETHROW_SQL;
}
struct tm ZDB::ResultSet::getDateTime(int columnIndex) {
  TRY {
    RETURN ResultSet_getDateTime(internal, columnIndex);
  } CATCH_RETHROW_SQL;
}
struct tm ZDB::ResultSet::getDateTimeByName(const char *columnName) {
  TRY {
    RETURN ResultSet_getDateTimeByName(internal, columnName);
  } CATCH_RETHROW_SQL;
}
