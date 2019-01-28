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

#include <org/puzzlehead/sqleasy/database_config.hpp>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

DatabaseConfig::Option::Option(const Database& database, const int option) :
		m_database(database), m_option(option)
{
}

DatabaseConfig::Option::operator bool()
{
	return bool(m_database) && m_option != INVALID_OPTION;
}

int DatabaseConfig::Option::setEnabled(const bool enabled)
{
	return bool(m_database) ?
			sqlite3_db_config(m_database.handle().get(), m_option,
					enabled ? ENABLED : DISABLED, nullptr) :
			SQLITE_MISUSE;
}

int DatabaseConfig::Option::enable()
{
	return setEnabled(true);
}

int DatabaseConfig::Option::disable()
{
	return setEnabled(false);
}

int DatabaseConfig::Option::enabled(bool& enabled)
{
	int result = SQLITE_MISUSE;

	if (bool(m_database))
	{
		enabled = false;
		result = sqlite3_db_config(m_database.handle().get(), m_option, UNCHANGED, &enabled);
	}

	return result;
}

DatabaseConfig::DatabaseConfig(const Database& database) :
		m_database(database)
{
}

DatabaseConfig::Option DatabaseConfig::foreignKeysOption()
{
#ifdef SQLITE_DBCONFIG_ENABLE_FKEY
	return Option(m_database, SQLITE_DBCONFIG_ENABLE_FKEY);
#else
	return Option(m_database, INVALID_OPTION);
#endif
}

DatabaseConfig::Option DatabaseConfig::triggersOption()
{
#ifdef SQLITE_DBCONFIG_ENABLE_TRIGGER
	return Option(m_database, SQLITE_DBCONFIG_ENABLE_TRIGGER);
#else
	return Option(m_database, INVALID_OPTION);
#endif
}

DatabaseConfig::Option DatabaseConfig::fts3TokenizerOption()
{
#ifdef SQLITE_DBCONFIG_ENABLE_FTS3_TOKENIZER
	return Option(m_database, SQLITE_DBCONFIG_ENABLE_FTS3_TOKENIZER);
#else
	return Option(m_database, INVALID_OPTION);
#endif
}

DatabaseConfig::Option DatabaseConfig::loadExtensionOption()
{
#ifdef SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION
	return Option(m_database, SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION);
#else
	return Option(m_database, INVALID_OPTION);
#endif
}

DatabaseConfig::Option DatabaseConfig::noCheckpointOnCloseOption()
{
#ifdef SQLITE_DBCONFIG_NO_CKPT_ON_CLOSE
	return Option(m_database, SQLITE_DBCONFIG_NO_CKPT_ON_CLOSE);
#else
	return Option(m_database, INVALID_OPTION);
#endif
}

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */
