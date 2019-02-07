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

#include <org/puzzlehead/sqleasy/binder.hpp>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

Binder::Binder(const Statement& statement) :
		m_api(statement.database().api()), m_statement(statement.object())
{
}

Binder::operator bool()
{
	return bool(m_statement);
}

int Binder::clear()
{
	return *this ? m_api->clearBindings(m_statement.get()) :
	SQLITE_MISUSE;
}

int Binder::count()
{
	return *this ? m_api->bindParameterCount(m_statement.get()) : 0;
}

int Binder::index(const std::string& name)
{
	return *this ?
			m_api->bindParameterIndex(m_statement.get(), name.c_str()) :
			INVALID_INDEX;
}

std::string Binder::name(const int index)
{
	return *this ? m_api->bindParameterName(m_statement.get(), index) : "";
}

int Binder::bindBlob(const int index, const void * value, const int size)
{
	return *this ?
			m_api->bindBlob(m_statement.get(), index, value, size, nullptr) :
			SQLITE_MISUSE;
}

int Binder::bindBlob(const std::string& name, const void * value,
		const int size)
{
	return bindBlob(index(name), value, size);
}

int Binder::bindBlob64(const int index, const void * value, const int64_t size)
{
	return *this ?
			m_api->bindBlob64(m_statement.get(), index, value, size, nullptr) :
			SQLITE_MISUSE;
}

int Binder::bindBlob64(const std::string& name, const void * value,
		const int64_t size)
{
	return bindBlob64(index(name), value, size);
}

int Binder::bindDouble(const int index, const double value)
{
	return *this ? m_api->bindDouble(m_statement.get(), index, value) :
	SQLITE_MISUSE;
}

int Binder::bindDouble(const std::string& name, const double value)
{
	return bindDouble(index(name), value);
}

int Binder::bindInt(const int index, const int value)
{
	return *this ? m_api->bindInt(m_statement.get(), index, value) :
	SQLITE_MISUSE;
}

int Binder::bindInt(const std::string& name, const int value)
{
	return bindInt(index(name), value);
}

int Binder::bindInt64(const int index, const int64_t value)
{
	return *this ? m_api->bindInt64(m_statement.get(), index, value) :
	SQLITE_MISUSE;
}

int Binder::bindInt64(const std::string& name, const int64_t value)
{
	return bindInt(index(name), value);
}

int Binder::bindNull(const int index)
{
	return *this ? m_api->bindNull(m_statement.get(), index) : SQLITE_MISUSE;
}

int Binder::bindNull(const std::string& name)
{
	return bindNull(index(name));
}

int Binder::bindText(const int index, const std::string& value)
{
	return *this ?
			m_api->bindText(m_statement.get(), index, value.c_str(),
					value.length(), nullptr) :
			SQLITE_MISUSE;
}

int Binder::bindText(const std::string& name, const std::string& value)
{
	return bindText(index(name), value);
}

int Binder::bindZeroBlob(const int index, const int size)
{
	return *this ? m_api->bindZeroblob(m_statement.get(), index, size) :
	SQLITE_MISUSE;
}

int Binder::bindZeroBlob(const std::string& name, const int size)
{
	return bindZeroBlob(index(name), size);
}

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */
