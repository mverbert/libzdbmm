#include "zdbmm.h"

ZDB::ResultSet::ResultSet(ResultSet_T resultSet) {
    internal = resultSet;
}
int ZDB::ResultSet::getColumnCount() {
    return ResultSet_getColumnCount(internal);
}
const char *ZDB::ResultSet::getColumnName(int columnIndex) {
    return ResultSet_getColumnName(internal, columnIndex);
}
long ZDB::ResultSet::getColumnSize(int columnIndex) {
    return ResultSet_getColumnSize(internal, columnIndex);
}
int ZDB::ResultSet::next() {
    return ResultSet_next(internal);
}
const char *ZDB::ResultSet::getString(int columnIndex) {
    return ResultSet_getString(internal, columnIndex);
}
const char *ZDB::ResultSet::getStringByName(const char *columnName) {
    return ResultSet_getStringByName(internal, columnName);
}
int ZDB::ResultSet::getInt(int columnIndex) {
    return ResultSet_getInt(internal, columnIndex);
}
int ZDB::ResultSet::getIntByName(const char *columnName) {
    return ResultSet_getIntByName(internal, columnName);
}
long long int ZDB::ResultSet::getLLong(int columnIndex) {
    return ResultSet_getLLong(internal, columnIndex);
}
long long int ZDB::ResultSet::getLLongByName(const char *columnName) {
    return ResultSet_getLLongByName(internal, columnName);
}
double ZDB::ResultSet::getDouble(int columnIndex) {
    return ResultSet_getDouble(internal, columnIndex);
}
double ZDB::ResultSet::getDoubleByName(const char *columnName) {
    return ResultSet_getDoubleByName(internal, columnName);
}
const void *ZDB::ResultSet::getBlob(int columnIndex, int *size) {
    return ResultSet_getBlob(internal, columnIndex, size);
}
const void *ZDB::ResultSet::getBlobByName(const char *columnName, int *size) {
    return ResultSet_getBlobByName(internal, columnName, size);
}
