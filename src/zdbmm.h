#include <zdb.h>

namespace ZDB {

  class URL
  {
    URL_T internal;
  public:
    URL(const char* url);
    ~URL();
    void* value();
  };

  class Connection;

  class ConnectionPool 
  {
    ConnectionPool_T internal;
    URL* url;
  public:
    ConnectionPool(URL* url);
    ~ConnectionPool();
    URL* getURL();
    void setInitialConnections(int connections);
    int getInitialConnections();
    void setMaxConnections(int maxConnections);
    int getMaxConnections();
    void setConnectionTimeout(int connectionTimeout);
    int getConnectionTimeout();
    void setAbortHandler(void(*abortHandler)(const char *error));
    void setReaper(int sweepInterval);
    int size();
    int active();
    void start();
    void stop();
    Connection* getConnection();
    void returnConnection(Connection* connection);
    int reapConnections();
  };

  class ResultSet;
  class PreparedStatement;
 
  class Connection {
    Connection_T internal;
  public:
    Connection(Connection_T connection);
    void setQueryTimeout(int ms);
    int getQueryTimeout();
    void setMaxRows(int max);
    int getMaxRows();
    int ping();
    void clear();
    void close();
    void beginTransaction();
    void commit();
    void rollback();
    long long int lastRowId();
    long long int rowsChanged();
    void execute(const char *sql, ...);
    ResultSet* executeQuery(const char *sql, ...);
    PreparedStatement* prepareStatement(const char *sql, ...);
    void* value();
  };

  class ResultSet {
    ResultSet_T internal;
  public:
    ResultSet(ResultSet_T resultSet);
    int getColumnCount();
    const char *getColumnName(int columnIndex);
    long getColumnSize(int columnIndex);
    int next();
    const char *getString(int columnIndex);
    const char *getStringByName(const char *columnName);
    int getInt(int columnIndex);
    int getIntByName(const char *columnName);
    long long int getLLong(int columnIndex);
    long long int getLLongByName(const char *columnName);
    double getDouble(int columnIndex);
    double getDoubleByName(const char *columnName);
    const void *getBlob(int columnIndex, int *size);
    const void *getBlobByName(const char *columnName, int *size);
  };

  class PreparedStatement {
    PreparedStatement_T internal;
  public:
    PreparedStatement(PreparedStatement_T preparedStatement);
    void setString(int parameterIndex, const char *x);
    void setInt(int parameterIndex, int x);
    void setLLong(int parameterIndex, long long int x);
    void setDouble(int parameterIndex, double x);
    void setBlob(int parameterIndex, const void *x, int size);
    void execute();
    ResultSet* executeQuery();
    long long int rowsChanged();
  };

};
