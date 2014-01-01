#include "zdbmm.h"

ZDB::SQLException::SQLException(Exception_Frame* sqlException) {
  internal = sqlException;
}
