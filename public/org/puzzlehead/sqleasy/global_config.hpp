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

#ifndef ORG_PUZZLEHEAD_SQLEASY_GLOBAL_CONFIG_HPP_
#define ORG_PUZZLEHEAD_SQLEASY_GLOBAL_CONFIG_HPP_

#include <functional>
#include <mutex>

#include <org/puzzlehead/sqleasy/sqlite3_api.hpp>
#include <org/puzzlehead/sqleasy/types.hpp>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

class GlobalConfig
{
public:

	enum class ThreadingMode: int {
		SingleThread = 0,
		MultiThread = 1,
		Serialized = 2
	};

	GlobalConfig();

	explicit GlobalConfig(const Sqlite3Api::SharedPtr& api);

	virtual ~GlobalConfig();

	Sqlite3Api::SharedPtr api() const;

	int initialize();

	int shutdown();

	int setThreadingMode(const ThreadingMode& threadingMode);

	int setLoggerCallback(const LoggerCallback& logger);

protected:

	void log(const int code, const std::string& message);

	static void loggerCallback(void * object, int code, const char * message);

	std::mutex m_loggerMutex;

	Sqlite3Api::SharedPtr m_api = nullptr;

	LoggerCallback m_logger = nullptr;
};

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */

#endif /* ORG_PUZZLEHEAD_SQLEASY_GLOBAL_CONFIG_HPP_ */
