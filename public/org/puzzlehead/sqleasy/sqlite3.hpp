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

#ifndef ORG_PUZZLEHEAD_SQLEASY_SQLITE3_HPP_
#define ORG_PUZZLEHEAD_SQLEASY_SQLITE3_HPP_

#include <sqlite3.h>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

class Sqlite3
{
public:

	Sqlite3() = default;

	virtual ~Sqlite3() = default;

	virtual int bindBlob(sqlite3_stmt * stmt, int index, const void * value,
			int size, void (*deleter)(void *));

	virtual int bindBlob64(sqlite3_stmt * stmt, int index, const void * value,
			sqlite3_int64 size, void (*deleter)(void *));

	virtual int bindDouble(sqlite3_stmt * stmt, int index, double value);

	virtual int bindInt(sqlite3_stmt * stmt, int index, int value);

	virtual int bindInt64(sqlite3_stmt * stmt, int index, sqlite3_int64 value);

	virtual int bindNull(sqlite3_stmt * stmt, int index);

	virtual int bindParameterCount(sqlite3_stmt * stmt);

	virtual int bindParameterIndex(sqlite3_stmt * stmt, const char * name);

	virtual const char * bindParameterName(sqlite3_stmt * stmt, int index);

	virtual int bindText(sqlite3_stmt * stmt, int index, const char * value,
			int size, void (*deleter)(void *));

	virtual int bindText64(sqlite3_stmt * stmt, int index, const char * value,
			sqlite3_int64 size, void (*deleter)(void *),
			unsigned char encoding);

	virtual int bindZeroBlob(sqlite3_stmt * stmt, int index, int size);

	virtual int bindZeroBlob64(sqlite3_stmt * stmt, int index,
			sqlite3_int64 size);

	virtual int clearBindings(sqlite3_stmt * stmt);

	virtual int closeV2(sqlite3 * db);

	virtual const void * columnBlob(sqlite3_stmt * stmt, int index);

	virtual int columnBytes(sqlite3_stmt * stmt, int);

	virtual int columnCount(sqlite3_stmt * stmt);

	virtual double columnDouble(sqlite3_stmt * stmt, int index);

	virtual int columnInt(sqlite3_stmt * stmt, int index);

	virtual sqlite3_int64 columnInt64(sqlite3_stmt * stmt, int index);

	virtual const char * columnName(sqlite3_stmt * stmt, int index);

	virtual const unsigned char * columnText(sqlite3_stmt * stmt, int index);

	virtual int columnType(sqlite3_stmt * stmt, int);

	virtual int dataCount(sqlite3_stmt * stmt);

	virtual int dbConfig(sqlite3 * db, int op, const char * arg);

	virtual int dbConfig(sqlite3 * db, int op, void * arg1, int arg2, int arg3);

	virtual int dbConfig(sqlite3 * db, int op, int arg1, int * arg2);

	virtual int errcode(sqlite3 * db);

	virtual const char * errmsg(sqlite3 * db);

	virtual const void * errmsg16(sqlite3 * db);

	virtual const char * errstr(int errcode);

	virtual int exec(sqlite3* db, const char * sql,
			int (*callback)(void *, int, char **, char **), void * arg,
			char ** errmsg);

	virtual int extendedErrcode(sqlite3 * db);

	virtual int finalize(sqlite3_stmt * stmt);

	virtual int openV2(const char * filename, sqlite3 ** db, int flags,
			const char * zVfs);

	virtual int prepareV2(sqlite3 * db, const char * sql, int nByte,
			sqlite3_stmt * stmt, const char ** tail);

	virtual int reset(sqlite3_stmt * stmt);

	virtual int step(sqlite3_stmt * stmt);

	virtual int stmtBusy(sqlite3_stmt * stmt);
};

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */

#endif /* ORG_PUZZLEHEAD_SQLEASY_SQLITE3_HPP_ */
