#include <stdarg.h>
#include "zdbmm.h"

ZDB::Connection::Connection(Connection_T connection) {
  internal = connection;
};

void ZDB::Connection::setQueryTimeout(int ms) {
  Connection_setQueryTimeout(internal, ms);
}

int ZDB::Connection::getQueryTimeout() {
  return Connection_getQueryTimeout(internal);
}
void ZDB::Connection::setMaxRows(int max) {
  Connection_setMaxRows(internal, max);  
}
int ZDB::Connection::getMaxRows() {
  return Connection_getMaxRows(internal);
}
int ZDB::Connection::ping() {
  Connection_ping(internal);
}
void ZDB::Connection::clear() {
  Connection_clear(internal);
}

void ZDB::Connection::close() {
  Connection_close(internal);
}

void ZDB::Connection::beginTransaction() {
  Connection_beginTransaction(internal);
}
void ZDB::Connection::commit() {
  Connection_commit(internal);
}
void ZDB::Connection::rollback() {
  Connection_rollback(internal);
}
long long int ZDB::Connection::lastRowId() {
  return Connection_lastRowId(internal);
}
long long int ZDB::Connection::rowsChanged() {
  return Connection_rowsChanged(internal);
}
void ZDB::Connection::execute(const char *sql, ...) {
  va_list ap;
  va_start(ap, sql);
  Connection_execute(internal, sql, ap);
  va_end(ap);
}

ZDB::ResultSet* ZDB::Connection::executeQuery(const char *sql, ...) {
  va_list ap;
  ResultSet_T rs;
  va_start(ap, sql);
  rs = Connection_executeQuery(internal, sql, ap);
  va_end(ap);
  return new ZDB::ResultSet(rs);
}

ZDB::PreparedStatement* ZDB::Connection::prepareStatement(const char *sql, ...) {
  va_list ap;
  PreparedStatement_T ps;
  va_start(ap, sql);
  ps = Connection_prepareStatement(internal, sql, ap);
  va_end(ap);
  return new ZDB::PreparedStatement(ps);
}

void * ZDB::Connection::value() {
  return internal;
}
