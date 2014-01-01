#include <zdb.h>

#ifndef CATCH_RETHROW_SQL
# define CATCH_RETHROW_SQL ELSE { throw new ZDB::SQLException(&Exception_frame); } END_TRY
#endif
