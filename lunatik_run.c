/*
* Copyright (c) 2023 ring-0 Ltda.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <linux/module.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "lunatik.h"

static lua_State *L;

static const luaL_Reg lunatik_libs[] = {
	{LUA_GNAME, luaopen_base},
	{LUA_LOADLIBNAME, luaopen_package},
	{LUA_COLIBNAME, luaopen_coroutine},
	{LUA_TABLIBNAME, luaopen_table},
	{LUA_STRLIBNAME, luaopen_string},
	{LUA_MATHLIBNAME, luaopen_math},
	{LUA_UTF8LIBNAME, luaopen_utf8},
	{LUA_DBLIBNAME, luaopen_debug},
	{"lunatik", luaopen_lunatik},
	{NULL, NULL}
};

static int __init lunatik_run_init(void)
{
	return lunatik_runtime(&L, lunatik_libs, "lunatik.lua", true);
}

static void __exit lunatik_run_exit(void)
{
	lunatik_stop(&L);
}

module_init(lunatik_run_init);
module_exit(lunatik_run_exit);
MODULE_LICENSE("Dual MIT/GPL");
MODULE_AUTHOR("Lourival Vieira Neto <lourival.neto@ring-0.io>");

