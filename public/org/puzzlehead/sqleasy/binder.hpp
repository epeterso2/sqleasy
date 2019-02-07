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

#ifndef ORG_PUZZLEHEAD_SQLEASY_BINDER_HPP_
#define ORG_PUZZLEHEAD_SQLEASY_BINDER_HPP_

#include <cstdint>
#include <string>
#include <vector>

#include <sqlite3.h>

#include <org/puzzlehead/sqleasy/statement.hpp>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

class Binder
{
public:

	explicit Binder(const Statement& statement);

	virtual ~Binder() = default;

	explicit operator bool();

	int clear();

	int count();

	int index(const std::string& name);

	std::string name(const int index);

	int bindBlob(const int index, const void * value, const int size);

	int bindBlob(const std::string& name, const void * value, const int size);

	int bindBlob64(const int index, const void * value, const int64_t size);

	int bindBlob64(const std::string& name, const void * value, const int64_t size);

	int bindDouble(const int index, const double value);

	int bindDouble(const std::string& name, const double value);

	int bindInt(const int index, const int value);

	int bindInt(const std::string& name, const int value);

	int bindInt64(const int index, const int64_t value);

	int bindInt64(const std::string& name, const int64_t value);

	int bindNull(const int index);

	int bindNull(const std::string& name);

	int bindText(const int index, const std::string& value);

	int bindText(const std::string& name, const std::string& value);

	int bindZeroBlob(const int index, const int size);

	int bindZeroBlob(const std::string& name, const int size);

protected:

	static constexpr int INVALID_INDEX = 0;

	Sqlite3Api::SharedPtr m_api = nullptr;

	Sqlite3StatementPtr m_statement = nullptr;
};

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */

#endif /* ORG_PUZZLEHEAD_SQLEASY_BINDER_HPP_ */
