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

#ifndef ORG_PUZZLEHEAD_SQLEASY_TYPES_HPP_
#define ORG_PUZZLEHEAD_SQLEASY_TYPES_HPP_

#include <memory>

#include <sqlite3.h>

namespace org
{
namespace puzzlehead
{
namespace sqleasy
{

using Sqlite3DatabasePtr = std::shared_ptr<sqlite3>;

using Sqlite3StatementPtr = std::shared_ptr<sqlite3_stmt>;

using LoggerFunction = std::function<void(void * object, int code, const char * message)>;

using LoggerCallback = std::function<void(const int code, const std::string& message)>;

} /* namespace sqleasy */
} /* namespace puzzlehead */
} /* namespace org */

#endif /* ORG_PUZZLEHEAD_SQLEASY_TYPES_HPP_ */
