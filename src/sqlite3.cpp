/*
 * MIT License
 * 
 * Copyright (c) 2019 Eric Peterson eric@puzzlehead.org
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <org/puzzlehead/sqleasy/sqlite3.hpp>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

int Sqlite3::bindBlob(sqlite3_stmt * stmt, int index, const void * value,
		int size, void (*deleter)(void *))
{
	return sqlite3_bind_blob(stmt, index, value, size, deleter);
}

int Sqlite3::bindBlob64(sqlite3_stmt * stmt, int index, const void * value,
		sqlite3_int64 size, void (*deleter)(void *))
{
	return sqlite3_bind_blob64(stmt, index, value, size, deleter);
}

int Sqlite3::bindDouble(sqlite3_stmt * stmt, int index, double value)
{
	return sqlite3_bind_double(stmt, index, value);
}

int Sqlite3::bindInt(sqlite3_stmt * stmt, int index, int value)
{
	return sqlite3_bind_int(stmt, index, value);
}

int Sqlite3::bindInt64(sqlite3_stmt * stmt, int index, sqlite3_int64 value)
{
	return sqlite3_bind_int64(stmt, index, value);

}

int Sqlite3::bindNull(sqlite3_stmt * stmt, int index)
{
	return sqlite3_bind_null(stmt, index);
}

int Sqlite3::bindParameterCount(sqlite3_stmt * stmt)
{
	return sqlite3_bind_parameter_count(stmt);
}

int Sqlite3::bindParameterIndex(sqlite3_stmt * stmt, const char * name)
{
	return sqlite3_bind_parameter_index(stmt, name);
}

const char * Sqlite3::bindParameterName(sqlite3_stmt * stmt, int index)
{
	return sqlite3_bind_parameter_name(stmt, index);
}

int Sqlite3::bindText(sqlite3_stmt * stmt, int index, const char * value,
		int size, void (*deleter)(void *))
{
	return sqlite3_bind_text(stmt, index, value, size, deleter);
}

int Sqlite3::bindText64(sqlite3_stmt * stmt, int index, const char * value,
		sqlite3_int64 size, void (*deleter)(void *), unsigned char encoding)
{
	return sqlite3_bind_text64(stmt, index, value, size, deleter, encoding);
}

int Sqlite3::bindZeroBlob(sqlite3_stmt * stmt, int index, int size)
{
	return sqlite3_bind_zeroblob(stmt, index, size);
}

int Sqlite3::bindZeroBlob64(sqlite3_stmt * stmt, int index, sqlite3_int64 size)
{
	return sqlite3_bind_zeroblob64(stmt, index, size);
}

int Sqlite3::clearBindings(sqlite3_stmt * stmt)
{
	return sqlite3_clear_bindings(stmt);
}

int Sqlite3::closeV2(sqlite3 * db)
{
	return sqlite3_close_v2(db);
}

const void * Sqlite3::columnBlob(sqlite3_stmt * stmt, int index)
{
	return sqlite3_column_blob(stmt, index);
}

int Sqlite3::columnBytes(sqlite3_stmt * stmt, int index)
{
	return sqlite3_column_bytes(stmt, index);
}

int Sqlite3::columnCount(sqlite3_stmt * stmt)
{
	return sqlite3_column_count(stmt);
}

int Sqlite3::columnInt(sqlite3_stmt * stmt, int index)
{
	return sqlite3_column_int(stmt, index);
}

sqlite3_int64 Sqlite3::columnInt64(sqlite3_stmt * stmt, int index)
{
	return sqlite3_column_int64(stmt, index);
}

const char * Sqlite3::columnName(sqlite3_stmt * stmt, int index)
{
	return sqlite3_column_name(stmt, index);
}

const unsigned char * Sqlite3::columnText(sqlite3_stmt * stmt, int index)
{
	return sqlite3_column_text(stmt, index);
}

int Sqlite3::columnType(sqlite3_stmt * stmt, int index)
{
	return sqlite3_column_type(stmt, index);
}

int Sqlite3::dataCount(sqlite3_stmt * stmt)
{
	return sqlite3_data_count(stmt);
}

int Sqlite3::dbConfig(sqlite3 * db, int op, const char * arg)
{
	return sqlite3_db_config(db, op, arg);
}

int Sqlite3::dbConfig(sqlite3 * db, int op, void * arg1, int arg2, int arg3)
{
	return sqlite3_db_config(db, op, arg1, arg2, arg3);
}

int Sqlite3::dbConfig(sqlite3 * db, int op, int arg1, int * arg2)
{
	return sqlite3_db_config(db, op, arg1, arg2);
}

int Sqlite3::errcode(sqlite3 * db)
{
	return sqlite3_errcode(db);
}

const char * Sqlite3::errmsg(sqlite3 * db)
{
	return sqlite3_errmsg(db);
}

const void * Sqlite3::errmsg16(sqlite3 * db)
{
	return sqlite3_errmsg16(db);
}

const char * Sqlite3::errstr(int errcode)
{
	return sqlite3_errstr(errcode);
}

int Sqlite3::finalize(sqlite3_stmt * stmt)
{
	return sqlite3_finalize(stmt);
}

int Sqlite3::openV2(const char * filename, sqlite3 ** db, int flags,
		const char * zVfs)
{
	return sqlite3_open_v2(filename, db, flags, zVfs);
}

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */
