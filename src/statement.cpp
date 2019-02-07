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

#include <org/puzzlehead/sqleasy/statement.hpp>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

Statement::Statement(const Database& database, const std::string& sql) :
		m_database(database)
{
	sqlite3_stmt * stmt = nullptr;

	if (m_database
			&& m_database.api()->prepareV2(m_database.object().get(),
					sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
	{
		m_object.reset(stmt, sqlite3_finalize);
	}
}

Statement::operator bool()
{
	return bool(m_object);
}

Database Statement::database() const
{
	return m_database;
}

Sqlite3StatementPtr Statement::object() const
{
	return m_object;
}

int Statement::step()
{
	return *this ? m_database.api()->step(m_object.get()) : SQLITE_MISUSE;
}

int Statement::reset()
{
	return *this ? m_database.api()->reset(m_object.get()) : SQLITE_MISUSE;
}

bool Statement::busy()
{
	return *this && (m_database.api()->stmtBusy(m_object.get()) != 0);
}

bool Statement::readOnly()
{
	return *this && (m_database.api()->stmtReadonly(m_object.get()) != 0);
}

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */
