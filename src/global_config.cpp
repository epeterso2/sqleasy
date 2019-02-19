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

#include <mutex>

#include <org/puzzlehead/sqleasy/global_config.hpp>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

GlobalConfig::GlobalConfig() :
		GlobalConfig(Sqlite3Api::create())
{
}

GlobalConfig::GlobalConfig(const Sqlite3Api::SharedPtr& api) :
		m_api(api)
{
}

GlobalConfig::~GlobalConfig()
{
	setLoggerCallback(nullptr);
}

Sqlite3Api::SharedPtr GlobalConfig::api() const
{
	return m_api;
}

int GlobalConfig::initialize()
{
	return m_api ? m_api->initialize() : SQLITE_MISUSE;
}

int GlobalConfig::shutdown()
{
	return m_api ? m_api->shutdown() : SQLITE_MISUSE;
}

int GlobalConfig::setThreadingMode(const ThreadingMode& threadingMode)
{
	int result = SQLITE_MISUSE;

	if (m_api)
	{
		int option;

		switch (threadingMode)
		{
		case ThreadingMode::SingleThread:
			option = SQLITE_CONFIG_SINGLETHREAD;
			break;

		case ThreadingMode::MultiThread:
			option = SQLITE_CONFIG_MULTITHREAD;
			break;

		case ThreadingMode::Serialized:
			option = SQLITE_CONFIG_SERIALIZED;
			break;
		}

		result = m_api->config(option);
	}

	return result;
}

int GlobalConfig::setLoggerCallback(const LoggerCallback& logger)
{
	std::lock_guard<std::mutex> lock(m_loggerMutex);

	return m_api ? m_api->config(SQLITE_CONFIG_LOG, loggerCallback, this) : SQLITE_MISUSE;
}

void GlobalConfig::loggerCallback(void * object, int code, const char * message)
{
	GlobalConfig * gc = static_cast<GlobalConfig *>(object);

	if (gc != nullptr && gc->m_logger)
	{
		gc->log(code, message);
	}
}

void GlobalConfig::log(const int code, const std::string& message)
{
	std::lock_guard<std::mutex> lock(m_loggerMutex);

	if (m_logger)
	{
		m_logger(code, message);
	}
}

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */
