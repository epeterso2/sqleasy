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

#ifndef ORG_PUZZLEHEAD_SQLEASY_DATABASE_HPP_
#define ORG_PUZZLEHEAD_SQLEASY_DATABASE_HPP_

#include <memory>
#include <string>

#include <sqlite3.h>

#include <org/puzzlehead/sqleasy/types.hpp>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

class Database
{
public:

	explicit Database(const std::string& filename);

	Database(const std::string& filename, const int flags);

	Database(const std::string& filename, const std::string& vfs);

	Database(const std::string& filename, const int flags, const std::string& vfs);

	virtual ~Database() = default;

	explicit operator bool();

	Sqlite3DatabasePtr object() const;

	int exec(const std::string& sql);

	int errorCode();

	int extendedErrorCode();

	std::string errorMessage();

protected:

	static constexpr int DEFAULT_FLAGS = SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;

	static constexpr auto DEFAULT_VFS = "";

	Sqlite3DatabasePtr m_object = nullptr;
};

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */

#endif /* ORG_PUZZLEHEAD_SQLEASY_DATABASE_HPP_ */
