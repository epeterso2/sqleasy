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

#include <org/puzzlehead/sqleasy/database.hpp>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

Database::Database(const std::string& filename) :
		Database(filename, DEFAULT_FLAGS, DEFAULT_VFS)
{
}

Database::Database(const std::string& filename, const int flags) :
		Database(filename, flags, DEFAULT_VFS)
{
}

Database::Database(const std::string& filename, const std::string& vfs) :
		Database(filename, DEFAULT_FLAGS, vfs)
{
}

Database::Database(const std::string& filename, const int flags,
		const std::string& vfs)
{
	sqlite3 * db = nullptr;

	if (sqlite3_open_v2(filename.c_str(), &db, flags,
			vfs == "" ? nullptr : vfs.c_str()) == SQLITE_OK)
	{
		m_handle.reset(db, sqlite3_close_v2);
	}
}

Database::operator bool()
{
	return m_handle != nullptr;
}

Database::Handle Database::handle() const
{
	return m_handle;
}

int Database::exec(const std::string& sql)
{
	return m_handle == nullptr ? SQLITE_MISUSE : sqlite3_exec(m_handle.get(), sql.c_str(), nullptr, nullptr, nullptr);
}

int Database::errorCode()
{
	return m_handle == nullptr ? SQLITE_MISUSE : sqlite3_errcode(m_handle.get());
}

int Database::extendedErrorCode()
{
	return m_handle == nullptr ? SQLITE_MISUSE : sqlite3_errcode(m_handle.get());
}

std::string Database::errorMessage()
{
	return m_handle == nullptr ? "" : sqlite3_errmsg(m_handle.get());
}

std::string Database::errorString(const int errorCode)
{
	return sqlite3_errstr(errorCode);
}

}
/* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */
