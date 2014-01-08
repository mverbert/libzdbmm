#include "zdbmm.h"
#include "SQLExceptionmm.h"

ZDB::PreparedStatement::PreparedStatement(PreparedStatement_T preparedStatement) {
    internal = preparedStatement;
}

void ZDB::PreparedStatement::setString(int parameterIndex, const char *x) {
  TRY {
    PreparedStatement_setString(internal, parameterIndex, x);
  } CATCH_RETHROW_SQL;
}
void ZDB::PreparedStatement::setInt(int parameterIndex, int x) {
  TRY {
    PreparedStatement_setInt(internal, parameterIndex, x);
  } CATCH_RETHROW_SQL;
}
void ZDB::PreparedStatement::setLLong(int parameterIndex, long long x) {
  TRY {
    PreparedStatement_setLLong(internal, parameterIndex, x);
  } CATCH_RETHROW_SQL;
}
void ZDB::PreparedStatement::setDouble(int parameterIndex, double x) {
  TRY {
    PreparedStatement_setDouble(internal, parameterIndex, x);
  } CATCH_RETHROW_SQL;
}
void ZDB::PreparedStatement::setBlob(int parameterIndex, const void *x, int size) {
  TRY {
    PreparedStatement_setBlob(internal, parameterIndex, x, size);
  } CATCH_RETHROW_SQL;
}
void ZDB::PreparedStatement::setTimestamp(int parameterIndex, time_t x) {
  TRY {
    PreparedStatement_setTimestamp(internal, parameterIndex, x);
  } CATCH_RETHROW_SQL;
}
void ZDB::PreparedStatement::execute() {
  TRY {
    PreparedStatement_execute(internal);
  } CATCH_RETHROW_SQL;
}
ZDB::ResultSet* ZDB::PreparedStatement::executeQuery() {
  TRY {
    ResultSet_T rs = PreparedStatement_executeQuery(internal);
    RETURN new ZDB::ResultSet(rs);
  } CATCH_RETHROW_SQL;
}
long long ZDB::PreparedStatement::rowsChanged() {
  TRY {
    RETURN PreparedStatement_rowsChanged(internal);
  } CATCH_RETHROW_SQL;
}
