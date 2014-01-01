#include "zdbmm.h"
#include "SQLExceptionmm.h"

ZDB::ConnectionPool::ConnectionPool(ZDB::URL* url) {
  this->url = url;
  TRY {
    internal = ConnectionPool_new((URL_T) url->value());
  } CATCH_RETHROW_SQL;
};

ZDB::ConnectionPool::~ConnectionPool() {
  TRY {
    ConnectionPool_free(&internal);
  } CATCH_RETHROW_SQL;
}

ZDB::URL* ZDB::ConnectionPool::getURL() {
  return url;
}

void ZDB::ConnectionPool::setInitialConnections(int connections) {
  TRY {
    ConnectionPool_setInitialConnections(internal, connections);
  } CATCH_RETHROW_SQL;
}

int ZDB::ConnectionPool::getInitialConnections() {
  TRY {
    RETURN ConnectionPool_getInitialConnections(internal);
  } CATCH_RETHROW_SQL;
}

void ZDB::ConnectionPool::setMaxConnections(int maxConnections) {
  TRY {
    ConnectionPool_setMaxConnections(internal, maxConnections);
  } CATCH_RETHROW_SQL;
}

int ZDB::ConnectionPool::getMaxConnections() {
  TRY {
    RETURN ConnectionPool_getMaxConnections(internal);
  } CATCH_RETHROW_SQL;
}

void ZDB::ConnectionPool::setConnectionTimeout(int connectionTimeout) {
  TRY {
    ConnectionPool_setConnectionTimeout(internal, connectionTimeout);
  } CATCH_RETHROW_SQL;
}

int ZDB::ConnectionPool::getConnectionTimeout() {
  TRY {
    RETURN ConnectionPool_getConnectionTimeout(internal);
  } CATCH_RETHROW_SQL;
}

void ZDB::ConnectionPool::setAbortHandler(void(*abortHandler)(const char *error)) {
  TRY {
    ConnectionPool_setAbortHandler(internal, abortHandler);
  } CATCH_RETHROW_SQL;
}

void ZDB::ConnectionPool::setReaper(int sweepInterval) {
  TRY {
    ConnectionPool_setReaper(internal, sweepInterval);
  } CATCH_RETHROW_SQL;
}

int ZDB::ConnectionPool::size() {
  TRY {
    RETURN ConnectionPool_size(internal);
  } CATCH_RETHROW_SQL;
}

int ZDB::ConnectionPool::active() {
  TRY {
    RETURN ConnectionPool_active(internal);
  } CATCH_RETHROW_SQL;
}

void ZDB::ConnectionPool::start() {
  TRY {
    ConnectionPool_start(internal);
  } CATCH_RETHROW_SQL;
}

void ZDB::ConnectionPool::stop() {
  TRY {
    ConnectionPool_stop(internal);
  } CATCH_RETHROW_SQL;
}

ZDB::Connection* ZDB::ConnectionPool::getConnection() {
  Connection_T connection;
  TRY {
    connection = ConnectionPool_getConnection(internal);
  } CATCH_RETHROW_SQL;
  return new ZDB::Connection(connection);
}

void ZDB::ConnectionPool::returnConnection(ZDB::Connection* connection) {
  TRY {
    ConnectionPool_returnConnection(internal, (Connection_T) connection->value());
  } CATCH_RETHROW_SQL;
  delete connection;
}

int ZDB::ConnectionPool::reapConnections() {
  TRY {
    RETURN ConnectionPool_reapConnections(internal);
  } CATCH_RETHROW_SQL;
}
