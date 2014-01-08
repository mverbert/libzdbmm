#include <stdarg.h>
#include "zdbmm.h"
#include "SQLExceptionmm.h"

ZDB::Connection::Connection(Connection_T connection) {
  internal = connection;
}

void ZDB::Connection::setQueryTimeout(int ms) {
  TRY {
    Connection_setQueryTimeout(internal, ms);
  } CATCH_RETHROW_SQL;
}

int ZDB::Connection::getQueryTimeout() {
  TRY {
    RETURN Connection_getQueryTimeout(internal);
  } CATCH_RETHROW_SQL;
}

void ZDB::Connection::setMaxRows(int max) {
  TRY {
    Connection_setMaxRows(internal, max);  
  } CATCH_RETHROW_SQL;
}
int ZDB::Connection::getMaxRows() {
  TRY {
    RETURN Connection_getMaxRows(internal);
  } CATCH_RETHROW_SQL;
}
int ZDB::Connection::ping() {
  TRY {
    Connection_ping(internal);
  } CATCH_RETHROW_SQL;
}
void ZDB::Connection::clear() {
  TRY {
    Connection_clear(internal);
  } CATCH_RETHROW_SQL;
}

void ZDB::Connection::close() {
  TRY {
    Connection_close(internal);
  } CATCH_RETHROW_SQL;
}

void ZDB::Connection::beginTransaction() {
  TRY {
    Connection_beginTransaction(internal);
  } CATCH_RETHROW_SQL;
}
void ZDB::Connection::commit() {
  TRY {
    Connection_commit(internal);
  } CATCH_RETHROW_SQL;
}
void ZDB::Connection::rollback() {
  TRY {
    Connection_rollback(internal);
  } CATCH_RETHROW_SQL;
}
long long ZDB::Connection::lastRowId() {
  TRY {
    RETURN Connection_lastRowId(internal);
  } CATCH_RETHROW_SQL;
}
long long ZDB::Connection::rowsChanged() {
  TRY {
    RETURN Connection_rowsChanged(internal);
  } CATCH_RETHROW_SQL;
}
void ZDB::Connection::execute(const char *sql, ...) {
  TRY {
    va_list ap;
    va_start(ap, sql);
    Connection_execute(internal, sql, ap);
    va_end(ap);
  } CATCH_RETHROW_SQL;
}

ZDB::ResultSet* ZDB::Connection::executeQuery(const char *sql, ...) {
  TRY {
    va_list ap;
    ResultSet_T rs;
    va_start(ap, sql);
    rs = Connection_executeQuery(internal, sql, ap);
    va_end(ap);
    RETURN new ZDB::ResultSet(rs);
  } CATCH_RETHROW_SQL;
}

ZDB::PreparedStatement* ZDB::Connection::prepareStatement(const char *sql, ...) {
  TRY {
    va_list ap;
    PreparedStatement_T ps;
    va_start(ap, sql);
    ps = Connection_prepareStatement(internal, sql, ap);
    va_end(ap);
    RETURN new ZDB::PreparedStatement(ps);
  } CATCH_RETHROW_SQL;
}

void * ZDB::Connection::value() {
  return internal;
}
