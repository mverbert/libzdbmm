#include "zdbmm.h"

ZDB::PreparedStatement::PreparedStatement(PreparedStatement_T preparedStatement) {
    internal = preparedStatement;
}
void ZDB::PreparedStatement::setString(int parameterIndex, const char *x) {
    PreparedStatement_setString(internal, parameterIndex, x);
}
void ZDB::PreparedStatement::setInt(int parameterIndex, int x) {
    PreparedStatement_setInt(internal, parameterIndex, x);
}
void ZDB::PreparedStatement::setLLong(int parameterIndex, long long int x) {
    PreparedStatement_setLLong(internal, parameterIndex, x);
}
void ZDB::PreparedStatement::setDouble(int parameterIndex, double x) {
    PreparedStatement_setDouble(internal, parameterIndex, x);
}
void ZDB::PreparedStatement::setBlob(int parameterIndex, const void *x, int size) {
    PreparedStatement_setBlob(internal, parameterIndex, x, size);
}
void ZDB::PreparedStatement::execute() {
    PreparedStatement_execute(internal);
}
ZDB::ResultSet* ZDB::PreparedStatement::executeQuery() {
    ResultSet_T rs = PreparedStatement_executeQuery(internal);
    return new ZDB::ResultSet(rs);
}
long long int ZDB::PreparedStatement::rowsChanged() {
    return PreparedStatement_rowsChanged(internal);
}
